#pragma once
#include "ticketFactory.hpp"
#include "queue.hpp"
#include "doublyLinkedList.hpp"
#include "hashTable.hpp"
#include "stack.hpp"

class TicketSystem {
private:
    TicketFactory factory;
    Queue queue;
    DoublyLinkedList history;
    HashTable index;
    Stack undoStack;

public:
    void addIncident(int choice);
    void solveNext();
    void undo();
    void findTicket(int id);
    void showStatus() const;
    void showHistory() const;
    void listTypes() const;
};