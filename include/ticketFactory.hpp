#pragma once
#include "ticket.hpp"
#include <vector>
#include <string>
#include <iostream>

class TicketFactory {
private:
    int nextId;
    const vector<string> names;
    const vector<int> priorities;

public:
    TicketFactory();
    Ticket create(int choice);
    void displayOptions() const;
};