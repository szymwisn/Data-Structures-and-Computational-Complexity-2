#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYLIST_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYLIST_H

#include<string>
#include<iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <fstream>

using namespace std;

class AdjacencyList {
    struct element {
        int source;
        int destination;
        int weight;

        explicit element(int src = 0, int dest = 0, int weight = 0) {
            this->source = src;
            this->destination = dest;
            this->weight = weight;
        }
    };

    vector<list<element>> graph;
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    bool directed; // dla algorytmow MST false, dla najkrotszej drogi true

public:
    // konstruktor i destruktor
    AdjacencyList();
    AdjacencyList(string fileName, string type);
    AdjacencyList(int nodes, double density);
    ~AdjacencyList();

    // glowne funkcje
    void loadFromFile(string fileName, string type);
    void generate(int nodes, double density);
    void addNode(int src, int dest, int weight, vector<list<element>>& graph);
    void display();
    void clear();

    // algorytmy
    void prim();
    void kruskal();
    void dijkstra();
    void fordBellman();

    // funkcje pomocnicze
//    vector<list<element>> getGraph() { return this->graph; }
};


#endif
