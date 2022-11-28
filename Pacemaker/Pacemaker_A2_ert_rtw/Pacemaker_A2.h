/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_A2.h
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

#ifndef RTW_HEADER_Pacemaker_A2_h_
#define RTW_HEADER_Pacemaker_A2_h_
#ifndef Pacemaker_A2_COMMON_INCLUDES_
#define Pacemaker_A2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#include "MW_AnalogIn.h"
#endif                                 /* Pacemaker_A2_COMMON_INCLUDES_ */

#include "Pacemaker_A2_types.h"
#include <stddef.h>
#include "send_params.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  real_T csumrev[499];
  uint8_T TxDataLocChar[60];
  uint8_T TmpSignalConversionAtSendto[60];
  uint8_T RxData[46];
  uint8_T RxDataLocChar[46];
  uint32_T TxPinLoc;
  uint32_T SCIModuleLoc;
  MW_SCI_StopBits_Type StopBitsValue;
  MW_SCI_Parity_Type ParityValue;
  MW_I2C_Mode_Type ModeType;
  uint32_T i2cname;
  real_T VENT_SIGNAL;                  /* '<S7>/VENT_SIGNAL' */
  real_T ATR_SIGNAL;                   /* '<S7>/ATR_SIGNAL' */
  real_T GREEN_LED;                    /* '<Root>/ MODES' */
  real_T RED_LED;                      /* '<Root>/ MODES' */
  real_T d;
  real_T modValueRev;
  real_T z;
  real_T rtb_FXOS87006AxesSensor_idx_0;
  real_T rtb_FXOS87006AxesSensor_idx_1;
  real_T rtb_FXOS87006AxesSensor_idx_2;
  real_T d1;
  int16_T b_RegisterValue[3];
  real32_T ATR_AMP;
  real32_T VENT_AMP;
  real32_T VENT_PULSE_WIDTH;
  real32_T ATR_PULSE_WIDTH;
  real32_T VENT_sensitivity;
  real32_T ATR_sensitivity;
  real32_T VENT_AMP_i;                 /* '<Root>/COM_IN' */
  real32_T VENT_PULSE_WIDTH_g;         /* '<Root>/COM_IN' */
  real32_T ATR_AMP_o;                  /* '<Root>/COM_IN' */
  real32_T ATR_PULSE_WIDTH_d;          /* '<Root>/COM_IN' */
  real32_T ATR_sensitivity_h;          /* '<Root>/COM_IN' */
  real32_T VENT_sensitivity_p;         /* '<Root>/COM_IN' */
  real32_T PACING_REF_PWM;             /* '<Root>/ MODES' */
  real32_T VENT_CMP_REF_PWM;           /* '<Root>/ MODES' */
  real32_T ATR_CMP_REF_PWM;            /* '<Root>/ MODES' */
  int32_T i;
  uint16_T MODE;
  uint16_T LRL;
  uint16_T PVARP;
  uint16_T ARP;
  uint16_T VRP;
  uint16_T MSR;
  uint16_T Activity_threshold;
  uint16_T Respond_factor;
  uint16_T Reaction_time;
  uint16_T Recovery_time;
  uint16_T rate;                       /* '<Root>/Rate Calculator' */
  uint16_T LRL_j;                      /* '<Root>/COM_IN' */
  uint16_T VRP_l;                      /* '<Root>/COM_IN' */
  uint16_T ARP_m;                      /* '<Root>/COM_IN' */
  uint16_T MSR_m;                      /* '<Root>/COM_IN' */
  uint16_T PVARP_i;                    /* '<Root>/COM_IN' */
  uint16_T MODE_d;                     /* '<Root>/COM_IN' */
  uint16_T Reaction_time_i;            /* '<Root>/COM_IN' */
  uint16_T Recovery_time_n;            /* '<Root>/COM_IN' */
  uint16_T Respond_factor_b;           /* '<Root>/COM_IN' */
  uint16_T Activity_threshold_a;       /* '<Root>/COM_IN' */
  uint8_T BytePack12[2];               /* '<S7>/Byte Pack12' */
  uint8_T BytePack13[2];               /* '<S7>/Byte Pack13' */
  uint8_T BytePack8[2];                /* '<S7>/Byte Pack8' */
  uint8_T BytePack[4];                 /* '<S7>/Byte Pack' */
  uint8_T BytePack1[4];                /* '<S7>/Byte Pack1' */
  uint8_T BytePack6[4];                /* '<S7>/Byte Pack6' */
  uint8_T BytePack7[4];                /* '<S7>/Byte Pack7' */
  uint8_T BytePack2[4];                /* '<S7>/Byte Pack2' */
  uint8_T BytePack3[4];                /* '<S7>/Byte Pack3' */
  uint8_T BytePack4[2];                /* '<S7>/Byte Pack4' */
  uint8_T BytePack5[2];                /* '<S7>/Byte Pack5' */
  uint8_T BytePack11[2];               /* '<S7>/Byte Pack11' */
  uint8_T BytePack14[2];               /* '<S7>/Byte Pack14' */
  uint8_T BytePack15[2];               /* '<S7>/Byte Pack15' */
  uint8_T BytePack16[2];               /* '<S7>/Byte Pack16' */
  uint8_T BytePack17[2];               /* '<S7>/Byte Pack17' */
  uint8_T BytePack9[8];                /* '<S7>/Byte Pack9' */
  uint8_T BytePack10[8];               /* '<S7>/Byte Pack10' */
  uint8_T b_SwappedDataBytes[2];
  uint8_T b_RegisterValue_m;
  uint8_T status;
  boolean_T PACE_CHARGE_CTRL;          /* '<Root>/ MODES' */
  boolean_T ATR_PACE_CTRL;             /* '<Root>/ MODES' */
  boolean_T VENT_PACE_CTRL;            /* '<Root>/ MODES' */
  boolean_T VENT_GND_CTRL;             /* '<Root>/ MODES' */
  boolean_T PACE_GND_CTRL;             /* '<Root>/ MODES' */
  boolean_T ATR_GND_CTRL;              /* '<Root>/ MODES' */
  boolean_T FRONTEND_CTRL;             /* '<Root>/ MODES' */
} B_Pacemaker_A2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MovingAverage_Pa_T obj; /* '<S8>/Moving Average' */
  freedomk64f_fxos8700_Pacemake_T obj_b;/* '<S8>/FXOS8700 6-Axes Sensor' */
  freedomk64f_DigitalRead_Pacem_T obj_i;/* '<S5>/VENT_CMP_DETECT' */
  freedomk64f_DigitalRead_Pacem_T obj_a;/* '<S5>/ATR_CMP_DETECT' */
  freedomk64f_AnalogInput_Pacem_T obj_j;/* '<S7>/VENT_SIGNAL' */
  freedomk64f_AnalogInput_Pacem_T obj_p;/* '<S7>/ATR_SIGNAL' */
  freedomk64f_SCIRead_Pacemaker_T obj_e;/* '<Root>/Serial Receive' */
  freedomk64f_DigitalWrite_Pace_T obj_n;/* '<S4>/Digital Write9' */
  freedomk64f_DigitalWrite_Pace_T obj_f;/* '<S4>/Digital Write8' */
  freedomk64f_DigitalWrite_Pace_T obj_pf;/* '<S4>/Digital Write7' */
  freedomk64f_DigitalWrite_Pace_T obj_jo;/* '<S4>/Digital Write6' */
  freedomk64f_DigitalWrite_Pace_T obj_jk;/* '<S4>/Digital Write5' */
  freedomk64f_DigitalWrite_Pace_T obj_bq;/* '<S4>/Digital Write14' */
  freedomk64f_DigitalWrite_Pace_T obj_l;/* '<S4>/Digital Write12' */
  freedomk64f_DigitalWrite_Pace_T obj_jf;/* '<S4>/Digital Write1' */
  freedomk64f_DigitalWrite_Pace_T obj_m;/* '<S4>/Digital Write' */
  freedomk64f_PWMOutput_Pacemak_T obj_ml;/* '<S4>/PWM Output2' */
  freedomk64f_PWMOutput_Pacemak_T obj_d;/* '<S4>/PWM Output1' */
  freedomk64f_PWMOutput_Pacemak_T obj_j3;/* '<S4>/PWM Output' */
  freedomk64f_SCIWrite_Pacemake_T obj_fu;/* '<S7>/Send to DCM' */
  uint32_T temporalCounter_i1;         /* '<Root>/ MODES' */
  uint16_T increase_step_size;         /* '<Root>/Rate Calculator' */
  uint16_T target_rate;                /* '<Root>/Rate Calculator' */
  uint16_T reduce_step_size;           /* '<Root>/Rate Calculator' */
  uint8_T is_c5_Pacemaker_A2;          /* '<Root>/Rate Calculator' */
  uint8_T is_active_c5_Pacemaker_A2;   /* '<Root>/Rate Calculator' */
  uint8_T temporalCounter_i1_h;        /* '<Root>/Rate Calculator' */
  uint8_T is_c2_Pacemaker_A2;          /* '<Root>/COM_IN' */
  uint8_T is_active_c2_Pacemaker_A2;   /* '<Root>/COM_IN' */
  uint8_T is_c3_Pacemaker_A2;          /* '<Root>/ MODES' */
  uint8_T is_AAIR;                     /* '<Root>/ MODES' */
  uint8_T is_AOOR;                     /* '<Root>/ MODES' */
  uint8_T is_VVIR;                     /* '<Root>/ MODES' */
  uint8_T is_VOOR;                     /* '<Root>/ MODES' */
  uint8_T is_active_c3_Pacemaker_A2;   /* '<Root>/ MODES' */
} DW_Pacemaker_A2_T;

/* Parameters (default storage) */
struct P_Pacemaker_A2_T_ {
  real_T ATR_CMP_DETECT_SampleTime;    /* Expression: SampleTime
                                        * Referenced by: '<S5>/ATR_CMP_DETECT'
                                        */
  real_T VENT_CMP_DETECT_SampleTime;   /* Expression: SampleTime
                                        * Referenced by: '<S5>/VENT_CMP_DETECT'
                                        */
  real_T SerialReceive_SampleTime;     /* Expression: -1
                                        * Referenced by: '<Root>/Serial Receive'
                                        */
  real_T FXOS87006AxesSensor_SampleTime;/* Expression: 0.01
                                         * Referenced by: '<S8>/FXOS8700 6-Axes Sensor'
                                         */
  real_T ATR_SIGNAL_SampleTime;        /* Expression: SampleTime
                                        * Referenced by: '<S7>/ATR_SIGNAL'
                                        */
  real_T VENT_SIGNAL_SampleTime;       /* Expression: SampleTime
                                        * Referenced by: '<S7>/VENT_SIGNAL'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Pacemaker_A2_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Pacemaker_A2_T Pacemaker_A2_P;

/* Block signals (default storage) */
extern B_Pacemaker_A2_T Pacemaker_A2_B;

/* Block states (default storage) */
extern DW_Pacemaker_A2_T Pacemaker_A2_DW;

/* External function called from main */
extern void Pacemaker_A2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Pacemaker_A2_initialize(void);
extern void Pacemaker_A2_step0(void);
extern void Pacemaker_A2_step1(void);
extern void Pacemaker_A2_step(int_T tid);
extern void Pacemaker_A2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Pacemaker_A2_T *const Pacemaker_A2_M;
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
 * '<Root>' : 'Pacemaker_A2'
 * '<S1>'   : 'Pacemaker_A2/ MODES'
 * '<S2>'   : 'Pacemaker_A2/COM_IN'
 * '<S3>'   : 'Pacemaker_A2/INPUTS'
 * '<S4>'   : 'Pacemaker_A2/OUTPUT'
 * '<S5>'   : 'Pacemaker_A2/PULSE DETECT'
 * '<S6>'   : 'Pacemaker_A2/Rate Calculator'
 * '<S7>'   : 'Pacemaker_A2/Send To DCM'
 * '<S8>'   : 'Pacemaker_A2/accelerometer'
 */
#endif                                 /* RTW_HEADER_Pacemaker_A2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
