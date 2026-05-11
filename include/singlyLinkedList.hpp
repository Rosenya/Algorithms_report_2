#pragma once

#include "ticket.hpp"

struct Node {
    Ticket data;
    Node* next;
    Node(Ticket t) : data(t), next(nullptr) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    void add(Ticket t);
    void insertSorted(Ticket t);
    void removeById(int id);
    Ticket* find(int id);
    void display();
    bool isEmpty();
    Ticket* getHeadData();
    void removeFirst();
};