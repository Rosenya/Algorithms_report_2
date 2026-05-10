#include "../include/hashTable.hpp"

int HashTable::hashFunction(int id) const {
    return id % SIZE;
}

void HashTable::insert(const Ticket& ticket) {
    int index = hashFunction(ticket.id);
   
    table[index].addBack(ticket);
}

bool HashTable::find(int id, Ticket& out) const {
    int index = hashFunction(id);
    return table[index].findById(id, out);
}