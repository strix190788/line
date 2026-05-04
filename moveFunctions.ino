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
  while (leftSens.mapRead() < 50 or rightSens.mapRead() < 50) lineMove(pwr, kp);
}

void pMove(int error, int pwr, float kp) {
  int Psost = error * kp;
  bot.move(pwr - Psost, pwr + Psost);
}

void turnLeft(int pwr, float kp, int prd) {
  long currentMillis = millis();
  while (millis() - currentMillis < prd) pMove(leftSens.mapRead() - 40, pwr, kp);
}

void turnRight(int pwr, float kp, int prd) {
  long currentMillis = millis();
  while (millis() - currentMillis < prd) pMove(40 - rightSens.mapRead(), pwr, kp);
}

void lineMoveToTower(int dist, int pwr, float kp) {
  int distance = dist + 10;
  while (distance > dist) {
    distance = distance + (sonic.read() - distance) / 2;
    lineMove(pwr, kp, 6);
  }
}
void findTower(int dist) {
  bot.move(80, -80);
  int distance = dist + 10;
  while (distance > dist or distance < 10) {
    distance = sonic.read();
    delay(50);
  }
  bot.stop();
}

void aroundTheTower() {
}