#include "app.hpp"

wxIMPLEMENT_APP(app); // main function

app::app() = default;

app::~app() = default;

bool app::OnInit(){
    frame = new mainWindow(); // adds and runs main window upon the application being started
    frame->Show(true);
    
    return true;
}