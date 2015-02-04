#include "DebounceButton.h"

DebounceButton::DebounceButton(uint8_t pin, uint8_t mode, bool push, uint8_t delay) : pin(pin), debounceDelay(delay), lastStateChangeTime(millis()), lastState(!push), pushState(push) {    
    pinMode(pin, mode);
}

bool DebounceButton::getPush(){
    bool pinState = digitalRead(pin);
    return isStateChanged(pinState) && (pinState == pushState);
}

bool DebounceButton::getRelease(){
    bool pinState = digitalRead(pin);
    return isStateChanged(pinState) && (pinState != pushState);
}

bool DebounceButton::getButtonState(){
    bool pinState = digitalRead(pin);
    isStateChanged(pinState);
    return lastState;
}

bool DebounceButton::isStateChanged(const bool pinState){
    if( (millis()-lastStateChangeTime > debounceDelay) && (pinState != lastState) ){
        lastState = pinState;
        lastStateChangeTime = millis();
        return true;
    }
    return false;
}
