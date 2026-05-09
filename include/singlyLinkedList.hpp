#pragma once

class SinglyLinkedList {
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void push_front(int value);
    void print() const;

private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
};