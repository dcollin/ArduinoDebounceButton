#include "DebounceButton.h"

/********************************************************************
*                                                                   *
*    Connect a push button between ground and digital pin 10.       *
*    Default the pullup resistor will be active. The default        *
*    debounce delay is 200ms.                                       *
*                                                                   *
*    GND <--------- [Tactile push button] ---------> DigitalPin10   *
*                                                                   *
*********************************************************************/

#define buttonPin   10

DebounceButton button = DebounceButton(buttonPin);

void setup(){
    Serial.begin(9600);
    Serial.println("###SimpleDebounceButton example###");
};

void loop(){
    if(button.getPush()){
        Serial.println("Push button pressed");
    }
};