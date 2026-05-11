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
    cout << "8. TEST: Generuj 50/100/1000 zgloszen\n";
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
        case 0:
        {
            cout << "Zamykanie systemu...\n"
                 << endl;
            running = false;
            break;
        }

        case 1:
        {
            auto start = chrono::high_resolution_clock::now();
            system.listTypes();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji: " << duration.count() << " us" << endl;
            break;
        }

        case 2:
        {
            system.listTypes();
            cout << "Wybor: ";
            int typeChoice = getIntInput();

            if (typeChoice < 0 || typeChoice > 7)
            {
                cout << "!! Blad: Nieprawidlowa kategoria.\n";
            }
            else
            {
                auto start = chrono::high_resolution_clock::now();
                system.push(typeChoice);
                auto end = chrono::high_resolution_clock::now();
                auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
                cout << ">> Czas operacji: " << duration.count() << " us" << endl;
            }
            break;
        }

        case 3:
        {
            auto start = chrono::high_resolution_clock::now();
            system.pop();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji: " << duration.count() << " us" << endl;
            break;
        }

        case 4:
        {
            auto start = chrono::high_resolution_clock::now();
            system.showStatus();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji: " << duration.count() << " us" << endl;
            break;
        }

        case 5:
        {
            auto start = chrono::high_resolution_clock::now();
            system.showHistory();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji: " << duration.count() << " us" << endl;
            break;
        }

        case 6:
        {
            auto start = chrono::high_resolution_clock::now();
            system.undo();
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji: " << duration.count() << " us" << endl;
            break;
        }

        case 7:
        {
            cout << "Podaj ID: ";
            int searchId = getIntInput();
            auto start = chrono::high_resolution_clock::now();
            system.search(searchId);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Czas operacji: " << duration.count() << " us" << endl;
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
                system.push(i % 8);
            }
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            cout << ">> Wygenerowano " << n << " zgloszen w czasie: " << duration.count() << " us" << endl;
            break;
        }

        default:
            cout << "!! Blad: Opcja poza zakresem.\n";
            break;
        }
    }
}