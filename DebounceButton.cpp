
#include "DebounceButton.h"

bool DebounceButton::uniquePush(){
	if(millis()-lastStateChangeTime < debounceDelay){
    	return false;
    }else{
        if(lastState == 1 && digitalRead(pin) == LOW){
        	lastState = 0;
            lastStateChangeTime = millis();
        	return true;
        }else if(lastState == 0 && digitalRead(pin) == HIGH){
        	lastState = 1;
        	lastStateChangeTime = millis();
        }
        return false;
    }
}
