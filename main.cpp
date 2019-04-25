#include <iostream>
#include "Menu.h"
#include "Test.h"


int main() {
    Menu menu;
    Test test;

    // dzieki temu rand nie bedzie generowalo zawsze tej samej sekwencji liczb
    srand(time(NULL));

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;
        cout << "1. wyznaczanie minimalnego drzewa rozpinającego (MST)" << endl;
        cout << "2. wyznaczanie najkrótszej ścieżki w grafie" << endl;
        cout << "3. testy" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Podaj opcje:";
        cin >> option;
        cout << endl;

        switch (option){
            case '1':
                menu.menuMST();
                break;

            case '2':
                menu.menuShortestPath();
                break;

            case '3':
                test.runTests();
                break;
            default:
                break;
        }

    } while (option != '0');

    return 0;
}