// FILE: go_fish.cpp
// This is a main program which demonstrates and simulates the Go! Fish! game
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

/* FUNCTION - void dealHand(Deck &d, Player &p, int numCards)
 * the player will receive some number of random cards from the shuffled deck
     input parms - the player who is receiving card, the number of dealing cards and a deck of cards
     output parms - None
*/
void dealHand(Deck &d, Player &p, int numCards);

/* FUNCTION - void removeAllCardsSameRank(Card c, Player &findplayer, Player &askplayer)
 * the player asks for a specific cards, and the finding player must remove all cards
 * with that same rank from his deck, and those cards are added to the asking player's deck
     input parms - a card, two players
     output parms - None
*/
void removeAllCardsSameRank(Card c, Player &findplayer, Player &askplayer);

/* FUNCTION - void checkPairToBook(Player &player)
 * the player will check his deck for a pair of cards with the same rank, and the player will
 * book all pairs of same rank
     input parms - the player
     output parms - None
*/
void checkPairToBook(Player &player, ofstream &oFile);

int main( )
{
    ofstream oFile;
    oFile.open("gofish_results.txt");
    oFile << "Go Fish\n" << endl;

    int numCards = 7;

    Player p1("Joe");
    Player p2("Ana");

    Deck d;  //create a deck of cards
    oFile << "There are " << d.size() << " cards in the deck." << endl;
    d.shuffle();


    oFile << "Game start! Deal seven cards to both players!" << endl;
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    //show the player's initial hand
    oFile << p1.getName() <<"'s initial hand: " << p1.showHand() << endl;
    oFile << p2.getName() <<"'s initial hand: " << p2.showHand() << endl;

    //game ends if the total number of book deck size is 52 (all pairs have been booked)
    while((p1.getBookSize()+p2.getBookSize()) != 52){
        oFile << endl;
        oFile << p1.getName() << "'s turn:" << endl;
        //check pairs of cards at the beginning of the player's turn
        checkPairToBook(p1, oFile);

        //if the player's hand is empty, deal a new card and pass this turn
        if(p1.getHandSize() == 0){
            if(d.size() > 0) {
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                oFile << p1.getName() << "'s hand is empty, draws a " << newCard.toString() << endl;
            }
            else{
                //if the deck is empty, do nothing and pass this turn
                oFile << "The deck is empty!" << endl;
            }
        }

        //if the player's hand is not empty, ask the other player for a random rank
        else{
            oFile << p1.getName() <<"'s hand: " << p1.showHand() << endl;
            oFile << p1.getName() <<"'s book: " << p1.showBooks() << endl;
            Card askCard = p1.chooseCardFromHand();
            oFile << p1.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl;
            int indicator = 0;

            //if the other player has that rank, give all cards with that rank to this player, and keep asking for another rank
            while(p2.rankInHand(askCard)){
                oFile << p2.getName() << " says: Yes, I have a " << askCard.rankString(askCard.getRank()) << "." << endl;
                removeAllCardsSameRank(askCard,p2,p1);
                checkPairToBook(p1, oFile);
                if(p1.getHandSize() != 0) {
                    askCard = p1.chooseCardFromHand();
                    oFile << p1.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl;
                }
                else{
                    indicator = 1;
                }
            }

            //if the other player does not have that rank, he says "Go! Fish!"
            if(indicator == 0) {
                oFile << p2.getName() << " says: Go Fish!" << endl;
            }

            //this player will draw a new card and end his turn
            if(d.size() > 0) {
                Card newCard = d.dealCard();
                p1.addCard(newCard);
                oFile << p1.getName() <<" draws a " << newCard.toString() << endl;
            }
        }

        //Then it is the other player's turn, repeat the same rules
        oFile << endl << p2.getName() << "'s turn:" << endl;
        checkPairToBook(p2, oFile);
        if(p2.getHandSize() == 0){
            if(d.size() > 0) {
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                oFile << p2.getName() << "'s hand is empty, draws a " << newCard.toString() << endl;
            }
            else{
                oFile << "The deck is empty!" << endl;
            }
        }
        else{
            oFile << p2.getName() <<"'s hand: " << p2.showHand() << endl;
            oFile << p2.getName() <<"'s book: " << p2.showBooks() << endl;
            Card askCard = p2.chooseCardFromHand();
            oFile << p2.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl;
            int indicator = 0;
            while(p1.rankInHand(askCard)){
                oFile << p1.getName() << " says: Yes, I have a " << askCard.rankString(askCard.getRank()) << "." << endl;
                removeAllCardsSameRank(askCard,p1,p2);
                checkPairToBook(p2, oFile);
                if(p2.getHandSize() != 0) {
                    askCard = p2.chooseCardFromHand();
                    oFile << p2.getName() << " asks - Do you have a " << askCard.rankString(askCard.getRank()) << "?" << endl;
                }
                else{
                    indicator = 1;
                }
            }
            if(indicator == 0) {
                oFile << p1.getName() << " says: Go Fish!" << endl;
            }
            if(d.size() > 0) {
                Card newCard = d.dealCard();
                p2.addCard(newCard);
                oFile << p2.getName() << " draws " << newCard.toString() << endl;
            }
        }
    }

    //when the deck is empty and all pairs have been booked, the player with the most number of booked pairs won
    oFile << endl << endl;
    oFile << "Game Over!" << endl;
    oFile << p1.getName() << "'s book: " << p1.showBooks() << endl;
    oFile << p1.getName() << " booked " << p1.getBookSize() << " cards." << endl;
    oFile << p2.getName() << "'s book: " << p2.showBooks() << endl;
    oFile << p2.getName() << " booked " << p2.getBookSize() << " cards." << endl;
    if(p1.getBookSize() > p2.getBookSize()){
        oFile << p1.getName() << " won!" << endl;
    }
    else if (p1.getBookSize() == p2.getBookSize()){
        oFile << "Two players tie!" << endl;
    }
    else{
        oFile << p2.getName() << " won!" << endl;
    }

    oFile.close();
    return EXIT_SUCCESS;
}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i<numCards; i++)
        p.addCard(d.dealCard());
}

void removeAllCardsSameRank(Card c, Player &findplayer, Player &askplayer){
    for(int i=findplayer.getHandSize()-1; i>=0; i--){
        if(findplayer.rankInHand(c)){
            Card newcard = findplayer.removeCardFromHand(c);
            askplayer.addCard(newcard);
        }
    }
}

void checkPairToBook(Player &player, ofstream &oFile) {
    if (player.getHandSize() > 1) {
        int count = player.getHandSize()/2;
        while(count > 0){
            Card card1;
            Card card2;
            if(player.checkHandForBook(card1,card2)){
                player.bookCards(card1,card2);
                oFile << player.getName() << " books the " << card1.toString() << " and " << card2.toString() << "." << endl;
                player.removeCardFromHand(card1);
                player.removeCardFromHand(card2);
            }
            count--;
        }
    }
}





