#include "blackjack.h"
#include "craps.h"
#include "hangman.h"
#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
/*
Psudeo Code
display menu
get user input
if user input is b, run blackjack
if user inpuit is c, run craps
if user input is h, run hangman
if user input is q, quit
play untill user input is q
*/
// things to do: create a struct for cards for blackjack
using namespace std;
// sources: Unicode chart, chat GPT to figure out how to use the locale class
// and how to change text color function declarations



int main() {

  char game;

  while (true) {
    cout << "Welcome to the game menu! Please select a game to play: \n B - "
            "Blackjack \n C - Craps \n H - Hangman \n Q - Quit \n";
    cin >> game;

    if (game == 'B' || game == 'b') {
      blackJack();

    } else if (game == 'C' || game == 'c') {
      craps();
    } else if (game == 'H' || game == 'h') {
      hangman();
    } else if (game == 'Q' || game == 'q') {
      break;
    } else {
      wcout << "Invalid input, please try again.\n";
      
    }
  }
}
