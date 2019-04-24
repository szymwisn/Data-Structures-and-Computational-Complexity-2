#include "Test.h"

void Test::testPrim(int nodes, double density) {
    AdjacencyList al(false);
    for(int i = 0; i < tests; i++) {
        al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        al.prim();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("\n---Lista sasiedztwa: algorytm Prima---\n");
    printf("V = %d, D = %f, %d ns (%d pomiarow)", nodes, density, average, tests);

    cout << endl;

    AdjacencyMatrix am(false);
    for(int i = 0; i < tests; i++) {
        am.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        am.prim();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("\n---Macierz sasiedztwa: algorytm Prima---\n");
    printf("V = %d, D = %f, %d ns (%d pomiarow)", nodes, density, average, tests);

    cout << endl;
}

void Test::testDijkstra(int nodes, double density) {
    AdjacencyList al(true);
    for(int i = 0; i < tests; i++) {
        al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        al.dijkstra();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("\n---Lista sasiedztwa: algorytm Prima---\n");
    printf("V = %d, D = %f, %d ns (%d pomiarow)", nodes, density, average, tests);

    cout << endl;

    AdjacencyMatrix am(true);
    for(int i = 0; i < tests; i++) {
        am.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now();
        am.dijkstra();
        auto end = std::chrono::steady_clock::now();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("\n---Macierz sasiedztwa: algorytm Prima---\n");
    printf("V = %d, D = %f, %d ns (%d pomiarow)", nodes, density, average, tests);

    cout << endl;
}
