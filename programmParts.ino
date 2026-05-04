void settings() {
  bot.initMotors();
  bot.reverse();
  bot.reverseLeftMotor();
  bot.reverseRightMotor();
}

void yellowToTurn90() {
  bot.move(80, 80, 3000);
  turnLeft(80, 3, 2000);
  driveToCross(80, 1.2);
  turnRight(80, 3, 2000);
  while (rightSens.mapRead() < 40) {
    bot.pMove(leftSens.mapRead() - 40, 80, 3);
  }
  bot.stop();
}