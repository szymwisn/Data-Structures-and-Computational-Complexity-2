#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYMATRIX_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYMATRIX_H

#include<string>
#include<iostream>
#include <fstream>
#include "Edge.h"

using namespace std;

class AdjacencyMatrix {
    int **graph;
    int **spanningTree;
    priority_queue<Edge, vector<Edge>, CompareWeight> priorQueue;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int startNodeSP;
    const int MAX = 999999999;

public:
    // konstruktor i destruktor
    AdjacencyMatrix(bool directed);
    ~AdjacencyMatrix();

    // glowne funkcje
    void loadFromFile(string fileName);
    void generate(int nodes, double density);
    void generate(vector<list<Edge>> g);
    void addEdge(int src, int dest, int weight);
    void display();
    void display(int ** graph);
    void clear();

    // algorytmy
    void prim();
    void kruskal();
    void dijkstra();
    void fordBellman();
};


#endif
