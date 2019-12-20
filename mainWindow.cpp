#include "mainWindow.hpp"

wxBEGIN_EVENT_TABLE(mainWindow, wxFrame)
EVT_BUTTON(10001, mainWindow::dealButtonClick) // binds functions to buttons
EVT_BUTTON(10002, mainWindow::shuffleButtonClick)
EVT_BUTTON(10003, mainWindow::refillButtonClick)
wxEND_EVENT_TABLE()

mainWindow::mainWindow() : wxFrame(nullptr, wxID_ANY, "Main Window", wxPoint(600, 300), wxSize(525, 289), wxDEFAULT_FRAME_STYLE, wxFrameNameStr){ // main window that is opened on program start
    dealButton = new wxButton(this, 10001, "Deal", wxPoint(10, 10), wxSize(150, 50));
    shuffleButton = new wxButton(this, 10002, "Shuffle", wxPoint(10, 70), wxSize(150, 50));
    refillButton = new wxButton(this, 10003, "Refill", wxPoint(10, 130), wxSize(150, 50));
    SetBackgroundColour(*wxWHITE);
}

mainWindow::~mainWindow() = default;

void mainWindow::dealButtonClick(wxCommandEvent &event){ // function runs every time the deal button is clicked
    delete cardImage1; // images must be deleted else they overlap and cause errors.
    delete cardImage2;
    deck.deal();
    cardImage1 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck::drawnCard), wxPoint(200, 10), wxSize(150, 229), wxNO_BORDER, "1st Card");
    cardImage2 = new wxStaticBitmap(this, wxID_ANY, wxBitmap(deck::drawnCard2), wxPoint(350, 10), wxSize(150, 229), wxNO_BORDER, "2nd Card");
    event.Skip(); // tells the program that the event has been completed
}

void mainWindow::shuffleButtonClick(wxCommandEvent &event){ // function runs every time the shuffle button is clicked
    deck.shuffle();
    wxMessageBox("The deck was shuffled!", "Shuffled");
    event.Skip();
}

void mainWindow::refillButtonClick(wxCommandEvent &event){ // function runs every time the shuffle button is clicked
    deck.refill();
    wxMessageBox("The deck has been refilled", "Deck Refilled");
    event.Skip();
}