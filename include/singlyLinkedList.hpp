#pragma once
#include "ticket.hpp"

class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void insertSorted(const Ticket& ticket);
    bool removeFront(Ticket& out);
    bool findById(int id, Ticket& out) const;
    void removeById(int id);
    bool isEmpty() const;
    void print() const;

private:
    struct Node {
        Ticket data;
        Node* next;
    };

    Node* head;
    Node* tail;
};