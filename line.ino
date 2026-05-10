#include <KPMIS.h>
KPMIS bot;
#include <analogSensor.h>
analogSensor leftSens(A0, 2, 3);
analogSensor rightSens(A1, 4, 5);
analogSensor pot(A10);
#include <Ultrasonic.h>
Ultrasonic sonic(10, 11);  // (trig, echo)
//const int rightSensBlack = 50;
//const int lensSensBlack = 50;
int distance;
void setup() {
  bot.initMotors();
  bot.reverseRightMotor();
  bot.waitButtons();
  moveToTower(15);
  bot.stop();



  // find
  
}


void loop() {
}
