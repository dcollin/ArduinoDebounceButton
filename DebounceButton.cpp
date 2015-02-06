#include "DebounceButton.h"
#include "limits.h"

DebounceButton::DebounceButton(uint8_t pin, uint8_t mode, bool push, uint8_t delay) : pin(pin), debounceDelay(delay), lastStateChangeTime(millis()), lastState(!push), pushState(push) {    
    pinMode(pin, mode);
}

bool DebounceButton::getPush(){
    const bool pinState = digitalRead(pin);
    return isStateChanged(pinState) && (pinState == pushState);
}

bool DebounceButton::getRelease(){
    const bool pinState = digitalRead(pin);
    return isStateChanged(pinState) && (pinState != pushState);
}

bool DebounceButton::getButtonState(){
    const bool pinState = digitalRead(pin);
    if(isStateChanged(pinState)){
        return pinState;
    }else{
        return lastState;
    }
}

bool DebounceButton::isStateChanged(const bool pinState){
    bool timeToReadNewValue = false;
    
    //Implementing debouce functionality by ignoring all changes that happens {this->debounceDelay}ms after the last pin state change.
    const unsigned long currentTime = millis();
    if(currentTime > lastStateChangeTime){
        //normal case where there have been some time since last call
        timeToReadNewValue = ( currentTime-lastStateChangeTime > debounceDelay );
    }else if(currentTime < lastStateChangeTime){
        //special case when the millis timer has done a overflow since last call
        timeToReadNewValue = ( (ULONG_MAX-lastStateChangeTime)+currentTime > debounceDelay );
    }else{
        //time is unchanged since last call
        return false;
    }
    
    if( timeToReadNewValue && (pinState != lastState) ){
        lastState = pinState;
        lastStateChangeTime = currentTime;
        return true;
    }
    
    return false;
}
