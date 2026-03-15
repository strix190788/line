void lineMove(int pwr, float kp) {
  int error = leftSens.mapRead() - rightSens.mapRead();
  int Psost = error * kp;
  bot.move(1.05 * pwr - Psost, pwr + Psost);
}

void lineMove(int pwr, float kp, int prd) {
  long currentMillis = millis();
  while (millis() - currentMillis < prd) lineMove(pwr, kp);
}

void driveToCross(int pwr, float kp) {
  while (leftSens.mapRead() + rightSens.mapRead() < 80) lineMove(pwr, kp);
  //while (leftSens.mapRead() < 50 or rightSens.mapRead() < 50) lineMove(pwr, kp);
}

void pMove(int error, int pwr, float kp){
  int Psost = error * kp;
  bot.move(pwr - Psost, pwr + Psost);
}