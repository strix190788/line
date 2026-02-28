#include <KPMIS.h>
KPMIS bot;
#include <analogSensor.h>
analogSensor leftSens(A0, 2, 3);
analogSensor rightSens(A1, 4, 5);
void setup() {
  bot.initMotors();
  bot.reverse();
  bot.reverseRightMotor();
  bot.waitButtons();
  while (leftSens.mapRead() < 50 or rightSens.mapRead() < 50) lineMove(80, 1.2);
  bot.stop();
}
void loop() {
}
