#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_AdjacencyMatrix_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_AdjacencyMatrix_H

#include<string>
#include<iostream>

using namespace std;

struct Node {
    Node* next;
    int weight;
};

class AdjacencyMatrix {
    // TODO ogarnac liste sasiadow
    bool directed; // dla algorytmow MST false, dla najkrotszej drogi true
    int nodes;

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
