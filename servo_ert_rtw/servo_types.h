/*
 * File: servo_types.h
 *
 * Code generated for Simulink model 'servo'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 08:34:22 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_servo_types_h_
#define RTW_HEADER_servo_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_GtaT2TPu8wQVLKHBwLo3ME
#define struct_tag_GtaT2TPu8wQVLKHBwLo3ME

struct tag_GtaT2TPu8wQVLKHBwLo3ME
{
  char_T f1;
  char_T f2;
  char_T f3;
  char_T f4;
  char_T f5;
  char_T f6;
  char_T f7;
  char_T f8;
  char_T f9[2];
  char_T f10[2];
  char_T f11[2];
  char_T f12[2];
};

#endif                                 /*struct_tag_GtaT2TPu8wQVLKHBwLo3ME*/

#ifndef typedef_cell_servo_T
#define typedef_cell_servo_T

typedef struct tag_GtaT2TPu8wQVLKHBwLo3ME cell_servo_T;

#endif                                 /*typedef_cell_servo_T*/

#ifndef struct_tag_O2Hap3tiAr1xYyd5SB7jqH
#define struct_tag_O2Hap3tiAr1xYyd5SB7jqH

struct tag_O2Hap3tiAr1xYyd5SB7jqH
{
  cell_servo_T AvailablePwmPinNames;
};

#endif                                 /*struct_tag_O2Hap3tiAr1xYyd5SB7jqH*/

#ifndef typedef_i_codertarget_arduinobase_int_T
#define typedef_i_codertarget_arduinobase_int_T

typedef struct tag_O2Hap3tiAr1xYyd5SB7jqH i_codertarget_arduinobase_int_T;

#endif                               /*typedef_i_codertarget_arduinobase_int_T*/

#ifndef struct_tag_mpp1zrYKkiJ3gUUTqSUOmD
#define struct_tag_mpp1zrYKkiJ3gUUTqSUOmD

struct tag_mpp1zrYKkiJ3gUUTqSUOmD
{
  int32_T isInitialized;
  i_codertarget_arduinobase_int_T *Hw;
};

#endif                                 /*struct_tag_mpp1zrYKkiJ3gUUTqSUOmD*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_mpp1zrYKkiJ3gUUTqSUOmD codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (default storage) */
typedef struct P_servo_T_ P_servo_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_servo_T RT_MODEL_servo_T;

#endif                                 /* RTW_HEADER_servo_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
