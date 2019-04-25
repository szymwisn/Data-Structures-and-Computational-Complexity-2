#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYLIST_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYLIST_H

#include<string>
#include<iostream>
#include <fstream>
#include "Edge.h"

using namespace std;

class AdjacencyList {
    vector<list<Edge>> graph;
    vector<list<Edge>> spanningTree;
    priority_queue<Edge, vector<Edge>, CompareWeight> priorQueue;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int startNodeSP;
    const int MAX = 999999999;

public:
    // konstruktor i destruktor
    AdjacencyList(bool directed);
    ~AdjacencyList();

    // glowne funkcje
    void loadFromFile(string fileName);
    vector<list<Edge>> generate(int nodes, double density);
    void addEdge(int src, int dest, int weight);
    void display();
    void display(vector<list<Edge>> g);
    void clear();

    // algorytmy
    void prim();
    void kruskal();
    void dijkstra();
    void fordBellman();
};


#endif
