#include "../include/stack.hpp"
#include <iostream>

void Stack::push(std::string action) {
    data.push_back(action);
}

std::string Stack::pop() {
    if (data.empty()) {
        return "";
    }
    std::string last = data.back();
    data.pop_back();
    return last;
}

void Stack::display() {
    if (data.empty()) {
        std::cout << "Historia jest pusta." << std::endl;
        return;
    }
    for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i) {
        std::cout << "- " << data[i] << std::endl;
    }
}

bool Stack::isEmpty() {
    return data.empty();
}