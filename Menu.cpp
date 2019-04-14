#include "Menu.h"
#include "AdjacencyMatrix.h"
#include "AdjacencyMatrix.h"

void Menu::displayMenuMST() {
    cout << endl;
    cout << "--- wyznaczanie minimalnego drzewa rozpinającego (MST) ---" << endl;
    cout << "1. Wczytaj z pliku" << endl;
    cout << "2. Wygeneruj graf losowo" << endl;
    cout << "3. Wyswietl listowo i macierzowo na ekranie" << endl;
    cout << "4. Algorytm Prima" << endl;
    cout << "5. Algorytm Kruskala" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Menu::displayMenuShortestPath() {
    cout << endl;
    cout << "--- wyznaczanie najkrótszej ścieżki w grafie ---" << endl;
    cout << "1. Wczytaj z pliku" << endl;
    cout << "2. Wygeneruj graf losowo" << endl;
    cout << "3. Wyswietl listowo i macierzowo na ekranie" << endl;
    cout << "4. Algorytm Dijkstry" << endl;
    cout << "5. Algorytm Forda-Bellmana" << endl;
    cout << "0. Powrot do menu" << endl;
    cout << "Podaj opcje:";
}

void Menu::menuMST() {
    AdjacencyMatrix al;
    AdjacencyMatrix am;

    char opt;
    string fileName;
    int value;

    do{
        displayMenuMST();
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': // wczytanie z pliku
                cout << " Podaj nazwe pliku:";
                cin >> fileName;

                al.loadFromFile(fileName);
                al.display();

                am.loadFromFile(fileName);
                am.display();
                break;

            case '2': // wygenerowanie losowego grafu
                cout << " podaj ilosc wierzcholkow:";
                cin >> value;

                double density;

                cout << " podaj gestosc:";
                cin >> density;
                al.generate(value, density);
                al.display();

                am.generate(value, density);
                am.display();
                break;

            case '3': // wyswietlenie
                al.display();
                am.display();
                break;

            case '4': // algorytm prima
                al.prim();
                al.display();

                am.prim();
                am.display();
                break;

            case '5': // algorytm kruskala
                al.kruskal();
                al.display();

                am.kruskal();
                am.display();
                break;
        }

    } while (opt != '0');
}

void Menu::menuShortestPath() {
    AdjacencyMatrix al;
    AdjacencyMatrix am;

    char opt;
    string fileName;
    int index, value;

    do{
        displayMenuShortestPath();
        cin >> opt;
        cout << endl;
        switch (opt){
            case '1': // wczytanie z pliku
                cout << " Podaj nazwe pliku:";
                cin >> fileName;

                al.loadFromFile(fileName);
                al.display();

                am.loadFromFile(fileName);
                am.display();
                break;

            case '2': // wygenerowanie losowego grafu
                cout << " podaj ilosc wierzcholkow:";
                cin >> value;

                double density;

                cout << " podaj gestosc:";
                cin >> density;
                al.generate(value, density);
                al.display();

                am.generate(value, density);
                am.display();
                break;

            case '3': // wyswietlenie
                al.display();
                am.display();
                break;

            case '4': // algorytm dijkstry
                al.dijkstra();
                al.display();

                am.dijkstra();
                am.display();
                break;

            case '5': // algorytm forda-bellmana
                al.fordBellman();
                al.display();

                am.fordBellman();
                am.display();
                break;
        }

    } while (opt != '0');
}
