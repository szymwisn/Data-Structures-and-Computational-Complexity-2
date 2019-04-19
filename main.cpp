#include <iostream>
#include "Menu.h"
#include "AdjacencyList.h"

Menu menu;

int main() {

    AdjacencyList lst;
    lst.loadFromFile("file", "");
//    lst.addNode(0, 1, 2, lst.getGraph());
//    lst.addNode(0, 2, 3);
//    lst.addNode(1, 0, 1);
//    lst.addNode(1, 2, 3);
//    lst.addNode(2, 0, 1);
//    lst.display();


//
//    // dzieki temu rand nie bedzie generowalo zawsze tej samej sekwencji liczb
//    srand(time(NULL));
//
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