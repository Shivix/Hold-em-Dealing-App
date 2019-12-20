#ifndef HOLDEMDEALER_APP_HPP
#define HOLDEMDEALER_APP_HPP

#include "mainWindow.hpp"

class app : public wxApp {
public:
    app();
    ~app() override;
    
    bool OnInit() override;

private:
    mainWindow* frame = nullptr;
    
};


#endif //HOLDEMDEALER_APP_HPP
