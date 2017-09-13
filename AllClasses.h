#ifndef ALLCLASSES_
#define ALLCLASSES_

#include <iostream>
#include <array>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>    // std::random_shuffle

using namespace std;

// Output formating
const string LPAD = " ";
const string LTAB = "    ";

// Forward Declerations
class Shoe;
class Table;
class Person;
class Dealer;
class Player;

int myRandom(int i) { return rand()%i;}

//----------------------------------------------------------------------------------------

// Person Class ==========================================================================
class Person{
private:
    //Person Name
    float playerBetForWin = 0;
    float playerBetForLoss = 0;
    Table* tablePtr;
    string pName;
    float totalMoney;
public:
    // Constructors ---------------
    Person() : pName(" "), totalMoney(0){}
    Person(string name, int money) : pName(" "), totalMoney(0){
        totalMoney = money;
        pName = name;
    }
    // END Constructors ---------------
    
    // Methods ---------------
    string getName(){return pName;}
    void setName(string name){pName = name;}
    
    float getTotalMoney(){return totalMoney;}
    void setTotalMoney(int newAmount){totalMoney=newAmount;}
    
    float getBet(float bet){
        if (getTotalMoney() >= bet){
            setTotalMoney(getTotalMoney()-bet);
        }else if (bet > getTotalMoney()){
            bet = getTotalMoney();
            setTotalMoney(0);
        }else{
            cout << LPAD << "You don't have enough money, please by in for more." << endl;
            bet = 0;
        }
        return bet;
    }
    
    float getplayerBetForWin(){return playerBetForWin;}
    void setplayerBetForWin(float amount){playerBetForWin = amount;}
    
    float getplayerBetForLoss(){return playerBetForLoss;}
    void setplayerBetForLoss(float amount){playerBetForLoss = amount;}
    
    Table* getTablePtr(){ return tablePtr; }
    void setTablePtr(Table* table){ tablePtr = table; }
    
    void displayPerson(){
        cout << pName<< " " << totalMoney << endl;
    }
    // END Methods ---------------
};
// END Person Class ======================================================================

// Player Class ==========================================================================
class Player : public Person{
public:
    // Constructors ---------------
    Player() : Person(){}
    Player(string name, int money) : Person(name, money){}
    // END Constructors ---------------
};
// END Player Class ======================================================================

// Dealer Class ==========================================================================
class Dealer : public Person{
private:
    // House Rules
    int numbOfDecks;
    
    //Table pointer of dealers table
    
public:
    // Constructors ---------------
    Dealer() : Person("random", 99), numbOfDecks(1){}
    Dealer(string name, int money) : Person(name, money), numbOfDecks(1){}
    Dealer(string name, int money, int decks) : Person(name, money), numbOfDecks(decks){}
    // END Constructors ---------------
    
    // Methods ---------------
    void startDeal(); // referance method call, method outside class just before main
    
    int getNumbOfDecks(){return numbOfDecks;}
    
    // END Methods ---------------
};
// END Dealer Class ======================================================================

struct CardStruct;

struct PersonStruct{
    Person* personPtr = nullptr;
    bool playing = false;
    float bet = 0;
    int handCount1;
    int handCount2;
    vector<CardStruct> handVector;
};

struct CardStruct{
    bool show = true;
    string cardInfo = "unknown";
    int cardNumber = 0;
    string cardName = "unknown";
    string cardSuit = "unknown";
    int cardValue = 0;
    int deckNumber = 0;
};

// Table Class ===========================================================================
//	                   dealer
//	  /----------\                /----------\
//	 /		      \--------------/            \
//	|                                          |
//	|  -discard-     -houseBank-     -shoe-    |
//	|                                          |
//	|                                          |
//	|   P1           dealerArray          P7   |
//	|                                          |
//	 \                                        /
//	  \     P2       playerArray       P6    /
//	   \                                    /
//	    \        P3      P4      P5        /
//	     \                                /
//	      -------------------------------

class Table{
private:
    // Variables ---------------
    static const int HARRAYSIZE = 8;
    static const int PLAYERSIZE = 7;
    static const int DEALERINDEX = 0;
    PersonStruct humanArray[HARRAYSIZE];
    
    //house bank
    float houseBank=9999999;
    
    // Table Rules
    int numbOfDecksTR = 6;
    float tableMinBet = 1;
    float tableMaxBet = 50;
    float blackjackPayout = 2.5;// 2.5 is 3:2 win this is added to
    float insuranceBetAmount = .5;// .5 is half original bet
    float insurancePayout = 2;// 2 is 2:1, this bet is multiplied by original bet then added to that bet
    
    vector<int> tableShoe;
    
    int humanArrayTurn;
    
    // END Variables ---------------
    
public:
    // Constructors ---------------
    Table(){
        // get shoe size from newDealer
        fillShoe(1);
        for (int i=0;i<HARRAYSIZE;i++){
            humanArray[i].personPtr = nullptr;
        }
    }
    // END Constructors ---------------
    
    // Methods ---------------
    
    //	Places A New Dealer
    bool setDealer(Dealer *newDealer){
        bool success;
        if (!(humanArray[0].personPtr == nullptr)){
            success = false;
        }else{
            humanArray[0].personPtr = newDealer;
            newDealer->setTablePtr(this);
            fillShoe(newDealer->getNumbOfDecks());
            success = true;
        }
        return success;
    }
    void clearDealer(){humanArray[0].personPtr = nullptr;}// clears dealer
    
    //	1) Places A New Player 2) clears a player
    void setPlayer(int loc, Person* newPlayer){
        humanArray[loc].personPtr = newPlayer;
        newPlayer->setTablePtr(this);
    }
    void clearPlayer(int loc){humanArray[loc].personPtr = nullptr;}// clears player
    
    //	1) gets player name 2) gets player total money
    string getPlayerName(int loc){return humanArray[loc].personPtr->getName();}
    float getPlayerTotalMoney(int loc){return humanArray[loc].personPtr->getTotalMoney();}
    
    //	1) gets bet value on table 2) sets bet value on table
    float getPlayerTableBet(int loc){return humanArray[loc].bet;}
    void setPlayerTableBet(int loc, float bet, float winLoss){humanArray[loc].bet = bet + winLoss;}
    
    //	1) gets name of card in hand at spicific location 2) sets card name at specific location
    string getCardName(int humanloc, int handloc){return humanArray[humanloc].handVector[handloc].cardName;}
    //	void setCardName(int humanloc, string newName){
    //		CardStruct jimmy;
    //
    //		humanArray[humanloc].handVector.insert(humanArray[humanloc].handVector.begin(), jimmy);
    //	}
    
    //	1) gets suit of card in hand at spicific location 2) sets card suit at specific location
    string getCardSuit(int humanloc, int handloc){return humanArray[humanloc].handVector[handloc].cardSuit;}
    void setCardSuit(int humanloc, int handloc, string newSuit){
        humanArray[humanloc].handVector[handloc].cardSuit = newSuit;
    }
    
    //	1) gets value of card in hand at spicific location 2) sets card value at specific location
    int getCardValue(int humanloc, int handloc){return humanArray[humanloc].handVector[handloc].cardValue;}
    void setCardValue(int humanloc, int handloc, int newValue){
        humanArray[humanloc].handVector[handloc].cardValue = newValue;
    }
    
    //	1) gets name of dealer 2) gets total money of dealer
    string getDealerName(){return humanArray[0].personPtr->getName();}
    float getTotalMoney(){return humanArray[0].personPtr->getTotalMoney();}
    
    //	gets table min bet
    float gettableMinBet(){return tableMinBet;}
    void settableMinBet(float minbet){tableMinBet = minbet;}
    
    //	gets table max bet
    float gettableMaxBet(){return tableMaxBet;}
    void settableMaxBet(float maxbet){tableMinBet = maxbet;}
    
    //	Displays table, will be used to create gui
    void tableDisplay(){
        //display
        cout << "Table Min Bet: " << gettableMinBet() << endl;
        cout << "Table Max Bet: " << gettableMaxBet() << endl << endl;
        for (int i=0; i<HARRAYSIZE; i++){
            if(humanArray[i].personPtr == nullptr){
                // skip player
            }else{
                //output person info
                if(i==0){
                    cout << "Dealer: " << humanArray[i].personPtr->getName() << endl;
                }else{
                    cout << "Player " << i << ":   "; humanArray[i].personPtr->displayPerson();
                }
                if (i == 0){//skip
                }else{cout << "bet:        " << humanArray[i].bet << endl;}
                
                // output hand info
                for (auto card:humanArray[i].handVector){
                    if (card.show == false){
                        cout << LTAB <<
                        "*HIDDEN*  " <<  setw(16) << left << card.cardName <<
                        " " << setw(20) << card.cardSuit <<
                        " " << card.cardValue << "  *HIDDEN*" << endl;
                    }else{
                        cout << LTAB <<
                        "cardname: " << setw(7) << left << card.cardName <<
                        "cardsuit: " << setw(10) << card.cardSuit <<
                        "cardvalue: " << card.cardValue << endl;
                    }
                }
                cout << endl;
            }
        }
    }
    
    //	SHOE TESTING ONLY
    void displayShoe(){
        cout << "Current Shoe, the next card out will be: " << tableShoe.back() << " (Cards are serialized)" << endl;
        for (auto card:tableShoe){cout << card << " ";}
        cout << endl << "Number of Cards left in shoe: " << tableShoe.size() << endl;
    }
    
    //	CARD TRANSLATOR TESTING
    CardStruct cardTranslator(int cnumber, int humanloc){
        CardStruct card;
        string cinfo;
        //	13 cards per suit 4 suits in 52 cards
        //	1 is ace has multiple values but will be output as ace
        //	2-10 9 cards face value
        //	11-13 - 3 cards king queen jack all have value of 10
        if (cnumber == 0 || cnumber == -1){ cinfo = to_string(cnumber);//check for shuffle & cut cards
        }else{
            if (humanloc < 0){
                humanArray[humanloc].handVector.clear();
            }else{
                string cname;
                string csuit;
                int cvalue;
                
                int cNameValueMod = cnumber % 13;
                
                int cSuitMod = cnumber % 52; // removing decks from number then sorting suits
                if (cSuitMod > 0 && cSuitMod <= 13){		csuit = "Spades   ";
                }else if (cSuitMod > 13 && cSuitMod <= 26){ csuit = "Clubs    ";
                }else if (cSuitMod > 26 && cSuitMod <= 39){ csuit = "Hearts   ";
                }else {										csuit = "Diamonds ";}
                
                switch (cNameValueMod) { //assigns value and name to cards
                    case  1:  cvalue =  1; cname = "Ace"; break;
                    case 11:  cvalue = 10; cname = "Jack"; break;
                    case 12:  cvalue = 10; cname = "Queen"; break;
                    case  0:  cvalue = 10; cname = "King"; break;
                    default:  cvalue = cNameValueMod;
                        cname = to_string(cNameValueMod); break;
                }
                
                int dnum = (cnumber/52) + 1; // get number of deck
                
                //Changes all numbers to strings for dispaying
                string scnum = to_string(cnumber);
                string scvalue = to_string(cvalue);
                string sdnum = to_string(dnum);
                cinfo = scnum + " " + cname + " " + csuit + " " + scvalue + " " + sdnum;
                
                // sets to index cardstruct to card outputs
                card.cardInfo = cinfo;
                card.cardNumber = cnumber;
                card.cardName = cname;
                card.cardSuit = csuit;
                card.cardValue = cvalue;
                card.deckNumber = dnum;
                humanArray[humanloc].handVector.insert(humanArray[humanloc].handVector.begin(), card);
            }
        }
        return card;
    }
    
    
    //	creates and files the shoe
    void fillShoe(int size){
        tableShoe.clear();
        int numbOfCards = size * 52;
        for (int i=0;i<numbOfCards;i++){
            tableShoe.push_back(i+1);
        }
        srand(unsigned (time(0)));
        random_shuffle ( tableShoe.begin(), tableShoe.end(), myRandom);
        int cutCard = ((rand() % (numbOfCards/3))+(numbOfCards/10)); // finds location for cut card
        tableShoe.insert (tableShoe.begin() + cutCard, 0); // places cutcard *back part of deck should move to front*************************************************************************
        tableShoe.insert (tableShoe.begin(), -1); // place shuffle card
    }
    
    //	gets a card and removes it from the shoe
    int getShoeCard(){
        int card = tableShoe[tableShoe.size()-1];
        tableShoe.pop_back();
        return card;
    }
    
    //	gets if the shoe is empty
    bool shoeEmpty(){return tableShoe.empty();}
    
    //	gets the shoe is size
    int shoeSize(){return tableShoe.size();}
    
    Table* getTablePtr(){ return this; }
    
    Person* getPersonPtr(int index){return humanArray[index].personPtr;}
    
    void showCardQ(int i, int i2){humanArray[i].handVector[i2].show = false;}
    
    // END Methods ---------------
};
// END Table Class =======================================================================

void Dealer::startDeal(){
//    cout<<"now in startdeal" << endl;
    
    //array for checking if bets are out for players to play hand
    array<bool, 7> isPlayerPlaying;
    isPlayerPlaying.fill(false);
    int conditionWin;
    int conditionLose;
    int conditionPush;
    
    //	burn Card
    cout << "Dealer burns first card." << endl << endl;
    this->getTablePtr()->getShoeCard();
    
    //	Check for bets
    // at this point I think another thread will be needed. The player has the time between
    // the playing hand to add a bet to there bet variable on the table. once dealer has
    // finished dealing, taking losses and applying wins, players will get a few seconds
    // to place next bet.
    cout << "Dealer: \"Place your bets!\"" << endl << endl;
    
    //	counts valid players
    int count = 7;
    int countSkippedPlayers = 0;
    isPlayerPlaying[0] = true;
    for (int p = 1; p <= 7; p++){
        if (this->getTablePtr()->getPlayerTableBet(p) == 0){
            countSkippedPlayers++;
        }else if(this->getTablePtr()->getPlayerTableBet(p) < this->getTablePtr()->gettableMinBet()){
            cout << "Dealer: \"I\'m sorry player " << p << " your bet is below the table minimum.\""
            << endl << LTAB << LTAB << "\"Please increase your bet to play the next hand.\"" << endl << endl;
            countSkippedPlayers++;
        }else if(this->getTablePtr()->getPlayerTableBet(p) > this->getTablePtr()->gettableMaxBet()){
            cout<< "Dealer: \"I\'m sorry player " << p << " your bet is above the table maximum.\""
            << endl << LTAB << LTAB << "\"Please decrease your bet to play the next hand.\"" << endl << endl;
            countSkippedPlayers++;
        }else if(this->getTablePtr()->getPersonPtr(p) == nullptr){//skip player
            countSkippedPlayers++;
        }else{
            isPlayerPlaying[p] = true;
        }
    }
    
    //	1 round of dealing 1 card face up ending with the dealer
    for (int i = 0; i <= 7; i++){
        if (!isPlayerPlaying[i]){ //skip person
        }else{
            this->getTablePtr()->cardTranslator(this->getTablePtr()->getShoeCard(), i);
        }
    }
    
    cout << "Dealer deals 1 card to players." << endl << endl;
    
    //	1 round of dealing 1 card face up ending with the dealer card face down
    for (int i = 0; i <= 7; i++){
        if (!isPlayerPlaying[i]){ //skip person
        }else{
            this->getTablePtr()->cardTranslator(this->getTablePtr()->getShoeCard(), i);
            if (i == 0){
                this->getTablePtr()->showCardQ(i, 1);
            }
        }
    }
    
    cout << "Dealer deals 1 more card to players." << endl << endl;

    
    
    //set current hand value
    
    cout << "Dealer \"nopeeks\" for 21, if 10 showing in dealers hand." << endl << endl;

    //	if dealer up card is 10, dealer "nopeek" for blackjack, if blackjack hand over.
    //		note if blackjacks are push
    if (this->getTablePtr()->getCardValue(0, 0) == 10 && this->getTablePtr()->getCardValue(0, 1) == 1){
        conditionWin = -1;
        conditionLose = 20;
        conditionPush = 21;
        for (int i = 0; i <= 7; i++){
            if (!isPlayerPlaying[i]){ //skip person
            }else{
                this->getTablePtr()->cardTranslator(this->getTablePtr()->getShoeCard(), i);
                
            }
        }
    }
    
    cout << "Functunallity still to add..." <<endl;
    
    cout << LPAD << "Dealer ends round if \"nopeek\" shows 21." << endl;
    
    cout << LPAD << "Dealer offers insurance to players, if Ace showing." << endl;
    //	if dealer up card is ace, insurance is asked for, side bet that dealer had a blackjack,
    //      if blackjack hand over. note if blackjacks are push
    
    cout << LPAD << "Dealer starts hand if no 21 in dealer's hand." << endl;
    //	if no blackjack for dealer, dealer moves to first player, and around the table. left player?
    //		each player can hit, stand, double down, sometimes split.
    
    cout << LPAD << "After all players have played their hand. Dealer plays." << endl;
    //	dealer revels face down card and follows house rules(stand on 17, hit soft 17, ect...).
    
    cout << LPAD << "Dealer collects losses and rewards wins, leaves pushes." << endl;
    //	collects losses, leaves pushes, assigns wins.
    
    cout << LPAD << "Dealer collects cards and re-deals or shuffles if needed." << endl;
    //	clears cards, suffles if shuffle card comes up
    
    cout << "...end" << endl << endl;
}


#endif
