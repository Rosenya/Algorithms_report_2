#pragma once

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(int value);
    void print() const;

private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
};