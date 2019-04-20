#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
}

AdjacencyList::AdjacencyList(string fileName) : AdjacencyList() {
    loadFromFile(fileName);
}

AdjacencyList::AdjacencyList(int nodes, double density) : AdjacencyList() {
    generate(nodes, density);
}

AdjacencyList::~AdjacencyList() {
    clear();
}

void AdjacencyList::loadFromFile(string fileName) {
    ifstream file;
    string str;
    Node node;

    clear();

    file.open(fileName);

    if(file.is_open()) {
        file >> str;
        this->edges = stoi(str);

        file >> str;
        this->nodes = stoi(str);

        printf("edges: %d, nodes: %d\n", edges, nodes);

        // dla algorytmow SP
        if (directed) {
            file >> str;
            node.spFirstNode = stoi(str);
        }

        int source = 0;

        // wczytywanie kolejnych wersow z pliku
        for(int i = 0; i < this->edges; i++) {
            file >> str;
            source = stoi(str);

            file >> str;
            node.destination = stoi(str);

            file >> str;
            node.weight = stoi(str);

            addNode(source, node.destination, node.weight);
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void AdjacencyList::generate(int nodes, double density) {
    clear();

    // TODO najpierw generowac drzewo rozpinajace, potem pozostale krawedzie

    if(directed) {
        this->edges = (int) (density * nodes * (nodes - 1));
    } else {
        this->edges = (int) ((density * nodes * (nodes - 1)) / 2);
    }

    this->nodes = nodes;

    this->graph.resize(this->nodes);

    //TODO spojrzec na to swiezym okiem
    for(int i = 0; i < this->edges; i++) {
        addNode(rand() % this->nodes, // source
                rand() % this->nodes, // destination
                rand() % 10 + 1);     // weight
    }
}

void AdjacencyList::display() {
    // Graf skierowany - algorytmy SP
    if(directed) {
        printf("\n--- Graf skierowany ---");
        for(int i = 0; i < graph.size(); i++) {
            printf("\nNode[%d]: ", i);

            for (auto &iter : graph[i]) {
                printf(" -> %d(w: %d)   ", iter.destination, iter.weight);
            }
        }
        cout << endl;
    }
    // Graf nieskierowany - algorytmy MST
    else {
        printf("\n--- Graf nieskierowany ---");
        for(int i = 0; i < graph.size(); i++) {
            printf("\nNode[%d]: ", i);

            for (auto &iter : graph[i]) {
                printf(" -> %d(w: %d)   ", iter.destination, iter.weight);
            }
        }
        cout << endl;
    }
}

void AdjacencyList::prim() {

}

void AdjacencyList::kruskal() {

}

void AdjacencyList::dijkstra() {

}

void AdjacencyList::fordBellman() {

}

void AdjacencyList::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->graph.clear();
}

void AdjacencyList::addNode(int src, int dest, int weight) {
    this->graph.resize(this->nodes);

    if(this->directed) {
        this->graph[src].push_back(Node(dest, weight));
    } else {
        this->graph[src].push_back(Node(dest, weight));
        this->graph[dest].push_back(Node(src, weight));
    }
}