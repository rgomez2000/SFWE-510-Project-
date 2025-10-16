PROGRAM program2
  VAR
    Switch_Conveyor AT %IX2.0 : BOOL;
    Bottle_Presence_Fill AT %IX2.1 : BOOL;
    Bottle_Presence_Cap AT %IX2.2 : BOOL;
    Bottle_Presence_Label AT %IX2.3 : BOOL;
    Optical_Neck_Sensor AT %IX2.4 : BOOL;
    Stop_Conveyor_Fill AT %MX2.0 : BOOL;
    Stop_Conveyor_Cap AT %MX2.1 : BOOL;
    Stop_Conveyor_Label AT %MX2.2 : BOOL;
    Conveyor AT %QX2.0 : BOOL;
    Fill AT %QX2.1 : BOOL;
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
