#pragma once
#include <string>
using namespace std;

class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(const string& operation);
    void print() const;

private:
    struct Node {
        string operation;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
};