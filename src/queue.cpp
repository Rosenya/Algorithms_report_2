#include "../include/queue.hpp"

void Queue::enqueue(Ticket t) {
    list.add(t);
}

void Queue::push(Ticket t) {
    list.insertSorted(t);
}

void Queue::insertSorted(Ticket t) {
    list.insertSorted(t);
}

void Queue::dequeue() {
    list.removeFirst();
}

Ticket* Queue::peek() {
    return list.getHeadData();
}

void Queue::display() {
    list.display();
}

bool Queue::isEmpty() {
    return list.isEmpty();
}