#include "../include/menu.hpp"
#include <iostream>
#include <limits>
#include <chrono>

using namespace std;

Menu::Menu(TicketSystem &ts) : system(ts), running(true) {}

void Menu::clearInput() const
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Menu::getIntInput() const
{
    int input;
    while (true)
    {
        if (cin >> input)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
        else
        {
            cout << "!! Blad: Wymagana liczba. Sprobuj ponownie: ";
            clearInput();
        }
    }
}

void Menu::displayMenu() const
{
    cout << "\n=== SYSTEM ZARZADZANIA INCYDENTAMI ===\n";
    cout << "1. Wyswietl kategorie\n";
    cout << "2. Dodaj zgloszenie\n";
    cout << "3. Rozwiaz nastepne\n";
    cout << "4. Stan kolejki\n";
    cout << "5. Historia operacji\n";
    cout << "6. Cofnij ostatnie (Undo)\n";
    cout << "7. Szukaj po ID\n";
    cout << "8. TEST: Generuj 100 zgloszen\n";
    cout << "0. Wyjscie\n";
    cout << "Wybor: ";
}

void Menu::run()
{
    while (running)
    {
        displayMenu();
        int choice = getIntInput();

        switch (choice)
        {
        case 1:
            system.listTypes();
            break;
        case 2:
        {
            system.listTypes();
            cout << "Wybor: ";
            int choice = getIntInput();

            if (choice < 1 || choice > 8)
            {
                cout << "!! Blad: Nieprawidlowa kategoria.\n";
            }
            else
            {
                system.addIncident(choice - 1);
            }
            break;
        }
        case 3:
            system.solveNext();
            break;
        case 4:
            system.showStatus();
            break;
        case 5:
            system.showHistory();
            break;
        case 6:
            system.undo();
            break;
        case 7:
        {
            cout << "Podaj ID: ";
            int searchId = getIntInput();

            auto start = chrono::high_resolution_clock::now();
            system.findTicket(searchId);
            auto end = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji (Hash Table): " << duration.count() << " us" << endl;
            break;
        }

        case 8:
        {
            cout << "Liczba zgloszen (1: 50, 2: 100, 3: 1000): ";
            int amountChoice = getIntInput();
            int n = (amountChoice == 1) ? 50 : (amountChoice == 2) ? 100
                                                                   : 1000;

            auto start = chrono::high_resolution_clock::now();
            for (int i = 0; i < n; i++)
            {
                system.addIncident(i % 8);
            }
            auto end = chrono::high_resolution_clock::now();

            auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
            cout << ">> Wygenerowano " << n << " zgloszen w czasie: " << duration.count() << " ms" << endl;
            break;
        }
        default:
            cout << "!! Blad: Opcja poza zakresem.\n";
            break;
        }
    }
}