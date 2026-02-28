void lineMove(int pwr, float kp){
  int error = leftSens.mapRead() - rightSens.mapRead();
  int Psost = error * kp;
  bot.move(pwr - Psost, pwr + Psost);
}