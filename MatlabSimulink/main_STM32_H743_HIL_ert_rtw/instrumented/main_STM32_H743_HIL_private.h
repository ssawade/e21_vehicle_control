/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_STM32_H743_HIL_private.h
 *
 * Code generated for Simulink model 'main_STM32_H743_HIL'.
 *
 * Model version                  : 2.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Sat Jan  6 21:34:02 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_main_STM32_H743_HIL_private_h_
#define RTW_HEADER_main_STM32_H743_HIL_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"
#include "main_STM32_H743_HIL.h"
#include "main_STM32_H743_HIL_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern rtTimingBridge main_STM32_H743_HIL_TimingBrdg;
extern void SPIControllerTransfer_Start(DW_SPIControllerTransfer2_mai_T *localDW);
extern void main_SPIControllerTransfer2(uint16_T rtu_0,
  B_SPIControllerTransfer2_main_T *localB, DW_SPIControllerTransfer2_mai_T
  *localDW);
extern void main_ST_MATLABFunction_Init(DW_MATLABFunction_main_STM32__T *localDW);
extern void main_STM32_H_MATLABFunction(int32_T rtu_u, uint8_T rty_byte_array[4],
  DW_MATLABFunction_main_STM32__T *localDW);
extern void main_S_MATLABFunction1_Init(DW_MATLABFunction1_main_STM32_T *localDW);
extern void main_STM32__MATLABFunction1(int32_T rtu_u, uint8_T rty_byte_array[4],
  DW_MATLABFunction1_main_STM32_T *localDW);
extern void SPIControllerTransfer2_Term(DW_SPIControllerTransfer2_mai_T *localDW);

#endif                           /* RTW_HEADER_main_STM32_H743_HIL_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
