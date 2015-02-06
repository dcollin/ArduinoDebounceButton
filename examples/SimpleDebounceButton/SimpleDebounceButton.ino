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
#define ledPin      13

DebounceButton button = DebounceButton(buttonPin);

void setup(){
    Serial.begin(9600);
    Serial.println("###SimpleDebounceButton example###");
    pinMode(ledPin, OUTPUT);
};

void loop(){
    bool push = button.getPush();
    if(push){
        Serial.println("Push button pressed");
    }else{
        Serial.println("Push button released");
    }
    digitalWrite(ledPin, push);
};