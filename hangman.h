#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;
/*
Psudeo Code:
create hangman function

read words from word text file and input them into vector

pick a random word from the vector 

hide the word behind ?

let user guess the lettters untill they get the word or get 6 wrong guesses

if they get the word display congrats
if they get 6 wrong guesses display you lose
*/
// declaration

void hangman();
// Pre: none
// Post: genorate a random word and allow the user to guess the word letter by
// letter

void hangman() {

  string word, guess;
  int wrongGuesses = 0, unkownLetters = 0;
  bool wordGuessed = false;
  srand(time(0));
  // read file and put words into vector
  ifstream inFile;
  string fileword;
  vector<string> words;
  inFile.open("words.txt");
  inFile >> fileword;
  while (!inFile.fail()) {
    words.push_back(fileword);
    inFile >> fileword;
  }
  inFile.close();
  // pick random word
  int random = rand() % words.size();
  word = words[random];
  // diplay the random word
  for (int i = 0; i < word.length(); i++) {
    guess += "?";
  }
  cout << "guess the word: " << guess << endl;
  cout << "you have 6 wrong guesses\n" << endl;
  // allow user to guess the word
  while (wrongGuesses < 6 && wordGuessed == false) {
    char letter;
    cout << "enter a letter: ";
    cin >> letter;
    bool found = false;
    for (int i = 0; i < word.length(); i++) {
      if (word[i] == letter) {
        guess[i] = letter;
        found = true;
      }
    }
    if (!found && wrongGuesses != 6) {
      cout << "wrong guess\n" << endl;
      wrongGuesses++;

      cout << guess << endl;
      cout << "you have " << 6 - wrongGuesses << " wrong guesses left" << endl
           << endl;
    } else if (found) {
      cout << "correct guess\n" << endl;
      cout << guess << endl;
    }
    unkownLetters = 0;
    // check the amount of unguessed letters
    for (int i = 0; i < word.length(); i++) {
      if (guess[i] == '?') {
        unkownLetters += 1;
      }
    }
    // if there are no unguessed numbers end game
    if (unkownLetters == 0) {
      wordGuessed = true;
    }
  }
  // exit if user guesses 6 wrong guesses
  if (wrongGuesses == 6) {
    cout << "you lose" << endl;
    cout << "the word was " << word << endl << endl;
  } else if (wordGuessed == true) {
    cout << "you win" << endl;
    cout << "the word was " << word << endl << endl;
  }
}