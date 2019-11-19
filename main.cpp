/*
  Peter Nguyen
  10/29/19
  Prof. T
  COSC 1437
*/

#include "class and functions.h"

int main(){

  Team t1;
  Team t2;
  Scoreboard game;
  string userInput = "";
  char option;

  cout << "\033[2J\033[1;1H";
  cout << "\nFootball Game" << endl;
  setTeamInfo(t1, 1);
  setTeamInfo(t2, 2);
  game.showScoreboard(t1, t2);

  cout << "\033[2J\033[1;1H";
  do {
    game.showScoreboard(t1, t2);
    showMenu();
    option = validateChar(option);
    handleOption(option,t1,t2);
    cout << "\033[2J\033[1;1H";
  } while (option != 'Q' && option != 'q');
  cout << "Goodbye...";

  return 0;
}

