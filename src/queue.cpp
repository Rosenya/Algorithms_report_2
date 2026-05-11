#include "../include/queue.hpp"

void Queue::enqueue(const Ticket& ticket)
{
    list.insertSorted(ticket);
}

bool Queue::dequeue(Ticket& out)
{
    return list.removeFront(out);
}

bool Queue::isEmpty() const { 
    return list.isEmpty(); 
}

void Queue::print() const
{
    list.print();
}