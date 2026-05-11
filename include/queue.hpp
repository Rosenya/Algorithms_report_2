#pragma once

#include "singlyLinkedList.hpp"

class Queue {
private:
    SinglyLinkedList list;

public:
    void enqueue(Ticket t);
    void push(Ticket t);
    void dequeue();
    Ticket* peek();
    void display();
    bool isEmpty();
    void insertSorted(Ticket t);
};