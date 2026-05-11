#pragma once

#include <string>
#include <vector>

class Stack {
private:
    std::vector<std::string> data;

public:
    void push(std::string action);
    std::string pop();
    void display();
    bool isEmpty();
};