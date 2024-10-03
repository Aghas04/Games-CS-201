#include <fstream>
#include <iostream>
#include <locale>
#include <string>
#include <vector>

//source: gpt for symbols and colors
/*
Psudeo Code:
assign 1 of 4 symbols to cards
for each symobl set a rank out of 13 cards
assign a value to each card correcsponding to its rank

after deck is created shuffle deck

after deck is shuffled craete function to take top card of deck

deal cards to user allow user to hit or stand

add cards to the users hand if they hit
if they stand end and show dealers card
untill dealer has more than 17 hit

finally compare and output winner

*/

using namespace std;
// Declarations
struct Card {
  string suit;
  string rank;
  int value;
};

void createDecks(vector<int> &deck);

void blackJack();
// Pre: none
// Post: randomly genorate a dealer and user card and allow the user to hit or
// stand then genorate the dealer's card

void createDecks(vector<Card> &deck) {
  Card tempCard;
  const string suits[4] = {"\u2665", "\u2666", "\u2663",
                           "\u2660"}; // Hearts, Diamonds, Clubs, Spades
  const string ranks[13] = {"A", "2", "3",  "4", "5", "6", "7","8", "9", "10", "J", "Q", "K"};
  const int values[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
  srand(time(0));
  //asign values to cards in deck
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 13; j++) {
      //assign suit and rank
      tempCard.suit = suits[i - 1];
      tempCard.rank = ranks[j - 1];
      tempCard.value = values[j - 1];
      deck.push_back(tempCard);
    }
  }
  //shuffle deck
  for (int i = 0; i < 52; i++) {
    tempCard = deck[i];
    int indx = rand() % 52;
    deck[i] = deck[indx];
    deck[indx] = tempCard;
  }
}

Card dealCard(vector<Card> &deck) {
  // Pre: deck is full & shuffled
  // post: returns 1st element in deck and removes from deck
  Card value = deck[0];
  deck.erase(deck.begin());
  return value;
}

void blackJack() {
  char hitOrStand;
  int dealerTotal = 0, userTotal = 0;
  int playerAce = 0, dealerAce = 0;

  string Red = "\033[031m";
  string Reset = "\033[0m";


  
  vector<Card> deck;
  createDecks(deck);
  vector<Card> playerHand;
  vector<Card> dealerHand;
  //deal player cards
  Card userCard = dealCard(deck);
  playerHand.push_back(userCard);
  userCard = dealCard(deck);
  playerHand.push_back(userCard);
  //deal dealers cards
  Card dealerCard = dealCard(deck);
  dealerHand.push_back(dealerCard);
  dealerCard = dealCard(deck);
  dealerHand.push_back(dealerCard);

  cout << "WELCOME TO BLACKJACK!\n" << endl;

  //display user cards
  cout << "Your Cards: \n";
  for (int i = 0; i < playerHand.size(); i++) {
    if (playerHand[i].rank == "A") {
      playerAce += 1;}

    userTotal += playerHand[i].value;
    if (playerHand[i].suit == "♥" || playerHand[i].suit == "♦") {
      cout << Red << playerHand[i].suit << " " << playerHand[i].rank << Reset << endl;
    }
    else {
    cout << playerHand[i].suit << " " << playerHand[i].rank << endl;
    }
  }
  while (userTotal > 21 && playerAce > 0) {
    userTotal -= 10;
    playerAce -= 1;
  }
  cout << "user total: " << userTotal << endl;
  //allow user to hit or stand
  while (true) {
    cout << "\ndo you want to hit or stand? (h/s) ";
    cin >> hitOrStand;
    if (hitOrStand == 'h') {
      userCard = dealCard(deck);
      playerHand.push_back(userCard);
      if (userCard.rank == "A") {
        playerAce += 1;
      }
      userTotal += userCard.value;
      while (userTotal > 21 && playerAce > 0) {
        userTotal -= 10;
        playerAce -= 1;
      }
      if (userTotal > 21) {
        userTotal = 0;
        playerAce = 0;
        for (int i = 0; i < playerHand.size(); i++) {
          if (playerHand[i].rank == "A") {
            playerAce += 1;}

          userTotal += playerHand[i].value;
          if (playerHand[i].suit == "♥" || playerHand[i].suit == "♦") {
            cout << Red << playerHand[i].suit << " " << playerHand[i].rank << Reset << endl;
          }
          else {
          cout << playerHand[i].suit << " " << playerHand[i].rank << endl;
          }

        }
        while (userTotal > 21 && playerAce > 0) {
          userTotal -= 10;
          playerAce -= 1;
        }
        break;
        }

      else if (userTotal == 21) {
        userTotal = 0;
        playerAce = 0;
        for (int i = 0; i < playerHand.size(); i++) {
          if (playerHand[i].rank == "A") {
            playerAce += 1;}

          userTotal += playerHand[i].value;
          if (playerHand[i].suit == "♥" || playerHand[i].suit == "♦") {
            cout << Red << playerHand[i].suit << " " << playerHand[i].rank << Reset << endl;
          }
          else {
          cout << playerHand[i].suit << " " << playerHand[i].rank << endl;
          }

        }
        while (userTotal > 21 && playerAce > 0) {
          userTotal -= 10;
          playerAce -= 1;
        }
        break;
      }
      cout << "\nYour Cards: \n";
      userTotal = 0;
      playerAce = 0;
      for (int i = 0; i < playerHand.size(); i++) {
        if (playerHand[i].rank == "A") {
          playerAce += 1;}

        userTotal += playerHand[i].value;
        if (playerHand[i].suit == "♥" || playerHand[i].suit == "♦") {
          cout << Red << playerHand[i].suit << " " << playerHand[i].rank << Reset << endl;
        }
        else {
        cout << playerHand[i].suit << " " << playerHand[i].rank << endl;
        }

      }
      while (userTotal > 21 && playerAce > 0) {
        userTotal -= 10;
        playerAce -= 1;
      }
      cout << "\nuser total: " << userTotal << endl;
    }
    else if (hitOrStand == 's') {
      break;
    }
  }
  //break if user goes over 21
  if (userTotal > 21) {
    cout << "\nyou Bust you lose\n" << endl;
  }
  //win if user hits 21
  else if (userTotal == 21) {
    cout << "\nyou win\n" << endl;
  }
  else {
    //display dealers cards
    cout << "\nDealer Cards: \n";
    dealerTotal = 0;
    dealerAce = 0;
    for (int i = 0; i < dealerHand.size(); i++) {
      if (dealerHand[i].rank == "A") {
        dealerAce += 1;
      }
      dealerTotal += dealerHand[i].value;
      if (dealerHand[i].suit == "♥" || dealerHand[i].suit == "♦") {
        cout << Red << dealerHand[i].suit << " " << dealerHand[i].rank << Reset << endl;
      }
      else {
      cout << dealerHand[i].suit << " " << dealerHand[i].rank << endl;
      }
    }
    cout << "\ndealer total: " << dealerTotal << endl;

    while (dealerTotal <= 17) {
      dealerCard = dealCard(deck);
      dealerHand.push_back(dealerCard);
      if (dealerCard.rank == "A" && dealerTotal > 10) {
        dealerTotal += dealerCard.value - 10;  
      }
      else {
        dealerTotal += dealerCard.value;
      }

    }
    //display final cards
    cout << "\nFinal Cards: \n";
    cout << "\nYour Cards: \n";
    userTotal = 0;
    playerAce = 0;
    for (int i = 0; i < playerHand.size(); i++) {
      if (playerHand[i].rank == "A") {
          playerAce += 1;
      }
      
      userTotal += playerHand[i].value;
      if (playerHand[i].suit == "♥" || playerHand[i].suit == "♦") {
        cout << Red << playerHand[i].suit << " " << playerHand[i].rank << Reset << endl;
      }
      else {
      cout << playerHand[i].suit << " " << playerHand[i].rank << endl;
      }
      
    }
    while (userTotal > 21 && playerAce > 0) {
      userTotal -= 10;
      playerAce -= 1;
    }
    cout << "\nuser total: " << userTotal << endl;
    cout << "\nDealer Cards: \n";
    dealerTotal = 0;
    dealerAce = 0;
    for (int i = 0; i < dealerHand.size(); i++) {
      if (dealerHand[i].rank == "A") {
        dealerAce += 1;
      }
      dealerTotal += dealerHand[i].value;
      if (dealerHand[i].suit == "♥" || dealerHand[i].suit == "♦") {
        cout << Red << dealerHand[i].suit << " " << dealerHand[i].rank << Reset << endl;
      }
      else {
      cout << dealerHand[i].suit << " " << dealerHand[i].rank << endl;
      }
    }
    while (dealerTotal > 21 && dealerAce > 0) {
      dealerTotal -= 10;
      dealerAce -= 1;
    }
    
    cout << "\ndealer total: " << dealerTotal << endl;
    //display who won
    if (dealerTotal > 21) {
      cout << "\ndealer Bust you win\n" << endl;
    }
    else if (dealerTotal > userTotal) {
      cout << "\ndealer wins\n" << endl;
    }
    else if (userTotal > dealerTotal) {
      cout << "\nCongrats you win\n" << endl;
    }
    else {
      cout << "\npush\n" << endl;
    }
  }
}