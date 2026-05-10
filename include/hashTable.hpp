#pragma once
#include "singlyLinkedList.hpp"

class HashTable {
public:
    void insert(const Ticket& ticket);
    bool find(int id, Ticket& out) const;
private:
    static const int SIZE = 13;
    SinglyLinkedList table[SIZE];
    int hashFunction(int id) const;
};