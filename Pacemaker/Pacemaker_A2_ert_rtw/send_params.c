/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params.c
 *
 * Code generated for Simulink model 'Pacemaker_A2'.
 *
 * Model version                  : 4.5
 * Simulink Coder version         : 9.8 (R2022b) 13-May-2022
 * C/C++ source code generated on : Mon Nov 28 15:08:26 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Pacemaker_A2_types.h"
#include "send_params_private.h"
#include "Pacemaker_A2.h"
#include "send_params.h"
#include <string.h>
#include "rtwtypes.h"
#include <stddef.h>

/* Forward declaration for local functions */
static void Pacemaker_A2_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj);
static void Pacemaker_A2_SystemCore_setup(freedomk64f_SCIWrite_Pacemake_T *obj)
{
  MW_SCI_Parity_Type ParityValue;
  MW_SCI_StopBits_Type StopBitsValue;
  uint32_T RxPinLoc;
  uint32_T SCIModuleLoc;
  obj->isInitialized = 1;
  RxPinLoc = MW_UNDEFINED_VALUE;
  SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&SCIModuleLoc, false, RxPinLoc, 10U);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  StopBitsValue = MW_SCI_STOPBITS_1;
  ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, ParityValue, StopBitsValue);
  obj->isSetupComplete = true;
}

/* System initialize for Simulink Function: '<Root>/Send To DCM' */
void send_params_Init(void)
{
  MW_AnalogIn_TriggerSource_Type trigger_val;
  freedomk64f_AnalogInput_Pacem_T *obj;

  /* Start for MATLABSystem: '<S7>/ATR_SIGNAL' */
  Pacemaker_A2_DW.obj_p.matlabCodegenIsDeleted = false;
  Pacemaker_A2_DW.obj_p.SampleTime = Pacemaker_A2_P.ATR_SIGNAL_SampleTime;
  obj = &Pacemaker_A2_DW.obj_p;
  Pacemaker_A2_DW.obj_p.isInitialized = 1;
  obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(16U);
  trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource(Pacemaker_A2_DW.obj_p.MW_ANALOGIN_HANDLE,
    trigger_val, 0U);
  Pacemaker_A2_DW.obj_p.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/VENT_SIGNAL' */
  Pacemaker_A2_DW.obj_j.matlabCodegenIsDeleted = false;
  Pacemaker_A2_DW.obj_j.SampleTime = Pacemaker_A2_P.VENT_SIGNAL_SampleTime;
  obj = &Pacemaker_A2_DW.obj_j;
  Pacemaker_A2_DW.obj_j.isInitialized = 1;
  obj->MW_ANALOGIN_HANDLE = MW_AnalogInSingle_Open(17U);
  trigger_val = MW_ANALOGIN_SOFTWARE_TRIGGER;
  MW_AnalogIn_SetTriggerSource(Pacemaker_A2_DW.obj_j.MW_ANALOGIN_HANDLE,
    trigger_val, 0U);
  Pacemaker_A2_DW.obj_j.isSetupComplete = true;

  /* Start for MATLABSystem: '<S7>/Send to DCM' */
  Pacemaker_A2_DW.obj_fu.isInitialized = 0;
  Pacemaker_A2_DW.obj_fu.matlabCodegenIsDeleted = false;
  Pacemaker_A2_SystemCore_setup(&Pacemaker_A2_DW.obj_fu);
}

/* Output and update for Simulink Function: '<Root>/Send To DCM' */
void send_params(void)
{
  int32_T i;
  uint8_T status;

  /* SignalConversion generated from: '<S7>/MODE' */
  Pacemaker_A2_B.MODE = Pacemaker_A2_B.MODE_d;

  /* SignalConversion generated from: '<S7>/LRL' */
  Pacemaker_A2_B.LRL = Pacemaker_A2_B.LRL_j;

  /* SignalConversion generated from: '<S7>/PVARP' */
  Pacemaker_A2_B.PVARP = Pacemaker_A2_B.PVARP_i;

  /* SignalConversion generated from: '<S7>/VENT_AMP' */
  Pacemaker_A2_B.ATR_AMP = Pacemaker_A2_B.ATR_AMP_o;

  /* SignalConversion generated from: '<S7>/ATR_AMP' */
  Pacemaker_A2_B.VENT_AMP = Pacemaker_A2_B.VENT_AMP_i;

  /* SignalConversion generated from: '<S7>/VENT_PULSE_WIDTH' */
  Pacemaker_A2_B.VENT_PULSE_WIDTH = Pacemaker_A2_B.VENT_PULSE_WIDTH_g;

  /* SignalConversion generated from: '<S7>/ATR_PULSE_WIDTH' */
  Pacemaker_A2_B.ATR_PULSE_WIDTH = Pacemaker_A2_B.ATR_PULSE_WIDTH_d;

  /* SignalConversion generated from: '<S7>/VENT_sensitivity' */
  Pacemaker_A2_B.VENT_sensitivity = Pacemaker_A2_B.VENT_sensitivity_p;

  /* SignalConversion generated from: '<S7>/ATR_sensitivity' */
  Pacemaker_A2_B.ATR_sensitivity = Pacemaker_A2_B.ATR_sensitivity_h;

  /* SignalConversion generated from: '<S7>/ARP' */
  Pacemaker_A2_B.ARP = Pacemaker_A2_B.ARP_m;

  /* SignalConversion generated from: '<S7>/VRP' */
  Pacemaker_A2_B.VRP = Pacemaker_A2_B.VRP_l;

  /* SignalConversion generated from: '<S7>/MSR' */
  Pacemaker_A2_B.MSR = Pacemaker_A2_B.MSR_m;

  /* SignalConversion generated from: '<S7>/Activity_threshold' */
  Pacemaker_A2_B.Activity_threshold = Pacemaker_A2_B.Activity_threshold_a;

  /* SignalConversion generated from: '<S7>/Response_factor' */
  Pacemaker_A2_B.Respond_factor = Pacemaker_A2_B.Respond_factor_b;

  /* SignalConversion generated from: '<S7>/Reaction_time' */
  Pacemaker_A2_B.Reaction_time = Pacemaker_A2_B.Reaction_time_i;

  /* SignalConversion generated from: '<S7>/Recovery_time' */
  Pacemaker_A2_B.Recovery_time = Pacemaker_A2_B.Recovery_time_n;

  /* S-Function (any2byte): '<S7>/Byte Pack12' */

  /* Pack: <S7>/Byte Pack12 */
  (void) memcpy(&Pacemaker_A2_B.BytePack12[0], &Pacemaker_A2_B.MODE,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack13' */

  /* Pack: <S7>/Byte Pack13 */
  (void) memcpy(&Pacemaker_A2_B.BytePack13[0], &Pacemaker_A2_B.LRL,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack8' */

  /* Pack: <S7>/Byte Pack8 */
  (void) memcpy(&Pacemaker_A2_B.BytePack8[0], &Pacemaker_A2_B.PVARP,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack' */

  /* Pack: <S7>/Byte Pack */
  (void) memcpy(&Pacemaker_A2_B.BytePack[0], &Pacemaker_A2_B.ATR_AMP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack1' */

  /* Pack: <S7>/Byte Pack1 */
  (void) memcpy(&Pacemaker_A2_B.BytePack1[0], &Pacemaker_A2_B.VENT_AMP,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack6' */

  /* Pack: <S7>/Byte Pack6 */
  (void) memcpy(&Pacemaker_A2_B.BytePack6[0], &Pacemaker_A2_B.VENT_PULSE_WIDTH,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack7' */

  /* Pack: <S7>/Byte Pack7 */
  (void) memcpy(&Pacemaker_A2_B.BytePack7[0], &Pacemaker_A2_B.ATR_PULSE_WIDTH,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack2' */

  /* Pack: <S7>/Byte Pack2 */
  (void) memcpy(&Pacemaker_A2_B.BytePack2[0], &Pacemaker_A2_B.VENT_sensitivity,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack3' */

  /* Pack: <S7>/Byte Pack3 */
  (void) memcpy(&Pacemaker_A2_B.BytePack3[0], &Pacemaker_A2_B.ATR_sensitivity,
                4);

  /* S-Function (any2byte): '<S7>/Byte Pack4' */

  /* Pack: <S7>/Byte Pack4 */
  (void) memcpy(&Pacemaker_A2_B.BytePack4[0], &Pacemaker_A2_B.ARP,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack5' */

  /* Pack: <S7>/Byte Pack5 */
  (void) memcpy(&Pacemaker_A2_B.BytePack5[0], &Pacemaker_A2_B.VRP,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack11' */

  /* Pack: <S7>/Byte Pack11 */
  (void) memcpy(&Pacemaker_A2_B.BytePack11[0], &Pacemaker_A2_B.MSR,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack14' */

  /* Pack: <S7>/Byte Pack14 */
  (void) memcpy(&Pacemaker_A2_B.BytePack14[0],
                &Pacemaker_A2_B.Activity_threshold,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack15' */

  /* Pack: <S7>/Byte Pack15 */
  (void) memcpy(&Pacemaker_A2_B.BytePack15[0], &Pacemaker_A2_B.Respond_factor,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack16' */

  /* Pack: <S7>/Byte Pack16 */
  (void) memcpy(&Pacemaker_A2_B.BytePack16[0], &Pacemaker_A2_B.Reaction_time,
                2);

  /* S-Function (any2byte): '<S7>/Byte Pack17' */

  /* Pack: <S7>/Byte Pack17 */
  (void) memcpy(&Pacemaker_A2_B.BytePack17[0], &Pacemaker_A2_B.Recovery_time,
                2);

  /* MATLABSystem: '<S7>/ATR_SIGNAL' */
  if (Pacemaker_A2_DW.obj_p.SampleTime != Pacemaker_A2_P.ATR_SIGNAL_SampleTime)
  {
    Pacemaker_A2_DW.obj_p.SampleTime = Pacemaker_A2_P.ATR_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(Pacemaker_A2_DW.obj_p.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S7>/ATR_SIGNAL' */
  MW_AnalogInSingle_ReadResult(Pacemaker_A2_DW.obj_p.MW_ANALOGIN_HANDLE,
    &Pacemaker_A2_B.ATR_SIGNAL, 7);

  /* S-Function (any2byte): '<S7>/Byte Pack9' */

  /* Pack: <S7>/Byte Pack9 */
  (void) memcpy(&Pacemaker_A2_B.BytePack9[0], &Pacemaker_A2_B.ATR_SIGNAL,
                8);

  /* MATLABSystem: '<S7>/VENT_SIGNAL' */
  if (Pacemaker_A2_DW.obj_j.SampleTime != Pacemaker_A2_P.VENT_SIGNAL_SampleTime)
  {
    Pacemaker_A2_DW.obj_j.SampleTime = Pacemaker_A2_P.VENT_SIGNAL_SampleTime;
  }

  MW_AnalogIn_Start(Pacemaker_A2_DW.obj_j.MW_ANALOGIN_HANDLE);

  /* MATLABSystem: '<S7>/VENT_SIGNAL' */
  MW_AnalogInSingle_ReadResult(Pacemaker_A2_DW.obj_j.MW_ANALOGIN_HANDLE,
    &Pacemaker_A2_B.VENT_SIGNAL, 7);

  /* S-Function (any2byte): '<S7>/Byte Pack10' */

  /* Pack: <S7>/Byte Pack10 */
  (void) memcpy(&Pacemaker_A2_B.BytePack10[0], &Pacemaker_A2_B.VENT_SIGNAL,
                8);

  /* SignalConversion generated from: '<S7>/Send to DCM' */
  Pacemaker_A2_B.TmpSignalConversionAtSendto[0] = Pacemaker_A2_B.BytePack12[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[2] = Pacemaker_A2_B.BytePack13[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[4] = Pacemaker_A2_B.BytePack8[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[1] = Pacemaker_A2_B.BytePack12[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[3] = Pacemaker_A2_B.BytePack13[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[5] = Pacemaker_A2_B.BytePack8[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[6] = Pacemaker_A2_B.BytePack[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[10] = Pacemaker_A2_B.BytePack1[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[14] = Pacemaker_A2_B.BytePack6[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[18] = Pacemaker_A2_B.BytePack7[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[22] = Pacemaker_A2_B.BytePack2[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[26] = Pacemaker_A2_B.BytePack3[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[7] = Pacemaker_A2_B.BytePack[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[11] = Pacemaker_A2_B.BytePack1[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[15] = Pacemaker_A2_B.BytePack6[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[19] = Pacemaker_A2_B.BytePack7[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[23] = Pacemaker_A2_B.BytePack2[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[27] = Pacemaker_A2_B.BytePack3[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[8] = Pacemaker_A2_B.BytePack[2];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[12] = Pacemaker_A2_B.BytePack1[2];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[16] = Pacemaker_A2_B.BytePack6[2];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[20] = Pacemaker_A2_B.BytePack7[2];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[24] = Pacemaker_A2_B.BytePack2[2];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[28] = Pacemaker_A2_B.BytePack3[2];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[9] = Pacemaker_A2_B.BytePack[3];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[13] = Pacemaker_A2_B.BytePack1[3];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[17] = Pacemaker_A2_B.BytePack6[3];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[21] = Pacemaker_A2_B.BytePack7[3];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[25] = Pacemaker_A2_B.BytePack2[3];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[29] = Pacemaker_A2_B.BytePack3[3];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[30] = Pacemaker_A2_B.BytePack4[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[32] = Pacemaker_A2_B.BytePack5[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[34] = Pacemaker_A2_B.BytePack11[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[36] = Pacemaker_A2_B.BytePack14[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[38] = Pacemaker_A2_B.BytePack15[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[40] = Pacemaker_A2_B.BytePack16[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[42] = Pacemaker_A2_B.BytePack17[0];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[31] = Pacemaker_A2_B.BytePack4[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[33] = Pacemaker_A2_B.BytePack5[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[35] = Pacemaker_A2_B.BytePack11[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[37] = Pacemaker_A2_B.BytePack14[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[39] = Pacemaker_A2_B.BytePack15[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[41] = Pacemaker_A2_B.BytePack16[1];
  Pacemaker_A2_B.TmpSignalConversionAtSendto[43] = Pacemaker_A2_B.BytePack17[1];
  for (i = 0; i < 8; i++) {
    Pacemaker_A2_B.TmpSignalConversionAtSendto[i + 44] =
      Pacemaker_A2_B.BytePack9[i];
    Pacemaker_A2_B.TmpSignalConversionAtSendto[i + 52] =
      Pacemaker_A2_B.BytePack10[i];
  }

  /* End of SignalConversion generated from: '<S7>/Send to DCM' */

  /* MATLABSystem: '<S7>/Send to DCM' */
  status = 1U;
  while (status != 0) {
    memcpy((void *)&Pacemaker_A2_B.TxDataLocChar[0], (void *)
           &Pacemaker_A2_B.TmpSignalConversionAtSendto[0], (size_t)60 * sizeof
           (uint8_T));
    status = MW_SCI_Transmit(Pacemaker_A2_DW.obj_fu.MW_SCIHANDLE,
      &Pacemaker_A2_B.TxDataLocChar[0], 60U);
  }

  /* End of MATLABSystem: '<S7>/Send to DCM' */
}

/* Termination for Simulink Function: '<Root>/Send To DCM' */
void send_params_Term(void)
{
  /* Terminate for MATLABSystem: '<S7>/ATR_SIGNAL' */
  if (!Pacemaker_A2_DW.obj_p.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_p.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_p.isSetupComplete) {
      MW_AnalogIn_Stop(Pacemaker_A2_DW.obj_p.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Pacemaker_A2_DW.obj_p.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/ATR_SIGNAL' */

  /* Terminate for MATLABSystem: '<S7>/VENT_SIGNAL' */
  if (!Pacemaker_A2_DW.obj_j.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_j.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_j.isSetupComplete) {
      MW_AnalogIn_Stop(Pacemaker_A2_DW.obj_j.MW_ANALOGIN_HANDLE);
      MW_AnalogIn_Close(Pacemaker_A2_DW.obj_j.MW_ANALOGIN_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/VENT_SIGNAL' */

  /* Terminate for MATLABSystem: '<S7>/Send to DCM' */
  if (!Pacemaker_A2_DW.obj_fu.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_fu.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_fu.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_fu.isSetupComplete) {
      MW_SCI_Close(Pacemaker_A2_DW.obj_fu.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Send to DCM' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
