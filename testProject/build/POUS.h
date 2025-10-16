#include "beremiz.h"
#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

__DECLARE_ENUMERATED_TYPE(LOGLEVEL,
  LOGLEVEL__CRITICAL,
  LOGLEVEL__WARNING,
  LOGLEVEL__INFO,
  LOGLEVEL__DEBUG
)
// FUNCTION_BLOCK LOGGER
// Data part
typedef struct {
  // FB Interface - IN, OUT, IN_OUT variables
  __DECLARE_VAR(BOOL,EN)
  __DECLARE_VAR(BOOL,ENO)
  __DECLARE_VAR(BOOL,TRIG)
  __DECLARE_VAR(STRING,MSG)
  __DECLARE_VAR(LOGLEVEL,LEVEL)

  // FB private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,TRIG0)

} LOGGER;

void LOGGER_init__(LOGGER *data__, BOOL retain);
// Code part
void LOGGER_body__(LOGGER *data__);
// PROGRAM PROGRAM2
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_VAR(BOOL,SWITCH_CONVEYOR)
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_FILL)
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_CAP)
  __DECLARE_VAR(BOOL,BOTTLE_PRESENCE_LABEL)
  __DECLARE_VAR(BOOL,OPTICAL_NECK_SENSOR)
  __DECLARE_VAR(BOOL,STOP_CONVEYOR_FILL)
  __DECLARE_VAR(BOOL,STOP_CONVEYOR_CAP)
  __DECLARE_VAR(BOOL,STOP_CONVEYOR_LABEL)
  __DECLARE_VAR(BOOL,CONVEYOR)
  __DECLARE_VAR(BOOL,FILL)

} PROGRAM2;

void PROGRAM2_init__(PROGRAM2 *data__, BOOL retain);
// Code part
void PROGRAM2_body__(PROGRAM2 *data__);
#endif //__POUS_H
