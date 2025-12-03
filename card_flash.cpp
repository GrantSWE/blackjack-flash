#include "main.h"


void startFlash() {

    cout << "The game has started. Good luck." << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    
    system("clear");

    // This is used to determine the flash time
    int playerSkill;
    while(playerSkill > 3 || playerSkill < 1){
        cout << "What is your skill level?" << endl;
        cout << "1. Beginner     2. Intermediate     3. Expert" << endl;
        cin >> playerSkill;
        if(playerSkill > 3 || playerSkill < 1){
            cout << "Invalid choice. Try again." << endl;
        }
    }

    system("clear");

    int flashTime;
    switch(playerSkill){
        case 1:
            cout << "We'll start slow so you can start keeping pace." << endl;
            cout << "When this feels slow, move on." << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            flashTime = 5000;
            break;
        case 2:
            cout << "Getting the hang of things? Try this pace." << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            flashTime = 2000;
            break;
        case 3:
            cout << "So you can count? See if you can keep up at this pace." << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            flashTime = 1000;
            break;
        default:
            break;
    }

    char viewCount;
    cout << "Would you like to see the count as the game runs? (Y/N)" << endl;
    cin >> viewCount;
    viewCount = toupper(viewCount);

    while(viewCount != 'Y' && viewCount != 'N'){
        cout << "Incorrect character, please enter a 'Y' or 'N'" << endl;
        cin >> viewCount;
        viewCount = toupper(viewCount);
    }

    // Start of the actual game.
    vector<Card> deck = createDeck();
    shuffleDeck(deck);

    int runningCount = 0;

    for(size_t i = 0; i < deck.size(); ++i){
        system("clear");

        runningCount += getCardCountValue(deck[i]);

        cout << "Card " << (i + 1) << ": "
                        << rankToString(deck[i].rank)
                        << suitToString(deck[i].suit)
                        << endl;

        // displayDigitalCard(rankToString(deck[i].rank), suitToString(deck[i].suit));      // Not yet finished.

        if(viewCount == 'Y'){
            cout << "Running Count: " << runningCount << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(flashTime));
    }
    
    cout << "\nFinished revealing all 52 cards. " << endl;
    cout << "Final running count: " << runningCount << endl;
    cout << (runningCount == 0 ? "As expected, its back to zero!" : "Hm, that's surprising...") << endl;

}

int main(){

    startFlash();

    return 0;
}