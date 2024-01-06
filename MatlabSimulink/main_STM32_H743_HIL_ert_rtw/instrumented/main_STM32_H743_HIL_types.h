/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: main_STM32_H743_HIL_types.h
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

#ifndef RTW_HEADER_main_STM32_H743_HIL_types_h_
#define RTW_HEADER_main_STM32_H743_HIL_types_h_
#include "rtwtypes.h"
#include "mw_stm32_spi_ll.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_2DXLRriZ9wBR741CrBzWmE_
#define DEFINED_TYPEDEF_FOR_struct_2DXLRriZ9wBR741CrBzWmE_

typedef struct {
  real32_T Ts;
  real32_T a_max;
  real32_T j_max;
} struct_2DXLRriZ9wBR741CrBzWmE;

#endif

/* Custom Type definition for MATLABSystem: '<S8>/SPI Controller Transfer2' */
#include "mw_stm32_spi_ll.h"
#include "mw_stm32_spi_ll.h"
#ifndef struct_tag_MSAwd9aJgkV9QRQd4m3y7E
#define struct_tag_MSAwd9aJgkV9QRQd4m3y7E

struct tag_MSAwd9aJgkV9QRQd4m3y7E
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  STM32_SPI_ModuleStruct_T* MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_MSAwd9aJgkV9QRQd4m3y7E */

#ifndef typedef_stm32cube_blocks_SPIControlle_T
#define typedef_stm32cube_blocks_SPIControlle_T

typedef struct tag_MSAwd9aJgkV9QRQd4m3y7E stm32cube_blocks_SPIControlle_T;

#endif                             /* typedef_stm32cube_blocks_SPIControlle_T */

/* Custom Type definition for MATLABSystem: '<S13>/Timer Capture1' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_BAqjeaqOiaF5foOwXEapOH
#define struct_tag_BAqjeaqOiaF5foOwXEapOH

struct tag_BAqjeaqOiaF5foOwXEapOH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_BAqjeaqOiaF5foOwXEapOH */

#ifndef typedef_stm32cube_blocks_TimerCapture_T
#define typedef_stm32cube_blocks_TimerCapture_T

typedef struct tag_BAqjeaqOiaF5foOwXEapOH stm32cube_blocks_TimerCapture_T;

#endif                             /* typedef_stm32cube_blocks_TimerCapture_T */

/* Custom Type definition for MATLABSystem: '<S18>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
#ifndef struct_tag_wiywjhRn0JhvylthmapQgB
#define struct_tag_wiywjhRn0JhvylthmapQgB

struct tag_wiywjhRn0JhvylthmapQgB
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_wiywjhRn0JhvylthmapQgB */

#ifndef typedef_stm32cube_blocks_DigitalPortR_T
#define typedef_stm32cube_blocks_DigitalPortR_T

typedef struct tag_wiywjhRn0JhvylthmapQgB stm32cube_blocks_DigitalPortR_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortR_T */

#ifndef struct_tag_S5MMpcz8vT0FlmhmEl4q5C
#define struct_tag_S5MMpcz8vT0FlmhmEl4q5C

struct tag_S5MMpcz8vT0FlmhmEl4q5C
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_S5MMpcz8vT0FlmhmEl4q5C */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_S5MMpcz8vT0FlmhmEl4q5C stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Custom Type definition for MATLAB Function: '<S14>/MATLAB Function4' */
#ifndef struct_tag_fzY3sKZdip3TqG33WqqO7G
#define struct_tag_fzY3sKZdip3TqG33WqqO7G

struct tag_fzY3sKZdip3TqG33WqqO7G
{
  uint8_T f1[10];
};

#endif                                 /* struct_tag_fzY3sKZdip3TqG33WqqO7G */

#ifndef typedef_cell_wrap_0_main_STM32_H743_H_T
#define typedef_cell_wrap_0_main_STM32_H743_H_T

typedef struct tag_fzY3sKZdip3TqG33WqqO7G cell_wrap_0_main_STM32_H743_H_T;

#endif                             /* typedef_cell_wrap_0_main_STM32_H743_H_T */

#ifndef struct_tag_IuECLTEtq0L5mURmv3mUTH
#define struct_tag_IuECLTEtq0L5mURmv3mUTH

struct tag_IuECLTEtq0L5mURmv3mUTH
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real32_T pWinLen;
  real32_T pBuf[10];
  real32_T pHeap[10];
  real32_T pMidHeap;
  real32_T pIdx;
  real32_T pPos[10];
  real32_T pMinHeapLength;
  real32_T pMaxHeapLength;
};

#endif                                 /* struct_tag_IuECLTEtq0L5mURmv3mUTH */

#ifndef typedef_c_dsp_internal_MedianFilter_c_T
#define typedef_c_dsp_internal_MedianFilter_c_T

typedef struct tag_IuECLTEtq0L5mURmv3mUTH c_dsp_internal_MedianFilter_c_T;

#endif                             /* typedef_c_dsp_internal_MedianFilter_c_T */

#ifndef struct_tag_KT387TO2So4uk2kI2Lbb3C
#define struct_tag_KT387TO2So4uk2kI2Lbb3C

struct tag_KT387TO2So4uk2kI2Lbb3C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_KT387TO2So4uk2kI2Lbb3C */

#ifndef typedef_stm32cube_blocks_UARTRead_mai_T
#define typedef_stm32cube_blocks_UARTRead_mai_T

typedef struct tag_KT387TO2So4uk2kI2Lbb3C stm32cube_blocks_UARTRead_mai_T;

#endif                             /* typedef_stm32cube_blocks_UARTRead_mai_T */

#ifndef struct_tag_K5QCAuLh2FF8FsZmLWzJxB
#define struct_tag_K5QCAuLh2FF8FsZmLWzJxB

struct tag_K5QCAuLh2FF8FsZmLWzJxB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_K5QCAuLh2FF8FsZmLWzJxB */

#ifndef typedef_stm32cube_blocks_UARTWrite_ma_T
#define typedef_stm32cube_blocks_UARTWrite_ma_T

typedef struct tag_K5QCAuLh2FF8FsZmLWzJxB stm32cube_blocks_UARTWrite_ma_T;

#endif                             /* typedef_stm32cube_blocks_UARTWrite_ma_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_main_STM32_H743_HIL_T
#define typedef_cell_wrap_main_STM32_H743_HIL_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_main_STM32_H743_HIL_T;

#endif                             /* typedef_cell_wrap_main_STM32_H743_HIL_T */

#ifndef struct_tag_nJDWLJcITUG6sTG8JTIHYE
#define struct_tag_nJDWLJcITUG6sTG8JTIHYE

struct tag_nJDWLJcITUG6sTG8JTIHYE
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
};

#endif                                 /* struct_tag_nJDWLJcITUG6sTG8JTIHYE */

#ifndef typedef_stm32cube_blocks_AnalogInputF_T
#define typedef_stm32cube_blocks_AnalogInputF_T

typedef struct tag_nJDWLJcITUG6sTG8JTIHYE stm32cube_blocks_AnalogInputF_T;

#endif                             /* typedef_stm32cube_blocks_AnalogInputF_T */

#ifndef struct_tag_mG5etVnwn6ERPOSPnk7tJ
#define struct_tag_mG5etVnwn6ERPOSPnk7tJ

struct tag_mG5etVnwn6ERPOSPnk7tJ
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_main_STM32_H743_HIL_T inputVarSize;
  int32_T NumChannels;
  c_dsp_internal_MedianFilter_c_T pMID;
};

#endif                                 /* struct_tag_mG5etVnwn6ERPOSPnk7tJ */

#ifndef typedef_dsp_simulink_MedianFilter_mai_T
#define typedef_dsp_simulink_MedianFilter_mai_T

typedef struct tag_mG5etVnwn6ERPOSPnk7tJ dsp_simulink_MedianFilter_mai_T;

#endif                             /* typedef_dsp_simulink_MedianFilter_mai_T */

#ifndef struct_tag_c6vUyHR5f8xkCafg9uVRGF
#define struct_tag_c6vUyHR5f8xkCafg9uVRGF

struct tag_c6vUyHR5f8xkCafg9uVRGF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_c6vUyHR5f8xkCafg9uVRGF */

#ifndef typedef_stm32cube_blocks_EncoderBlock_T
#define typedef_stm32cube_blocks_EncoderBlock_T

typedef struct tag_c6vUyHR5f8xkCafg9uVRGF stm32cube_blocks_EncoderBlock_T;

#endif                             /* typedef_stm32cube_blocks_EncoderBlock_T */

#ifndef struct_tag_C3ug75osl8w3UN1OXa3ipB
#define struct_tag_C3ug75osl8w3UN1OXa3ipB

struct tag_C3ug75osl8w3UN1OXa3ipB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_C3ug75osl8w3UN1OXa3ipB */

#ifndef typedef_stm32cube_blocks_PWMOutput_ma_T
#define typedef_stm32cube_blocks_PWMOutput_ma_T

typedef struct tag_C3ug75osl8w3UN1OXa3ipB stm32cube_blocks_PWMOutput_ma_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_ma_T */

/* Parameters (default storage) */
typedef struct P_main_STM32_H743_HIL_T_ P_main_STM32_H743_HIL_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_main_STM32_H743_HIL_T RT_MODEL_main_STM32_H743_HIL_T;

#endif                             /* RTW_HEADER_main_STM32_H743_HIL_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
