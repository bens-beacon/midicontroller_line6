/* MIDISEND.h
 * Send MidiSignals to Line6 Pod. TX-Pin will be used!
 *
 */

#ifndef MIDISEND_H
#define MIDISEND_H

#include "Arduino.h"

class MIDISEND
{
  public:
  	MIDISEND();
		void next(int);
		void prev(int);
		void change(int,int);
		void changestep(int,int,int);
		void turn(int,int);
	private:
		int State=0;
		int State1=0;
		int State2=0;
		int Value=0;
		int Prog=1;
};

MIDISEND::MIDISEND(){
	
}


void MIDISEND::turn(int CC, int MIDIVALUE){
	if(MIDIVALUE == 0 && MIDIVALUE == State){
		Serial.write(176); 
		Serial.write(CC); 
		Serial.write(127);
		State = -1;
  } 
	if(MIDIVALUE == -1 && MIDIVALUE == State){
		Serial.write(176); 
		Serial.write(CC); 
		Serial.write(0);
		State = ~State;
  }   
}

void MIDISEND::change(int CC, int MIDIVALUE){
	int a = Value-2;
	int b = Value+2;	
	if(MIDIVALUE < a || MIDIVALUE > b){
		Serial.write(176); 
		Serial.write(CC); 
		Serial.write(MIDIVALUE);
		//Serial.print(CC, DEC); 
		//Serial.print(" -> ");
		//Serial.println(MIDIVALUE,DEC); 
		Value = MIDIVALUE;
		delay(10);
	}
}

void MIDISEND::changestep(int CC, int MIDIVALUE, int step){
	int a = Value-2;
	int b = Value+2;	
	if(MIDIVALUE < a || MIDIVALUE > b){
		Serial.write(176); 
		Serial.write(CC); 
		Serial.write(MIDIVALUE/step);
		//Serial.print(CC, DEC); 
		//Serial.print(" -> ");
		//Serial.println(MIDIVALUE/step,DEC); 
		Value = MIDIVALUE;
		delay(10);
	}
}

void MIDISEND::next(int BUTTON){
	if(BUTTON == 0 && BUTTON == State1){
		Prog +=4;
		Serial.write(192); 
		Serial.write(1); 
		Serial.write(Prog);
		State1 = -1;
  } 
 	if(BUTTON == -1 && BUTTON == State1){
		Prog +=4;
		Serial.write(192); 
		Serial.write(1); 
		Serial.write(Prog);
		State1 = ~State1;	
	} 
}
void MIDISEND::prev(int BUTTON){
	if(BUTTON == 0 && BUTTON == State2){
		Prog -=4;
		Serial.write(192); 
		Serial.write(1); 
		Serial.write(Prog);
		State2 = -1;
  } 
 	if(BUTTON == -1 && BUTTON == State2){
		Prog -=4;
		Serial.write(192); 
		Serial.write(1); 
		Serial.write(Prog);
		State2 = ~State2;	
	} 
}



#endif
