/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
 *
 * Code generated for Simulink model 'accelerometer_test'.
 *
 * Model version                  : 6.2
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Sun Nov 27 21:31:28 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "accelerometer_test.h"
#include "accelerometer_test_private.h"
#include "rtwtypes.h"
#include "limits.h"
#include "ext_work.h"
#include "board.h"
#include "mw_cmsis_rtos.h"
#define UNUSED(x)                      x = x
#define NAMELEN                        16
#define EXIT_ON_ERROR(msg, cond)       if (cond) { return(0); }

extern const char *TgtConnInit(int_T argc, char_T *argv[]);
extern void TgtConnTerm();
extern void TgtConnPreStep(int_T tid);
extern void TgtConnPostStep(int_T tid);
const char * csErrorStatus;

/* Function prototype declaration*/
void exitFcn(int sig);
void *terminateTask(void *arg);
void *baseRateTask(void *arg);
void *subrateTask(void *arg);
volatile boolean_T stopRequested = false;
volatile boolean_T runModel = true;
mw_signal_event_t stopSem;
mw_signal_event_t baserateTaskSem;
mw_signal_event_t subrateTaskSem[1];
int taskId[1];
mw_thread_t schedulerThread;
mw_thread_t baseRateThread;
mw_thread_t backgroundThread;
void *threadJoinStatus;
int terminatingmodel = 0;
mw_thread_t subRateThread[1];
int subratePriority[1];
void *subrateTask(void *arg)
{
  int tid = *((int *) arg);
  int subRateId;
  subRateId = tid + 1;
  while (runModel) {
    mw_osSignalEventWaitEver(&subrateTaskSem[tid]);
    if (terminatingmodel)
      break;
    accelerometer_test_step(subRateId);

    /* Get model outputs here */
    TgtConnPostStep(subRateId);
  }

  mw_osThreadExit((void *)0);
  return NULL;
}

void *baseRateTask(void *arg)
{
  runModel = (rtmGetErrorStatus(accelerometer_test_M) == (NULL)) &&
    !rtmGetStopRequested(accelerometer_test_M);
  while (runModel) {
    TgtConnPreStep(0);
    mw_osSignalEventWaitEver(&baserateTaskSem);
    if (rtmStepTask(accelerometer_test_M, 1)
        ) {
      mw_osSignalEventRelease(&subrateTaskSem[0]);
    }

    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModePauseIfNeeded(accelerometer_test_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(accelerometer_test_M, true);
      }

      if (rtmGetStopRequested(accelerometer_test_M) == true) {
        rtmSetErrorStatus(accelerometer_test_M, "Simulation finished");
        break;
      }
    }

    accelerometer_test_step(0);

    /* Get model outputs here */
    TgtConnPostStep(0);
    rtExtModeCheckEndTrigger();
    stopRequested = !((rtmGetErrorStatus(accelerometer_test_M) == (NULL)) &&
                      !rtmGetStopRequested(accelerometer_test_M));
    runModel = !stopRequested;
  }

  terminateTask(arg);
  mw_osThreadExit((void *)0);
  return NULL;
}

void exitFcn(int sig)
{
  UNUSED(sig);
  rtmSetErrorStatus(accelerometer_test_M, "stopping the model");
  runModel = 0;
}

void *terminateTask(void *arg)
{
  UNUSED(arg);
  terminatingmodel = 1;

  {
    int i;

    /* Signal all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(mw_osSignalEventRelease(&subrateTaskSem[i]), 0,
                   "mw_osSignalEventRelease");
      CHECK_STATUS(mw_osSignalEventDelete(&subrateTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }

    /* Wait for all periodic tasks to complete */
    for (i=0; i<1; i++) {
      CHECK_STATUS(mw_osThreadJoin(subRateThread[i], &threadJoinStatus), 0,
                   "mw_osThreadJoin");
    }

    runModel = 0;

    /* Wait for background task to complete */
    CHECK_STATUS(mw_osThreadJoin(backgroundThread, &threadJoinStatus), 0,
                 "mw_osThreadJoin");
  }

  /* Terminate model */
  accelerometer_test_terminate();
  rtExtModeShutdown(2);
  TgtConnTerm();
  mw_osSignalEventRelease(&stopSem);
  return NULL;
}

void *backgroundTask(void *arg)
{
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(accelerometer_test_M->extModeInfo, 2, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(accelerometer_test_M, true);
      }
    }

    runCommService();
  }

  mw_osThreadExit((void *)0);
  return NULL;
}

int main(int argc, char **argv)
{
  subratePriority[0] = 41;
  SystemCoreClockUpdate();
  hardware_init();
  rtmSetErrorStatus(accelerometer_test_M, 0);
  rtExtModeParseArgs(argc, (const char_T **)argv, NULL);

  /* Target connectivity initialization */
  csErrorStatus = TgtConnInit(argc, argv);
  EXIT_ON_ERROR("Error initializing target connectivity: %s\n", csErrorStatus);

  /* Initialize model */
  accelerometer_test_initialize();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(accelerometer_test_M));
  rtExtModeCheckInit(2);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(accelerometer_test_M->extModeInfo, 2, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(accelerometer_test_M, true);
    }
  }

  rtERTExtModeStartMsg();

  /* Call RTOS Initialization function */
  mw_RTOSInit(0.001, 1);

  /* Wait for stop semaphore */
  mw_osSignalEventWaitEver(&stopSem);

#if (MW_NUMBER_TIMER_DRIVEN_TASKS > 0)

  {
    int i;
    for (i=0; i < MW_NUMBER_TIMER_DRIVEN_TASKS; i++) {
      CHECK_STATUS(mw_osSignalEventDelete(&timerTaskSem[i]), 0,
                   "mw_osSignalEventDelete");
    }
  }

#endif

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
