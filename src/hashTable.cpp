#include "../include/hashTable.hpp"

int HashTable::hashFunction(int id) {
    return id % TABLE_SIZE;
}

void HashTable::insert(Ticket ticket) {
    table[hashFunction(ticket.id)].add(ticket);
}

Ticket* HashTable::search(int id) {
    return table[hashFunction(id)].find(id);
}

void HashTable::remove(int id) {
    table[hashFunction(id)].removeById(id);
}