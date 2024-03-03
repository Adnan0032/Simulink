/*
 * File: stateflow4.h
 *
 * Code generated for Simulink model 'stateflow4'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec  5 11:36:40 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_stateflow4_h_
#define RTW_HEADER_stateflow4_h_
#include <stddef.h>
#ifndef stateflow4_COMMON_INCLUDES_
# define stateflow4_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_arduino_digitalio.h"
#endif                                 /* stateflow4_COMMON_INCLUDES_ */

#include "stateflow4_types.h"
#include "MW_target_hardware_resources.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"

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
  codertarget_arduinobase_blo_h_T obj_n;/* '<Root>/Digital Input' */
  codertarget_arduinobase_blo_h_T obj_j;/* '<Root>/Digital Input1' */
  j_codertarget_arduinobase_int_T gobj_1;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_2;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_3;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_4;/* '<Root>/PWM' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output' */
  codertarget_arduinobase_block_T obj_hy;/* '<Root>/Digital Output1' */
  uint8_T is_active_c3_stateflow4;     /* '<Root>/Chart' */
  uint8_T is_c3_stateflow4;            /* '<Root>/Chart' */
  uint8_T is_power;                    /* '<Root>/Chart' */
} DW_stateflow4_T;

/* Parameters (default storage) */
struct P_stateflow4_T_ {
  real_T DigitalInput1_SampleTime;     /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input1'
                                        */
  real_T DigitalInput_SampleTime;      /* Expression: 0.1
                                        * Referenced by: '<Root>/Digital Input'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_stateflow4_T {
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
extern P_stateflow4_T stateflow4_P;

/* Block states (default storage) */
extern DW_stateflow4_T stateflow4_DW;

/* External function called from main */
extern void stateflow4_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void stateflow4_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void stateflow4_initialize(void);
extern void stateflow4_step0(void);
extern void stateflow4_step1(void);
extern void stateflow4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_stateflow4_T *const stateflow4_M;

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
 * '<Root>' : 'stateflow4'
 * '<S1>'   : 'stateflow4/Chart'
 */
#endif                                 /* RTW_HEADER_stateflow4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
