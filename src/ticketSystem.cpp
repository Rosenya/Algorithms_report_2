#include "../include/ticketSystem.hpp"
#include <iostream>

using namespace std;

void TicketSystem::addIncident(int choice) {
    Ticket t = factory.create(choice);
    queue.enqueue(t);
    index.insert(t);
    undoStack.push(t);
    history.push_front("ZGLOSZONO: " + t.name + " (ID: " + to_string(t.id) + ")");

    cout << ">> Sukces: Dodano zgloszenie " << t.name << " [ID: " << t.id << "]\n";
}

void TicketSystem::solveNext() {
    Ticket t;
    if (queue.dequeue(t)) {
        history.push_front("ROZWIAZANO: " + t.name + " (ID: " + to_string(t.id) + ")");
        cout << ">> Przetworzono: " << t.name << " (ID: " << t.id << ")\n";
    } else {
        cout << ">> Info: Kolejka jest pusta.\n";
    }
}

void TicketSystem::undo() {
    Ticket lastTicket;
    if (undoStack.pop(lastTicket)) {
        history.push_front("UNDO: Cofnieto dodanie " + lastTicket.name + " [ID: " + to_string(lastTicket.id) + "]");
        cout << ">> Cofnieto ostatnia operacje (ID: " << lastTicket.id << ").\n";
    } else {
        cout << ">> Info: Brak operacji do cofniecia.\n";
    }
}

void TicketSystem::findTicket(int id) {
    Ticket found;
    if (index.find(id, found)) {
        cout << "--- Dane o incydencie ---\n";
        cout << "ID: " << found.id << "\n";
        cout << "Nazwa: " << found.name << "\n";
        cout << "Priorytet: " << found.priority << "\n";
    } else {
        cout << ">> Blad: Nie znaleziono incydentu o ID " << id << "\n";
    }
}

void TicketSystem::showStatus() const {
    cout << "\n=== AKTUALNA KOLEJKA PRIORYTETOWA ===\n";
    if (queue.isEmpty()) {
        cout << "(pusta)\n";
    } else {
        queue.print();
    }
}

void TicketSystem::showHistory() const {
    cout << "\n=== HISTORIA OPERACJI (LOGI) ===\n";
    history.print();
}

void TicketSystem::listTypes() const {
    factory.displayOptions();
}