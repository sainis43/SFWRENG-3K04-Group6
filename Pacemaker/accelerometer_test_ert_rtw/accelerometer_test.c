/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: accelerometer_test.c
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
#include "accelerometer_test_types.h"
#include <string.h>
#include <math.h>
#include "rtwtypes.h"
#include <stddef.h>
#include "MW_I2C.h"
#include "accelerometer_test_private.h"
#include "accelerometer_test_dt.h"

/* Block signals (default storage) */
B_accelerometer_test_T accelerometer_test_B;

/* Block states (default storage) */
DW_accelerometer_test_T accelerometer_test_DW;

/* Real-time model */
static RT_MODEL_accelerometer_test_T accelerometer_test_M_;
RT_MODEL_accelerometer_test_T *const accelerometer_test_M =
  &accelerometer_test_M_;

/* Forward declaration for local functions */
static void accelerometer__SystemCore_setup(freedomk64f_fxos8700_accelero_T *obj);
static void acceleromete_SystemCore_setup_p(dsp_simulink_MovingAverage_ac_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void accelerometer_test_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(accelerometer_test_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (accelerometer_test_M->Timing.TaskCounters.TID[1])++;
  if ((accelerometer_test_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    accelerometer_test_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void accelerometer__SystemCore_setup(freedomk64f_fxos8700_accelero_T *obj)
{
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue;
  uint8_T status;
  obj->isInitialized = 1;
  ModeType = MW_I2C_MASTER;
  i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(i2cname, ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  b_SwappedDataBytes[0] = 43U;
  b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  OSA_TimeDelay(500U);
  status = 42U;
  status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, true,
    false);
  if (status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &status, 1U, false, true);
    memcpy((void *)&b_RegisterValue, (void *)&status, (size_t)1 * sizeof(uint8_T));
  } else {
    b_RegisterValue = 0U;
  }

  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = (uint8_T)(b_RegisterValue & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 14U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 91U;
  b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  b_SwappedDataBytes[0] = 42U;
  b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U, &b_SwappedDataBytes[0], 2U,
                     false, false);
  obj->isSetupComplete = true;
}

static void acceleromete_SystemCore_setup_p(dsp_simulink_MovingAverage_ac_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

/* Model step function for TID0 */
void accelerometer_test_step0(void)    /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* External mode */
  rtExtModeUploadCheckTrigger(2);
  rtExtModeUpload(0, (real_T)accelerometer_test_M->Timing.taskTime0);

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.001s, 0.0s] */
    if ((rtmGetTFinal(accelerometer_test_M)!=-1) &&
        !((rtmGetTFinal(accelerometer_test_M)-
           accelerometer_test_M->Timing.taskTime0) >
          accelerometer_test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(accelerometer_test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(accelerometer_test_M)) {
      rtmSetErrorStatus(accelerometer_test_M, "Simulation finished");
    }
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  accelerometer_test_M->Timing.taskTime0 =
    ((time_T)(++accelerometer_test_M->Timing.clockTick0)) *
    accelerometer_test_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void accelerometer_test_step1(void)    /* Sample time: [0.1s, 0.0s] */
{
  g_dsp_internal_SlidingWindowA_T *obj;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  real_T z;
  int32_T i;
  int16_T b_RegisterValue[3];
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;

  /* MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
  if (accelerometer_test_DW.obj_i.SampleTime !=
      accelerometer_test_P.FXOS87006AxesSensor_SampleTime) {
    accelerometer_test_DW.obj_i.SampleTime =
      accelerometer_test_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(accelerometer_test_DW.obj_i.i2cobj.MW_I2C_HANDLE,
    29U, &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(accelerometer_test_DW.obj_i.i2cobj.MW_I2C_HANDLE, 29U,
                      &output_raw[0], 6U, false, true);
    memcpy((void *)&b_RegisterValue[0], (void *)&output_raw[0], (size_t)3 *
           sizeof(int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[0], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[0], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[1], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[1], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
    memcpy((void *)&y[0], (void *)&b_RegisterValue[2], (size_t)2 * sizeof
           (uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&b_RegisterValue[2], (void *)&b_x[0], (size_t)1 * sizeof
           (int16_T));
  } else {
    b_RegisterValue[0] = 0;
    b_RegisterValue[1] = 0;
    b_RegisterValue[2] = 0;
  }

  rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)(b_RegisterValue[0] >> 2) *
    2.0 * 0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)(b_RegisterValue[1] >> 2) *
    2.0 * 0.244 / 1000.0;
  rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)(b_RegisterValue[2] >> 2) *
    2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */

  /* Sqrt: '<S1>/Sqrt' incorporates:
   *  Math: '<S1>/Math Function'
   *  Math: '<S1>/Math Function1'
   *  Math: '<S1>/Math Function2'
   *  Sum: '<S1>/Add'
   *  Sum: '<S1>/Add1'
   *
   * About '<S1>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S1>/Math Function1':
   *  Operator: magnitude^2
   *
   * About '<S1>/Math Function2':
   *  Operator: magnitude^2
   */
  rtb_FXOS87006AxesSensor_idx_0 = sqrt((rtb_FXOS87006AxesSensor_idx_0 *
    rtb_FXOS87006AxesSensor_idx_0 + rtb_FXOS87006AxesSensor_idx_1 *
    rtb_FXOS87006AxesSensor_idx_1) + rtb_FXOS87006AxesSensor_idx_2 *
    rtb_FXOS87006AxesSensor_idx_2);

  /* MATLABSystem: '<S1>/Moving Average' */
  if (accelerometer_test_DW.obj.TunablePropsChanged) {
    accelerometer_test_DW.obj.TunablePropsChanged = false;
  }

  obj = accelerometer_test_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 599; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 599; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  rtb_FXOS87006AxesSensor_idx_1 = obj->pCumRevIndex;
  rtb_FXOS87006AxesSensor_idx_2 = obj->pCumSum;
  for (i = 0; i < 599; i++) {
    accelerometer_test_B.csumrev[i] = obj->pCumSumRev[i];
  }

  accelerometer_test_B.modValueRev = obj->pModValueRev;
  z = 0.0;

  /* MATLABSystem: '<S1>/Moving Average' */
  accelerometer_test_B.MovingAverage = 0.0;

  /* MATLABSystem: '<S1>/Moving Average' */
  rtb_FXOS87006AxesSensor_idx_2 += rtb_FXOS87006AxesSensor_idx_0;
  if (accelerometer_test_B.modValueRev == 0.0) {
    z = accelerometer_test_B.csumrev[(int32_T)rtb_FXOS87006AxesSensor_idx_1 - 1]
      + rtb_FXOS87006AxesSensor_idx_2;
  }

  accelerometer_test_B.csumrev[(int32_T)rtb_FXOS87006AxesSensor_idx_1 - 1] =
    rtb_FXOS87006AxesSensor_idx_0;
  if (rtb_FXOS87006AxesSensor_idx_1 != 599.0) {
    rtb_FXOS87006AxesSensor_idx_1++;
  } else {
    rtb_FXOS87006AxesSensor_idx_1 = 1.0;
    rtb_FXOS87006AxesSensor_idx_2 = 0.0;
    for (i = 597; i >= 0; i--) {
      accelerometer_test_B.csumrev[i] += accelerometer_test_B.csumrev[i + 1];
    }
  }

  if (accelerometer_test_B.modValueRev == 0.0) {
    /* MATLABSystem: '<S1>/Moving Average' */
    accelerometer_test_B.MovingAverage = z / 600.0;
  }

  obj->pCumSum = rtb_FXOS87006AxesSensor_idx_2;
  for (i = 0; i < 599; i++) {
    obj->pCumSumRev[i] = accelerometer_test_B.csumrev[i];
  }

  obj->pCumRevIndex = rtb_FXOS87006AxesSensor_idx_1;
  if (accelerometer_test_B.modValueRev > 0.0) {
    obj->pModValueRev = accelerometer_test_B.modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  rtExtModeUpload(1, (real_T)((accelerometer_test_M->Timing.clockTick1) * 0.1));

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  accelerometer_test_M->Timing.clockTick1++;
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void accelerometer_test_step(int_T tid)
{
  switch (tid) {
   case 0 :
    accelerometer_test_step0();
    break;

   case 1 :
    accelerometer_test_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void accelerometer_test_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(accelerometer_test_M, -1);
  accelerometer_test_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  accelerometer_test_M->Sizes.checksums[0] = (2365902244U);
  accelerometer_test_M->Sizes.checksums[1] = (700824880U);
  accelerometer_test_M->Sizes.checksums[2] = (4223270562U);
  accelerometer_test_M->Sizes.checksums[3] = (3735960603U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    accelerometer_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(accelerometer_test_M->extModeInfo,
      &accelerometer_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(accelerometer_test_M->extModeInfo,
                        accelerometer_test_M->Sizes.checksums);
    rteiSetTPtr(accelerometer_test_M->extModeInfo, rtmGetTPtr
                (accelerometer_test_M));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    accelerometer_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 21;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  {
    g_dsp_internal_SlidingWindowA_T *obj;
    int32_T i;

    /* Start for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
    accelerometer_test_DW.obj_i.isInitialized = 0;
    accelerometer_test_DW.obj_i.i2cobj.isInitialized = 0;
    accelerometer_test_DW.obj_i.i2cobj.matlabCodegenIsDeleted = false;
    accelerometer_test_DW.obj_i.matlabCodegenIsDeleted = false;
    accelerometer_test_DW.obj_i.SampleTime =
      accelerometer_test_P.FXOS87006AxesSensor_SampleTime;
    accelerometer__SystemCore_setup(&accelerometer_test_DW.obj_i);

    /* Start for MATLABSystem: '<S1>/Moving Average' */
    accelerometer_test_DW.obj.isInitialized = 0;
    accelerometer_test_DW.obj.NumChannels = -1;
    accelerometer_test_DW.obj.FrameLength = -1;
    accelerometer_test_DW.obj.matlabCodegenIsDeleted = false;
    acceleromete_SystemCore_setup_p(&accelerometer_test_DW.obj);

    /* InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
    obj = accelerometer_test_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0;
      for (i = 0; i < 599; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S1>/Moving Average' */
  }
}

/* Model terminate function */
void accelerometer_test_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindowA_T *obj_0;

  /* Terminate for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */
  if (!accelerometer_test_DW.obj_i.matlabCodegenIsDeleted) {
    accelerometer_test_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((accelerometer_test_DW.obj_i.isInitialized == 1) &&
        accelerometer_test_DW.obj_i.isSetupComplete) {
      MW_I2C_Close(accelerometer_test_DW.obj_i.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &accelerometer_test_DW.obj_i.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S1>/Moving Average' */
  if (!accelerometer_test_DW.obj.matlabCodegenIsDeleted) {
    accelerometer_test_DW.obj.matlabCodegenIsDeleted = true;
    if ((accelerometer_test_DW.obj.isInitialized == 1) &&
        accelerometer_test_DW.obj.isSetupComplete) {
      obj_0 = accelerometer_test_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      accelerometer_test_DW.obj.NumChannels = -1;
      accelerometer_test_DW.obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S1>/Moving Average' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
