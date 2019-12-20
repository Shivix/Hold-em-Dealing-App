#ifndef HOLDEMDEALER_MAINWINDOW_HPP
#define HOLDEMDEALER_MAINWINDOW_HPP
#include <wx/wx.h>
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
    wxStaticBitmap* cardImage1 = nullptr;
    wxStaticBitmap* cardImage2 = nullptr;
    
    void dealButtonClick(wxCommandEvent &event);
    void shuffleButtonClick(wxCommandEvent &event);
    void refillButtonClick(wxCommandEvent &event);

    wxDECLARE_EVENT_TABLE();
};


#endif //HOLDEMDEALER_MAINWINDOW_HPP
