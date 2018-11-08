//
// Created by Aditya Singh on 11/8/18.
//

#include "deck.h"
#include "card.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


Deck::Deck(){
    Card myCards[SIZE];
    const std::vector<Card::Suit> suits {Card::Suit::clubs, Card::Suit::diamonds, Card::Suit::hearts, Card::Suit::spades};
    int i = 0;
    for(const auto & s : suits) {
        for (int r = 0; r < 14; r++) {
            myCards[i] = Card(r, s);
            i++;
        }
    }
    int myIndex = 51;
//Vector Implementation??

    std::vector <Card> Cards{};
    for(const auto & s : suits) {
        for (int r = 0; r < 14; r++) {
            Cards.push_back(s,r);
        }
    }


};

void Deck::shuffle() {

// random generator function:
    std::random_shuffle (Cards.begin(), Cards.end());

    // print out content:
    std::cout << "deck contains:";
    for (std::vector<int>::iterator it=Cards.begin(); it!=Cards.end(); ++it){
        std::cout << ' ' << *it;
        std::cout << '\n';
    }

}

Card Deck::dealCard() {
    Card tempCard;
    tempCard = myCards[myIndex];
    myCards[myIndex] = NULL;
    myIndex--;
    return tempCard;
    //?? Not sure how to delete - I think we will have to use a pointer, maybe a vector of pointers

}

int Deck::size() const{
    return(Cards.size());   //what is "Cards"? where is it defined

}



