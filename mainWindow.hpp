#ifndef HOLDEMDEALER_MAINWINDOW_HPP
#define HOLDEMDEALER_MAINWINDOW_HPP

#include "deck.hpp"

class mainWindow : public wxFrame{
public:
    mainWindow();
    ~mainWindow() override;
    
    deck deck;
    
private:

    wxButton* dealButton = nullptr;
    wxButton* shuffleButton = nullptr;
    wxButton* refillButton = nullptr;
    wxButton* communityButton = nullptr;
    wxStaticBitmap* cardImage = nullptr;
    wxStaticBitmap* cardImage2 = nullptr;
    wxStaticBitmap* communityImage = nullptr;
    wxStaticBitmap* communityImage2 = nullptr;
    wxStaticBitmap* communityImage3 = nullptr;
    wxStaticBitmap* communityImage4 = nullptr;
    wxStaticBitmap* communityImage5 = nullptr;
    
    void dealButtonClick(wxCommandEvent &event);
    void shuffleButtonClick(wxCommandEvent &event);
    void refillButtonClick(wxCommandEvent &event);
    void communityButtonClick(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};


#endif //HOLDEMDEALER_MAINWINDOW_HPP
