#include "../include/ticketSystem.hpp"
#include <iostream>
#include <string>

TicketSystem::TicketSystem() : nextId(101) {}

void TicketSystem::push(int typeIndex) {
    Ticket t = factory.createTicket(typeIndex, nextId++);
    priorityQueue.insertSorted(t);
    index.insert(t);
    history.push("Dodano (Priority): " + t.name + " [ID: " + std::to_string(t.id) + "]");
}

void TicketSystem::enqueue(int typeIndex) {
    Ticket t = factory.createTicket(typeIndex, nextId++);
    priorityQueue.insertSorted(t);
    index.insert(t);
    history.push("Dodano (FIFO): " + t.name + " [ID: " + std::to_string(t.id) + "]");
}

void TicketSystem::pop() {
    Ticket* t = priorityQueue.peek();
    if (t != nullptr) {
        history.push("Rozwiazano: " + t->name + " [ID: " + std::to_string(t->id) + "]");
        index.remove(t->id);
        priorityQueue.dequeue();
    } else {
        std::cout << "Brak zgloszen." << std::endl;
    }
}

void TicketSystem::dequeue() {
    pop();
}

void TicketSystem::search(int id) {
    Ticket* t = index.search(id);
    if (t != nullptr) {
        std::cout << "Znaleziono: " << t->name << " (Prio: " << t->priority << ")" << std::endl;
    } else {
        std::cout << "Nie znaleziono ID: " << id << std::endl;
    }
}

void TicketSystem::undo() {
    std::string lastAction = history.pop();
    if (!lastAction.empty()) {
        std::cout << "Cofanie operacji: " << lastAction << std::endl;
    } else {
        std::cout << "Brak operacji do cofniecia." << std::endl;
    }
}

void TicketSystem::listTypes() {
    factory.listTypes();
}

void TicketSystem::showStatus() {
    priorityQueue.display();
}

void TicketSystem::showHistory() {
    history.display();
}