#pragma once

#include "queue.hpp"
#include "hashTable.hpp"
#include "stack.hpp"
#include "ticketFactory.hpp"
#include <string>

class TicketSystem {
private:
    Queue priorityQueue;
    HashTable index;
    Stack history;
    TicketFactory factory;
    int nextId;

public:
    TicketSystem();
    void push(int typeIndex);
    void pop();
    void enqueue(int typeIndex);
    void dequeue();
    void search(int id);
    void undo();
    void listTypes();
    void showStatus();
    void showHistory();
};