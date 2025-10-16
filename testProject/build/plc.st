TYPE
  LOGLEVEL : (CRITICAL, WARNING, INFO, DEBUG) := INFO;
END_TYPE

FUNCTION_BLOCK LOGGER
  VAR_INPUT
    TRIG : BOOL;
    MSG : STRING;
    LEVEL : LOGLEVEL := INFO;
  END_VAR
  VAR
    TRIG0 : BOOL;
  END_VAR

  IF TRIG AND NOT TRIG0 THEN
  {{
   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  }}
  END_IF;
  TRIG0:=TRIG;
END_FUNCTION_BLOCK


PROGRAM program2
  VAR
    Switch_Conveyor : BOOL;
    Bottle_Presence_Fill : BOOL;
    Bottle_Presence_Cap : BOOL;
    Bottle_Presence_Label : BOOL;
    Optical_Neck_Sensor : BOOL;
    Stop_Conveyor_Fill : BOOL;
    Stop_Conveyor_Cap : BOOL;
    Stop_Conveyor_Label : BOOL;
    Conveyor : BOOL;
    Fill : BOOL;
  END_VAR

  Stop_Conveyor_Cap := Bottle_Presence_Cap;
  Stop_Conveyor_Fill := Bottle_Presence_Fill;
  Stop_Conveyor_Label := Bottle_Presence_Label;
  IF Stop_Conveyor_Cap OR Stop_Conveyor_Fill OR Stop_Conveyor_Label THEN
    Conveyor := FALSE; (*reset*)
  END_IF;
  IF Switch_Conveyor THEN
    Conveyor := TRUE; (*set*)
  END_IF;
  Fill := Bottle_Presence_Fill AND Optical_Neck_Sensor;
  IF NOT(Switch_Conveyor) THEN
    Conveyor := FALSE; (*reset*)
  END_IF;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program2;
  END_RESOURCE
END_CONFIGURATION
