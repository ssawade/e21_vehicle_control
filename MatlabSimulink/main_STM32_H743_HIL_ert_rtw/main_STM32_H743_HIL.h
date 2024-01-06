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
 * C/C++ source code generated on : Sat Jan  6 21:34:02 2024
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
#include "rtw_extmode.h"
#include "sysran_types.h"
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

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  ((const char_T **)(&((rtm)->errorStatus)))
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

/* user code (top of header file) */
#include "profile_generator.h"

/* Block signals for system '<S8>/SPI Controller Transfer2' */
typedef struct {
  uint16_T SPIControllerTransfer2;     /* '<S8>/SPI Controller Transfer2' */
} B_SPIControllerTransfer2_main_T;

/* Block states (default storage) for system '<S8>/SPI Controller Transfer2' */
typedef struct {
  stm32cube_blocks_SPIControlle_T obj; /* '<S8>/SPI Controller Transfer2' */
  boolean_T objisempty;                /* '<S8>/SPI Controller Transfer2' */
} DW_SPIControllerTransfer2_mai_T;

/* Block states (default storage) for system '<S14>/MATLAB Function' */
typedef struct {
  int32_T sfEvent;                     /* '<S14>/MATLAB Function' */
  uint8_T is_active_c13_main_STM32_H743_H;/* '<S14>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit;    /* '<S14>/MATLAB Function' */
} DW_MATLABFunction_main_STM32__T;

/* Block states (default storage) for system '<S14>/MATLAB Function1' */
typedef struct {
  int32_T sfEvent;                     /* '<S14>/MATLAB Function1' */
  uint8_T is_active_c14_main_STM32_H743_H;/* '<S14>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit;    /* '<S14>/MATLAB Function1' */
} DW_MATLABFunction1_main_STM32_T;

/* Block signals (default storage) */
typedef struct {
  cell_wrap_0_main_STM32_H743_H_T b[5];
  uint8_T uartWriteData[26];
  cell_wrap_0_main_STM32_H743_H_T b_m;
  cell_wrap_0_main_STM32_H743_H_T c;
  cell_wrap_0_main_STM32_H743_H_T d;
  GPIO_TypeDef * portNameLoc_c;
  boolean_T pinReadArrayLoc[5];
  real32_T vprev;
  real32_T p;
  real32_T temp;
  real32_T flag_tmp;
  real32_T ind1;
  real32_T ind2;
  real32_T f_k;
  real32_T f1;
  real32_T ind1_c;
  real32_T ind2_b;
  real32_T f2;
  real32_T f3;
  real32_T DiscreteTransferFcn3_tmp;
  real32_T cnt1;
  real32_T cnt2;
  int32_T c_p;
  int32_T i;
  int32_T i_c;
  uint32_T count_old;                  /* '<S9>/Unit Delay' */
  uint32_T count_new;                  /* '<S9>/Encoder1' */
  uint32_T AnalogtoDigitalConverter;   /* '<S18>/Analog to Digital Converter' */
  uint32_T AnalogtoDigitalConverter_c; /* '<S16>/Analog to Digital Converter' */
  real32_T DataTypeConversion3;        /* '<Root>/Data Type Conversion3' */
  real32_T v_ist_kmh;                  /* '<Root>/Subsystem' */
  real32_T nMot_1pmin;                 /* '<Root>/Subsystem' */
  real32_T u_ref;                      /* '<Root>/Model' */
  real32_T phi3_M_filt_norm;           /* '<Root>/Model' */
  real32_T i_calc_ext;                 /* '<Root>/Model' */
  real32_T TmpRTBAtMemoryInport1;      /* '<Root>/Model' */
  real32_T a_ist_mps2;                 /* '<Root>/Subsystem' */
  real32_T count_diff_filt;            /* '<Root>/Function-Call Subsystem' */
  real32_T count_diff_filt3;           /* '<Root>/Discrete Transfer Fcn3' */
  real32_T v_ist_kmph_TIM3;            /* '<Root>/Gain9' */
  real32_T v_soll_chart_kmh;           /* '<Root>/Model' */
  real32_T n_Mot1min;                  /* '<S12>/Gain8' */
  real32_T xpp;                        /* '<S12>/Gain3' */
  real32_T Gain13;                     /* '<S12>/Gain13' */
  real32_T A3_filt;                    /* '<Root>/Median Filter2' */
  real32_T t_trigger_tim3_ch1;         /* '<S13>/Gain7' */
  real32_T f_trigger_tim3_ch1_1pmin;   /* '<S13>/Gain' */
  real32_T f;                          /* '<S13>/MATLAB Function1' */
  real32_T count_diff_filt1;           /* '<S9>/MAF_1_order' */
  real32_T count_diff_filt2;           /* '<S9>/MAF_3_order' */
  real32_T raw_angle_deg;              /* '<S8>/Gain' */
  real32_T ped;                        /* '<S8>/Gain2' */
  int32_T count_diff;                  /* '<S13>/MATLAB Function' */
  int32_T count_diff_e;                /* '<S9>/MATLAB Function' */
  uint32_T pinReadLoc;
  uint16_T TimerCapture1;              /* '<S13>/Timer Capture1' */
  uint16_T left_shift_2;               /* '<S8>/Shift Arithmetic1' */
  uint16_T right_shift_2;              /* '<S8>/Shift Arithmetic4' */
  uint8_T PG4_in_Kupplung;
  uint8_T TmpRTBAtMemory1Inport1;      /* '<Root>/Model' */
  uint8_T DataTypeConversion7[5];      /* '<Root>/Data Type Conversion7' */
  uint8_T PG6_in_Bremse;
  uint8_T debug_fcn_state;             /* '<Root>/Model' */
  uint8_T uart_tx_data[26];            /* '<S14>/Byte Pack' */
  uint8_T Product;                     /* '<S14>/Product' */
  uint8_T uart_rx_data;                /* '<S14>/UART//USART Read' */
  uint8_T byte_array[10];              /* '<S14>/MATLAB Function4' */
  GPIO_TypeDef * portNameLoc;
  uint8_T byte_array_a[4];             /* '<S14>/MATLAB Function3' */
  uint8_T byte_array_n[4];             /* '<S14>/MATLAB Function2' */
  uint8_T byte_array_j[4];             /* '<S14>/MATLAB Function1' */
  uint8_T byte_array_e[4];             /* '<S14>/MATLAB Function' */
  boolean_T dir;                       /* '<S9>/Encoder1' */
  boolean_T flag;
  B_SPIControllerTransfer2_main_T SPIControllerTransfer3;/* '<S8>/SPI Controller Transfer2' */
  B_SPIControllerTransfer2_main_T SPIControllerTransfer2;/* '<S8>/SPI Controller Transfer2' */
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
  real32_T DiscreteTransferFcn3_states[2];/* '<Root>/Discrete Transfer Fcn3' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S12>/Discrete-Time Integrator' */
  real32_T MAF_4_order_states[4];      /* '<S13>/MAF_4_order' */
  real32_T MAF_1_order_states;         /* '<S9>/MAF_1_order' */
  real32_T MAF_3_order_states[3];      /* '<S9>/MAF_3_order' */
  int32_T MAF_4_order_circBuf;         /* '<S13>/MAF_4_order' */
  int32_T MAF_3_order_circBuf;         /* '<S9>/MAF_3_order' */
  uint32_T UnitDelay_DSTATE;           /* '<S9>/Unit Delay' */
  real32_T v_ist_kmh_Buffer0;          /* synthesized block */
  real32_T TmpRTBAtModelInport5_Buffer0;/* synthesized block */
  real32_T Memory_PreviousInput;       /* '<Root>/Memory' */
  real32_T Memory2_PreviousInput;      /* '<Root>/Memory2' */
  real32_T TmpRTBAtMemoryInport1_Buffer0;/* synthesized block */
  real32_T TmpRTBAtSubsystemInport1_Buffer;/* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInport;/* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInpo_g;/* synthesized block */
  real32_T xpp_Buffer0;                /* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInp_gk;/* synthesized block */
  real32_T TmpRTBAtdata_exchange_HMIInpo_d;/* synthesized block */
  real32_T count_diff_filt2_Buffer0;   /* synthesized block */
  uint16_T UnitDelay_DSTATE_m;         /* '<S13>/Unit Delay' */
  uint16_T DelayInput1_DSTATE;         /* '<S32>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S14>/Unit Delay' */
  int8_T TriggeredSubsystem1_SubsysRanBC;/* '<Root>/Triggered Subsystem1' */
  int8_T data_exchange_HMI_SubsysRanBC;/* '<Root>/data_exchange_HMI' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  uint8_T TmpRTBAtModelInport7_Buffer0;/* synthesized block */
  uint8_T Memory1_PreviousInput;       /* '<Root>/Memory1' */
  uint8_T TmpRTBAtMemory1Inport1_Buffer0;/* synthesized block */
  uint8_T TmpRTBAtdata_exchange_HMIInpo_c;/* synthesized block */
  uint8_T TmpRTBAtModelInport6_Buffer; /* synthesized block */
  uint8_T is_active_c1_main_STM32_H743_HI;/* '<S13>/MATLAB Function1' */
  uint8_T is_active_c4_main_STM32_H743_HI;/* '<S13>/MATLAB Function' */
  uint8_T is_active_c10_main_STM32_H743_H;/* '<S14>/MATLAB Function4' */
  uint8_T is_active_c3_main_STM32_H743_HI;/* '<S9>/MATLAB Function' */
  boolean_T Memory_PreviousInput_o;    /* '<S38>/Memory' */
  MdlrefDW_ECU_RCP_T Model_InstanceData;/* '<Root>/Model' */
  DW_MATLABFunction_main_STM32__T sf_MATLABFunction3;/* '<S14>/MATLAB Function3' */
  DW_MATLABFunction1_main_STM32_T sf_MATLABFunction2;/* '<S14>/MATLAB Function2' */
  DW_MATLABFunction1_main_STM32_T sf_MATLABFunction1;/* '<S14>/MATLAB Function1' */
  DW_MATLABFunction_main_STM32__T sf_MATLABFunction_d;/* '<S14>/MATLAB Function' */
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
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S8>/Gain'
                                        */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S8>/Gain2'
                                        */
  real32_T MAF_1_order_InitialStates;
                                /* Computed Parameter: MAF_1_order_InitialStates
                                 * Referenced by: '<S9>/MAF_1_order'
                                 */
  real32_T MAF_1_order_Coefficients[2];
                                 /* Computed Parameter: MAF_1_order_Coefficients
                                  * Referenced by: '<S9>/MAF_1_order'
                                  */
  real32_T MAF_3_order_InitialStates;
                                /* Computed Parameter: MAF_3_order_InitialStates
                                 * Referenced by: '<S9>/MAF_3_order'
                                 */
  real32_T MAF_3_order_Coefficients[4];
                                 /* Computed Parameter: MAF_3_order_Coefficients
                                  * Referenced by: '<S9>/MAF_3_order'
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
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S13>/Gain'
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
  real32_T v_ist_kmh_InitialCondition;
                               /* Computed Parameter: v_ist_kmh_InitialCondition
                                * Referenced by:
                                */
  real32_T TmpRTBAtModelInport5_InitialCon;
                          /* Computed Parameter: TmpRTBAtModelInport5_InitialCon
                           * Referenced by:
                           */
  real32_T vst_factor_Value;           /* Computed Parameter: vst_factor_Value
                                        * Referenced by: '<Root>/vst_factor'
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
  real32_T TmpRTBAtMemoryInport1_InitialCo;
                          /* Computed Parameter: TmpRTBAtMemoryInport1_InitialCo
                           * Referenced by:
                           */
  real32_T xpp_InitialCondition;     /* Computed Parameter: xpp_InitialCondition
                                      * Referenced by:
                                      */
  real32_T gear_Value;                 /* Computed Parameter: gear_Value
                                        * Referenced by: '<Root>/gear'
                                        */
  real32_T gradient_relative_Value;
                                  /* Computed Parameter: gradient_relative_Value
                                   * Referenced by: '<Root>/gradient_relative'
                                   */
  real32_T count_diff_filt2_InitialConditi;
                          /* Computed Parameter: count_diff_filt2_InitialConditi
                           * Referenced by:
                           */
  real32_T DiscreteTransferFcn3_InitialSta;
                          /* Computed Parameter: DiscreteTransferFcn3_InitialSta
                           * Referenced by: '<Root>/Discrete Transfer Fcn3'
                           */
  uint32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S9>/Unit Delay'
                                */
  uint16_T Constant2_Value;            /* Expression: 0x4000
                                        * Referenced by: '<S8>/Constant2'
                                        */
  uint16_T Constant3_Value;            /* Expression: 0x3ff5
                                        * Referenced by: '<S8>/Constant3'
                                        */
  uint16_T Constant_Value_i;           /* Expression: 0x4000
                                        * Referenced by: '<S8>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Expression: 0x3ffe
                                        * Referenced by: '<S8>/Constant1'
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
  uint8_T TmpRTBAtModelInport7_InitialCon;
                          /* Computed Parameter: TmpRTBAtModelInport7_InitialCon
                           * Referenced by:
                           */
  uint8_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<Root>/Memory1'
                                  */
  uint8_T TmpRTBAtMemory1Inport1_InitialC;
                          /* Computed Parameter: TmpRTBAtMemory1Inport1_InitialC
                           * Referenced by:
                           */
};

/* Code_Instrumentation_Declarations_Placeholder */

/* Real-time Model Data Structure */
struct tag_RTM_main_STM32_H743_HIL_T {
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
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint32_T clockTick4;
    uint32_T clockTick5;
    struct {
      uint32_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
      boolean_T TID0_3;
      boolean_T TID1_2;
      boolean_T TID1_3;
      boolean_T TID2_3;
      boolean_T TID2_4;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
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
extern real32_T rtP_a_den_stg[2];      /* Variable: a_den_stg
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_a_den_vFzg[3];     /* Variable: a_den_vFzg
                                        * Referenced by: '<Root>/Discrete Transfer Fcn3'
                                        */
extern real32_T rtP_b_num_stg[2];      /* Variable: b_num_stg
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_b_num_vFzg[3];     /* Variable: b_num_vFzg
                                        * Referenced by: '<Root>/Discrete Transfer Fcn3'
                                        */
extern real32_T rtP_cphi;              /* Variable: cphi
                                        * Referenced by: '<Root>/Model'
                                        */
extern real32_T rtP_ks_vel;            /* Variable: ks_vel
                                        * Referenced by: '<Root>/Gain9'
                                        */
extern real32_T rtP_ped_high_deg;      /* Variable: ped_high_deg
                                        * Referenced by: '<S8>/Saturation'
                                        */
extern real32_T rtP_ped_low_deg;       /* Variable: ped_low_deg
                                        * Referenced by:
                                        *   '<S8>/Constant7'
                                        *   '<S8>/Saturation'
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
 * Block '<S12>/Discrete-Time Integrator1' : Unused code path elimination
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
