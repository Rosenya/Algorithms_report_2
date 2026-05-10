#include "../include/stack.hpp"

Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    Ticket temp;
    while (pop(temp));
}

void Stack::push(const Ticket& ticket) {
    Node* newNode = new Node{ticket, top};
    top = newNode;
}

bool Stack::pop(Ticket& out) {
    if (isEmpty()) return false;
    
    Node* temp = top;
    out = top->data;
    top = top->next;
    delete temp;
    return true;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}