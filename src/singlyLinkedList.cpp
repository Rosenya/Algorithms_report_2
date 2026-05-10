#include "../include/singlyLinkedList.hpp"
#include <iostream>

SinglyLinkedList::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

SinglyLinkedList::~SinglyLinkedList()
{
    Node* current = head;

    while (current)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}

void SinglyLinkedList::addBack(const Ticket& ticket)
{
    Node* newNode = new Node{ticket, nullptr};

    if (!head)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

bool SinglyLinkedList::removeFront(Ticket& out)
{
    if (!head) return false;

    Node* temp = head;
    out = head->data;
    head = head->next;

    if (!head)
        tail = nullptr;

    delete temp;
    return true;
}

bool SinglyLinkedList::findById(int id, Ticket& out) const {
    Node* current = head;
    while (current) {
        if (current->data.id == id) {
            out = current->data;
            return true;
        }
        current = current->next;
    }
    return false;
}

bool SinglyLinkedList::isEmpty() const
{
    return head == nullptr;
}

void SinglyLinkedList::print() const
{
    Node* current = head;

    while (current)
    {
        std::cout << current->data.id << " -> ";
        current = current->next;
    }

    std::cout << "nullptr\n";
}