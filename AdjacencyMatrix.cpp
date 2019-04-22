#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
}

AdjacencyMatrix::~AdjacencyMatrix() {
    clear();
}

void AdjacencyMatrix::loadFromFile(string fileName) {
    ifstream file;
    string str;
    Edge edge;

    clear();

    file.open(fileName);

    if(file.is_open()) {
        file >> str;
        this->edges = stoi(str);

        file >> str;
        this->nodes = stoi(str);

        this->graph = new int * [this->nodes];

        for(int k = 0; k < this->nodes; k++) {
            this->graph[k] = new int [this->nodes];
        }

        for(int k = 0; k < this->nodes; k++) {
            for(int l = 0; l < this->nodes; l++) {
                this->graph[k][l] = 0;
            }
        }

        // dla algorytmow SP
        if (directed) {
            file >> str;
            this->startNodeSP = stoi(str);
        }

        // wczytywanie kolejnych wersow z pliku
        for(int i = 0; i < this->edges; i++) {
            file >> str;
            edge.source = stoi(str);

            file >> str;
            edge.destination = stoi(str);

            file >> str;
            edge.weight = stoi(str);

            this->graph[edge.source][edge.destination] = edge.weight;
            this->graph[edge.destination][edge.source] = edge.weight;
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void AdjacencyMatrix::generate(int nodes, double density) {

}

void AdjacencyMatrix::display() {
    printf("\n--- Macierz sasiedztwa ---\n");

    cout << "    ";
    for(int i = 0; i < this->nodes; i++) {
        cout << "[" << i << "] ";
    }

    cout << endl;

    for(int i = 0; i < this->nodes; i++) {
        cout << "[" << i << "] ";
        for(int j = 0; j < this->nodes; j++) {
            cout << " " << this->graph[i][j] << "  ";
        }
        cout << endl;
    }
}

void AdjacencyMatrix::prim() {
    // TODO PRZY NIESKIEROWANYM WSZYSTKIE WIERZCHOLKI SA W POLOWIE MACIERZY

}

void AdjacencyMatrix::kruskal() {

}

void AdjacencyMatrix::dijkstra() {

}

void AdjacencyMatrix::fordBellman() {

}

void AdjacencyMatrix::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;

    for(int i = 0; i < this->nodes; i++) {
        delete [] this->graph[i];
    }

    if(this->nodes > 0) {
        delete [] this->graph;
    }
}