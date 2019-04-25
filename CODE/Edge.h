#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_EDGE_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_EDGE_H

#include <vector>
#include <list>
#include <queue>
#include <algorithm>


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

struct CompareWeight {
    bool operator()(Edge const& e1, Edge const& e2) {
        return e1.weight > e2.weight;
    }
};


#endif
