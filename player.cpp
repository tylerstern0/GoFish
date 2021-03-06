//
// Created by Aditya Singh on 11/8/18.
//
#include "player.h"
#include "deck.h"
#include "card.h"
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

Player::Player(){
    //copy constructor

}

Player::Player(string _name){
    myName = _name;

    vector <Card> myHand;

    vector <Card> myBook;

}

string Player::getName() const {
    return myName;
}

void Player::addCard(Card c){
    if(myHand.size() < 52){
        myHand.push_back(c);
    }
    else{
        cout<<"Hand is Full"<<endl;
    }
}

Card Player::removeCardFromHand(Card c) {

    Card tempCard;

    for(int i = 0; i<myHand.size(); i++)
    {
        if(myHand[i] == c){
            tempCard = myHand[i];
            myHand.erase(myHand.begin()+i);
        }

    }

    return(tempCard);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

}

bool Player::checkHandForBook(Card &c1, Card &c2) {

    for(int i = 0; i<myHand.size(); i++){
        for(int j = 0; j<myHand.size(); j++)
            if(myHand[i].getSuit() != myHand[j].getSuit())
            {
                if(myHand[i] == myHand[j]){
                    c1 = myHand[i];
                    c2 = myHand[j];
                    bookCards(c1, c2);

                    removeCardFromHand(c1);

                    removeCardFromHand(c2);


                    return(true);
                }


            }
    }
    return(false);
}

bool Player::rankInHand(Card c) const {
    for(int i = 0; i<myHand.size(); i++)
    {
        if(myHand[i].getRank() == c.getRank()){
            return(true);
        }

    }
    return(false);


}

Card Player::chooseCardFromHand() const {
    srand((unsigned)time(0));  //seed the random number generator

        int i = (rand() % myHand.size());
        return (myHand[i]);
}

Card Player::searchHand(Card c) const {
    Card newCard;

    for (int i = 0; i < getHandSize(); i++){
        if(myHand[i].getRank() == c.getRank()){
            newCard  = myHand[i];
        }
    }
    return newCard;
}

bool Player::cardInHand(Card c) const {
    for(int i = 0; i<myHand.size(); i++)
    {
        if(myHand[i] == c){
            return(true);
        }

    }
    return(false);

}


int Player::getBookSize() const {
    return((myBook.size())/2);

}

int Player::getHandSize() const {
    return(myHand.size());
}

string Player::showHand() const {
    string hand_content;
    for(int i =0; i<myHand.size(); i++){
        hand_content = hand_content + myHand[i].toString() + "  ";
    }
    return(hand_content);
}
string Player::showBooks() const {
    string book_content;
    for(int i =0; i<myBook.size(); i++){
        book_content = book_content + myBook[i].toString() + "  ";
    }
    return(book_content);
}

bool Player::handEmpty() const {
    return (myHand.empty());
}

