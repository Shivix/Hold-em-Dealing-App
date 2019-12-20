#include <random>
#include <wx/msgdlg.h>
#include "deck.hpp"

deck::card deck::drawnCard; // static member must be defined outside of the class
deck::card deck::drawnCard2;

deck::deck() = default;

deck::~deck() = default;

void deck::deal(){

    if(!deckEmpty){
        if (deckCounter < 52){
            drawnCard = deckVec[deckCounter++];
            drawnCard2 = deckVec[deckCounter++];
        }
        else{
            drawnCard = nullptr; // stops an image from being shown when the deck is empty
            drawnCard2 = nullptr;
            deckEmpty = true;
            wxMessageBox("The deck is empty, please press refill to refill the deck", "Deck Empty");
        }
    }
    else{
        wxMessageBox("The deck is empty, please press refill to refill the deck", "Deck Empty");
    }
}

void deck::shuffle(){
    std::random_device rd; // random number generator for shuffle
    std::mt19937 rn(rd()); // function since random_shuffle was removed in c++17
    std::shuffle(deckVec.begin(), deckVec.end(), rn); // shuffles the array of cards in a pseudo-random order
}

void deck::refill(){ // "refills" the deck by setting the counter that loops through the deckVec array to 0
    deckCounter = 0; 
    deckEmpty = false;
}
