/*
 * File: dcmoteur.h
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

#ifndef RTW_HEADER_dcmoteur_h_
#define RTW_HEADER_dcmoteur_h_
#include <stddef.h>
#ifndef dcmoteur_COMMON_INCLUDES_
# define dcmoteur_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_PWM.h"
#include "MW_AnalogIn.h"
#endif                                 /* dcmoteur_COMMON_INCLUDES_ */

#include "dcmoteur_types.h"
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

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_int_o_T obj; /* '<Root>/PWM' */
  codertarget_arduinobase_inter_T obj_g;/* '<Root>/Analog Input' */
  j_codertarget_arduinobase_int_T gobj_1;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_2;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_3;/* '<Root>/PWM' */
  j_codertarget_arduinobase_int_T gobj_4;/* '<Root>/PWM' */
} DW_dcmoteur_T;

/* Parameters (default storage) */
struct P_dcmoteur_T_ {
  real_T AnalogInput_SampleTime;       /* Expression: -1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_dcmoteur_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
extern P_dcmoteur_T dcmoteur_P;

/* Block states (default storage) */
extern DW_dcmoteur_T dcmoteur_DW;

/* Model entry point functions */
extern void dcmoteur_initialize(void);
extern void dcmoteur_step(void);
extern void dcmoteur_terminate(void);

/* Real-time Model object */
extern RT_MODEL_dcmoteur_T *const dcmoteur_M;

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
 * '<Root>' : 'dcmoteur'
 */
#endif                                 /* RTW_HEADER_dcmoteur_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
