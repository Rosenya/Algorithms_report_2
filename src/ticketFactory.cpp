#include "../include/ticketFactory.hpp"
#include <iostream>

TicketFactory::TicketFactory() 
    : nextId(1), 
      names({
          "Phishing",             // 0
          "Vulnerability scan",   // 1
          "Malware outbreak",     // 2
          "Password spray",       // 3
          "Brute force",          // 4
          "Logic bomb",           // 5
          "Account compromise",   // 6
          "SQL injection"         // 7
      }),
      priorities({
          1, // Phishing (Medium)
          0, // Vulnerability scan (Low)
          3, // Malware outbreak (Critical)
          1, // Password spray (Medium)
          2, // Brute force (High)
          3, // Logic bomb (Critical)
          2, // Account compromise (High)
          3  // SQL injection (Critical)
      }) {}

Ticket TicketFactory::createTicket(int typeIndex, int id) {
    Ticket t;
    t.id = id;
    if (typeIndex >= 0 && typeIndex < (int)names.size()) {
        t.name = names[typeIndex];
        t.priority = priorities[typeIndex];
    } else {
        t.name = "Unknown Incident";
        t.priority = 0;
    }
    return t;
}

void TicketFactory::listTypes() {
    std::cout << "\n--- DOSTEPNE TYPY INCYDENTOW ---" << std::endl;
    for (int i = 0; i < (int)names.size(); ++i) {
        std::cout << i << ". " << names[i] 
                  << " (Priorytet: " << priorities[i] << ")" << std::endl;
    }
}

int TicketFactory::getTypesCount() {
    return (int)names.size();
}