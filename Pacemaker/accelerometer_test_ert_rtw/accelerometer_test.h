/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: accelerometer_test.h
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

#ifndef RTW_HEADER_accelerometer_test_h_
#define RTW_HEADER_accelerometer_test_h_
#ifndef accelerometer_test_COMMON_INCLUDES_
#define accelerometer_test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "dt_info.h"
#include "ext_work.h"
#include "MW_I2C.h"
#endif                                 /* accelerometer_test_COMMON_INCLUDES_ */

#include "accelerometer_test_types.h"
#include <stddef.h>
#include <float.h>
#include <string.h>

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T csumrev[599];
  real_T MovingAverage;                /* '<S1>/Moving Average' */
  real_T modValueRev;
} B_accelerometer_test_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_ac_T obj; /* '<S1>/Moving Average' */
  freedomk64f_fxos8700_accelero_T obj_i;/* '<Root>/FXOS8700 6-Axes Sensor' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S1>/Scope' */
} DW_accelerometer_test_T;

/* Parameters (default storage) */
struct P_accelerometer_test_T_ {
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: 0.1
                                         * Referenced by: '<Root>/FXOS8700 6-Axes Sensor'
                                         */
};

/* Real-time Model Data Structure */
struct tag_RTM_accelerometer_test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_accelerometer_test_T accelerometer_test_P;

/* Block signals (default storage) */
extern B_accelerometer_test_T accelerometer_test_B;

/* Block states (default storage) */
extern DW_accelerometer_test_T accelerometer_test_DW;

/* External function called from main */
extern void accelerometer_test_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void accelerometer_test_initialize(void);
extern void accelerometer_test_step0(void);
extern void accelerometer_test_step1(void);
extern void accelerometer_test_step(int_T tid);
extern void accelerometer_test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_accelerometer_test_T *const accelerometer_test_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'accelerometer_test'
 * '<S1>'   : 'accelerometer_test/Subsystem'
 */
#endif                                 /* RTW_HEADER_accelerometer_test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
