/*
 * File: dcmoteur_types.h
 *
 * Code generated for Simulink model 'dcmoteur'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 11:30:06 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_dcmoteur_types_h_
#define RTW_HEADER_dcmoteur_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<Root>/Analog Input' */
#include "MW_SVD.h"
#ifndef struct_tag_Gc8EcsaAa6B4PVRJCSARvB
#define struct_tag_Gc8EcsaAa6B4PVRJCSARvB

struct tag_Gc8EcsaAa6B4PVRJCSARvB
{
  MW_Handle_Type MW_ANALOGIN_HANDLE;
};

#endif                                 /*struct_tag_Gc8EcsaAa6B4PVRJCSARvB*/

#ifndef typedef_f_arduinodriver_ArduinoAnalog_T
#define typedef_f_arduinodriver_ArduinoAnalog_T

typedef struct tag_Gc8EcsaAa6B4PVRJCSARvB f_arduinodriver_ArduinoAnalog_T;

#endif                               /*typedef_f_arduinodriver_ArduinoAnalog_T*/

#ifndef struct_tag_IH4ZAEwYd2ouei4lGVnLsG
#define struct_tag_IH4ZAEwYd2ouei4lGVnLsG

struct tag_IH4ZAEwYd2ouei4lGVnLsG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_arduinodriver_ArduinoAnalog_T AnalogInDriverObj;
  real_T SampleTime;
};

#endif                                 /*struct_tag_IH4ZAEwYd2ouei4lGVnLsG*/

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_IH4ZAEwYd2ouei4lGVnLsG codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

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

#ifndef typedef_cell_dcmoteur_T
#define typedef_cell_dcmoteur_T

typedef struct tag_GtaT2TPu8wQVLKHBwLo3ME cell_dcmoteur_T;

#endif                                 /*typedef_cell_dcmoteur_T*/

#ifndef struct_tag_O2Hap3tiAr1xYyd5SB7jqH
#define struct_tag_O2Hap3tiAr1xYyd5SB7jqH

struct tag_O2Hap3tiAr1xYyd5SB7jqH
{
  cell_dcmoteur_T AvailablePwmPinNames;
};

#endif                                 /*struct_tag_O2Hap3tiAr1xYyd5SB7jqH*/

#ifndef typedef_j_codertarget_arduinobase_int_T
#define typedef_j_codertarget_arduinobase_int_T

typedef struct tag_O2Hap3tiAr1xYyd5SB7jqH j_codertarget_arduinobase_int_T;

#endif                               /*typedef_j_codertarget_arduinobase_int_T*/

#ifndef struct_tag_ZksrEzekLFp3nSi7noWstB
#define struct_tag_ZksrEzekLFp3nSi7noWstB

struct tag_ZksrEzekLFp3nSi7noWstB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  j_codertarget_arduinobase_int_T *Hw;
  MW_Handle_Type MW_PWM_HANDLE;
  uint32_T PinPWM;
};

#endif                                 /*struct_tag_ZksrEzekLFp3nSi7noWstB*/

#ifndef typedef_codertarget_arduinobase_int_o_T
#define typedef_codertarget_arduinobase_int_o_T

typedef struct tag_ZksrEzekLFp3nSi7noWstB codertarget_arduinobase_int_o_T;

#endif                               /*typedef_codertarget_arduinobase_int_o_T*/

/* Parameters (default storage) */
typedef struct P_dcmoteur_T_ P_dcmoteur_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_dcmoteur_T RT_MODEL_dcmoteur_T;

#endif                                 /* RTW_HEADER_dcmoteur_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
