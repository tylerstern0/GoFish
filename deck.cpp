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
    unsigned int currentTime =  (unsigned)time(0);  //get time
    srand(currentTime);                             //seed w/ time
    Card tempCard;
    int swapIndex = 0;
    int tempIndex = myIndex;

    while(tempIndex >= 0) {
        swapIndex = (rand() % tempIndex);
        tempCard = myCards[swapIndex];
        myCards[swapIndex] = myCards[tempIndex];
        myCards[tempIndex] = tempCard;
        tempIndex--;
    }

/*

    int numSongs = 0;

    while(ctrptr != nullptr){             //count the number of nodes in the list -- should we implement as a function?
        numSongs++;
        ctrptr = ctrptr->next;
    }
    cout << "numSongs=" << numSongs << endl;

    while(ptr1 != nullptr){
        ptr2 = ptr1;
        ptr3 = ptr1;
        int random = (rand() % numSongs);   //select a random index to swap to
        cout << random << endl;
        for(int i = 0; i < random; i++){
            if(ptr2->next != nullptr) {     //traverse through the list random number of times, rolling over if you hit null
                ptr2 = ptr2->next;
            }else{
                ptr2=head;
            }

        }
        cout << "Swapping songs:" << ptr3->s.getName() << "and" << ptr2->s.getName() << endl;
        swap(ptr3, ptr2);                  //swap current position to current position + random
        ptr1 = ptr1 -> next;               //move ptr1 to next 'unshuffled' element (it may have already been shuffled and placed there)

    }

*/

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



