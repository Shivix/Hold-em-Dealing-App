#include <random>
#include <wx/msgdlg.h>
#include <chrono>
#include "deck.hpp"

    deck::deck() = default;

    deck::~deck() = default;

    void deck::deal(){

    if(!deckEmpty){
        if(deckCounter < 52){
            if(phase == phase::preflop){
                drawnCard = deckVec[deckCounter++];
                drawnCard2 = deckVec[deckCounter++];
            }
            else if(phase == phase::flop){
                drawnCard = deckVec[deckCounter++];
                drawnCard2 = deckVec[deckCounter++];
                drawnCard3 = deckVec[deckCounter++];
            }
            else{ // turn and river are dealt the same so can be handled in same if statement
                drawnCard = deckVec[deckCounter++];
            }
        }
        else{
            drawnCard = nullptr; // stops an image from being shown when the deck is empty
            drawnCard2 = nullptr;
            drawnCard3 = nullptr;
            deckEmpty = true;
            wxMessageBox("The deck is empty, please press refill to refill the deck", "Deck Empty");
        }
    }
    else{
        wxMessageBox("The deck is empty, please press refill to refill the deck", "Deck Empty");
    }
}

void deck::shuffle(){
    std::shuffle(deckVec.begin(), deckVec.end(), std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count())); // shuffles the array of cards in a pseudo-random order
}

void deck::refill(){ // "refills" the deck by setting the counter that loops through the deckVec array to 0
    deckCounter = 0; 
    deckEmpty = false;
}
