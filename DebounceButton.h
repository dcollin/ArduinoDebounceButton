
#ifndef DEBOUNCE_BUTTON_H
#define DEBOUNCE_BUTTON_H

#include "Arduino.h"

class DebounceButton{
private:
    uint8_t pin;
    uint8_t debounceDelay;
    unsigned long lastStateChangeTime;
    uint8_t lastState;
    
public:
    DebounceButton(uint8_t pin, bool pullup = true, uint8_t delay = 200){
   	    if(pullup){
	        pinMode(pin, INPUT_PULLUP);
	    }else{
	        pinMode(pin, INPUT);
	    }
	    this->pin = pin;
	    this->debounceDelay = delay;
	    this->lastStateChangeTime = millis();
	    this->lastState = HIGH;
	}
	
    uint8_t getButtonState();
    bool uniquePush();
    
};

#endif