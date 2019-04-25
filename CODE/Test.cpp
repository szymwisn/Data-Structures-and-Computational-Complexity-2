#include "Test.h"

void Test::testPrim(int nodes, double density) {
    AdjacencyList al(false);
    vector<list<Edge>> g;

    for(int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        al.prim();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Lista Prim     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    AdjacencyMatrix am(false);
    for(int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        am.prim();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Macierz Prim     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    cout << "\n=================================================================" << endl;
}

void Test::testKruskal(int nodes, double density) {
    AdjacencyList al(false);
    vector<list<Edge>> g;

    for(int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        al.kruskal();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Lista Kruskal     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    AdjacencyMatrix am(false);
    for(int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        am.kruskal();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Macierz Kurskal     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    cout << "\n=================================================================" << endl;
}

void Test::testDijkstra(int nodes, double density) {
    AdjacencyList al(true);
    vector<list<Edge>> g;

    for(int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        al.dijkstra();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Lista Dijkstra     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    AdjacencyMatrix am(true);
    for(int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        am.dijkstra();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Macierz Dijkstra     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    cout << "\n=================================================================" << endl;
}

void Test::testFordBellman(int nodes, double density) {
    AdjacencyList al(true);
    vector<list<Edge>> g;

    for(int i = 0; i < tests; i++) {
        g = al.generate(nodes, density);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        al.fordBellman();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Lista Ford-Bellman     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    AdjacencyMatrix am(true);
    for(int i = 0; i < tests; i++) {
        am.generate(g);
        auto beginning = std::chrono::steady_clock::now().time_since_epoch();
        am.fordBellman();
        auto end = std::chrono::steady_clock::now().time_since_epoch();
        auto time = end - beginning;
        sum += time.count();
    }
    average = sum / tests;
    sum = 0;

    printf("Macierz Ford-Bellman     ");
    printf("V: %d      D: %f      %d ns", nodes, density, average);

    cout << endl;

    cout << "\n=================================================================" << endl;
}

void Test::runTests() {
    int sizes[5] = {10, 20, 40, 60, 80};

    for(int i = 0; i < 5; i++) {
        testPrim(sizes[i], 0.25);
    }

    for(int i = 0; i < 5; i++) {
        testPrim(sizes[i], 0.50);

    }

    for(int i = 0; i < 5; i++) {
        testPrim(sizes[i], 0.75);
    }

    for(int i = 0; i < 5; i++) {
        testPrim(sizes[i], 0.99);
    }

    printf("\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n");

    for(int i = 0; i < 5; i++) {
        testKruskal(sizes[i], 0.25);
    }

    for(int i = 0; i < 5; i++) {
        testKruskal(sizes[i], 0.50);

    }

    for(int i = 0; i < 5; i++) {
        testKruskal(sizes[i], 0.75);
    }

    for(int i = 0; i < 5; i++) {
        testKruskal(sizes[i], 0.99);
    }

    printf("\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n");

    for(int i = 0; i < 5; i++) {
        testDijkstra(sizes[i], 0.25);
    }

    for(int i = 0; i < 5; i++) {
        testDijkstra(sizes[i], 0.50);

    }

    for(int i = 0; i < 5; i++) {
        testDijkstra(sizes[i], 0.75);
    }

    for(int i = 0; i < 5; i++) {
        testDijkstra(sizes[i], 0.99);
    }

    printf("\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n");

    for(int i = 0; i < 5; i++) {
        testFordBellman(sizes[i], 0.25);
    }

    for(int i = 0; i < 5; i++) {
        testFordBellman(sizes[i], 0.50);

    }

    for(int i = 0; i < 5; i++) {
        testFordBellman(sizes[i], 0.75);
    }

    for(int i = 0; i < 5; i++) {
        testFordBellman(sizes[i], 0.99);
    }

    printf("\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n\n==============================================================\n");
}
