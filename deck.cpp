#include "deck.h"
#include <string>
#include <ctime>
#include <cstdlib>

Deck::Deck(){
    myIndex = 0;
    for(int i=0;i<4;i++){
        for(int j=1;j<14;j++){
            myCards[i*13+j-1]=Card(j,(Card::Suit)i);
        }
    }
}

void Deck::shuffle(){
    unsigned int currentTime = (unsigned) time(0);
    srand(currentTime);
    for (int i = 0; i < 100; i++) {
        long die1 = (rand() % SIZE);
        long die2 = (rand() % SIZE);
        Card tempcard = myCards[die1];
        myCards[die1]=myCards[die2];
        myCards[die2]=tempcard;
    }
}

Card Deck::dealCard(){
    if(myIndex<=51) {
        Card c = myCards[myIndex];
        myIndex++;
        return c;
    }
}

int Deck::size() const{
    return (SIZE-myIndex);
}

