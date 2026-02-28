void lineMove(){
  int error = leftSens.mapRead() - rightSens.mapRead();
  int Psost = error * 1.2;
  int mainPwr = 80;
  bot.move(mainPwr - Psost, mainPwr + Psost);
}