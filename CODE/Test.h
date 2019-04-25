#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_TEST_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_TEST_H

#include <chrono>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

class Test {
public:
    void runTests();
    void testPrim(int nodes, double density);
    void testKruskal(int nodes, double density);
    void testDijkstra(int nodes, double density);
    void testFordBellman(int nodes, double density);

private:
    const int tests = 100;
    int average = 0;
    int sum = 0;
};


#endif
