// FILE: go_fish.cpp
// This is a main program which demonstrates and simulates the Go! Fish! game
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

//Input: the player who is reveiving card, the number of dealing cards and a deck of cards
//Output: none
//Function: the player will receive some number of random cards from the shuffled deck
void dealHand(Deck &d, Player &p, int numCards);

//Input: a card, two players
//Output: none
//Function: the player asks for a specific cards, and the finding player must remove all cards
//          with that same rank from his deck, and those cards are added to the asking player's deck
void removeAllCardsSameRank(Card c, Player &findplayer, Player &askplayer);

//Input: the player
//Output: none
//Function: the player will check his deck for a pair of cards with the same rank, and the player will
//          book all pairs of same rank
void checkPairToBook(Player &player);

int main( )
{
    int numCards = 7;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    cout << "There are " << d.size() << "cards in the deck." <<endl;
    d.shuffle();


    cout << "Game start! Deal seven cards to both players!" << endl;
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    //show the player's initial hand
    cout << p1.getName() <<" 's initial hand has : " << p1.showHand() << endl;
    cout << p2.getName() <<" 's initial hand has : " << p2.showHand() << endl;

    //game ends if the total number of book deck size is 52 (all pairs have been booked)
    while((p1.getBookSize()+p2.getBookSize())!=52){
        cout << endl << endl;
        cout << "Joe's turn:" << endl;
        //check pairs of cards at the beginning of the player's turn
        checkPairToBook(p1);

        //if the player's hand is empty, deal a new card and pass this turn
        if(p1.getHandSize()==0){
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                cout << "Joe's hand is empty, draws a new card " << newCard.toString() << endl;
            }
            else{
                //if the deck is empty, do nothing and pass this turn
                cout << "The deck is empty!" << endl;
            }
        }

        //if the player's hand is not empty, ask the other player for a random rank
        else{
            cout << p1.getName() <<" 's hand has : " << p1.showHand() << endl;
            cout << p1.getName() <<" 's book has : " << p1.showBooks() << endl;
            Card askCard = p1.chooseCardFromHand();
            cout << "Joe ask Jane for rank " << askCard.getRank() << endl;
            int indicator =0;

            //if the other player has that rank, give all cards with that rank to this player, and keep asking for another rank
            while(p2.rankInHand(askCard)){
                cout << "Jane says: Yes, I have a " << askCard.getRank() << endl;
                removeAllCardsSameRank(askCard,p2,p1);
                checkPairToBook(p1);
                if(p1.getHandSize()!=0) {
                    askCard = p1.chooseCardFromHand();
                    cout << "Joe ask Jane for rank " << askCard.getRank() << endl;
                }
                else{
                    indicator =1;
                }
            }

            //if the other player does not have that rank, he says "Go! Fish!"
            if(indicator==0) {
                cout << "Jane says: Go! Fish!" << endl;
            }

            //this player will draw a new card and end his turn
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                cout << "Joe draws a " << newCard.toString() << endl;
            }
        }

        //Then it is the other player's turn, repeat the same rules
        cout << endl << "Jane's turn:" << endl;
        checkPairToBook(p2);
        if(p2.getHandSize()==0){
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                cout << "Jane's hand is empty, draws a new card " << newCard.toString() << endl;
            }
            else{
                cout << "The deck is empty!" << endl;
            }
        }
        else{
            cout << p2.getName() <<" 's hand has : " << p2.showHand() << endl;
            cout << p2.getName() <<" 's book has : " << p2.showBooks() << endl;
            Card askCard = p2.chooseCardFromHand();
            cout << "Jane ask Joe for rank " << askCard.getRank() << endl;
            int indicator =0;
            while(p1.rankInHand(askCard)){
                cout << "Joe says: Yes, I have a " << askCard.getRank() << endl;
                removeAllCardsSameRank(askCard,p1,p2);
                checkPairToBook(p2);
                if(p2.getHandSize()!=0) {
                    askCard = p2.chooseCardFromHand();
                    cout << "Jane ask Joe for rank " << askCard.getRank() << endl;
                }
                else{
                    indicator =1;
                }
            }
            if(indicator==0) {
                cout << "Joe says: Go! Fish!" << endl;
            }
            if(d.size()>0) {
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                cout << "Jane draws a new card" << newCard.toString() << endl;
            }
        }
    }

    //when the deck is empty and all pairs have been booked, the player with the most number of booked pairs won
    cout << endl << endl;
    cout << "Game Over!" << endl;
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

void removeAllCardsSameRank(Card c, Player &findplayer, Player &askplayer){
    for(int i=findplayer.getHandSize()-1;i>=0;i--){
        if(findplayer.rankInHand(c)){
            Card newcard=findplayer.removeCardFromHand(c);
            askplayer.addCard(newcard);
        }
    }
}

void checkPairToBook(Player &player) {
    if (player.getHandSize()>1) {
        int count = player.getHandSize()/2;
        while(count>0){
            Card card1;
            Card card2;
            if(player.checkHandForBook(card1,card2)){
                player.bookCards(card1,card2);
                player.removeCardFromHand(card1);
                player.removeCardFromHand(card2);
            }
            count--;
        }
    }
}





