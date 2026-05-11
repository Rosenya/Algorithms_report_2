#pragma once

#include "ticket.hpp"
#include <string>
#include <vector>

class TicketFactory {
private:
    int nextId;
    std::vector<std::string> names;
    std::vector<int> priorities;

public:
    TicketFactory();
    Ticket createTicket(int typeIndex, int id);
    void listTypes();
    int getTypesCount();
};