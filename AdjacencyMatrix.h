#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYMATRIX_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_ADJACENCYMATRIX_H

#include<string>
#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>

using namespace std;

class AdjacencyMatrix {
    struct Edge {
        int source;
        int destination;
        int weight;

        explicit Edge(int src = 0, int dest = 0, int weight = 0) {
            this->source = src;
            this->destination = dest;
            this->weight = weight;
        }
    };

    // TODO pewnie zmienic cala funkcje, ale to jak zajme sie algo
    struct CompareWeight {
        bool operator()(Edge const& e1, Edge const& e2) {
            return e1.weight > e2.weight;
        }
    };


//    vector<vector<int>> graph;
    int **graph;
    bool directed;  // 0 - MST, 1 - SP
    int nodes;  // ilosc wezlow
    int edges; // ilosc krawedzi
    double density;
    int startNodeSP;

public:
    // konstruktor i destruktor
    AdjacencyMatrix(bool directed);
    ~AdjacencyMatrix();

    // glowne funkcje
    void loadFromFile(string fileName);
    void generate(int nodes, double density);
    void addEdge(int src, int dest, int weight);
    void display();
    void clear();

    // algorytmy
    void prim();
    void kruskal();
    void dijkstra();
    void fordBellman();
};


#endif
