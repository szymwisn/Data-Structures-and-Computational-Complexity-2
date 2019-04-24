#include <iostream>
#include "Menu.h"
#include "Test.h"


Menu menu;

int main() {
    // dzieki temu rand nie bedzie generowalo zawsze tej samej sekwencji liczb
    srand(time(NULL));

    Test test;

    int sizes[5] = {20, 30, 50, 80, 100};

    for(int i = 0; i < 5; i++) {
        test.testPrim(sizes[i], 0.25);
    }

    cout << "\n=================================================================" << endl;

    for(int i = 0; i < 5; i++) {
        test.testPrim(sizes[i], 0.50);

    }

    cout << "\n=================================================================" << endl;

    for(int i = 0; i < 5; i++) {
        test.testPrim(sizes[i], 0.75);
    }

    cout << "\n=================================================================" << endl;

    for(int i = 0; i < 5; i++) {
        test.testPrim(sizes[i], 0.99);
    }

//    char option;
//    do{
//        cout << endl;
//        cout << "==== MENU GLOWNE ===" << endl;
//        cout << "1. wyznaczanie minimalnego drzewa rozpinającego (MST)" << endl;
//        cout << "2. wyznaczanie najkrótszej ścieżki w grafie" << endl;
//        cout << "0. Wyjscie" << endl;
//        cout << "Podaj opcje:";
//        cin >> option;
//        cout << endl;
//
//        switch (option){
//            case '1':
//                menu.menuMST();
//                break;
//
//            case '2':
//                menu.menuShortestPath();
//                break;
//
//            default:
//                break;
//        }
//
//    } while (option != '0');

    return 0;
}