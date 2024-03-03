/*
 * stateflow3_dt.h
 *
 * Code generation for model "stateflow3".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C source code generated on : Tue Dec  5 09:29:33 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(codertarget_arduinobase_inter_T),
  sizeof(codertarget_arduinobase_block_T),
  sizeof(codertarget_arduinobase_int_b_T),
  sizeof(j_codertarget_arduinobase_int_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "codertarget_arduinobase_inter_T",
  "codertarget_arduinobase_block_T",
  "codertarget_arduinobase_int_b_T",
  "j_codertarget_arduinobase_int_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&stateflow3_B.AnalogInput), 5, 0, 1 }
  ,

  { (char_T *)(&stateflow3_DW.obj), 16, 0, 1 },

  { (char_T *)(&stateflow3_DW.obj_j), 14, 0, 1 },

  { (char_T *)(&stateflow3_DW.gobj_1), 17, 0, 4 },

  { (char_T *)(&stateflow3_DW.obj_b), 15, 0, 3 },

  { (char_T *)(&stateflow3_DW.is_c3_stateflow3), 7, 0, 1 },

  { (char_T *)(&stateflow3_DW.is_active_c3_stateflow3), 3, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  7U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&stateflow3_P.AnalogInput_SampleTime), 0, 0, 1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  1U,
  rtPTransitions
};

/* [EOF] stateflow3_dt.h */
