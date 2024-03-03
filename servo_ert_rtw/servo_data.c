/*
 * File: servo_data.c
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

#include "servo.h"
#include "servo_private.h"

/* Block parameters (default storage) */
P_servo_T servo_P = {
  /* Mask Parameter: RepeatingSequenceStair_OutValue
   * Referenced by: '<S1>/Vector'
   */
  { 0.0, 180.0 },

  /* Mask Parameter: LimitedCounter_uplimit
   * Referenced by: '<S4>/FixPt Switch'
   */
  1U,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S4>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S2>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S3>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
