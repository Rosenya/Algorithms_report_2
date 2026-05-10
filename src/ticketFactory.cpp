#include "../include/ticketFactory.hpp"

TicketFactory::TicketFactory() 
    : nextId(1), 
      names({
          "Phishing",                   // 0
          "Vulnerability scan",         // 1
          "Malware outbreak",           // 2
          "Password spray",             // 3
          "Brute force",                // 4
          "Logic bomb",                 // 5
          "Account compromise",         // 6
          "SQL injection"               // 7
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

Ticket TicketFactory::create(int choice) {
    Ticket t;
    t.id = nextId++;
    
    size_t index = choice % names.size(); 
    
    t.name = names[index];
    t.priority = priorities[index];
    return t;
}

void TicketFactory::displayOptions() const {
    std::cout << "--- Wybierz typ incydentu ---\n";
    for(size_t i = 0; i < names.size(); i++) {
        std::cout << i << ". " << names[i] << " (Priorytet: " << priorities[i] << ")\n";
    }
}