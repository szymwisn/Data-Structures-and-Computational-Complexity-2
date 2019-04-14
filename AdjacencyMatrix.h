#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYMATRIX_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYMATRIX_H

#include<string>
#include<iostream>

using namespace std;

class AdjacencyMatrix {
    // TODO ogarnac macierz sasiedztwa

public:
    // konstruktor i destruktor
    AdjacencyMatrix();
    ~AdjacencyMatrix();

    // glowne funkcje
    void loadFromFile(string fileName);
    void generate(int n, double density);
    void display();

    // algorytmy
    void prim();
    void kruskal();
    void dijkstra();
    void fordBellman();

    // funkcje pomocnicze
    void clear();
};


#endif
