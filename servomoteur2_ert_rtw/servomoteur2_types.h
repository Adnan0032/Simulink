/*
 * File: servomoteur2_types.h
 *
 * Code generated for Simulink model 'servomoteur2'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Nov  7 11:24:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_servomoteur2_types_h_
#define RTW_HEADER_servomoteur2_types_h_
#include "rtwtypes.h"

/* Model Code Variants */

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_E7ZjpEHEQzzHgi4oOkm0RC
#define struct_tag_E7ZjpEHEQzzHgi4oOkm0RC

struct tag_E7ZjpEHEQzzHgi4oOkm0RC
{
  int16_T __dummy;
};

#endif                                 /*struct_tag_E7ZjpEHEQzzHgi4oOkm0RC*/

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_E7ZjpEHEQzzHgi4oOkm0RC b_arduinodriver_ArduinoDigita_T;

#endif                               /*typedef_b_arduinodriver_ArduinoDigita_T*/

#ifndef struct_tag_s24Tu6ETtsZe5SOuhjxVUG
#define struct_tag_s24Tu6ETtsZe5SOuhjxVUG

struct tag_s24Tu6ETtsZe5SOuhjxVUG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
  real_T SampleTime;
};

#endif                                 /*struct_tag_s24Tu6ETtsZe5SOuhjxVUG*/

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_s24Tu6ETtsZe5SOuhjxVUG codertarget_arduinobase_block_T;

#endif                               /*typedef_codertarget_arduinobase_block_T*/

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

#ifndef typedef_cell_servomoteur2_T
#define typedef_cell_servomoteur2_T

typedef struct tag_GtaT2TPu8wQVLKHBwLo3ME cell_servomoteur2_T;

#endif                                 /*typedef_cell_servomoteur2_T*/

#ifndef struct_tag_O2Hap3tiAr1xYyd5SB7jqH
#define struct_tag_O2Hap3tiAr1xYyd5SB7jqH

struct tag_O2Hap3tiAr1xYyd5SB7jqH
{
  cell_servomoteur2_T AvailablePwmPinNames;
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

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_ZksrEzekLFp3nSi7noWstB codertarget_arduinobase_inter_T;

#endif                               /*typedef_codertarget_arduinobase_inter_T*/

/* Parameters (default storage) */
typedef struct P_servomoteur2_T_ P_servomoteur2_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_servomoteur2_T RT_MODEL_servomoteur2_T;

#endif                                 /* RTW_HEADER_servomoteur2_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
