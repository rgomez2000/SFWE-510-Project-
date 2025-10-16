void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM2_init__(PROGRAM2 *data__, BOOL retain) {
  __INIT_VAR(data__->SWITCH_CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_PRESENCE_FILL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_PRESENCE_CAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOTTLE_PRESENCE_LABEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->OPTICAL_NECK_SENSOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_CONVEYOR_FILL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_CONVEYOR_CAP,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->STOP_CONVEYOR_LABEL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CONVEYOR,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->FILL,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM2_body__(PROGRAM2 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,STOP_CONVEYOR_CAP,,__GET_VAR(data__->BOTTLE_PRESENCE_CAP,));
  __SET_VAR(data__->,STOP_CONVEYOR_FILL,,__GET_VAR(data__->BOTTLE_PRESENCE_FILL,));
  __SET_VAR(data__->,STOP_CONVEYOR_LABEL,,__GET_VAR(data__->BOTTLE_PRESENCE_LABEL,));
  if (((__GET_VAR(data__->STOP_CONVEYOR_CAP,) || __GET_VAR(data__->STOP_CONVEYOR_FILL,)) || __GET_VAR(data__->STOP_CONVEYOR_LABEL,))) {
    __SET_VAR(data__->,CONVEYOR,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->SWITCH_CONVEYOR,)) {
    __SET_VAR(data__->,CONVEYOR,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->,FILL,,(__GET_VAR(data__->BOTTLE_PRESENCE_FILL,) && __GET_VAR(data__->OPTICAL_NECK_SENSOR,)));
  if (!(__GET_VAR(data__->SWITCH_CONVEYOR,))) {
    __SET_VAR(data__->,CONVEYOR,,__BOOL_LITERAL(FALSE));
  };

  goto __end;

__end:
  return;
} // PROGRAM2_body__() 





