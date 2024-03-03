/*
 * File: led.h
 *
 * Code generated for Simulink model 'led'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Oct 24 11:44:21 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_led_h_
#define RTW_HEADER_led_h_
#include <math.h>
#include <stddef.h>
#ifndef led_COMMON_INCLUDES_
# define led_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* led_COMMON_INCLUDES_ */

#include "led_types.h"
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
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Output' */
  real_T Delay_DSTATE;                 /* '<S1>/Delay' */
} DW_led_T;

/* Parameters (default storage) */
struct P_led_T_ {
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S1>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_led_T {
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
extern P_led_T led_P;

/* Block states (default storage) */
extern DW_led_T led_DW;

/* External function called from main */
extern void led_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void led_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void led_initialize(void);
extern void led_step0(void);
extern void led_step1(void);
extern void led_terminate(void);

/* Real-time Model object */
extern RT_MODEL_led_T *const led_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
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
 * '<Root>' : 'led'
 * '<S1>'   : 'led/Subsystem'
 */
#endif                                 /* RTW_HEADER_led_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
