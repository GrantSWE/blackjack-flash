#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};

enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};

struct Card {
    Rank rank;
    Suit suit;
};

string rankToString(const Rank& rank){
    switch(rank){
        case TWO: return "2";
        case THREE: return "3";
        case FOUR: return "4";
        case FIVE: return "5";
        case SIX: return "6";
        case SEVEN: return "7";
        case EIGHT: return "8";
        case NINE: return "9";
        case TEN: return "10";
        case JACK: return "J";
        case QUEEN: return "Q";
        case KING: return "K";
        case ACE: return "A";
    }
    return "?"; // Default case
    // No breaks since we're returning, that breaks the function.
}

string suitToString(const Suit& suit){
    switch(suit){
        case HEARTS: return "❤️";
        case CLUBS: return "♣️";
        case DIAMONDS: return "♦️";
        case SPADES: return "♠️";
    }
    return "?"; // Default case
}

vector<Card> createDeck(){
    vector<Card> deck;
    deck.reserve(52);
    // Loop from 2 to A
    for (int r = TWO; r <= ACE; ++r){
        for (int s = HEARTS; s <= SPADES; ++s){
            Card card;
            card.rank = static_cast<Rank>(r);
            card.suit = static_cast<Suit>(s);
            deck.push_back(card);
        }
    }
    return deck;
}

void shuffleDeck(vector<Card>& deck){
    static mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    shuffle(deck.begin(), deck.end(), rng);
}

// Calculate the value of a card in the deck.
int getCardValue(const Card &card){
    switch(card.rank){
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN:;
        case JACK:
        case QUEEN:
        case KING: return 10;
        case ACE: return 11; // Handling 1 later
    }
    return 0;
}

int getCardCountValue(const Card &card){
    switch(card.rank){
        case TWO:
        case THREE:
        case FOUR:
        case FIVE:
        case SIX:
            return +1;
        case SEVEN:
        case EIGHT: 
        case NINE:
            return 0;
        case TEN:
        case JACK:
        case QUEEN:
        case KING:
        case ACE:
            return -1;
    }
}



// Still testing
void displayDigitalCard(string value, string suit) {
     /*
     General Layout -
     |------------------|
     |    2             |
     |                  |
     |         ♥        |
     |                  |
     |                  |
     |                  |
     |         ♥        |
     |                  |
     |              2   |
     |------------------|
     */

    for (int i = 0; i < 11; i++){
        for (int j = 0; j < 19; j++){

            // Borders
            if ((i == 0 && (j != 0 && j != 18)) || (i == 10 && (j != 0 && j != 18))) {
                cout << "-";
                continue;
            }
            if (j == 0 || j == 18){
                cout << "|";
                continue;
            }

            // Value
            if (value == "10"){
                if ((i == 1 && j == 3) || (i == 9 && j == 14)){
                    cout << "1";
                    continue;

                } else if ((i == 1 && j == 4) || (i == 9 && j == 15)){
                    cout << "0";
                    continue;
                }
            } else if ((i == 1 && j == 3) || (i == 9 && j == 15)){
                cout << value;
                continue;
            }

            // Suit 🥲
            if (value == "2") {
                if((i == 2 || i == 8) && j == 9) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "3") {
                if((i == 3 || i == 5 || i == 7) && j == 9) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "4") {
                if((i == 3 || i == 7) && (j == 6 || j == 12)) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "5") {
                if (((i == 2 || i == 8) && (j == 6 || j == 12)) ||
                    (i == 5 && j == 9)) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "6") {
                if ((i == 2 || i == 5 || i == 8) && (j == 6 || j == 12)) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "7") {
                if ((i == 3 && j == 9) ||
                    ((i == 2 || i == 5 || i == 8) && (j == 6 || j == 12))) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "8") {
                if ((i == 2 || i == 4 || i == 6 || i == 8) && (j == 6 || j == 12)){
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "9") {
                if (((i == 3 || i == 5 || i == 7) && j == 9) ||
                    ((i == 2 || i == 5 || i == 8) && (j == 6 || j == 12))) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else if (value == "10") {
                if ( ((i == 2 || i == 8) && (j == 6 || j == 12)) ||
                    ((i == 4 || i == 6) && (j == 6 || j == 9 || j == 12))
                ) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            } else {
                // Centered
                if (i == 5 && j == 10) {
                    cout << suit;
                } else {
                    cout << " ";
                }
            }

        }
        cout << endl;
    }
}