/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_STM32_H743_HIL_data.c
 *
 * Code generated for Simulink model 'main_STM32_H743_HIL'.
 *
 * Model version                  : 2.9
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Jan 15 20:57:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "main_STM32_H743_HIL.h"

/* Model block global parameters (default storage) */
struct_2DXLRriZ9wBR741CrBzWmE rtP_vel_profile = {
  0.005F,
  1.0F,
  1.0F
} ;                                    /* Variable: vel_profile
                                        * Referenced by: '<Root>/Model'
                                        */

real_T rtP_A = 1.87;                   /* Variable: A
                                        * Referenced by: '<S12>/Gain5'
                                        */
real_T rtP_b_vkm = -10.0;              /* Variable: b_vkm
                                        * Referenced by:
                                        *   '<Root>/Model'
                                        *   '<S12>/Constant1'
                                        */
real_T rtP_c_W = 0.4;                  /* Variable: c_W
                                        * Referenced by: '<S12>/Gain5'
                                        */
real_T rtP_eta = 0.95;                 /* Variable: eta
                                        * Referenced by: '<S12>/Gain'
                                        */
real_T rtP_f_R = 0.01;                 /* Variable: f_R
                                        * Referenced by: '<S12>/Gain4'
                                        */
real_T rtP_g = 9.81;                   /* Variable: g
                                        * Referenced by:
                                        *   '<S12>/Gain12'
                                        *   '<S12>/Gain4'
                                        */
real_T rtP_iD_car = 3.45;              /* Variable: iD_car
                                        * Referenced by:
                                        *   '<S12>/Gain1'
                                        *   '<S12>/Gain7'
                                        */
real_T rtP_iG_car[6] = { 0.001, 3.682, 2.002, 1.33, 1.0, 0.805 } ;/* Variable: iG_car
                                                                   * Referenced by:
                                                                   *   '<Root>/Model'
                                                                   *   '<S12>/Constant'
                                                                   */

real_T rtP_k1 = 0.00041274774774774787;/* Variable: k1
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_k2 = 0.0;                   /* Variable: k2
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_k3 = 0.0981;                /* Variable: k3
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_k4 = 0.00973685969563958;   /* Variable: k4
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_k5 = 108.63997764228304;    /* Variable: k5
                                        * Referenced by: '<Root>/Model'
                                        */
real_T rtP_m_F = 1110.0;               /* Variable: m_F
                                        * Referenced by:
                                        *   '<S12>/Gain12'
                                        *   '<S12>/Gain3'
                                        *   '<S12>/Gain4'
                                        */
real_T rtP_m_Zu = 0.0;                 /* Variable: m_Zu
                                        * Referenced by:
                                        *   '<S12>/Gain12'
                                        *   '<S12>/Gain3'
                                        *   '<S12>/Gain4'
                                        */
real_T rtP_m_vkm = -0.01;              /* Variable: m_vkm
                                        * Referenced by:
                                        *   '<Root>/Model'
                                        *   '<S12>/Gain9'
                                        */
real_T rtP_p[3] = { -5.1168E-6, 0.0518, 114.11 } ;/* Variable: p
                                                   * Referenced by:
                                                   *   '<Root>/Model'
                                                   *   '<S12>/Constant3'
                                                   *   '<S12>/Gain10'
                                                   *   '<S12>/Gain11'
                                                   */

real_T rtP_p_L = 1.225;                /* Variable: p_L
                                        * Referenced by: '<S12>/Gain5'
                                        */
real_T rtP_r_dyn = 0.30325;            /* Variable: r_dyn
                                        * Referenced by: '<S12>/Gain6'
                                        */
real_T rtP_r_stat = 0.30325;           /* Variable: r_stat
                                        * Referenced by: '<S12>/Gain2'
                                        */
int32_T rtP_reload_value = 10000;      /* Variable: reload_value
                                        * Referenced by: '<S9>/MATLAB Function'
                                        */
real32_T rtP_MFv = 0.4976F;            /* Variable: MFv
                                        * Referenced by: '<Root>/Model'
                                        */
real32_T rtP_UB = 15.0F;               /* Variable: UB
                                        * Referenced by: '<Root>/Model'
                                        */
real32_T rtP_cphi = 0.404635847F;      /* Variable: cphi
                                        * Referenced by: '<Root>/Model'
                                        */
real32_T rtP_phimax = 1.57079637F;     /* Variable: phimax
                                        * Referenced by: '<Root>/Model'
                                        */
real32_T rtP_phiminV = 0.533F;         /* Variable: phiminV
                                        * Referenced by: '<Root>/Model'
                                        */
real32_T rtP_v_0 = 36.1111107F;        /* Variable: v_0
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */

/* Block parameters (default storage) */
P_main_STM32_H743_HIL_T main_STM32_H743_HIL_P = {
  /* Mask Parameter: DetectIncrease_vinit
   * Referenced by: '<S32>/Delay Input1'
   */
  0U,

  /* Mask Parameter: SRFlipFlop_initial_condition
   * Referenced by: '<S38>/Memory'
   */
  false,

  /* Expression: 0
   * Referenced by: '<S4>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Computed Parameter: MAF_4_order_InitialStates
   * Referenced by: '<S13>/MAF_4_order'
   */
  0.0F,

  /* Computed Parameter: MAF_4_order_Coefficients
   * Referenced by: '<S13>/MAF_4_order'
   */
  { 0.2F, 0.2F, 0.2F, 0.2F, 0.2F },

  /* Computed Parameter: Gain7_Gain
   * Referenced by: '<S13>/Gain7'
   */
  0.0001F,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S12>/Discrete-Time Integrator'
   */
  0.005F,

  /* Expression: single(60/(2*pi))
   * Referenced by: '<S12>/Gain8'
   */
  9.54929638F,

  /* Computed Parameter: Gain13_Gain
   * Referenced by: '<S12>/Gain13'
   */
  3.6F,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S3>/Constant'
   */
  0.0F,

  /* Computed Parameter: phi3_driver_norm_Value
   * Referenced by: '<Root>/phi3_driver_norm'
   */
  0.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  6.66666651F,

  /* Computed Parameter: Memory_InitialCondition
   * Referenced by: '<Root>/Memory'
   */
  0.0F,

  /* Computed Parameter: Memory2_InitialCondition
   * Referenced by: '<Root>/Memory2'
   */
  0.0F,

  /* Computed Parameter: TmpRTBAtMemory2Inport1_InitialC
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: TmpRTBAtMemoryInport1_InitialCo
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: a_ist_mps2_InitialCondition
   * Referenced by:
   */
  0.0F,

  /* Computed Parameter: gear_Value
   * Referenced by: '<Root>/gear'
   */
  4.0F,

  /* Computed Parameter: gradient_relative_Value
   * Referenced by: '<Root>/gradient_relative'
   */
  0.0F,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S9>/Unit Delay'
   */
  0U,

  /* Expression: 0x4000
   * Referenced by: '<S8>/Constant'
   */
  16384U,

  /* Expression: 0x3ffe
   * Referenced by: '<S8>/Constant1'
   */
  16382U,

  /* Expression: 0x4000
   * Referenced by: '<S8>/Constant2'
   */
  16384U,

  /* Expression: 0x3ff5
   * Referenced by: '<S8>/Constant3'
   */
  16373U,

  /* Computed Parameter: UnitDelay_InitialCondition_f
   * Referenced by: '<S13>/Unit Delay'
   */
  0U,

  /* Computed Parameter: UnitDelay_InitialCondition_b
   * Referenced by: '<S14>/Unit Delay'
   */
  false,

  /* Computed Parameter: Logic_table
   * Referenced by: '<S38>/Logic'
   */
  { false, true, false, false, true, true, false, false, true, false, true, true,
    false, false, false, false },

  /* Computed Parameter: Memory1_InitialCondition
   * Referenced by: '<Root>/Memory1'
   */
  0U,

  /* Computed Parameter: TmpRTBAtMemory1Inport1_InitialC
   * Referenced by:
   */
  0U,

  /* Computed Parameter: TmpRTBAtModelInport7_InitialCon
   * Referenced by:
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
