# midicontroller_line6
Control Line6 Pod with Arduino.

## 


## Übertragungsprotokoll
Es werden drei Bytes über den Pin 1(TX) an den Pod übertragen. Die Übertragungsgeschwindigkeit ist 32250

| Status-Byte | Data-Byte       | Data-Byte     |
| ----------- | --------------- | ------------- |
| Midi-Befehl | Controller (CC) | Wert (0-127)  |
| 1 001 0000  | 00000000        | 00000000      |
  
Der Midi-Befehl besteht:

| 1           | 011       | 0000       |
| ----------- | --------- | ---------- |
| Status-Bit  | Befehlart | Midi-Kanal |

Es gibt acht Befehlsarten. Davon sind aber nur zwei Relevant. 

| Befehl        | Byte       | Dec |      
| ------------- | ---------- | --- |
| ProgramChange | 1 100 0000 | 192 |
| ControlChange | 1 011 0000 | 176 |

##  Controller


/* Program Change   1    0 - 127             */
/* Stomp            25   0 / 127             */
/* Mod              50   0 / 127             */
/* Delay            28   0 / 127             */
