#ifndef DEBOUNCE_BUTTON_H
#define DEBOUNCE_BUTTON_H

#include "Arduino.h"

class DebounceButton {

public:
    /**
    * Constructor
    * @arg mode - The preferred pin mode (default = INPUT_PULLUP)
    * @arg push - The state if the digital pin that represents a "push" state (LOW/HIGH)
    * @arg delay - The debounce delay used for thsi button
    */
    DebounceButton(uint8_t pin, uint8_t mode = INPUT_PULLUP, bool push = LOW, uint8_t delay = 200);
    
    /**
    * @return - True if the button is pushed, else false
    */
    bool getPush();
    
    /**
    * @return - True if the button is released, else false
    */
    bool getRelease();
    
    /**
    * @return - The current button state (LOW/HIGH)
    */
    bool getButtonState();
    
private:

    /**
    * @return - True if the state has changed of the digital pin, else false
    */
    bool isStateChanged(const bool pinState);
    
    //Private Instance Variables:
    uint8_t pin;                  //The digital pin used by the button
    uint8_t debounceDelay;              //The time between each button state change that is ignored as a precaution to avoid bouncing
    unsigned long lastStateChangeTime;  //The time (in millis) when the last pin state changed
    bool lastState;                     //The last known state of the button pin
    bool pushState;                     //The state of the button pin that is recognized as a push motion
};

#endif  //DEBOUNCE_BUTTON_H