/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Pacemaker_A2.c
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

#include "Pacemaker_A2.h"
#include "rtwtypes.h"
#include "Pacemaker_A2_types.h"
#include <string.h>
#include <math.h>
#include "rt_roundd_snf.h"
#include "rt_roundf_snf.h"
#include <stddef.h>
#include "send_params.h"
#include "send_params_private.h"

/* Named constants for Chart: '<Root>/ MODES' */
#define Pacemaker_A2_IN_AAIR           ((uint8_T)1U)
#define Pacemaker_A2_IN_AAIR_INITIAL   ((uint8_T)1U)
#define Pacemaker_A2_IN_AAIR_PACING    ((uint8_T)2U)
#define Pacemaker_A2_IN_AAIR_REF       ((uint8_T)3U)
#define Pacemaker_A2_IN_AAI_INITIAL    ((uint8_T)2U)
#define Pacemaker_A2_IN_AAI_PACING     ((uint8_T)3U)
#define Pacemaker_A2_IN_AAI_REF        ((uint8_T)4U)
#define Pacemaker_A2_IN_AOOR           ((uint8_T)5U)
#define Pacemaker_A2_IN_AOOR_INITIAL   ((uint8_T)1U)
#define Pacemaker_A2_IN_AOOR_PACING    ((uint8_T)2U)
#define Pacemaker_A2_IN_AOO_INITIAL    ((uint8_T)6U)
#define Pacemaker_A2_IN_AOO_PACING     ((uint8_T)7U)
#define Pacemaker_A2_IN_MainState      ((uint8_T)8U)
#define Pacemaker_A2_IN_VOOR           ((uint8_T)9U)
#define Pacemaker_A2_IN_VOOR_INTIAL    ((uint8_T)1U)
#define Pacemaker_A2_IN_VOOR_PACING    ((uint8_T)2U)
#define Pacemaker_A2_IN_VOO_INITIAL    ((uint8_T)10U)
#define Pacemaker_A2_IN_VOO_PACING     ((uint8_T)11U)
#define Pacemaker_A2_IN_VVIR           ((uint8_T)12U)
#define Pacemaker_A2_IN_VVIR_INITIAL   ((uint8_T)1U)
#define Pacemaker_A2_IN_VVIR_PACING    ((uint8_T)2U)
#define Pacemaker_A2_IN_VVIR_REF       ((uint8_T)3U)
#define Pacemaker_A2_IN_VVI_INITIAL    ((uint8_T)13U)
#define Pacemaker_A2_IN_VVI_PACING     ((uint8_T)14U)
#define Pacemaker_A2_IN_VVI_REF        ((uint8_T)15U)

/* Named constants for Chart: '<Root>/COM_IN' */
#define Pacemaker_A2_IN_ECHO_PARAM     ((uint8_T)1U)
#define Pacemaker_A2_IN_INITIAL        ((uint8_T)2U)
#define Pacemaker_A2_IN_SET_PARAM      ((uint8_T)3U)
#define Pacemaker_A2_IN_STANDBY        ((uint8_T)4U)

/* Named constants for Chart: '<Root>/Rate Calculator' */
#define Pacemaker_A2_IN_Addition       ((uint8_T)1U)
#define Pacemaker_A2_IN_Begin          ((uint8_T)2U)
#define Pacemaker_A2_IN_Change1        ((uint8_T)3U)
#define Pacemaker_A2_IN_Change2        ((uint8_T)4U)
#define Pacemaker_A2_IN_Data_Check     ((uint8_T)5U)
#define Pacemaker_A2_IN_Reduce         ((uint8_T)6U)

/* Block signals (default storage) */
B_Pacemaker_A2_T Pacemaker_A2_B;

/* Block states (default storage) */
DW_Pacemaker_A2_T Pacemaker_A2_DW;

/* Real-time model */
static RT_MODEL_Pacemaker_A2_T Pacemaker_A2_M_;
RT_MODEL_Pacemaker_A2_T *const Pacemaker_A2_M = &Pacemaker_A2_M_;

/* Forward declaration for local functions */
static void Pacemak_enter_atomic_Data_Check(void);
static void Pacemaker_A2_AAIR(const boolean_T *VENT_CMP_DETECT);
static void Pacemaker_A2_AAI_INITIAL(const boolean_T *VENT_CMP_DETECT);
static void Pacemaker_A2_MainState(void);
static void Pacemaker_A2_VVIR(const boolean_T *ATR_CMP_DETECT);
static void Pacemaker_A2_VVI_INITIAL(const boolean_T *ATR_CMP_DETECT);
static void Pacemaker_A2_SystemCore_setup_k(freedomk64f_SCIRead_Pacemaker_T *obj);
static void Pacemaker_A_SystemCore_setup_kl(freedomk64f_fxos8700_Pacemake_T *obj);
static void Pacemaker__SystemCore_setup_klr(dsp_simulink_MovingAverage_Pa_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Pacemaker_A2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Pacemaker_A2_M, 1));
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
  (Pacemaker_A2_M->Timing.TaskCounters.TID[1])++;
  if ((Pacemaker_A2_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    Pacemaker_A2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Function for Chart: '<Root>/Rate Calculator' */
static void Pacemak_enter_atomic_Data_Check(void)
{
  uint32_T qY;
  uint32_T qY_tmp;
  uint16_T c_x;
  qY_tmp = (uint32_T)Pacemaker_A2_B.MSR_m - /*MW:OvSatOk*/ Pacemaker_A2_B.LRL_j;
  qY = qY_tmp;
  if (qY_tmp > Pacemaker_A2_B.MSR_m) {
    qY = 0U;
    qY_tmp = 0U;
  }

  if (Pacemaker_A2_B.Recovery_time_n == 0) {
    if ((uint16_T)qY == 0) {
      Pacemaker_A2_DW.reduce_step_size = 0U;
    } else {
      Pacemaker_A2_DW.reduce_step_size = MAX_uint16_T;
    }
  } else {
    Pacemaker_A2_DW.reduce_step_size = (uint16_T)((uint32_T)(uint16_T)qY /
      Pacemaker_A2_B.Recovery_time_n);
    c_x = (uint16_T)((uint32_T)(uint16_T)qY - (uint16_T)((uint32_T)
      Pacemaker_A2_DW.reduce_step_size * Pacemaker_A2_B.Recovery_time_n));
    if ((c_x > 0) && (c_x >= (int32_T)((uint32_T)Pacemaker_A2_B.Recovery_time_n >>
          1) + (Pacemaker_A2_B.Recovery_time_n & 1))) {
      Pacemaker_A2_DW.reduce_step_size++;
    }
  }

  if (Pacemaker_A2_B.Reaction_time_i == 0) {
    if ((uint16_T)qY_tmp == 0) {
      Pacemaker_A2_DW.increase_step_size = 0U;
    } else {
      Pacemaker_A2_DW.increase_step_size = MAX_uint16_T;
    }
  } else {
    Pacemaker_A2_DW.increase_step_size = (uint16_T)((uint32_T)(uint16_T)qY_tmp /
      Pacemaker_A2_B.Reaction_time_i);
    c_x = (uint16_T)((uint32_T)(uint16_T)qY_tmp - (uint16_T)((uint32_T)
      Pacemaker_A2_DW.increase_step_size * Pacemaker_A2_B.Reaction_time_i));
    if ((c_x > 0) && (c_x >= (int32_T)((uint32_T)Pacemaker_A2_B.Reaction_time_i >>
          1) + (Pacemaker_A2_B.Reaction_time_i & 1))) {
      Pacemaker_A2_DW.increase_step_size++;
    }
  }
}

/* Function for Chart: '<Root>/ MODES' */
static void Pacemaker_A2_AAIR(const boolean_T *VENT_CMP_DETECT)
{
  real_T tmp_1;
  real32_T tmp;
  uint32_T qY;
  uint32_T qY_0;
  uint16_T tmp_0;
  uint16_T tmp_2;
  boolean_T out;
  switch (Pacemaker_A2_DW.is_AAIR) {
   case Pacemaker_A2_IN_AAIR_INITIAL:
    Pacemaker_A2_B.FRONTEND_CTRL = true;
    if (!*VENT_CMP_DETECT) {
      tmp_1 = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.rate);
      if (tmp_1 < 65536.0) {
        tmp_0 = (uint16_T)tmp_1;
      } else {
        tmp_0 = MAX_uint16_T;
      }

      tmp = rt_roundf_snf(Pacemaker_A2_B.ATR_PULSE_WIDTH_d);
      if (tmp < 65536.0F) {
        if (tmp >= 0.0F) {
          tmp_2 = (uint16_T)tmp;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint16_T;
      }

      qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_2;
      if (qY_0 > tmp_0) {
        qY_0 = 0U;
      }

      qY = qY_0 - /*MW:OvSatOk*/ Pacemaker_A2_B.ARP_m;
      if (qY > qY_0) {
        qY = 0U;
      }

      out = ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY);
    } else {
      out = false;
    }

    if (out) {
      Pacemaker_A2_DW.is_AAIR = Pacemaker_A2_IN_AAIR_PACING;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.ATR_PACE_CTRL = true;
      Pacemaker_A2_B.ATR_GND_CTRL = false;
      Pacemaker_A2_B.RED_LED = 1.0;
    } else if (*VENT_CMP_DETECT) {
      Pacemaker_A2_DW.is_AAIR = Pacemaker_A2_IN_AAIR_REF;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.FRONTEND_CTRL = false;
      Pacemaker_A2_B.ATR_PACE_CTRL = false;
      Pacemaker_A2_B.ATR_GND_CTRL = true;
      Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.VENT_AMP_i * 20.0F;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.GREEN_LED = 0.0;
    }
    break;

   case Pacemaker_A2_IN_AAIR_PACING:
    if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
        Pacemaker_A2_B.ATR_PULSE_WIDTH_d) {
      Pacemaker_A2_DW.is_AAIR = Pacemaker_A2_IN_AAIR_REF;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.FRONTEND_CTRL = false;
      Pacemaker_A2_B.ATR_PACE_CTRL = false;
      Pacemaker_A2_B.ATR_GND_CTRL = true;
      Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.VENT_AMP_i * 20.0F;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.GREEN_LED = 0.0;
    }
    break;

   default:
    /* case IN_AAIR_REF: */
    Pacemaker_A2_B.FRONTEND_CTRL = false;
    if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
        Pacemaker_A2_B.ARP_m) {
      Pacemaker_A2_DW.is_AAIR = Pacemaker_A2_IN_AAIR_INITIAL;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.FRONTEND_CTRL = true;
      Pacemaker_A2_B.ATR_PACE_CTRL = false;
      Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i / 5.0F * 100.0F;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.ATR_GND_CTRL = true;
      Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.ATR_sensitivity_h / 5.0F *
        100.0F;
      Pacemaker_A2_B.GREEN_LED = 1.0;
    }
    break;
  }
}

/* Function for Chart: '<Root>/ MODES' */
static void Pacemaker_A2_AAI_INITIAL(const boolean_T *VENT_CMP_DETECT)
{
  real_T tmp_1;
  real32_T tmp;
  uint32_T qY;
  uint32_T qY_0;
  uint16_T tmp_0;
  uint16_T tmp_2;
  boolean_T out;
  Pacemaker_A2_B.FRONTEND_CTRL = true;
  if (!*VENT_CMP_DETECT) {
    tmp_1 = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.LRL_j);
    if (tmp_1 < 65536.0) {
      tmp_0 = (uint16_T)tmp_1;
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = rt_roundf_snf(Pacemaker_A2_B.ATR_PULSE_WIDTH_d);
    if (tmp < 65536.0F) {
      if (tmp >= 0.0F) {
        tmp_2 = (uint16_T)tmp;
      } else {
        tmp_2 = 0U;
      }
    } else {
      tmp_2 = MAX_uint16_T;
    }

    qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_2;
    if (qY_0 > tmp_0) {
      qY_0 = 0U;
    }

    qY = qY_0 - /*MW:OvSatOk*/ Pacemaker_A2_B.ARP_m;
    if (qY > qY_0) {
      qY = 0U;
    }

    out = ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY);
  } else {
    out = false;
  }

  if (out) {
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AAI_PACING;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.ATR_PACE_CTRL = true;
    Pacemaker_A2_B.ATR_GND_CTRL = false;
    Pacemaker_A2_B.RED_LED = 1.0;
  } else if (*VENT_CMP_DETECT) {
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AAI_REF;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.FRONTEND_CTRL = false;
    Pacemaker_A2_B.ATR_PACE_CTRL = false;
    Pacemaker_A2_B.ATR_GND_CTRL = true;
    Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.VENT_AMP_i * 20.0F;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.GREEN_LED = 0.0;
  }
}

/* Function for Chart: '<Root>/ MODES' */
static void Pacemaker_A2_MainState(void)
{
  Pacemaker_A2_B.FRONTEND_CTRL = false;
  switch (Pacemaker_A2_B.MODE_d) {
   case 4:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AAI_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.FRONTEND_CTRL = true;
    Pacemaker_A2_B.ATR_PACE_CTRL = false;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i / 5.0F * 100.0F;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.ATR_GND_CTRL = true;
    Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.ATR_sensitivity_h / 5.0F *
      100.0F;
    Pacemaker_A2_B.GREEN_LED = 1.0;
    break;

   case 1:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AOO_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.ATR_PACE_CTRL = false;
    Pacemaker_A2_B.ATR_GND_CTRL = true;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i / 5.0F * 100.0F;
    Pacemaker_A2_B.GREEN_LED = 1.0;
    break;

   case 2:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VOO_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.VENT_GND_CTRL = true;
    Pacemaker_A2_B.VENT_PACE_CTRL = false;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
    Pacemaker_A2_B.RED_LED = 1.0;
    break;

   case 3:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VVI_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o / 5.0F * 100.0F;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.VENT_GND_CTRL = true;
    Pacemaker_A2_B.VENT_PACE_CTRL = false;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.VENT_CMP_REF_PWM = Pacemaker_A2_B.VENT_sensitivity_p / 5.0F *
      100.0F;
    Pacemaker_A2_B.FRONTEND_CTRL = true;
    Pacemaker_A2_B.RED_LED = 1.0;
    break;

   case 5:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AOOR;
    Pacemaker_A2_DW.is_AOOR = Pacemaker_A2_IN_AOOR_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.ATR_PACE_CTRL = false;
    Pacemaker_A2_B.ATR_GND_CTRL = true;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i * 20.0F;
    Pacemaker_A2_B.GREEN_LED = 1.0;
    break;

   case 6:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VOOR;
    Pacemaker_A2_DW.is_VOOR = Pacemaker_A2_IN_VOOR_INTIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.VENT_GND_CTRL = true;
    Pacemaker_A2_B.VENT_PACE_CTRL = false;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
    Pacemaker_A2_B.RED_LED = 1.0;
    break;

   case 7:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VVIR;
    Pacemaker_A2_DW.is_VVIR = Pacemaker_A2_IN_VVIR_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.VENT_GND_CTRL = true;
    Pacemaker_A2_B.VENT_PACE_CTRL = false;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.VENT_CMP_REF_PWM = Pacemaker_A2_B.VENT_sensitivity_p / 5.0F *
      100.0F;
    Pacemaker_A2_B.FRONTEND_CTRL = true;
    Pacemaker_A2_B.RED_LED = 1.0;
    break;

   case 8:
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AAIR;
    Pacemaker_A2_DW.is_AAIR = Pacemaker_A2_IN_AAIR_INITIAL;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.FRONTEND_CTRL = true;
    Pacemaker_A2_B.ATR_PACE_CTRL = false;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i / 5.0F * 100.0F;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.ATR_GND_CTRL = true;
    Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.ATR_sensitivity_h / 5.0F *
      100.0F;
    Pacemaker_A2_B.GREEN_LED = 1.0;
    break;
  }
}

/* Function for Chart: '<Root>/ MODES' */
static void Pacemaker_A2_VVIR(const boolean_T *ATR_CMP_DETECT)
{
  real_T tmp_1;
  real32_T tmp;
  uint32_T qY;
  uint32_T qY_0;
  uint16_T tmp_0;
  uint16_T tmp_2;
  boolean_T out;
  switch (Pacemaker_A2_DW.is_VVIR) {
   case Pacemaker_A2_IN_VVIR_INITIAL:
    Pacemaker_A2_B.FRONTEND_CTRL = true;
    if (!*ATR_CMP_DETECT) {
      tmp_1 = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.rate);
      if (tmp_1 < 65536.0) {
        tmp_0 = (uint16_T)tmp_1;
      } else {
        tmp_0 = MAX_uint16_T;
      }

      tmp = rt_roundf_snf(Pacemaker_A2_B.VENT_PULSE_WIDTH_g);
      if (tmp < 65536.0F) {
        if (tmp >= 0.0F) {
          tmp_2 = (uint16_T)tmp;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint16_T;
      }

      qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_2;
      if (qY_0 > tmp_0) {
        qY_0 = 0U;
      }

      qY = qY_0 - /*MW:OvSatOk*/ Pacemaker_A2_B.VRP_l;
      if (qY > qY_0) {
        qY = 0U;
      }

      out = ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY);
    } else {
      out = false;
    }

    if (out) {
      Pacemaker_A2_DW.is_VVIR = Pacemaker_A2_IN_VVIR_PACING;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.VENT_GND_CTRL = false;
      Pacemaker_A2_B.VENT_PACE_CTRL = true;
      Pacemaker_A2_B.GREEN_LED = 1.0;
    } else if (*ATR_CMP_DETECT) {
      Pacemaker_A2_DW.is_VVIR = Pacemaker_A2_IN_VVIR_REF;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.FRONTEND_CTRL = false;
      Pacemaker_A2_B.VENT_PACE_CTRL = false;
      Pacemaker_A2_B.VENT_GND_CTRL = true;
      Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.RED_LED = 0.0;
    }
    break;

   case Pacemaker_A2_IN_VVIR_PACING:
    if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
        Pacemaker_A2_B.VENT_PULSE_WIDTH_g) {
      Pacemaker_A2_DW.is_VVIR = Pacemaker_A2_IN_VVIR_REF;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.FRONTEND_CTRL = false;
      Pacemaker_A2_B.VENT_PACE_CTRL = false;
      Pacemaker_A2_B.VENT_GND_CTRL = true;
      Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.RED_LED = 0.0;
    }
    break;

   default:
    /* case IN_VVIR_REF: */
    Pacemaker_A2_B.FRONTEND_CTRL = false;
    if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
        Pacemaker_A2_B.VRP_l) {
      Pacemaker_A2_DW.is_VVIR = Pacemaker_A2_IN_VVIR_INITIAL;
      Pacemaker_A2_DW.temporalCounter_i1 = 0U;
      Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
      Pacemaker_A2_B.PACE_GND_CTRL = true;
      Pacemaker_A2_B.VENT_GND_CTRL = true;
      Pacemaker_A2_B.VENT_PACE_CTRL = false;
      Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
      Pacemaker_A2_B.VENT_CMP_REF_PWM = Pacemaker_A2_B.VENT_sensitivity_p / 5.0F
        * 100.0F;
      Pacemaker_A2_B.FRONTEND_CTRL = true;
      Pacemaker_A2_B.RED_LED = 1.0;
    }
    break;
  }
}

/* Function for Chart: '<Root>/ MODES' */
static void Pacemaker_A2_VVI_INITIAL(const boolean_T *ATR_CMP_DETECT)
{
  real32_T tmp;
  uint32_T qY;
  uint32_T qY_0;
  uint16_T tmp_0;
  uint16_T tmp_1;
  boolean_T out;
  Pacemaker_A2_B.FRONTEND_CTRL = true;
  if (!*ATR_CMP_DETECT) {
    Pacemaker_A2_B.d1 = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.LRL_j);
    if (Pacemaker_A2_B.d1 < 65536.0) {
      tmp_0 = (uint16_T)Pacemaker_A2_B.d1;
    } else {
      tmp_0 = MAX_uint16_T;
    }

    tmp = rt_roundf_snf(Pacemaker_A2_B.VENT_PULSE_WIDTH_g);
    if (tmp < 65536.0F) {
      if (tmp >= 0.0F) {
        tmp_1 = (uint16_T)tmp;
      } else {
        tmp_1 = 0U;
      }
    } else {
      tmp_1 = MAX_uint16_T;
    }

    qY_0 = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_1;
    if (qY_0 > tmp_0) {
      qY_0 = 0U;
    }

    qY = qY_0 - /*MW:OvSatOk*/ Pacemaker_A2_B.VRP_l;
    if (qY > qY_0) {
      qY = 0U;
    }

    out = ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY);
  } else {
    out = false;
  }

  if (out) {
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VVI_PACING;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.VENT_GND_CTRL = false;
    Pacemaker_A2_B.VENT_PACE_CTRL = true;
    Pacemaker_A2_B.GREEN_LED = 1.0;
  } else if (*ATR_CMP_DETECT) {
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VVI_REF;
    Pacemaker_A2_DW.temporalCounter_i1 = 0U;
    Pacemaker_A2_B.FRONTEND_CTRL = false;
    Pacemaker_A2_B.VENT_PACE_CTRL = false;
    Pacemaker_A2_B.VENT_GND_CTRL = true;
    Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
    Pacemaker_A2_B.PACE_GND_CTRL = true;
    Pacemaker_A2_B.RED_LED = 0.0;
  }
}

static void Pacemaker_A2_SystemCore_setup_k(freedomk64f_SCIRead_Pacemaker_T *obj)
{
  obj->isInitialized = 1;
  Pacemaker_A2_B.TxPinLoc = MW_UNDEFINED_VALUE;
  Pacemaker_A2_B.SCIModuleLoc = 0;
  obj->MW_SCIHANDLE = MW_SCI_Open(&Pacemaker_A2_B.SCIModuleLoc, false, 10U,
    Pacemaker_A2_B.TxPinLoc);
  MW_SCI_SetBaudrate(obj->MW_SCIHANDLE, 115200U);
  Pacemaker_A2_B.StopBitsValue = MW_SCI_STOPBITS_1;
  Pacemaker_A2_B.ParityValue = MW_SCI_PARITY_NONE;
  MW_SCI_SetFrameFormat(obj->MW_SCIHANDLE, 8, Pacemaker_A2_B.ParityValue,
                        Pacemaker_A2_B.StopBitsValue);
  obj->isSetupComplete = true;
}

static void Pacemaker_A_SystemCore_setup_kl(freedomk64f_fxos8700_Pacemake_T *obj)
{
  obj->isInitialized = 1;
  Pacemaker_A2_B.ModeType = MW_I2C_MASTER;
  Pacemaker_A2_B.i2cname = 0;
  obj->i2cobj.MW_I2C_HANDLE = MW_I2C_Open(Pacemaker_A2_B.i2cname,
    Pacemaker_A2_B.ModeType);
  obj->i2cobj.BusSpeed = 100000U;
  MW_I2C_SetBusSpeed(obj->i2cobj.MW_I2C_HANDLE, obj->i2cobj.BusSpeed);
  Pacemaker_A2_B.b_SwappedDataBytes[0] = 43U;
  Pacemaker_A2_B.b_SwappedDataBytes[1] = 64U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Pacemaker_A2_B.b_SwappedDataBytes[0], 2U, false, false);
  OSA_TimeDelay(500U);
  Pacemaker_A2_B.status = 42U;
  Pacemaker_A2_B.status = MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
    &Pacemaker_A2_B.status, 1U, true, false);
  if (Pacemaker_A2_B.status == 0) {
    MW_I2C_MasterRead(obj->i2cobj.MW_I2C_HANDLE, 29U, &Pacemaker_A2_B.status, 1U,
                      false, true);
    memcpy((void *)&Pacemaker_A2_B.b_RegisterValue_m, (void *)
           &Pacemaker_A2_B.status, (size_t)1 * sizeof(uint8_T));
  } else {
    Pacemaker_A2_B.b_RegisterValue_m = 0U;
  }

  Pacemaker_A2_B.b_SwappedDataBytes[0] = 42U;
  Pacemaker_A2_B.b_SwappedDataBytes[1] = (uint8_T)
    (Pacemaker_A2_B.b_RegisterValue_m & 254);
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Pacemaker_A2_B.b_SwappedDataBytes[0], 2U, false, false);
  Pacemaker_A2_B.b_SwappedDataBytes[0] = 14U;
  Pacemaker_A2_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Pacemaker_A2_B.b_SwappedDataBytes[0], 2U, false, false);
  Pacemaker_A2_B.b_SwappedDataBytes[0] = 91U;
  Pacemaker_A2_B.b_SwappedDataBytes[1] = 0U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Pacemaker_A2_B.b_SwappedDataBytes[0], 2U, false, false);
  Pacemaker_A2_B.b_SwappedDataBytes[0] = 42U;
  Pacemaker_A2_B.b_SwappedDataBytes[1] = 1U;
  MW_I2C_MasterWrite(obj->i2cobj.MW_I2C_HANDLE, 29U,
                     &Pacemaker_A2_B.b_SwappedDataBytes[0], 2U, false, false);
  obj->isSetupComplete = true;
}

static void Pacemaker__SystemCore_setup_klr(dsp_simulink_MovingAverage_Pa_T *obj)
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
void Pacemaker_A2_step0(void)          /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Pacemaker_A2_step1(void)          /* Sample time: [0.01s, 0.0s] */
{
  g_dsp_internal_SlidingWindowA_T *obj;
  int32_T i;
  real32_T tmp;
  uint32_T qY;
  uint16_T tmp_0;
  uint16_T tmp_1;
  uint8_T output_raw[6];
  uint8_T b_x[2];
  uint8_T y[2];
  uint8_T status;
  boolean_T ATR_CMP_DETECT;
  boolean_T VENT_CMP_DETECT;

  /* MATLABSystem: '<Root>/Serial Receive' */
  if (Pacemaker_A2_DW.obj_e.SampleTime !=
      Pacemaker_A2_P.SerialReceive_SampleTime) {
    Pacemaker_A2_DW.obj_e.SampleTime = Pacemaker_A2_P.SerialReceive_SampleTime;
  }

  status = MW_SCI_Receive(Pacemaker_A2_DW.obj_e.MW_SCIHANDLE,
    &Pacemaker_A2_B.RxDataLocChar[0], 46U);
  memcpy((void *)&Pacemaker_A2_B.RxData[0], (void *)
         &Pacemaker_A2_B.RxDataLocChar[0], (size_t)46 * sizeof(uint8_T));

  /* Chart: '<Root>/COM_IN' incorporates:
   *  MATLABSystem: '<Root>/Serial Receive'
   */
  if (Pacemaker_A2_DW.is_active_c2_Pacemaker_A2 == 0U) {
    Pacemaker_A2_DW.is_active_c2_Pacemaker_A2 = 1U;
    Pacemaker_A2_DW.is_c2_Pacemaker_A2 = Pacemaker_A2_IN_INITIAL;
    Pacemaker_A2_B.MODE_d = 1U;
    Pacemaker_A2_B.LRL_j = 30U;
    Pacemaker_A2_B.ATR_AMP_o = 0.0F;
    Pacemaker_A2_B.ATR_PULSE_WIDTH_d = 0.05F;
    Pacemaker_A2_B.VENT_AMP_i = 0.0F;
    Pacemaker_A2_B.VENT_PULSE_WIDTH_g = 0.05F;
    Pacemaker_A2_B.VRP_l = 150U;
    Pacemaker_A2_B.ARP_m = 150U;
    Pacemaker_A2_B.MSR_m = 50U;
    Pacemaker_A2_B.ATR_sensitivity_h = 0.25F;
    Pacemaker_A2_B.VENT_sensitivity_p = 0.25F;
    Pacemaker_A2_B.PVARP_i = 150U;
    Pacemaker_A2_B.Activity_threshold_a = 0U;
    Pacemaker_A2_B.Reaction_time_i = 10U;
    Pacemaker_A2_B.Respond_factor_b = 1U;
    Pacemaker_A2_B.Recovery_time_n = 2U;
  } else {
    switch (Pacemaker_A2_DW.is_c2_Pacemaker_A2) {
     case Pacemaker_A2_IN_ECHO_PARAM:
      Pacemaker_A2_DW.is_c2_Pacemaker_A2 = Pacemaker_A2_IN_STANDBY;
      break;

     case Pacemaker_A2_IN_INITIAL:
      Pacemaker_A2_DW.is_c2_Pacemaker_A2 = Pacemaker_A2_IN_STANDBY;
      break;

     case Pacemaker_A2_IN_SET_PARAM:
      Pacemaker_A2_DW.is_c2_Pacemaker_A2 = Pacemaker_A2_IN_STANDBY;
      break;

     default:
      /* case IN_STANDBY: */
      if ((status == 0) && (Pacemaker_A2_B.RxData[0] == 22)) {
        switch (Pacemaker_A2_B.RxData[1]) {
         case 85:
          Pacemaker_A2_DW.is_c2_Pacemaker_A2 = Pacemaker_A2_IN_SET_PARAM;
          memcpy((void *)&Pacemaker_A2_B.MODE_d, (void *)&Pacemaker_A2_B.RxData
                 [2], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.LRL_j, (void *)&Pacemaker_A2_B.RxData[4],
                 (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.ATR_AMP_o, (void *)
                 &Pacemaker_A2_B.RxData[6], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&Pacemaker_A2_B.ATR_PULSE_WIDTH_d, (void *)
                 &Pacemaker_A2_B.RxData[10], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&Pacemaker_A2_B.VENT_AMP_i, (void *)
                 &Pacemaker_A2_B.RxData[14], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&Pacemaker_A2_B.VENT_PULSE_WIDTH_g, (void *)
                 &Pacemaker_A2_B.RxData[18], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&Pacemaker_A2_B.VRP_l, (void *)&Pacemaker_A2_B.RxData
                 [22], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.ARP_m, (void *)&Pacemaker_A2_B.RxData
                 [24], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.MSR_m, (void *)&Pacemaker_A2_B.RxData
                 [26], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.ATR_sensitivity_h, (void *)
                 &Pacemaker_A2_B.RxData[28], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&Pacemaker_A2_B.VENT_sensitivity_p, (void *)
                 &Pacemaker_A2_B.RxData[32], (size_t)1 * sizeof(real32_T));
          memcpy((void *)&Pacemaker_A2_B.PVARP_i, (void *)
                 &Pacemaker_A2_B.RxData[36], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.Activity_threshold_a, (void *)
                 &Pacemaker_A2_B.RxData[38], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.Reaction_time_i, (void *)
                 &Pacemaker_A2_B.RxData[40], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.Respond_factor_b, (void *)
                 &Pacemaker_A2_B.RxData[42], (size_t)1 * sizeof(uint16_T));
          memcpy((void *)&Pacemaker_A2_B.Recovery_time_n, (void *)
                 &Pacemaker_A2_B.RxData[44], (size_t)1 * sizeof(uint16_T));
          break;

         case 34:
          Pacemaker_A2_DW.is_c2_Pacemaker_A2 = Pacemaker_A2_IN_ECHO_PARAM;
          send_params();
          break;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/COM_IN' */

  /* MATLABSystem: '<S5>/ATR_CMP_DETECT' */
  if (Pacemaker_A2_DW.obj_a.SampleTime !=
      Pacemaker_A2_P.ATR_CMP_DETECT_SampleTime) {
    Pacemaker_A2_DW.obj_a.SampleTime = Pacemaker_A2_P.ATR_CMP_DETECT_SampleTime;
  }

  /* MATLABSystem: '<S5>/ATR_CMP_DETECT' */
  ATR_CMP_DETECT = MW_digitalIO_read(Pacemaker_A2_DW.obj_a.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S5>/VENT_CMP_DETECT' */
  if (Pacemaker_A2_DW.obj_i.SampleTime !=
      Pacemaker_A2_P.VENT_CMP_DETECT_SampleTime) {
    Pacemaker_A2_DW.obj_i.SampleTime = Pacemaker_A2_P.VENT_CMP_DETECT_SampleTime;
  }

  /* MATLABSystem: '<S5>/VENT_CMP_DETECT' */
  VENT_CMP_DETECT = MW_digitalIO_read(Pacemaker_A2_DW.obj_i.MW_DIGITALIO_HANDLE);

  /* MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor' */
  if (Pacemaker_A2_DW.obj_b.SampleTime !=
      Pacemaker_A2_P.FXOS87006AxesSensor_SampleTime) {
    Pacemaker_A2_DW.obj_b.SampleTime =
      Pacemaker_A2_P.FXOS87006AxesSensor_SampleTime;
  }

  status = 1U;
  status = MW_I2C_MasterWrite(Pacemaker_A2_DW.obj_b.i2cobj.MW_I2C_HANDLE, 29U,
    &status, 1U, true, false);
  if (status == 0) {
    MW_I2C_MasterRead(Pacemaker_A2_DW.obj_b.i2cobj.MW_I2C_HANDLE, 29U,
                      &output_raw[0], 6U, false, true);
    memcpy((void *)&Pacemaker_A2_B.b_RegisterValue[0], (void *)&output_raw[0],
           (size_t)3 * sizeof(int16_T));
    memcpy((void *)&y[0], (void *)&Pacemaker_A2_B.b_RegisterValue[0], (size_t)2 *
           sizeof(uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&Pacemaker_A2_B.b_RegisterValue[0], (void *)&b_x[0], (size_t)
           1 * sizeof(int16_T));
    memcpy((void *)&y[0], (void *)&Pacemaker_A2_B.b_RegisterValue[1], (size_t)2 *
           sizeof(uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&Pacemaker_A2_B.b_RegisterValue[1], (void *)&b_x[0], (size_t)
           1 * sizeof(int16_T));
    memcpy((void *)&y[0], (void *)&Pacemaker_A2_B.b_RegisterValue[2], (size_t)2 *
           sizeof(uint8_T));
    b_x[0] = y[1];
    b_x[1] = y[0];
    memcpy((void *)&Pacemaker_A2_B.b_RegisterValue[2], (void *)&b_x[0], (size_t)
           1 * sizeof(int16_T));
  } else {
    Pacemaker_A2_B.b_RegisterValue[0] = 0;
    Pacemaker_A2_B.b_RegisterValue[1] = 0;
    Pacemaker_A2_B.b_RegisterValue[2] = 0;
  }

  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_0 = (real_T)(int16_T)
    (Pacemaker_A2_B.b_RegisterValue[0] >> 2) * 2.0 * 0.244 / 1000.0;
  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 = (real_T)(int16_T)
    (Pacemaker_A2_B.b_RegisterValue[1] >> 2) * 2.0 * 0.244 / 1000.0;
  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2 = (real_T)(int16_T)
    (Pacemaker_A2_B.b_RegisterValue[2] >> 2) * 2.0 * 0.244 / 1000.0;

  /* End of MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor' */

  /* Sqrt: '<S8>/Sqrt' incorporates:
   *  Math: '<S8>/Math Function'
   *  Math: '<S8>/Math Function1'
   *  Math: '<S8>/Math Function2'
   *  Sum: '<S8>/Add'
   *  Sum: '<S8>/Add1'
   *
   * About '<S8>/Math Function':
   *  Operator: magnitude^2
   *
   * About '<S8>/Math Function1':
   *  Operator: magnitude^2
   *
   * About '<S8>/Math Function2':
   *  Operator: magnitude^2
   */
  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_0 = sqrt
    ((Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_0 *
      Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_0 +
      Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 *
      Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1) +
     Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2 *
     Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2);

  /* MATLABSystem: '<S8>/Moving Average' */
  if (Pacemaker_A2_DW.obj.TunablePropsChanged) {
    Pacemaker_A2_DW.obj.TunablePropsChanged = false;
  }

  obj = Pacemaker_A2_DW.obj.pStatistic;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    for (i = 0; i < 499; i++) {
      obj->pCumSumRev[i] = 0.0;
    }

    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 = obj->pCumRevIndex;
  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2 = obj->pCumSum;
  for (i = 0; i < 499; i++) {
    Pacemaker_A2_B.csumrev[i] = obj->pCumSumRev[i];
  }

  Pacemaker_A2_B.modValueRev = obj->pModValueRev;
  Pacemaker_A2_B.z = 0.0;
  Pacemaker_A2_B.d = 0.0;
  Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2 +=
    Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_0;
  if (Pacemaker_A2_B.modValueRev == 0.0) {
    Pacemaker_A2_B.z = Pacemaker_A2_B.csumrev[(int32_T)
      Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 - 1] +
      Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2;
  }

  Pacemaker_A2_B.csumrev[(int32_T)Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 -
    1] = Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_0;
  if (Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 != 499.0) {
    Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1++;
  } else {
    Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1 = 1.0;
    Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2 = 0.0;
    for (i = 497; i >= 0; i--) {
      Pacemaker_A2_B.csumrev[i] += Pacemaker_A2_B.csumrev[i + 1];
    }
  }

  if (Pacemaker_A2_B.modValueRev == 0.0) {
    Pacemaker_A2_B.d = Pacemaker_A2_B.z / 500.0;
  }

  obj->pCumSum = Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_2;
  for (i = 0; i < 499; i++) {
    obj->pCumSumRev[i] = Pacemaker_A2_B.csumrev[i];
  }

  obj->pCumRevIndex = Pacemaker_A2_B.rtb_FXOS87006AxesSensor_idx_1;
  if (Pacemaker_A2_B.modValueRev > 0.0) {
    obj->pModValueRev = Pacemaker_A2_B.modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }

  /* Chart: '<Root>/Rate Calculator' incorporates:
   *  MATLABSystem: '<S8>/Moving Average'
   */
  if (Pacemaker_A2_DW.temporalCounter_i1_h < 15U) {
    Pacemaker_A2_DW.temporalCounter_i1_h++;
  }

  if (Pacemaker_A2_DW.is_active_c5_Pacemaker_A2 == 0U) {
    Pacemaker_A2_DW.is_active_c5_Pacemaker_A2 = 1U;
    Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Begin;
    Pacemaker_A2_B.rate = Pacemaker_A2_B.LRL_j;
  } else {
    switch (Pacemaker_A2_DW.is_c5_Pacemaker_A2) {
     case Pacemaker_A2_IN_Addition:
      if (Pacemaker_A2_B.d < Pacemaker_A2_B.Activity_threshold_a) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Data_Check;
        Pacemak_enter_atomic_Data_Check();
      } else if (Pacemaker_A2_DW.temporalCounter_i1_h >= 10U) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Change2;
        Pacemaker_A2_DW.temporalCounter_i1_h = 0U;
        if (Pacemaker_A2_B.rate < Pacemaker_A2_DW.target_rate) {
          qY = (uint32_T)Pacemaker_A2_B.rate +
            Pacemaker_A2_DW.increase_step_size;
          if (qY > 65535U) {
            qY = 65535U;
          }

          Pacemaker_A2_B.rate = (uint16_T)qY;
        } else if (Pacemaker_A2_B.rate == Pacemaker_A2_DW.target_rate) {
          Pacemaker_A2_B.rate = Pacemaker_A2_DW.target_rate;
        } else if (Pacemaker_A2_B.rate > Pacemaker_A2_DW.target_rate) {
          qY = (uint32_T)Pacemaker_A2_B.rate - /*MW:OvSatOk*/
            Pacemaker_A2_DW.reduce_step_size;
          if (qY > Pacemaker_A2_B.rate) {
            qY = 0U;
          }

          Pacemaker_A2_B.rate = (uint16_T)qY;
        }
      }
      break;

     case Pacemaker_A2_IN_Begin:
      Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Data_Check;
      Pacemak_enter_atomic_Data_Check();
      break;

     case Pacemaker_A2_IN_Change1:
      if (Pacemaker_A2_DW.temporalCounter_i1_h >= 10U) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Reduce;
        Pacemaker_A2_DW.temporalCounter_i1_h = 0U;
        Pacemaker_A2_DW.target_rate = Pacemaker_A2_B.LRL_j;
      }
      break;

     case Pacemaker_A2_IN_Change2:
      if (Pacemaker_A2_DW.temporalCounter_i1_h >= 10U) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Addition;
        Pacemaker_A2_DW.temporalCounter_i1_h = 0U;
        Pacemaker_A2_B.d = rt_roundd_snf(Pacemaker_A2_B.d - (real_T)
          Pacemaker_A2_B.Activity_threshold_a);
        if (Pacemaker_A2_B.d < 65536.0) {
          if (Pacemaker_A2_B.d >= 0.0) {
            tmp_0 = (uint16_T)Pacemaker_A2_B.d;
          } else {
            tmp_0 = 0U;
          }
        } else {
          tmp_0 = MAX_uint16_T;
        }

        qY = (uint32_T)Pacemaker_A2_B.Respond_factor_b * tmp_0;
        if (qY > 65535U) {
          qY = 65535U;
        }

        qY += Pacemaker_A2_B.LRL_j;
        if (qY > 65535U) {
          qY = 65535U;
        }

        Pacemaker_A2_DW.target_rate = (uint16_T)qY;
        if (Pacemaker_A2_DW.target_rate >= Pacemaker_A2_B.MSR_m) {
          Pacemaker_A2_DW.target_rate = Pacemaker_A2_B.MSR_m;
        }
      }
      break;

     case Pacemaker_A2_IN_Data_Check:
      if (Pacemaker_A2_B.d >= Pacemaker_A2_B.Activity_threshold_a) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Addition;
        Pacemaker_A2_DW.temporalCounter_i1_h = 0U;
        Pacemaker_A2_B.d = rt_roundd_snf(Pacemaker_A2_B.d - (real_T)
          Pacemaker_A2_B.Activity_threshold_a);
        if (Pacemaker_A2_B.d < 65536.0) {
          if (Pacemaker_A2_B.d >= 0.0) {
            tmp_0 = (uint16_T)Pacemaker_A2_B.d;
          } else {
            tmp_0 = 0U;
          }
        } else {
          tmp_0 = MAX_uint16_T;
        }

        qY = (uint32_T)Pacemaker_A2_B.Respond_factor_b * tmp_0;
        if (qY > 65535U) {
          qY = 65535U;
        }

        qY += Pacemaker_A2_B.LRL_j;
        if (qY > 65535U) {
          qY = 65535U;
        }

        Pacemaker_A2_DW.target_rate = (uint16_T)qY;
        if (Pacemaker_A2_DW.target_rate >= Pacemaker_A2_B.MSR_m) {
          Pacemaker_A2_DW.target_rate = Pacemaker_A2_B.MSR_m;
        }
      } else if (Pacemaker_A2_B.d < Pacemaker_A2_B.Activity_threshold_a) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Reduce;
        Pacemaker_A2_DW.temporalCounter_i1_h = 0U;
        Pacemaker_A2_DW.target_rate = Pacemaker_A2_B.LRL_j;
      }
      break;

     default:
      /* case IN_Reduce: */
      if (Pacemaker_A2_B.d >= Pacemaker_A2_B.Activity_threshold_a) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Data_Check;
        Pacemak_enter_atomic_Data_Check();
      } else if (Pacemaker_A2_DW.temporalCounter_i1_h >= 10U) {
        Pacemaker_A2_DW.is_c5_Pacemaker_A2 = Pacemaker_A2_IN_Change1;
        Pacemaker_A2_DW.temporalCounter_i1_h = 0U;
        if (Pacemaker_A2_B.rate < Pacemaker_A2_DW.target_rate) {
          qY = (uint32_T)Pacemaker_A2_B.rate +
            Pacemaker_A2_DW.increase_step_size;
          if (qY > 65535U) {
            qY = 65535U;
          }

          Pacemaker_A2_B.rate = (uint16_T)qY;
        } else if (Pacemaker_A2_B.rate == Pacemaker_A2_DW.target_rate) {
          Pacemaker_A2_B.rate = Pacemaker_A2_DW.target_rate;
        } else if (Pacemaker_A2_B.rate > Pacemaker_A2_DW.target_rate) {
          qY = (uint32_T)Pacemaker_A2_B.rate - /*MW:OvSatOk*/
            Pacemaker_A2_DW.reduce_step_size;
          if (qY > Pacemaker_A2_B.rate) {
            qY = 0U;
          }

          Pacemaker_A2_B.rate = (uint16_T)qY;
        }
      }
      break;
    }
  }

  /* End of Chart: '<Root>/Rate Calculator' */

  /* Chart: '<Root>/ MODES' */
  if (Pacemaker_A2_DW.temporalCounter_i1 < MAX_uint32_T) {
    Pacemaker_A2_DW.temporalCounter_i1++;
  }

  if (Pacemaker_A2_DW.is_active_c3_Pacemaker_A2 == 0U) {
    Pacemaker_A2_DW.is_active_c3_Pacemaker_A2 = 1U;
    Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_MainState;
    Pacemaker_A2_B.ATR_PACE_CTRL = false;
    Pacemaker_A2_B.ATR_GND_CTRL = false;
    Pacemaker_A2_B.VENT_GND_CTRL = false;
    Pacemaker_A2_B.VENT_PACE_CTRL = false;
    Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
    Pacemaker_A2_B.PACE_GND_CTRL = false;
    Pacemaker_A2_B.FRONTEND_CTRL = false;
  } else {
    switch (Pacemaker_A2_DW.is_c3_Pacemaker_A2) {
     case Pacemaker_A2_IN_AAIR:
      Pacemaker_A2_AAIR(&VENT_CMP_DETECT);
      break;

     case Pacemaker_A2_IN_AAI_INITIAL:
      Pacemaker_A2_AAI_INITIAL(&VENT_CMP_DETECT);
      break;

     case Pacemaker_A2_IN_AAI_PACING:
      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
          Pacemaker_A2_B.ATR_PULSE_WIDTH_d) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AAI_REF;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.FRONTEND_CTRL = false;
        Pacemaker_A2_B.ATR_PACE_CTRL = false;
        Pacemaker_A2_B.ATR_GND_CTRL = true;
        Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.VENT_AMP_i * 20.0F;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.GREEN_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_AAI_REF:
      Pacemaker_A2_B.FRONTEND_CTRL = false;
      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
          Pacemaker_A2_B.ARP_m) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AAI_INITIAL;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.FRONTEND_CTRL = true;
        Pacemaker_A2_B.ATR_PACE_CTRL = false;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i / 5.0F *
          100.0F;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.ATR_GND_CTRL = true;
        Pacemaker_A2_B.ATR_CMP_REF_PWM = Pacemaker_A2_B.ATR_sensitivity_h / 5.0F
          * 100.0F;
        Pacemaker_A2_B.GREEN_LED = 1.0;
      }
      break;

     case Pacemaker_A2_IN_AOOR:
      if (Pacemaker_A2_DW.is_AOOR == Pacemaker_A2_IN_AOOR_INITIAL) {
        Pacemaker_A2_B.d = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.rate);
        if (Pacemaker_A2_B.d < 65536.0) {
          tmp_0 = (uint16_T)Pacemaker_A2_B.d;
        } else {
          tmp_0 = MAX_uint16_T;
        }

        tmp = rt_roundf_snf(Pacemaker_A2_B.ATR_PULSE_WIDTH_d);
        if (tmp < 65536.0F) {
          if (tmp >= 0.0F) {
            tmp_1 = (uint16_T)tmp;
          } else {
            tmp_1 = 0U;
          }
        } else {
          tmp_1 = MAX_uint16_T;
        }

        qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_1;
        if (qY > tmp_0) {
          qY = 0U;
        }

        if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY)
        {
          Pacemaker_A2_DW.is_AOOR = Pacemaker_A2_IN_AOOR_PACING;
          Pacemaker_A2_DW.temporalCounter_i1 = 0U;
          Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
          Pacemaker_A2_B.PACE_GND_CTRL = true;
          Pacemaker_A2_B.ATR_PACE_CTRL = true;
          Pacemaker_A2_B.ATR_GND_CTRL = false;
          Pacemaker_A2_B.GREEN_LED = 0.0;
        }

        /* case IN_AOOR_PACING: */
      } else if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
                 Pacemaker_A2_B.ATR_PULSE_WIDTH_d) {
        Pacemaker_A2_DW.is_AOOR = Pacemaker_A2_IN_AOOR_INITIAL;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.ATR_PACE_CTRL = false;
        Pacemaker_A2_B.ATR_GND_CTRL = true;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i * 20.0F;
        Pacemaker_A2_B.GREEN_LED = 1.0;
      } else {
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.ATR_PACE_CTRL = true;
        Pacemaker_A2_B.ATR_GND_CTRL = false;
        Pacemaker_A2_B.GREEN_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_AOO_INITIAL:
      Pacemaker_A2_B.d = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.LRL_j);
      if (Pacemaker_A2_B.d < 65536.0) {
        tmp_0 = (uint16_T)Pacemaker_A2_B.d;
      } else {
        tmp_0 = MAX_uint16_T;
      }

      tmp = rt_roundf_snf(Pacemaker_A2_B.ATR_PULSE_WIDTH_d);
      if (tmp < 65536.0F) {
        if (tmp >= 0.0F) {
          tmp_1 = (uint16_T)tmp;
        } else {
          tmp_1 = 0U;
        }
      } else {
        tmp_1 = MAX_uint16_T;
      }

      qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_1;
      if (qY > tmp_0) {
        qY = 0U;
      }

      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AOO_PACING;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.ATR_PACE_CTRL = true;
        Pacemaker_A2_B.ATR_GND_CTRL = false;
        Pacemaker_A2_B.GREEN_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_AOO_PACING:
      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
          Pacemaker_A2_B.ATR_PULSE_WIDTH_d) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_AOO_INITIAL;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.ATR_PACE_CTRL = false;
        Pacemaker_A2_B.ATR_GND_CTRL = true;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.VENT_AMP_i / 5.0F *
          100.0F;
        Pacemaker_A2_B.GREEN_LED = 1.0;
      } else {
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.ATR_PACE_CTRL = true;
        Pacemaker_A2_B.ATR_GND_CTRL = false;
        Pacemaker_A2_B.GREEN_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_MainState:
      Pacemaker_A2_MainState();
      break;

     case Pacemaker_A2_IN_VOOR:
      if (Pacemaker_A2_DW.is_VOOR == Pacemaker_A2_IN_VOOR_INTIAL) {
        Pacemaker_A2_B.d = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.rate);
        if (Pacemaker_A2_B.d < 65536.0) {
          tmp_0 = (uint16_T)Pacemaker_A2_B.d;
        } else {
          tmp_0 = MAX_uint16_T;
        }

        tmp = rt_roundf_snf(Pacemaker_A2_B.VENT_PULSE_WIDTH_g);
        if (tmp < 65536.0F) {
          if (tmp >= 0.0F) {
            tmp_1 = (uint16_T)tmp;
          } else {
            tmp_1 = 0U;
          }
        } else {
          tmp_1 = MAX_uint16_T;
        }

        qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_1;
        if (qY > tmp_0) {
          qY = 0U;
        }

        if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY)
        {
          Pacemaker_A2_DW.is_VOOR = Pacemaker_A2_IN_VOOR_PACING;
          Pacemaker_A2_DW.temporalCounter_i1 = 0U;
          Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
          Pacemaker_A2_B.PACE_GND_CTRL = true;
          Pacemaker_A2_B.VENT_GND_CTRL = false;
          Pacemaker_A2_B.VENT_PACE_CTRL = true;
          Pacemaker_A2_B.RED_LED = 0.0;
        }

        /* case IN_VOOR_PACING: */
      } else if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
                 Pacemaker_A2_B.VENT_PULSE_WIDTH_g) {
        Pacemaker_A2_DW.is_VOOR = Pacemaker_A2_IN_VOOR_INTIAL;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.VENT_GND_CTRL = true;
        Pacemaker_A2_B.VENT_PACE_CTRL = false;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
        Pacemaker_A2_B.RED_LED = 1.0;
      } else {
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.VENT_GND_CTRL = false;
        Pacemaker_A2_B.VENT_PACE_CTRL = true;
        Pacemaker_A2_B.RED_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_VOO_INITIAL:
      Pacemaker_A2_B.d = rt_roundd_snf(60000.0 / (real_T)Pacemaker_A2_B.LRL_j);
      if (Pacemaker_A2_B.d < 65536.0) {
        tmp_0 = (uint16_T)Pacemaker_A2_B.d;
      } else {
        tmp_0 = MAX_uint16_T;
      }

      tmp = rt_roundf_snf(Pacemaker_A2_B.VENT_PULSE_WIDTH_g);
      if (tmp < 65536.0F) {
        if (tmp >= 0.0F) {
          tmp_1 = (uint16_T)tmp;
        } else {
          tmp_1 = 0U;
        }
      } else {
        tmp_1 = MAX_uint16_T;
      }

      qY = (uint32_T)tmp_0 - /*MW:OvSatOk*/ tmp_1;
      if (qY > tmp_0) {
        qY = 0U;
      }

      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >= qY) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VOO_PACING;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.VENT_GND_CTRL = false;
        Pacemaker_A2_B.VENT_PACE_CTRL = true;
        Pacemaker_A2_B.RED_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_VOO_PACING:
      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
          Pacemaker_A2_B.VENT_PULSE_WIDTH_g) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VOO_INITIAL;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.VENT_GND_CTRL = true;
        Pacemaker_A2_B.VENT_PACE_CTRL = false;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
        Pacemaker_A2_B.RED_LED = 1.0;
      } else {
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.VENT_GND_CTRL = false;
        Pacemaker_A2_B.VENT_PACE_CTRL = true;
        Pacemaker_A2_B.RED_LED = 0.0;
      }
      break;

     case Pacemaker_A2_IN_VVIR:
      Pacemaker_A2_VVIR(&ATR_CMP_DETECT);
      break;

     case Pacemaker_A2_IN_VVI_INITIAL:
      Pacemaker_A2_VVI_INITIAL(&ATR_CMP_DETECT);
      break;

     case Pacemaker_A2_IN_VVI_PACING:
      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
          Pacemaker_A2_B.VENT_PULSE_WIDTH_g) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VVI_REF;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.FRONTEND_CTRL = false;
        Pacemaker_A2_B.VENT_PACE_CTRL = false;
        Pacemaker_A2_B.VENT_GND_CTRL = true;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o * 20.0F;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = false;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.RED_LED = 0.0;
      }
      break;

     default:
      /* case IN_VVI_REF: */
      Pacemaker_A2_B.FRONTEND_CTRL = false;
      if ((uint32_T)((int32_T)Pacemaker_A2_DW.temporalCounter_i1 * 10) >=
          Pacemaker_A2_B.VRP_l) {
        Pacemaker_A2_DW.is_c3_Pacemaker_A2 = Pacemaker_A2_IN_VVI_INITIAL;
        Pacemaker_A2_DW.temporalCounter_i1 = 0U;
        Pacemaker_A2_B.PACING_REF_PWM = Pacemaker_A2_B.ATR_AMP_o / 5.0F * 100.0F;
        Pacemaker_A2_B.PACE_GND_CTRL = true;
        Pacemaker_A2_B.VENT_GND_CTRL = true;
        Pacemaker_A2_B.VENT_PACE_CTRL = false;
        Pacemaker_A2_B.PACE_CHARGE_CTRL = true;
        Pacemaker_A2_B.VENT_CMP_REF_PWM = Pacemaker_A2_B.VENT_sensitivity_p /
          5.0F * 100.0F;
        Pacemaker_A2_B.FRONTEND_CTRL = true;
        Pacemaker_A2_B.RED_LED = 1.0;
      }
      break;
    }
  }

  /* End of Chart: '<Root>/ MODES' */

  /* MATLABSystem: '<S4>/Digital Write' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_m.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.ATR_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write1' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_jf.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.PACE_CHARGE_CTRL);

  /* MATLABSystem: '<S4>/PWM Output' */
  MW_PWM_SetDutyCycle(Pacemaker_A2_DW.obj_j3.MW_PWM_HANDLE, (real_T)
                      Pacemaker_A2_B.PACING_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write5' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_jk.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.ATR_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write6' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_jo.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.VENT_PACE_CTRL);

  /* MATLABSystem: '<S4>/Digital Write7' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_pf.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.PACE_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write8' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_f.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.VENT_GND_CTRL);

  /* MATLABSystem: '<S4>/Digital Write9' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_n.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.GREEN_LED != 0.0);

  /* MATLABSystem: '<S4>/Digital Write12' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_l.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.RED_LED != 0.0);

  /* MATLABSystem: '<S4>/PWM Output1' */
  MW_PWM_SetDutyCycle(Pacemaker_A2_DW.obj_d.MW_PWM_HANDLE, (real_T)
                      Pacemaker_A2_B.VENT_CMP_REF_PWM);

  /* MATLABSystem: '<S4>/PWM Output2' */
  MW_PWM_SetDutyCycle(Pacemaker_A2_DW.obj_ml.MW_PWM_HANDLE, (real_T)
                      Pacemaker_A2_B.ATR_CMP_REF_PWM);

  /* MATLABSystem: '<S4>/Digital Write14' */
  MW_digitalIO_write(Pacemaker_A2_DW.obj_bq.MW_DIGITALIO_HANDLE,
                     Pacemaker_A2_B.FRONTEND_CTRL);
}

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Pacemaker_A2_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Pacemaker_A2_step0();
    break;

   case 1 :
    Pacemaker_A2_step1();
    break;

   default :
    /* do nothing */
    break;
  }
}

/* Model initialize function */
void Pacemaker_A2_initialize(void)
{
  {
    freedomk64f_DigitalRead_Pacem_T *obj;
    freedomk64f_DigitalWrite_Pace_T *obj_1;
    freedomk64f_PWMOutput_Pacemak_T *obj_2;
    g_dsp_internal_SlidingWindowA_T *obj_0;

    /* SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Send To DCM' incorporates:
     *  SubSystem: '<Root>/Send To DCM'
     */
    send_params_Init();

    /* End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<Root>/Send To DCM' */

    /* Start for MATLABSystem: '<Root>/Serial Receive' */
    Pacemaker_A2_DW.obj_e.isInitialized = 0;
    Pacemaker_A2_DW.obj_e.matlabCodegenIsDeleted = false;
    Pacemaker_A2_DW.obj_e.SampleTime = Pacemaker_A2_P.SerialReceive_SampleTime;
    Pacemaker_A2_SystemCore_setup_k(&Pacemaker_A2_DW.obj_e);

    /* Start for MATLABSystem: '<S5>/ATR_CMP_DETECT' */
    Pacemaker_A2_DW.obj_a.matlabCodegenIsDeleted = false;
    Pacemaker_A2_DW.obj_a.SampleTime = Pacemaker_A2_P.ATR_CMP_DETECT_SampleTime;
    obj = &Pacemaker_A2_DW.obj_a;
    Pacemaker_A2_DW.obj_a.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(0U, 0);
    Pacemaker_A2_DW.obj_a.isSetupComplete = true;

    /* Start for MATLABSystem: '<S5>/VENT_CMP_DETECT' */
    Pacemaker_A2_DW.obj_i.matlabCodegenIsDeleted = false;
    Pacemaker_A2_DW.obj_i.SampleTime = Pacemaker_A2_P.VENT_CMP_DETECT_SampleTime;
    obj = &Pacemaker_A2_DW.obj_i;
    Pacemaker_A2_DW.obj_i.isInitialized = 1;
    obj->MW_DIGITALIO_HANDLE = MW_digitalIO_open(1U, 0);
    Pacemaker_A2_DW.obj_i.isSetupComplete = true;

    /* Start for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor' */
    Pacemaker_A2_DW.obj_b.isInitialized = 0;
    Pacemaker_A2_DW.obj_b.i2cobj.isInitialized = 0;
    Pacemaker_A2_DW.obj_b.i2cobj.matlabCodegenIsDeleted = false;
    Pacemaker_A2_DW.obj_b.matlabCodegenIsDeleted = false;
    Pacemaker_A2_DW.obj_b.SampleTime =
      Pacemaker_A2_P.FXOS87006AxesSensor_SampleTime;
    Pacemaker_A_SystemCore_setup_kl(&Pacemaker_A2_DW.obj_b);

    /* Start for MATLABSystem: '<S8>/Moving Average' */
    Pacemaker_A2_DW.obj.isInitialized = 0;
    Pacemaker_A2_DW.obj.NumChannels = -1;
    Pacemaker_A2_DW.obj.FrameLength = -1;
    Pacemaker_A2_DW.obj.matlabCodegenIsDeleted = false;
    Pacemaker__SystemCore_setup_klr(&Pacemaker_A2_DW.obj);

    /* InitializeConditions for MATLABSystem: '<S8>/Moving Average' */
    obj_0 = Pacemaker_A2_DW.obj.pStatistic;
    if (obj_0->isInitialized == 1) {
      obj_0->pCumSum = 0.0;
      for (Pacemaker_A2_B.i = 0; Pacemaker_A2_B.i < 499; Pacemaker_A2_B.i++) {
        obj_0->pCumSumRev[Pacemaker_A2_B.i] = 0.0;
      }

      obj_0->pCumRevIndex = 1.0;
      obj_0->pModValueRev = 0.0;
    }

    /* End of InitializeConditions for MATLABSystem: '<S8>/Moving Average' */

    /* Start for MATLABSystem: '<S4>/Digital Write' */
    Pacemaker_A2_DW.obj_m.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_m;
    Pacemaker_A2_DW.obj_m.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(11U, 1);
    Pacemaker_A2_DW.obj_m.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write1' */
    Pacemaker_A2_DW.obj_jf.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_jf;
    Pacemaker_A2_DW.obj_jf.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(2U, 1);
    Pacemaker_A2_DW.obj_jf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output' */
    Pacemaker_A2_DW.obj_j3.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_A2_DW.obj_j3;
    Pacemaker_A2_DW.obj_j3.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(5U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_A2_DW.obj_j3.MW_PWM_HANDLE);
    Pacemaker_A2_DW.obj_j3.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write5' */
    Pacemaker_A2_DW.obj_jk.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_jk;
    Pacemaker_A2_DW.obj_jk.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(8U, 1);
    Pacemaker_A2_DW.obj_jk.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write6' */
    Pacemaker_A2_DW.obj_jo.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_jo;
    Pacemaker_A2_DW.obj_jo.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(9U, 1);
    Pacemaker_A2_DW.obj_jo.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write7' */
    Pacemaker_A2_DW.obj_pf.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_pf;
    Pacemaker_A2_DW.obj_pf.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(10U, 1);
    Pacemaker_A2_DW.obj_pf.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write8' */
    Pacemaker_A2_DW.obj_f.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_f;
    Pacemaker_A2_DW.obj_f.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(12U, 1);
    Pacemaker_A2_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write9' */
    Pacemaker_A2_DW.obj_n.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_n;
    Pacemaker_A2_DW.obj_n.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(43U, 1);
    Pacemaker_A2_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write12' */
    Pacemaker_A2_DW.obj_l.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_l;
    Pacemaker_A2_DW.obj_l.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(42U, 1);
    Pacemaker_A2_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output1' */
    Pacemaker_A2_DW.obj_d.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_A2_DW.obj_d;
    Pacemaker_A2_DW.obj_d.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(3U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_A2_DW.obj_d.MW_PWM_HANDLE);
    Pacemaker_A2_DW.obj_d.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/PWM Output2' */
    Pacemaker_A2_DW.obj_ml.matlabCodegenIsDeleted = false;
    obj_2 = &Pacemaker_A2_DW.obj_ml;
    Pacemaker_A2_DW.obj_ml.isInitialized = 1;
    obj_2->MW_PWM_HANDLE = MW_PWM_Open(6U, 2000.0, 0.0);
    MW_PWM_Start(Pacemaker_A2_DW.obj_ml.MW_PWM_HANDLE);
    Pacemaker_A2_DW.obj_ml.isSetupComplete = true;

    /* Start for MATLABSystem: '<S4>/Digital Write14' */
    Pacemaker_A2_DW.obj_bq.matlabCodegenIsDeleted = false;
    obj_1 = &Pacemaker_A2_DW.obj_bq;
    Pacemaker_A2_DW.obj_bq.isInitialized = 1;
    obj_1->MW_DIGITALIO_HANDLE = MW_digitalIO_open(13U, 1);
    Pacemaker_A2_DW.obj_bq.isSetupComplete = true;
  }
}

/* Model terminate function */
void Pacemaker_A2_terminate(void)
{
  b_freedomk64f_I2CMasterWrite__T *obj;
  g_dsp_internal_SlidingWindowA_T *obj_0;

  /* Terminate for MATLABSystem: '<Root>/Serial Receive' */
  if (!Pacemaker_A2_DW.obj_e.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_e.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_e.isSetupComplete) {
      MW_SCI_Close(Pacemaker_A2_DW.obj_e.MW_SCIHANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Serial Receive' */

  /* Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Send To DCM' incorporates:
   *  SubSystem: '<Root>/Send To DCM'
   */
  send_params_Term();

  /* End of Terminate for S-Function (sfun_private_function_caller) generated from: '<Root>/Send To DCM' */

  /* Terminate for MATLABSystem: '<S5>/ATR_CMP_DETECT' */
  if (!Pacemaker_A2_DW.obj_a.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_a.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_a.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_a.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/ATR_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S5>/VENT_CMP_DETECT' */
  if (!Pacemaker_A2_DW.obj_i.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_i.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_i.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_i.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/VENT_CMP_DETECT' */

  /* Terminate for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor' */
  if (!Pacemaker_A2_DW.obj_b.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_b.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_b.isSetupComplete) {
      MW_I2C_Close(Pacemaker_A2_DW.obj_b.i2cobj.MW_I2C_HANDLE);
    }
  }

  obj = &Pacemaker_A2_DW.obj_b.i2cobj;
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/FXOS8700 6-Axes Sensor' */

  /* Terminate for MATLABSystem: '<S8>/Moving Average' */
  if (!Pacemaker_A2_DW.obj.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj.isInitialized == 1) &&
        Pacemaker_A2_DW.obj.isSetupComplete) {
      obj_0 = Pacemaker_A2_DW.obj.pStatistic;
      if (obj_0->isInitialized == 1) {
        obj_0->isInitialized = 2;
      }

      Pacemaker_A2_DW.obj.NumChannels = -1;
      Pacemaker_A2_DW.obj.FrameLength = -1;
    }
  }

  /* End of Terminate for MATLABSystem: '<S8>/Moving Average' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write' */
  if (!Pacemaker_A2_DW.obj_m.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_m.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_m.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_m.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write1' */
  if (!Pacemaker_A2_DW.obj_jf.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_jf.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_jf.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_jf.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_jf.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output' */
  if (!Pacemaker_A2_DW.obj_j3.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_j3.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_j3.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_j3.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_A2_DW.obj_j3.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_A2_DW.obj_j3.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write5' */
  if (!Pacemaker_A2_DW.obj_jk.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_jk.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_jk.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_jk.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_jk.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write5' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write6' */
  if (!Pacemaker_A2_DW.obj_jo.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_jo.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_jo.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_jo.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_jo.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write6' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write7' */
  if (!Pacemaker_A2_DW.obj_pf.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_pf.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_pf.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_pf.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_pf.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write7' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write8' */
  if (!Pacemaker_A2_DW.obj_f.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_f.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_f.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_f.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write8' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write9' */
  if (!Pacemaker_A2_DW.obj_n.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_n.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_n.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_n.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write9' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write12' */
  if (!Pacemaker_A2_DW.obj_l.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_l.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_l.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_l.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write12' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output1' */
  if (!Pacemaker_A2_DW.obj_d.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_d.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_d.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_A2_DW.obj_d.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_A2_DW.obj_d.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output1' */

  /* Terminate for MATLABSystem: '<S4>/PWM Output2' */
  if (!Pacemaker_A2_DW.obj_ml.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_ml.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_ml.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_ml.isSetupComplete) {
      MW_PWM_Stop(Pacemaker_A2_DW.obj_ml.MW_PWM_HANDLE);
      MW_PWM_Close(Pacemaker_A2_DW.obj_ml.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/PWM Output2' */

  /* Terminate for MATLABSystem: '<S4>/Digital Write14' */
  if (!Pacemaker_A2_DW.obj_bq.matlabCodegenIsDeleted) {
    Pacemaker_A2_DW.obj_bq.matlabCodegenIsDeleted = true;
    if ((Pacemaker_A2_DW.obj_bq.isInitialized == 1) &&
        Pacemaker_A2_DW.obj_bq.isSetupComplete) {
      MW_digitalIO_close(Pacemaker_A2_DW.obj_bq.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Digital Write14' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
