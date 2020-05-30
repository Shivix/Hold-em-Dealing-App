#include "mainWindow.hpp"

wxBEGIN_EVENT_TABLE(mainWindow, wxFrame)
EVT_BUTTON(10001, mainWindow::dealButtonClick) // binds functions to buttons
EVT_BUTTON(10002, mainWindow::shuffleButtonClick)
EVT_BUTTON(10003, mainWindow::refillButtonClick)
EVT_BUTTON(10004, mainWindow::communityButtonClick)
wxEND_EVENT_TABLE()

mainWindow::mainWindow() : wxFrame(nullptr, wxID_ANY, "Main Window", wxPoint(500, 200), wxSize(1000, 800), wxDEFAULT_FRAME_STYLE, wxFrameNameStr){ // main window that is opened on program start
    dealButton = new wxButton(this, 10001, "Deal", wxPoint(10, 10), wxSize(150, 50));
    shuffleButton = new wxButton(this, 10002, "Shuffle", wxPoint(10, 70), wxSize(150, 50));
    refillButton = new wxButton(this, 10003, "Refill", wxPoint(10, 130), wxSize(150, 50));
    communityButton = new wxButton(this, 10004, "Flop", wxPoint(10, 190), wxSize(150, 50));
    SetBackgroundColour(*wxWHITE);
}

mainWindow::~mainWindow() = default;

    void mainWindow::dealButtonClick(wxCommandEvent &event){ // function runs every time the deal button is clicked
        wxDELETE(cardImage); // images must be deleted else they overlap and cause errors.
        wxDELETE(cardImage2);
        deck.prevPhase = deck.phase;
        deck.phase = deck::phase::preflop;
        deck.deal();
        cardImage = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard), wxPoint(200, 10), wxSize(150, 229), wxNO_BORDER, "1st Card");
        cardImage2 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard2), wxPoint(350, 10), wxSize(150, 229), wxNO_BORDER, "2nd Card");
        deck.phase = deck.prevPhase;
        event.Skip(); // tells the program that the event has been completed
    }

    void mainWindow::shuffleButtonClick(wxCommandEvent &event){ // function runs every time the shuffle button is clicked
        deck.shuffle();
        wxMessageBox("The deck was shuffled!", "Shuffled");
        event.Skip();
}

void mainWindow::refillButtonClick(wxCommandEvent &event){ // function runs every time the shuffle button is clicked
    deck.refill();
    wxDELETE(cardImage);
    wxDELETE(cardImage2);
    wxDELETE(communityImage);
    wxDELETE(communityImage2);
    wxDELETE(communityImage3);
    wxDELETE(communityImage4);
    wxDELETE(communityImage5);
    wxMessageBox("The deck has been refilled", "Deck Refilled");
    deck.phase = deck::phase::preflop;
    event.Skip();
}

void mainWindow::communityButtonClick(wxCommandEvent &event){ // function runs every time the shuffle button is clicked
    if(deck.phase == deck::phase::flop || deck.phase == deck::phase::preflop){
        deck.phase = deck::phase::flop;
        deck.deal();
        communityImage = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard), wxPoint(200, 250), wxSize(150, 229), wxNO_BORDER, "2nd Card");
        communityImage2 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard2), wxPoint(350, 250), wxSize(150, 229), wxNO_BORDER, "2nd Card");
        communityImage3 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard3), wxPoint(500, 250), wxSize(150, 229), wxNO_BORDER, "2nd Card");
        deck.phase = deck::phase::turn;
        wxDELETE(communityButton);
        communityButton = new wxButton(this, 10004, "Turn", wxPoint(10, 190), wxSize(150, 50));
    }
    else if(deck.phase == deck::phase::turn){
        deck.deal();
        communityImage4 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard), wxPoint(650, 250), wxSize(150, 229), wxNO_BORDER, "2nd Card");
        deck.phase = deck::phase::river;
        wxDELETE(communityButton);
        communityButton = new wxButton(this, 10004, "River", wxPoint(10, 190), wxSize(150, 50));
    }
    else if(deck.phase == deck::phase::river){
        deck.deal();
        communityImage5 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck.drawnCard), wxPoint(800, 250), wxSize(150, 229), wxNO_BORDER, "2nd Card");
        deck.phase = deck::phase::reset;
        wxDELETE(communityButton);
        communityButton = new wxButton(this, 10004, "Reset", wxPoint(10, 190), wxSize(150, 50));
    }
    else{
        wxDELETE(communityImage);
        wxDELETE(communityImage2);
        wxDELETE(communityImage3);
        wxDELETE(communityImage4);
        wxDELETE(communityImage5);
        deck.phase = deck::phase::preflop;
    }
    event.Skip();
}