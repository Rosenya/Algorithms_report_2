#include "../include/doublyLinkedList.hpp"
#include <iostream>
using namespace std;

DoublyLinkedList::DoublyLinkedList()
    : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList()
{
    Node* temp = head;

    while (temp != nullptr)
    {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}

void DoublyLinkedList::push_front(const string& operation)
{
    Node* newNode = new Node();
    newNode->operation = operation;
    newNode->next = head;
    newNode->prev = nullptr;

    if (head != nullptr)
    {
        head->prev = newNode;
    }
    else
    {
        tail = newNode;
    }

    head = newNode;
}

void DoublyLinkedList::print() const
{
    const Node* temp = head;

    while (temp != nullptr)
    {
        cout << temp->operation << endl;
        temp = temp->next;
    }
}