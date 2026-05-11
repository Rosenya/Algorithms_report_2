#pragma once
#include "ticketSystem.hpp"

class Menu {
private:
    TicketSystem& system;
    bool running;

    void displayMenu() const;
    void clearInput() const;
    int getIntInput() const;

public:
    Menu(TicketSystem& ts);
    void run();
};