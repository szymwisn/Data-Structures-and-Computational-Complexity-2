#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYLIST_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYLIST_H

#include<string>
#include<iostream>
#include <vector>
#include <list>

using namespace std;

struct Node {
    Node* next;
    int weight;
};

class AdjacencyList {
    vector<list<Node>> graph;
    int nodes;
    double density;
    bool directed; // dla algorytmow MST false, dla najkrotszej drogi true

public:
    // konstruktor i destruktor
    AdjacencyList();
    ~AdjacencyList();

    // glowne funkcje
    void loadFromFile(string fileName);
    void generate(int nodes, double density);
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
