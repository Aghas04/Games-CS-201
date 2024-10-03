#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
/*
create craps function
start user with $50 to bet
ask user to bet
if bet is more than user balance display insufficient funds
roll two dice, if dice is 7 or 11 user wins
if dice is 2, 3, or 12 user loses
else the user sets point a rolls again

if user rolls point they win
if user rolls 7 they lose
add or subtract bet from user balance
ask user if they want to play again
playuntill user says no
display what the user won or lost

*/

//declaration
void craps();
// Pre: none
// Post: genorate a roll of 2 dice, if they = 7 or 11, they win, if they = 2, 3,
// or 12, they lose, if else establish point and allow the user to roll again
// untill you hit the point or 7

void craps() {
  double netWorth = 50.00;
  int dice1, dice2, roll, point;
  bool win = false;
  int bet;
  srand(time(0));

  cout << "Welcome to Craps!\n" << endl;
  while (true) {
    win = false;
    if (netWorth <= 0) {
      cout << "You are out of money, sorry you lose!\n" << endl;
      break;
    }
    
    cout << "You have $" << netWorth << " to bet with.\n" << endl;
    cout << "Enter bet: ";
    cin >> bet;
    cout << endl;
    while (bet > netWorth) {
      cout << "You don't have enough money to bet that much.\n" << endl;
      cout << "Enter bet: ";
      cin >> bet;
      cout << endl;
    }
    
    
    dice1 = rand() % 6 + 1;
    dice2 = rand() % 6 + 1;
    roll = dice1 + dice2;
    cout << "you rolled: " << dice1 << " + " <<  dice2 << " = " << roll << endl;
    if (roll == 7 || roll == 11) {
      cout << "you win" << endl;
      netWorth += bet;
      win = true;
    }
    else if (roll == 2 || roll == 3 || roll == 12) {
      cout << "you lose" << endl;
      netWorth -= bet;
      win = true;
    }
    else {
      point = roll;
      cout << "point is: " << point << endl << endl;
    }
    while (true && !(win)) {
      dice1 = rand() % 6 + 1;
      dice2 = rand() % 6 + 1;
      roll = dice1 + dice2;
      cout << "you rolled: " << dice1 << " + " <<  dice2 << " = " << roll << endl;
      if (roll == 7) {
        cout << "you lose\n" << endl;
        netWorth -= bet;
        break;
      }
      else if (roll == point) {
        cout << "you win\n" << endl;
        netWorth += bet;
        break;
      }
      else {
        cout << "roll again\n" << endl;
      }
    }
    cout << "Would you like to go again? Y/N\n" << endl;
    cout << "enter you choice: ";
    char choice;
    cin >> choice;
    cout << endl;
    if (choice == 'N' || choice == 'n') {
      if (netWorth > 50) {
        cout << "You made a profit of $" << netWorth - 50 << endl << endl;
      }
      else {
        cout << "You lost $" << 50 - netWorth << endl << endl;
      }
      break;
    }
  }
}