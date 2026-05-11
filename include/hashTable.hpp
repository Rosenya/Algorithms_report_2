#pragma once

#include "ticket.hpp"
#include "singlyLinkedList.hpp"

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    SinglyLinkedList table[TABLE_SIZE];
    int hashFunction(int id);

public:
    void insert(Ticket ticket);
    Ticket* search(int id);
    void remove(int id);
};