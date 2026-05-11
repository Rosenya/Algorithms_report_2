#include "../include/ticketSystem.hpp"
#include "../include/menu.hpp"

int main() {
    TicketSystem engine;
    Menu gui(engine);
    
    gui.run();
    
    return 0;
}