/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: send_params_private.h
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

#ifndef RTW_HEADER_send_params_private_h_
#define RTW_HEADER_send_params_private_h_
#ifndef Pacemaker_A2_COMMON_INCLUDES_
#define Pacemaker_A2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "MW_SCI.h"
#include "MW_I2C.h"
#include "MW_AnalogIn.h"
#endif                                 /* Pacemaker_A2_COMMON_INCLUDES_ */

extern void send_params_Init(void);
extern void send_params_Term(void);

#endif                                 /* RTW_HEADER_send_params_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
