/*
 * Project TP1-Photon
 * Description: https://github.com/1795455/MGL7760-TP1-Photon.git
 * Author:
 * Date:
 */

// setup() runs once, when the device is first turned on.


#define Pin_ledRed  D2
#define Pin_ledBlue  D4
int count;

#include <FiniteStateMachine.h>
#include<GlobalVariables.h>
#include <FSM_led_RED.h>
#include <FSM_led_BLUE.h>


//SYSTEM_MODE(SEMI_AUTOMATIC);



void setup() {
  // Put initialization like pinMode and begin functions here.

  pinMode(Pin_ledRed, OUTPUT);      // declare LED as output
  pinMode(Pin_ledBlue, OUTPUT);      // declare LED as output

}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

  FSM_ledRed.update();
  FSM_ledBlue.update();

  

}