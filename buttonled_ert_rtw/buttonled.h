/*
 * File: buttonled.h
 *
 * Code generated for Simulink model 'buttonled'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Oct 24 12:13:12 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_buttonled_h_
#define RTW_HEADER_buttonled_h_
#include <math.h>
#include <stddef.h>
#ifndef buttonled_COMMON_INCLUDES_
# define buttonled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* buttonled_COMMON_INCLUDES_ */

#include "buttonled_types.h"
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
  codertarget_arduinobase_blo_l_T obj; /* '<Root>/Digital Input' */
  codertarget_arduinobase_block_T obj_g;/* '<Root>/Digital Output' */
  boolean_T Delay_DSTATE;              /* '<S2>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S5>/Delay Input1' */
} DW_buttonled_T;

/* Parameters (default storage) */
struct P_buttonled_T_ {
  boolean_T DetectRisePositive_vinit;/* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S5>/Delay Input1'
                                      */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  boolean_T Constant_Value_j;          /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S6>/Constant'
                                        */
  boolean_T Delay_InitialCondition;/* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_buttonled_T {
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
extern P_buttonled_T buttonled_P;

/* Block states (default storage) */
extern DW_buttonled_T buttonled_DW;

/* External function called from main */
extern void buttonled_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void buttonled_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void buttonled_initialize(void);
extern void buttonled_step0(void);
extern void buttonled_step1(void);
extern void buttonled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_buttonled_T *const buttonled_M;

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
 * '<Root>' : 'buttonled'
 * '<S1>'   : 'buttonled/Convertion'
 * '<S2>'   : 'buttonled/Subsystem'
 * '<S3>'   : 'buttonled/Convertion/If Action Subsystem'
 * '<S4>'   : 'buttonled/Convertion/If Action Subsystem1'
 * '<S5>'   : 'buttonled/Subsystem/Detect Rise Positive'
 * '<S6>'   : 'buttonled/Subsystem/Detect Rise Positive/Positive'
 */
#endif                                 /* RTW_HEADER_buttonled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
