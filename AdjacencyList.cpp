#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
}

AdjacencyList::~AdjacencyList() {
    clear();
}

void AdjacencyList::loadFromFile(string fileName) {
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

            addEdge(edge.source, edge.destination, edge.weight);
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
        addEdge(rand() % this->nodes, // source
                rand() % this->nodes, // destination
                rand() % 100);        // weight
    }
}

void AdjacencyList::display() {
    printf("\n--- Lista sasiedztwa ---");

    // Graf skierowany - algorytmy SP
    if(directed) {
        for(int i = 0; i < graph.size(); i++) {
            printf("\nNode[%d]:   ", i);

            for (auto &iter : graph[i]) {
                printf("-> %d (w: %d)  ", iter.destination, iter.weight);
            }
        }
        cout << endl;
    }
    // Graf nieskierowany - algorytmy MST
    else {
        for(int i = 0; i < graph.size(); i++) {
            printf("\nNode[%d]:   ", i);

            for (auto &iter : graph[i]) {
                printf("-> %d (w: %d)  ", iter.destination, iter.weight);
            }
        }
        cout << endl;
    }
}

void AdjacencyList::prim() {
    // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony
    bool* visited = new bool[this->graph.size()];

    // na poczatku wszystie wierzcholki nieodwiedzone
    for(int i = 0; i < this->graph.size(); i++) {
        visited[i] = false;
    }

    // numer wierzcholka - zaczynamy od 0
    int node = 0;

    // ustawienie rozmiaru wektora zawierajacego drzewo rozpinajace
    this->spanningTree.resize(this->nodes - 1);

    int weights = 0;

    // size - 1, bo mst ma o 1 krawedz mniej
    for(int i = 0; i < this->graph.size() - 1; i ++) {
        Edge minEdge;

        if(!visited[node]) {
            visited[node] = true;
            auto iter = graph[i].begin();

            //TODO problem jest z tym while
            while(iter != graph[i].end()) {
                    if(!visited[(*iter).destination]) {
                        priorQueue.push((*iter));
                    }
                iter++;
            }

            minEdge = priorQueue.top();

            if(!visited[minEdge.destination]) {
                this->spanningTree[node].push_back(Edge(minEdge.source, minEdge.destination, minEdge.weight));
//                this->spanningTree[edge.destination].push_back(Edge(edge.destination, edge.source, edge.weight));
                weights += minEdge.weight;
            }

            node = minEdge.destination;

        } else {
            minEdge = priorQueue.top();

            if(!visited[minEdge.destination]) {
                this->spanningTree[node].push_back(Edge(minEdge.source, minEdge.destination, minEdge.weight));
//                this->spanningTree[edge.destination].push_back(Edge(edge.destination, edge.source, edge.weight));
                weights += minEdge.weight;
            }

            node = minEdge.destination;
        }
    }


    printf("MST - reprezentacja listowa\n");
    for (auto &i : spanningTree) {
        Edge edge;

        auto iter = i.begin();

        while(iter != i.end()) {
            edge = (*iter);
            printf("%d -> %d (w: %d)\n", edge.source, edge.destination, edge.weight);
            iter++;
        }
    }

    printf("\nSuma wag: %d\n", weights);

    delete [] visited;
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
    this->startNodeSP = 0;
    this->graph.clear();
    this->spanningTree.clear();
    this->priorQueue.empty();
}

void AdjacencyList::addEdge(int src, int dest, int weight) {
    this->graph.resize(this->nodes);

    if(this->directed) {
        this->graph[src].push_back(Edge(src, dest, weight));
    } else {
        this->graph[src].push_back(Edge(src, dest, weight));
        this->graph[dest].push_back(Edge(dest, src, weight));
    }
}