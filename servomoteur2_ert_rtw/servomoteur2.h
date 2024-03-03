/*
 * File: servomoteur2.h
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

#ifndef RTW_HEADER_servomoteur2_h_
#define RTW_HEADER_servomoteur2_h_
#include <stddef.h>
#ifndef servomoteur2_COMMON_INCLUDES_
# define servomoteur2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* servomoteur2_COMMON_INCLUDES_ */

#include "servomoteur2_types.h"
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
  codertarget_arduinobase_inter_T obj; /* '<Root>/PWM' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Input' */
  j_codertarget_arduinobase_int_T gobj_1;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_2;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_3;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_4;/* '<Root>/PWM' */
  real_T Delay_DSTATE;                 /* '<Root>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S1>/Delay Input1' */
} DW_servomoteur2_T;

/* Parameters (default storage) */
struct P_servomoteur2_T_ {
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S1>/Delay Input1'
                                      */
  real_T Constant1_Value;              /* Expression: 255
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<Root>/Delay'
                                        */
  boolean_T Constant_Value_m;          /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S2>/Constant'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_servomoteur2_T {
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
extern P_servomoteur2_T servomoteur2_P;

/* Block states (default storage) */
extern DW_servomoteur2_T servomoteur2_DW;

/* External function called from main */
extern void servomoteur2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void servomoteur2_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void servomoteur2_initialize(void);
extern void servomoteur2_step0(void);
extern void servomoteur2_step1(void);
extern void servomoteur2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_servomoteur2_T *const servomoteur2_M;

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
 * '<Root>' : 'servomoteur2'
 * '<S1>'   : 'servomoteur2/Detect Rise Positive'
 * '<S2>'   : 'servomoteur2/Detect Rise Positive/Positive'
 */
#endif                                 /* RTW_HEADER_servomoteur2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
