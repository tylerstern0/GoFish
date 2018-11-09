//
// Created by Aditya Singh on 11/8/18.
//

#include "deck.h"
#include "card.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


Deck::Deck() {
    //Card myCards[SIZE];

    for (int r = 0; r < 13; r++) {
        myCards[r] = Card(r, (Card::Suit) 0);
    }
    for (int r = 0; r < 13; r++) {
        myCards[r+13] = Card(r, (Card::Suit) 1);
    }
    for (int r = 0; r < 13; r++) {
        myCards[r+25] = Card(r, (Card::Suit) 2);
    }
    for (int r = 0; r < 14; r++) {
        myCards[r+38] = Card(r, (Card::Suit) 3);
    }

    myIndex = 51;
}



void Deck::shuffle() {

    srand((unsigned)time(0));  //seed the random number generator
    Card tempCard;
    int swapIndex = 0;
    int tempIndex = myIndex; // this effectively hides the cards that are dealt


    while(tempIndex > 0) {
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


    int temp = myIndex;
    myIndex--;
    cout << myIndex << endl;
    cout<<myCards[temp].toString()<<endl;
    return myCards[temp];

    //if(Deck::size() > 0){


    //}
    //else{
    //    cout<<"No More Cards Left"<<endl;
   // }

}

int Deck::size() const{
    return (myIndex + 1);
}



