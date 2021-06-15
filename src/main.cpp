#include <Arduino.h>
#include "IFR_EV.h"


//Variables
int STATE_FLAG = 0;

//Pin definitions - change as necessary
int interrupt_pin = 2;

//
void interrupt_routine() {
    if(brake_pressed()){
      STATE_FLAG = 1;
    } else{
      STATE_FLAG = 0;
    }
}

void setup() {
  // put your setup code here, to run once:

  //executed if start button pressed
  
  //initialsing start button
  pinMode(interrupt_pin, INPUT);
  //initialising interrupt subroutine
  attachInterrupt(digitalPinToInterrupt(interrupt_pin), interrupt_routine, RISING);

  //set state flag
  STATE_FLAG = 0;

}

void loop() {
  // put your main code here, to run repeatedly:
  if(STATE_FLAG == 0){
    idle();
  } else{
    active();
  }
}

