#pragma once
#include "ticket.hpp"

class Stack {
private:
    struct Node {
        Ticket data;
        Node* next;
    };
    Node* top;

public:
    Stack();
    ~Stack();

    void push(const Ticket& ticket);
    bool pop(Ticket& out);
    bool isEmpty() const;
};