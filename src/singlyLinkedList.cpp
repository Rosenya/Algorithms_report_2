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

void SinglyLinkedList::insertSorted(const Ticket& data)
{
    Node* newNode = new Node{data, nullptr};

    if (head == nullptr || data.priority > head->data.priority)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data.priority >= data.priority)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
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

void SinglyLinkedList::removeById(int id) {
    if (!head) return;

    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next) {
        if (current->next->data.id == id) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}

bool SinglyLinkedList::isEmpty() const
{
    return head == nullptr;
}

void SinglyLinkedList::print() const {
    if (head == nullptr) {
        cout << "(kolejka jest pusta)" << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << "[ID: " << current->data.id << "] " 
             << current->data.name 
             << " (Priorytet: " << current->data.priority << ")";
        
        if (current->next != nullptr) {
            cout << "\n  V\n";
        }
        current = current->next;
    }
    cout << endl;
}