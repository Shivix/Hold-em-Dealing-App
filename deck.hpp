#ifndef HOLDEMDEALER_DECK_HPP
#define HOLDEMDEALER_DECK_HPP

#include <vector>
#include <wx/wx.h>

class deck{
public:
    
    deck();
    ~deck();
    
    void deal();
    void shuffle();
    void refill();
    
    typedef wxImage card; // increases readability since cards are just stored as images
    
    card drawnCard;
    card drawnCard2;
    card drawnCard3;
    
    bool deckEmpty = false;
    
    enum class phase{
        preflop,
        flop,
        turn,
        river,
        reset
    };
    enum phase phase;
    enum phase prevPhase;
    
private:
    int deckCounter = 0;
    
    std::vector<card> deckVec = { // images must be bitmaps, can be resized in code however were sized correctly precode to reduce file size
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\2H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\3H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\4H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\5H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\6H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\7H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\8H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\9H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\10H.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\JH.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\QH.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\KH.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\AH.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\2D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\3D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\4D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\5D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\6D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\7D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\8D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\9D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\10D.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\JD.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\QD.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\KD.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\AD.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\2C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\3C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\4C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\5C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\6C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\7C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\8C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\9C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\10C.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\JC.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\QC.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\KC.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\AC.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\2S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\3S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\4S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\5S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\6S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\7S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\8S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\9S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\10S.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\JS.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\QS.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\KS.bmp")),
        wxImage(_T("C:\\Users\\Mark\\CLionProjects\\Holdemdealer\\images\\AS.bmp"))
    };
};



#endif //HOLDEMDEALER_DECK_HPP
