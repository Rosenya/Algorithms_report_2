#include "../include/singlyLinkedList.hpp"
#include <iostream>

SinglyLinkedList::SinglyLinkedList() : head(nullptr) {}

SinglyLinkedList::~SinglyLinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void SinglyLinkedList::add(Ticket t) {
    Node* newNode = new Node(t);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void SinglyLinkedList::insertSorted(Ticket t) {
    Node* newNode = new Node(t);
    if (head == nullptr || t.priority > head->data.priority) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr && current->next->data.priority >= t.priority) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void SinglyLinkedList::removeById(int id) {
    if (head == nullptr) return;
    if (head->data.id == id) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* current = head;
    while (current->next != nullptr && current->next->data.id != id) {
        current = current->next;
    }
    if (current->next != nullptr) {
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
}

Ticket* SinglyLinkedList::find(int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.id == id) {
            return &(temp->data);
        }
        temp = temp->next;
    }
    return nullptr;
}

void SinglyLinkedList::display() {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << "ID: " << temp->data.id << " | " << temp->data.name 
                  << " | Prio: " << temp->data.priority << std::endl;
        temp = temp->next;
    }
}

bool SinglyLinkedList::isEmpty() {
    return head == nullptr;
}

Ticket* SinglyLinkedList::getHeadData() {
    if (head != nullptr) return &(head->data);
    return nullptr;
}

void SinglyLinkedList::removeFirst() {
    if (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}