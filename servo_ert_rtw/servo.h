/*
 * File: servo.h
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

#ifndef RTW_HEADER_servo_h_
#define RTW_HEADER_servo_h_
#include <math.h>
#include <stddef.h>
#ifndef servo_COMMON_INCLUDES_
# define servo_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_ServoWriteRead.h"
#endif                                 /* servo_COMMON_INCLUDES_ */

#include "servo_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_1;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_2;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_3;/* '<Root>/Standard Servo Write' */
  i_codertarget_arduinobase_int_T gobj_4;/* '<Root>/Standard Servo Write' */
  uint8_T Output_DSTATE;               /* '<S2>/Output' */
} DW_servo_T;

/* Parameters (default storage) */
struct P_servo_T_ {
  real_T RepeatingSequenceStair_OutValue[2];
                              /* Mask Parameter: RepeatingSequenceStair_OutValue
                               * Referenced by: '<S1>/Vector'
                               */
  uint8_T LimitedCounter_uplimit;      /* Mask Parameter: LimitedCounter_uplimit
                                        * Referenced by: '<S4>/FixPt Switch'
                                        */
  uint8_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T Output_InitialCondition;/* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S2>/Output'
                                   */
  uint8_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S3>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_servo_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_servo_T servo_P;

/* Block states (default storage) */
extern DW_servo_T servo_DW;

/* External function called from main */
extern void servo_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void servo_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void servo_initialize(void);
extern void servo_step0(void);
extern void servo_step1(void);
extern void servo_terminate(void);

/* Real-time Model object */
extern RT_MODEL_servo_T *const servo_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S1>/Out' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'servo'
 * '<S1>'   : 'servo/Repeating Sequence Stair'
 * '<S2>'   : 'servo/Repeating Sequence Stair/LimitedCounter'
 * '<S3>'   : 'servo/Repeating Sequence Stair/LimitedCounter/Increment Real World'
 * '<S4>'   : 'servo/Repeating Sequence Stair/LimitedCounter/Wrap To Zero'
 */
#endif                                 /* RTW_HEADER_servo_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
