/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_STM32_H743_HIL.h
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

#ifndef RTW_HEADER_main_STM32_H743_HIL_h_
#define RTW_HEADER_main_STM32_H743_HIL_h_
#ifndef main_STM32_H743_HIL_COMMON_INCLUDES_
#define main_STM32_H743_HIL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "string.h"
#include "code_profiling_utility_functions.h"
#include "main.h"
#include "MW_SPI.h"
#include "mw_stm32_spi_ll.h"
#include "stm_uart.h"
#endif                                /* main_STM32_H743_HIL_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "main_STM32_H743_HIL_types.h"
#include "ECU_RCP.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "model_reference_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* user code (top of header file) */
#include "profile_generator.h"

/* Block states (default storage) for system '<S8>/SPI Controller Transfer2' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S8>/SPI Controller Transfer2' */
  boolean_T objisempty;                /* '<S8>/SPI Controller Transfer2' */
} DW_SPIControllerTransfer2_mai_T;

/* Block signals (default storage) */
typedef struct {
  cell_wrap_0_main_STM32_H743_H_T b[5];
  uint8_T uartWriteData[26];
  cell_wrap_0_main_STM32_H743_H_T b_m;
  cell_wrap_0_main_STM32_H743_H_T c;
  cell_wrap_0_main_STM32_H743_H_T d;
  GPIO_TypeDef * portNameLoc;
  real_T rtb_xpp_tmp;
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  real32_T u_ref;                      /* '<Root>/Model' */
  real32_T phi3_M_filt_norm;           /* '<Root>/Model' */
  real32_T TmpRTBAtMemory2Inport1;     /* '<Root>/Model' */
  real32_T TmpRTBAtMemoryInport1;      /* '<Root>/Model' */
  real32_T a_ist_mps2;                 /* '<Root>/Subsystem' */
  real32_T i_calc_ext;                 /* '<Root>/Model' */
  real32_T v_soll_chart_kmh;           /* '<Root>/Model' */
  real32_T n_Mot1min;                  /* '<S12>/Gain8' */
  real32_T Gain13;                     /* '<S12>/Gain13' */
  real32_T vprev;
  real32_T p;
  real32_T temp;
  real32_T flag_tmp;
  real32_T ind1;
  real32_T ind2;
  real32_T f;
  real32_T f1;
  real32_T ind1_c;
  real32_T ind2_k;
  real32_T f2;
  real32_T f3;
  real32_T cnt1;
  real32_T cnt2;
  real32_T xpp;                        /* '<S12>/Gain3' */
  real32_T f4;
  int32_T c_c;
  int32_T i;
  uint32_T data;
  uint8_T TmpRTBAtMemory1Inport1;      /* '<Root>/Model' */
  uint8_T PG4_in_Kupplung;
  uint8_T PG6_in_Bremse;
  uint8_T debug_fcn_state;             /* '<Root>/Model' */
  uint8_T uart_tx_data[26];            /* '<S14>/Byte Pack' */
  uint8_T Product;                     /* '<S14>/Product' */
  uint8_T byte_array[10];              /* '<S14>/MATLAB Function4' */
  uint8_T byte_array_a[4];             /* '<S14>/MATLAB Function3' */
  uint8_T byte_array_n[4];             /* '<S14>/MATLAB Function2' */
  uint8_T byte_array_j[4];             /* '<S14>/MATLAB Function1' */
  uint8_T byte_array_e[4];             /* '<S14>/MATLAB Function' */
  boolean_T flag;
} B_main_STM32_H743_HIL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_simulink_MedianFilter_mai_T obj; /* '<Root>/Median Filter2' */
  stm32cube_blocks_UARTRead_mai_T obj_k;/* '<S14>/UART//USART Read' */
  stm32cube_blocks_UARTWrite_ma_T obj_a;/* '<S14>/UART//USART Write' */
  stm32cube_blocks_AnalogInputF_T obj_n;/* '<S18>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInputF_T obj_m;/* '<S16>/Analog to Digital Converter' */
  stm32cube_blocks_EncoderBlock_T obj_k2;/* '<S9>/Encoder1' */
  stm32cube_blocks_PWMOutput_ma_T obj_m3;/* '<S29>/PWM Output' */
  stm32cube_blocks_TimerCapture_T obj_o;/* '<S13>/Timer Capture1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S12>/Discrete-Time Integrator' */
  int32_T MAF_4_order_circBuf;         /* '<S13>/MAF_4_order' */
  real32_T Memory_PreviousInput;       /* '<Root>/Memory' */
  real32_T Memory2_PreviousInput;      /* '<Root>/Memory2' */
  real32_T TmpRTBAtMemory2Inport1_Buffer0;/* synthesized block */
  real32_T TmpRTBAtMemoryInport1_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSubsystemInport1_Buffer;/* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInport;/* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInpo_g;/* synthesized block */
  real32_T a_ist_mps2_Buffer0;         /* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInpo_d;/* synthesized block */
  real32_T v_ist_kmh_Buffer;           /* synthesized block */
  uint16_T UnitDelay_DSTATE_m;         /* '<S13>/Unit Delay' */
  uint16_T DelayInput1_DSTATE;         /* '<S32>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S14>/Unit Delay' */
  uint8_T Memory1_PreviousInput;       /* '<Root>/Memory1' */
  uint8_T TmpRTBAtMemory1Inport1_Buffer0;/* synthesized block */
  uint8_T TmpRTBAtdata_exchange_HMIInpo_c;/* synthesized block */
  uint8_T TmpRTBAtModelInport7_Buffer0;/* synthesized block */
  uint8_T TmpRTBAtModelInport6_Buffer; /* synthesized block */
  boolean_T Memory_PreviousInput_o;    /* '<S38>/Memory' */
  MdlrefDW_ECU_RCP_T Model_InstanceData;/* '<Root>/Model' */
  DW_SPIControllerTransfer2_mai_T SPIControllerTransfer3;/* '<S8>/SPI Controller Transfer2' */
  DW_SPIControllerTransfer2_mai_T SPIControllerTransfer2;/* '<S8>/SPI Controller Transfer2' */
} DW_main_STM32_H743_HIL_T;

/* Parameters (default storage) */
struct P_main_STM32_H743_HIL_T_ {
  uint16_T DetectIncrease_vinit;       /* Mask Parameter: DetectIncrease_vinit
                                        * Referenced by: '<S32>/Delay Input1'
                                        */
  boolean_T SRFlipFlop_initial_condition;
                                 /* Mask Parameter: SRFlipFlop_initial_condition
                                  * Referenced by: '<S38>/Memory'
                                  */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real32_T MAF_4_order_InitialStates;
                                /* Computed Parameter: MAF_4_order_InitialStates
                                 * Referenced by: '<S13>/MAF_4_order'
                                 */
  real32_T MAF_4_order_Coefficients[5];
                                 /* Computed Parameter: MAF_4_order_Coefficients
                                  * Referenced by: '<S13>/MAF_4_order'
                                  */
  real32_T Gain7_Gain;                 /* Computed Parameter: Gain7_Gain
                                        * Referenced by: '<S13>/Gain7'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S12>/Discrete-Time Integrator'
                            */
  real32_T Gain8_Gain;                 /* Expression: single(60/(2*pi))
                                        * Referenced by: '<S12>/Gain8'
                                        */
  real32_T Gain13_Gain;                /* Computed Parameter: Gain13_Gain
                                        * Referenced by: '<S12>/Gain13'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S3>/Constant'
                                        */
  real32_T phi3_driver_norm_Value; /* Computed Parameter: phi3_driver_norm_Value
                                    * Referenced by: '<Root>/phi3_driver_norm'
                                    */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real32_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<Root>/Memory'
                                   */
  real32_T Memory2_InitialCondition;
                                 /* Computed Parameter: Memory2_InitialCondition
                                  * Referenced by: '<Root>/Memory2'
                                  */
  real32_T TmpRTBAtMemory2Inport1_InitialC;
                          /* Computed Parameter: TmpRTBAtMemory2Inport1_InitialC
                           * Referenced by:
                           */
  real32_T TmpRTBAtMemoryInport1_InitialCo;
                          /* Computed Parameter: TmpRTBAtMemoryInport1_InitialCo
                           * Referenced by:
                           */
  real32_T a_ist_mps2_InitialCondition;
                              /* Computed Parameter: a_ist_mps2_InitialCondition
                               * Referenced by:
                               */
  real32_T gear_Value;                 /* Computed Parameter: gear_Value
                                        * Referenced by: '<Root>/gear'
                                        */
  real32_T gradient_relative_Value;
                                  /* Computed Parameter: gradient_relative_Value
                                   * Referenced by: '<Root>/gradient_relative'
                                   */
  uint32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S9>/Unit Delay'
                                */
  uint16_T Constant_Value_i;           /* Expression: 0x4000
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Expression: 0x3ffe
                                        * Referenced by: '<S8>/Constant1'
                                        */
  uint16_T Constant2_Value;            /* Expression: 0x4000
                                        * Referenced by: '<S8>/Constant2'
                                        */
  uint16_T Constant3_Value;            /* Expression: 0x3ff5
                                        * Referenced by: '<S8>/Constant3'
                                        */
  uint16_T UnitDelay_InitialCondition_f;
                             /* Computed Parameter: UnitDelay_InitialCondition_f
                              * Referenced by: '<S13>/Unit Delay'
                              */
  boolean_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S14>/Unit Delay'
                              */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S38>/Logic'
                                        */
  uint8_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<Root>/Memory1'
                                  */
  uint8_T TmpRTBAtMemory1Inport1_InitialC;
                          /* Computed Parameter: TmpRTBAtMemory1Inport1_InitialC
                           * Referenced by:
                           */
  uint8_T TmpRTBAtModelInport7_InitialCon;
                          /* Computed Parameter: TmpRTBAtModelInport7_InitialCon
                           * Referenced by:
                           */
};



/* Declare global externs for instrumentation */
extern void profileStart_m_0d34002402f40824(uint32_T);
extern void profileEnd_main_STM32_H743_HIL(uint32_T);
/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM_main_STM32_H743_HIL_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    struct {
      uint32_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_3;
      boolean_T TID1_2;
      boolean_T TID1_3;
      boolean_T TID2_3;
    } RateInteraction;
  } Timing;
};

/* Block parameters (default storage) */
extern P_main_STM32_H743_HIL_T main_STM32_H743_HIL_P;

/* Block signals (default storage) */
extern B_main_STM32_H743_HIL_T main_STM32_H743_HIL_B;

/* Block states (default storage) */
extern DW_main_STM32_H743_HIL_T main_STM32_H743_HIL_DW;

/* Model block global parameters (default storage) */
extern struct_2DXLRriZ9wBR741CrBzWmE rtP_vel_profile;/* Variable: vel_profile
                                                      * Referenced by: '<Root>/Model'
                                                      */
extern real_T rtP_A;                   /* Variable: A
                                        * Referenced by: '<S12>/Gain5'
                                        */
extern real_T rtP_b_vkm;               /* Variable: b_vkm
                                        * Referenced by:
                                        *   '<Root>/Model'
                                        *   '<S12>/Constant1'
                                        */
extern real_T rtP_c_W;                 /* Variable: c_W
                                        * Referenced by: '<S12>/Gain5'
                                        */
extern real_T rtP_eta;                 /* Variable: eta
                                        * Referenced by: '<S12>/Gain'
                                        */
extern real_T rtP_f_R;                 /* Variable: f_R
                                        * Referenced by: '<S12>/Gain4'
                                        */
extern real_T rtP_g;                   /* Variable: g
                                        * Referenced by:
                                        *   '<S12>/Gain12'
                                        *   '<S12>/Gain4'
                                        */
extern real_T rtP_iD_car;              /* Variable: iD_car
                                        * Referenced by:
                                        *   '<S12>/Gain1'
                                        *   '<S12>/Gain7'
                                        */
extern real_T rtP_iG_car[6];           /* Variable: iG_car
                                        * Referenced by:
                                        *   '<Root>/Model'
                                        *   '<S12>/Constant'
                                        */
extern real_T rtP_k1;                  /* Variable: k1
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_k2;                  /* Variable: k2
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_k3;                  /* Variable: k3
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_k4;                  /* Variable: k4
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_k5;                  /* Variable: k5
                                        * Referenced by: '<Root>/Model'
                                        */
extern real_T rtP_m_F;                 /* Variable: m_F
                                        * Referenced by:
                                        *   '<S12>/Gain12'
                                        *   '<S12>/Gain3'
                                        *   '<S12>/Gain4'
                                        */
extern real_T rtP_m_Zu;                /* Variable: m_Zu
                                        * Referenced by:
                                        *   '<S12>/Gain12'
                                        *   '<S12>/Gain3'
                                        *   '<S12>/Gain4'
                                        */
extern real_T rtP_m_vkm;               /* Variable: m_vkm
                                        * Referenced by:
                                        *   '<Root>/Model'
                                        *   '<S12>/Gain9'
                                        */
extern real_T rtP_p[3];                /* Variable: p
                                        * Referenced by:
                                        *   '<Root>/Model'
                                        *   '<S12>/Constant3'
                                        *   '<S12>/Gain10'
                                        *   '<S12>/Gain11'
                                        */
extern real_T rtP_p_L;                 /* Variable: p_L
                                        * Referenced by: '<S12>/Gain5'
                                        */
extern real_T rtP_r_dyn;               /* Variable: r_dyn
                                        * Referenced by: '<S12>/Gain6'
                                        */
extern real_T rtP_r_stat;              /* Variable: r_stat
                                        * Referenced by: '<S12>/Gain2'
                                        */
extern int32_T rtP_reload_value;       /* Variable: reload_value
                                        * Referenced by: '<S9>/MATLAB Function'
                                        */
extern real32_T rtP_MFv;               /* Variable: MFv
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_UB;                /* Variable: UB
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_cphi;              /* Variable: cphi
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_phimax;            /* Variable: phimax
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_phiminV;           /* Variable: phiminV
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_v_0;               /* Variable: v_0
                                        * Referenced by: '<S12>/Discrete-Time Integrator'
                                        */

/* External function called from main */
extern void main_STM32_H743_HIL_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void main_STM32_H743_HIL_initialize(void);
extern void main_STM32_H743_HIL_step0(void);
extern void main_STM32_H743_HIL_step1(void);
extern void main_STM32_H743_HIL_step2(void);
extern void main_STM32_H743_HIL_step3(void);
extern void main_STM32_H743_HIL_step4(void);
extern void main_STM32_H743_HIL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_main_STM32_H743_HIL_T *const main_STM32_H743_HIL_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void TIM15_IRQHandler(void);
  void main_STM32_H743_HIL_configure_interrupts (void);
  void main_STM32_H743_HIL_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Discrete Transfer Fcn3' : Unused code path elimination
 * Block '<S8>/Constant7' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Unused code path elimination
 * Block '<S8>/Gain' : Unused code path elimination
 * Block '<S8>/Gain2' : Unused code path elimination
 * Block '<S8>/Saturation' : Unused code path elimination
 * Block '<S8>/Shift Arithmetic1' : Unused code path elimination
 * Block '<S8>/Shift Arithmetic4' : Unused code path elimination
 * Block '<S8>/Sum' : Unused code path elimination
 * Block '<S9>/Data Type Conversion' : Unused code path elimination
 * Block '<S9>/MAF_1_order' : Unused code path elimination
 * Block '<S9>/MAF_3_order' : Unused code path elimination
 * Block '<Root>/Gain9' : Unused code path elimination
 * Block '<S12>/Discrete-Time Integrator1' : Unused code path elimination
 * Block '<S13>/Gain' : Unused code path elimination
 * Block '<Root>/vst_factor' : Unused code path elimination
 * Block '<S14>/Data Type Conversion6' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'main_STM32_H743_HIL'
 * '<S1>'   : 'main_STM32_H743_HIL/Analog to Digital Converter1'
 * '<S2>'   : 'main_STM32_H743_HIL/Analog to Digital Converter2'
 * '<S3>'   : 'main_STM32_H743_HIL/Compare To Zero1'
 * '<S4>'   : 'main_STM32_H743_HIL/Compare To Zero2'
 * '<S5>'   : 'main_STM32_H743_HIL/Digital Port Read1'
 * '<S6>'   : 'main_STM32_H743_HIL/Digital Port Write1'
 * '<S7>'   : 'main_STM32_H743_HIL/Digital Port Write2'
 * '<S8>'   : 'main_STM32_H743_HIL/Fahrpedalsensor'
 * '<S9>'   : 'main_STM32_H743_HIL/Function-Call Subsystem'
 * '<S10>'  : 'main_STM32_H743_HIL/Hardware Interrupt'
 * '<S11>'  : 'main_STM32_H743_HIL/PWM Output'
 * '<S12>'  : 'main_STM32_H743_HIL/Subsystem'
 * '<S13>'  : 'main_STM32_H743_HIL/Triggered Subsystem1'
 * '<S14>'  : 'main_STM32_H743_HIL/data_exchange_HMI'
 * '<S15>'  : 'main_STM32_H743_HIL/Analog to Digital Converter1/ECSoC'
 * '<S16>'  : 'main_STM32_H743_HIL/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S17>'  : 'main_STM32_H743_HIL/Analog to Digital Converter2/ECSoC'
 * '<S18>'  : 'main_STM32_H743_HIL/Analog to Digital Converter2/ECSoC/ECSimCodegen'
 * '<S19>'  : 'main_STM32_H743_HIL/Digital Port Read1/ECSoC'
 * '<S20>'  : 'main_STM32_H743_HIL/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S21>'  : 'main_STM32_H743_HIL/Digital Port Write1/ECSoC'
 * '<S22>'  : 'main_STM32_H743_HIL/Digital Port Write1/ECSoC/ECSimCodegen'
 * '<S23>'  : 'main_STM32_H743_HIL/Digital Port Write2/ECSoC'
 * '<S24>'  : 'main_STM32_H743_HIL/Digital Port Write2/ECSoC/ECSimCodegen'
 * '<S25>'  : 'main_STM32_H743_HIL/Function-Call Subsystem/MATLAB Function'
 * '<S26>'  : 'main_STM32_H743_HIL/Hardware Interrupt/ECSoC'
 * '<S27>'  : 'main_STM32_H743_HIL/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S28>'  : 'main_STM32_H743_HIL/PWM Output/ECSoC'
 * '<S29>'  : 'main_STM32_H743_HIL/PWM Output/ECSoC/ECSimCodegen'
 * '<S30>'  : 'main_STM32_H743_HIL/Triggered Subsystem1/MATLAB Function'
 * '<S31>'  : 'main_STM32_H743_HIL/Triggered Subsystem1/MATLAB Function1'
 * '<S32>'  : 'main_STM32_H743_HIL/data_exchange_HMI/Detect Increase'
 * '<S33>'  : 'main_STM32_H743_HIL/data_exchange_HMI/MATLAB Function'
 * '<S34>'  : 'main_STM32_H743_HIL/data_exchange_HMI/MATLAB Function1'
 * '<S35>'  : 'main_STM32_H743_HIL/data_exchange_HMI/MATLAB Function2'
 * '<S36>'  : 'main_STM32_H743_HIL/data_exchange_HMI/MATLAB Function3'
 * '<S37>'  : 'main_STM32_H743_HIL/data_exchange_HMI/MATLAB Function4'
 * '<S38>'  : 'main_STM32_H743_HIL/data_exchange_HMI/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_main_STM32_H743_HIL_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
