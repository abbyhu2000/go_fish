// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    cout << "There are " << d.size() << "cards in the deck." <<endl;
    d.shuffle();

    //testing different functions
//    Card c1(1, Card::clubs);
//    Card c2(2,Card::clubs);
//    Card c3(3,Card::clubs);
//    Card c4(4,Card::clubs);
//    Card c5(5,Card::clubs);
//
//    p1.addCard(c1);
//    p1.addCard(c2);
//    p1.addCard(c3);
//    p1.addCard(c4);
//    p1.addCard(c5);
//    p1.addCard(c1);
//    p1.addCard(c2);
//    p1.addCard(c3);
//
//    p2.addCard(c4);
//    p2.addCard(c4);
//    p2.addCard(c5);
//    p2.addCard(c1);
//    p2.addCard(c5);
//    p2.addCard(c1);
//    p2.addCard(c5);
//    p2.addCard(c4);
//
//    p1.checkPairToBook();
//    cout << p1.getName() <<" 's hand has : " << p1.showHand() << endl;
//    cout << p1.getName() <<" 's book has : " << p1.showBooks() << endl;
//
//    Card askCard = p1.chooseCardFromHand();
//    cout << "Player 1 ask player 2 for card " << askCard.toString() << endl;
//    while(p2.rankInHand(askCard)){
//        p2.removeAllCardsSameRank(askCard,p1);
//        cout << p1.getName() <<" 's hand has : " << p1.showHand() << endl;
//        cout << p2.getName() <<" 's hand has : " << p2.showHand() << endl;
//        p1.checkPairToBook();
//        askCard = p1.chooseCardFromHand();
//        cout << "Player 1 ask player 2 for card " << askCard.toString() << endl;
//    }

    cout << "Game start! Deal seven cards to both players!" << endl;
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" 's initial hand has : " << p1.showHand() << endl;
    cout << p2.getName() <<" 's initial hand has : " << p2.showHand() << endl;

    //check pairs at the beginning of the game
//    p1.checkPairToBook();
//    p2.checkPairToBook();
//
//    cout << p1.getName() <<" 's hand has : " << p1.showHand() << endl;
//    cout << p2.getName() <<" 's hand has : " << p2.showHand() << endl;
//    cout << p1.getName() <<" 's book has : " << p1.showBooks() << endl;
//    cout << p2.getName() <<" 's book has : " << p2.showBooks() << endl;

    //game ends if the total number of book deck size is 52
    while((p1.getBookSize()+p2.getBookSize())!=52){
        cout << endl << endl;
        p1.checkPairToBook();
        if(p1.getHandSize()==0){
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                cout << "Joe's hand is empty, draws a new card" << newCard.toString() << endl;
            }
        }
        else{
            //check pairs at the beginning of the round
            //p1.checkPairToBook();
            cout << p1.getName() <<" 's hand has : " << p1.showHand() << endl;
            cout << p1.getName() <<" 's book has : " << p1.showBooks() << endl;
            Card askCard = p1.chooseCardFromHand();
            cout << "Joe ask Jane for rank " << askCard.getRank() << endl;
            while(p2.rankInHand(askCard)){
                cout << "Jane says: Yes, I have a " << askCard.getRank() << endl;
                p2.removeAllCardsSameRank(askCard,p1);
                //p1.checkPairToBook();
                askCard = p1.chooseCardFromHand();
                cout << "Joe ask Jane for rank " << askCard.getRank() << endl;
            }
            cout << "Jane says: Go! Fish!" << endl;
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                cout << "Joe draws a " << newCard.toString() << endl;
            }
        }


        p2.checkPairToBook();
        if(p2.getHandSize()==0){
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                cout << "Jane's hand is empty, draws a new card" << newCard.toString() << endl;
            }
        }
        else{
            //check pairs at the beginning of the round
            //p2.checkPairToBook();
            cout << p2.getName() <<" 's hand has : " << p2.showHand() << endl;
            cout << p2.getName() <<" 's book has : " << p2.showBooks() << endl;
            Card askCard = p2.chooseCardFromHand();
            cout << "Jane ask Joe for rank " << askCard.getRank() << endl;
            while(p1.rankInHand(askCard)){
                cout << "Joe says: Yes, I have a " << askCard.getRank() << endl;
                p1.removeAllCardsSameRank(askCard,p2);
                //p1.checkPairToBook();
                askCard = p2.chooseCardFromHand();
                cout << "Jane ask Joe for rank " << askCard.getRank() << endl;
            }
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                cout << "Jane's hand is empty, draws a new card" << newCard.toString() << endl;
            }
        }
    }

    cout << p1.getName() <<" 's book has : " << p1.showBooks() << endl;
    cout << p2.getName() <<" 's book has : " << p2.showBooks() << endl;
    if(p1.getBookSize()>p2.getBookSize()){
        cout << p1.getName() << " won!" << endl;
    }
    else if (p1.getBookSize()==p2.getBookSize()){
        cout << "Two players tie!" << endl;
    }
    else{
        cout << p2.getName() << " won!" << endl;
    }

    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}






