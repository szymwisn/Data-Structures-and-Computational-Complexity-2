#include "AdjacencyMatrix.h"

AdjacencyMatrix::AdjacencyMatrix(bool directed) {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->directed = directed;
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
                this->graph[k][l] = MAX;
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

            addEdge(edge.source, edge.destination, edge.weight);
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

// generuje graf bazujac na reprezentacji listowej
void AdjacencyMatrix::generate(vector<list<Edge>> g) {
    clear();

    this->nodes = g.size();

    this->graph = new int * [this->nodes];

    for(int k = 0; k < this->nodes; k++) {
        this->graph[k] = new int [this->nodes];
    }

    for(int k = 0; k < this->nodes; k++) {
        for(int l = 0; l < this->nodes; l++) {
            this->graph[k][l] = MAX;
        }
    }

    for(int i = 0; i < g.size(); i++) {
        Edge edge;
        auto iter = g[i].begin();
        while(iter != g[i].end()) {
            edge.source = (*iter).source;
            edge.destination = (*iter).destination;
            edge.weight = (*iter).weight;
            addEdge(edge.source, edge.destination, edge.weight);
            iter++;
        }
    }
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
            if(this->graph[i][j] == MAX) {
                cout << " -  ";
            } else {
                cout << " " << this->graph[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

void AdjacencyMatrix::display(int ** g) {
    printf("\n--- Macierz sasiedztwa ---\n");

    cout << "    ";
    for(int i = 0; i < this->nodes; i++) {
        cout << "[" << i << "] ";
    }

    cout << endl;

    for(int i = 0; i < this->nodes; i++) {
        cout << "[" << i << "] ";
        for(int j = 0; j < this->nodes; j++) {
            if(g[i][j] == MAX) {
                cout << " -  ";
            } else {
                cout << " " << g[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

void AdjacencyMatrix::prim() {
    // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony
    bool* visited = new bool[this->nodes];

    // na poczatku wszystkie wierzcholki nieodwiedzone
    for(int i = 0; i < this->nodes; i++) {
        visited[i] = false;
    }

    // stworzenie i wypelnienie spanning tree
    this->spanningTree = new int * [this->nodes];

    for(int k = 0; k < this->nodes; k++) {
        this->spanningTree[k] = new int [this->nodes];
    }

    for(int k = 0; k < this->nodes; k++) {
        for(int l = 0; l < this->nodes; l++) {
            this->spanningTree[k][l] = MAX;
        }
    }

    // numer wierzcholka - zaczynamy od 0
    int node = 0;

    // sumaryczna waga spanning tree
    int weights = 0;

    for (int i = 0; i < this->nodes; i++) {
        Edge minEdge;
        Edge edge;

        // jesli wierzcholek wczesniej nie byl odwiedzony to dodaje
        // go do kolejki piorytetowej
        if(!visited[node]) {
            for(int j = 0; j < this->nodes; j++) {
                // dodanie wierzcholka do kolejki piorytetowej
                if(!visited[node] && this->graph[node][j] != 0) {
                    edge.source = node;
                    edge.destination = j;
                    edge.weight = this->graph[node][j];
                    priorQueue.push(edge);
                }
            }

            // sciagniecie wierzcholka o najnizszej wadze
            minEdge = priorQueue.top();
            // usuniecie tego wierzcholka z kolejki
            this->priorQueue.pop();

            // jesli nie byl jeszcze odwiedzony - dodaje go do spanning tree i zwiekszam wage sumaryczna
            if(!visited[minEdge.destination]) {
                this->spanningTree[minEdge.source][minEdge.destination] = minEdge.weight;
                this->spanningTree[minEdge.destination][minEdge.source] = minEdge.weight;
                weights += minEdge.weight;
            }

            // oznaczenie wierzcholka jako odwiedzony
            visited[node] = true;
        } else {
            // sciagniecie wierzcholka o najnizszej wadze
            minEdge = priorQueue.top();
            // usuniecie tego wierzcholka z kolejki
            this->priorQueue.pop();

            // jesli nie byl jeszcze odwiedzony - dodaje go do spanning tree i zwiekszam wage sumaryczna
            if(!visited[minEdge.destination]) {
                this->spanningTree[minEdge.source][minEdge.destination] = minEdge.weight;
                this->spanningTree[minEdge.destination][minEdge.source] = minEdge.weight;
                weights += minEdge.weight;
            }
            i--;
        }
        // przejscie do kolejnego wierzcholka
        node = minEdge.destination;
    }

    // wyswietlenie drzewa rozpinajacego
    display(this->spanningTree);

    // wyswietlenie wag
    printf("\nSuma wag: %d\n", weights);

    //czyszczenie
    delete [] visited;
    this->priorQueue.empty();
    for(int i = 0; i < this->nodes; i++) {
        delete [] this->spanningTree[i];
    }
    delete [] spanningTree;
}

void AdjacencyMatrix::kruskal() {

}

void printPathd(int parent[], int i) {
    if(parent[i] == -1) {
        return;
    }
    printPathd(parent, parent[i]);
    printf("-> %d ", i);
}

void AdjacencyMatrix::dijkstra() {
    // numer wierzcholka startowego
    int node = this->startNodeSP;

    // zainicjalizowanie odleglosci dla kazdego wierzcholka
    int* distances = new int[this->nodes];
    for(int i = 0; i < this->nodes; i++) {
        distances[i] = MAX;
    }

    // tutaj przechowywane sa rodzice wierzcholka
    int * parent = new int[this->nodes];

    // zaladowanie pierwszego wierzcholka do kolejki
    this->priorQueue.push(Edge(node, node, 0));

    // ustawienie dystansu do siebie na 0
    distances[node] = 0;

    // pierwszy wierzcholek nie ma zadnego poprzednika w sciezce
    parent[node] = -1;

    while(!this->priorQueue.empty()) {
        // pobranie atrybutu source wierzcholka
        int v1 = priorQueue.top().source;

        // usuniecie wierzcholka o najnizszej wadze z kolejki piorytetowej
        priorQueue.pop();

        // itracja po kazdym sasiadujacym wierzcholku
        for(int i = 0; i < this->nodes; i++) {
            int weight = graph[v1][i];

            // jesli jest krotsza droga z wierzcholka v1 do v2 to aktualizuje ja
            if(distances[i] > distances[v1] + weight) {
                distances[i] = distances[v1] + weight;
                priorQueue.push(Edge(i, v1, weight));

                // zapisuje rodzica wierzcholka na potrzeby wyswietlenia calej sciezki
                parent[i] = v1;
            }
        }
    }

    printf("\n--- Algorytm wykonany na macierzy sasiedztwa ---\n");
    printf("Odleglosc z wierzcholka %d do pozostalych wierzcholkow:\n", this->startNodeSP);
    printf("Z:    Do:       Waga:    Sciezka:\n");
    for(int i = 0; i < this->nodes; i++) {
        printf("%d  ->  %d        %d        %d ", this->startNodeSP, i, distances[i], this->startNodeSP);

        printPathd(parent, i);
        cout << endl;
    }

    delete [] distances;
    delete [] parent;
    this->priorQueue.empty();
}

void AdjacencyMatrix::fordBellman() {

}

void AdjacencyMatrix::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->priorQueue.empty();

    for(int i = 0; i < this->nodes; i++) {
        delete [] this->graph[i];
    }

    for(int i = 0; i < this->nodes; i++) {
        delete [] this->spanningTree[i];
    }

    if(this->nodes > 0) {
        delete [] this->graph;
        delete [] this->spanningTree;
    }
}

void AdjacencyMatrix::addEdge(int src, int dest, int weight) {
    if(this->directed) {
        this->graph[src][dest] = weight;
    } else {
        this->graph[src][dest] = weight;
        this->graph[dest][src] = weight;
    }
}