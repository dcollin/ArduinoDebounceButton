#ifndef DEBOUNCE_BUTTON_H
#define DEBOUNCE_BUTTON_H

#include "Arduino.h"

#define DEAFULT_INPUT               INPUT_PULLUP
#define DEFAULT_PUSH_MOTION         LOW
#define DEAFULT_DEBOUNCE_DELAY      200

class DebounceButton {

public:

    /**
    * Constructor
    * @arg mode - The preferred pin mode (default = INPUT_PULLUP)
    * @arg push - The state if the digital pin that represents a "push" state (LOW/HIGH) (default = LOW)
    * @arg delay - The debounce delay used for this button (default = 200ms)
    */
    DebounceButton(uint8_t pin, uint8_t mode = DEAFULT_INPUT, bool push = DEFAULT_PUSH_MOTION, uint8_t delay = DEAFULT_DEBOUNCE_DELAY);
    
    /**
    * @return - True if the button is pushed, else false
    */
    bool getPush();
    
private:

    /**
    * @return - True if the state has changed of the digital pin, else false
    */
    bool isStateChanged(const bool pinState);
    
    //Private Instance Variables:
    const uint8_t pin;                  //The digital pin used by the button
    uint8_t debounceDelay;              //The time between each button state change that is ignored as a precaution to avoid bouncing
    unsigned long lastStateChangeTime;  //The time (in millis) when the last pin state changed
    bool lastState;                     //The last known state of the button pin
    bool pushState;                     //The state of the button pin that is recognized as a push motion
    
};

#endif  //DEBOUNCE_BUTTON_H