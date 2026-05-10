#pragma once
#include "singlyLinkedList.hpp"

class Queue {
public:
    void enqueue(const Ticket& ticket);
    bool dequeue(Ticket& out);
    bool isEmpty() const;
    void print() const;

private:
    SinglyLinkedList list;
};