#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(bool directed) {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->directed = directed;
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

    if(directed) {
        this->edges = (int) (density * nodes * (nodes - 1));
    } else {
        this->edges = (int) ((density * nodes * (nodes - 1)) / 2);
    }

    this->nodes = nodes;
    this->graph.resize(this->nodes);

    // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony
    bool* visited = new bool[this->graph.size()];

    // na poczatku wszystie wierzcholki nieodwiedzone
    for(int i = 0; i < this->graph.size(); i++) {
        visited[i] = false;
    }

    // generowanie drzewa rozpinajacego
    int node = rand() % this->nodes;

    for(int i = 0; i < this->graph.size() - 1; i++) {
        Edge edge;
        if(!visited[node]) {
            visited[node] = true;
            edge.source = node;
            do {
                edge.destination = rand() % nodes;
            } while(visited[edge.destination]);

            edge.weight = rand() % 10;

            addEdge(edge.source, edge.destination, edge.weight);
        }
        node = edge.destination;
    }

    // dodanie pozostalych krawedzi
    for(int i = this->graph.size() - 1; i < this->edges; i++) {
        Edge edge;
        edge.source = rand() % nodes;

        do {
            edge.destination = rand() % nodes;
        } while(edge.source == edge.destination);

        edge.weight = rand() % 10;

        addEdge(edge.source, edge.destination, edge.weight);
    }

    delete [] visited;
}

void AdjacencyList::display() {
    printf("\n--- Lista sasiedztwa ---");

    cout << endl;

    for(int i = 0; i < this->graph.size(); i++) {
        printf("Node[%d]:    ", i);
        for (auto &iter : this->graph[i]) {
            printf("%d -> %d (w: %d)    ", iter.source, iter.destination, iter.weight);
        }
        cout << endl;
    }
}

void AdjacencyList::display(vector<list<Edge>> g) {
    printf("\n--- Lista sasiedztwa ---");

    cout << endl;

    for(int i = 0; i < g.size(); i++) {
        printf("Node[%d]:    ", i);
        for (auto &iter : g[i]) {
            printf("%d -> %d (w: %d)    ", iter.source, iter.destination, iter.weight);
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
    this->spanningTree.resize(this->nodes);

    int weights = 0;

    for (int i = 0; i < this->graph.size(); i++) {
        Edge minEdge;

        if(!visited[node]) {
            auto iter = graph[node].begin();

            while(iter != graph[node].end()) {
                    if(!visited[(*iter).destination]) {
                        priorQueue.push((*iter));
                    }
                iter++;
            }

            minEdge = priorQueue.top();
            this->priorQueue.pop();

            if(!visited[minEdge.destination]) {
                this->spanningTree[node].push_back(Edge(minEdge.source, minEdge.destination, minEdge.weight));
                this->spanningTree[minEdge.destination].push_back(Edge(minEdge.destination, minEdge.source, minEdge.weight));
                weights += minEdge.weight;
            }

            visited[node] = true;
        } else {
            minEdge = priorQueue.top();
            this->priorQueue.pop();

            if(!visited[minEdge.destination]) {
                this->spanningTree[node].push_back(Edge(minEdge.source, minEdge.destination, minEdge.weight));
                this->spanningTree[minEdge.destination].push_back(Edge(minEdge.destination, minEdge.source, minEdge.weight));
                weights += minEdge.weight;
            }

            i--;
        }
        node = minEdge.destination;
    }

    display(this->spanningTree);

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