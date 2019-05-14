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

        // zapisanie wszystkich krawedzi do wektora
        for (auto &i : this->graph) {
            auto iter = i.begin();
            while(iter != i.end()) {
                this->allEdges.push_back((*iter));
                iter++;
            }
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

vector<list<Edge>> AdjacencyList::generate(int nodes, double density) {
    clear();

    if(directed) {
        this->edges = (int) (density * nodes * (nodes - 1));
    } else {
        this->edges = (int) ((density * nodes * (nodes - 1)) / 2);
    }

    this->nodes = nodes;
    this->graph.resize(this->nodes);

    bool ** exists = new bool*[this->graph.size()];

    for(int i = 0; i < this->graph.size(); i++) {
        exists[i] = new bool[this->graph.size()];
    }

    for(int i = 0; i < this->graph.size(); i++) {
        for(int j = 0; j < this->graph.size(); j++) {
            exists[i][j] = false;
        }
    }

    // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony
    bool* visited = new bool[this->graph.size()];

    // na poczatku wszystie wierzcholki nieodwiedzone
    for(int i = 0; i < this->graph.size(); i++) {
        visited[i] = false;
    }

    // generowanie drzewa rozpinajacego
    int node = rand() % this->nodes;

    Edge edge;

    for(int i = 0; i < this->graph.size() - 1; i++) {
        if(!visited[node]) {
            // ustawia wierzcholek na odwiedzony
            visited[node] = true;
            edge.source = node;
            do {
                // losuje do ktorego wierzcholka isc
                edge.destination = rand() % nodes;
            } while(visited[edge.destination]);

            // losuje wage
            edge.weight = rand() % 100;

            // dodaje wierzcholek do grafu
            addEdge(edge.source, edge.destination, edge.weight);
            exists[edge.source][edge.destination] = true;
            if(!directed) {
                exists[edge.destination][edge.source] = true;
            }
        }
        node = edge.destination;
    }

    // dodanie pozostalych krawedzi
    for(int i = this->graph.size() - 1; i < this->edges; i++) {
        if(!directed) {
            do {
                edge.source = rand() % nodes;
                edge.destination = rand() % nodes;
            } while(edge.source == edge.destination || exists[edge.source][edge.destination] || exists[edge.destination][edge.source]);
        } else {
            do {
                edge.source = rand() % nodes;
                edge.destination = rand() % nodes;
            } while(edge.source == edge.destination || exists[edge.source][edge.destination]);
        }

        edge.weight = rand() % 100;

        addEdge(edge.source, edge.destination, edge.weight);
        exists[edge.source][edge.destination] = true;
        if(!directed) {
            exists[edge.destination][edge.source] = true;
        }
    }

    // zapisanie wszystkich krawedzi do wektora
    for (auto &i : this->graph) {
        auto iter = i.begin();
        while(iter != i.end()) {
            this->allEdges.push_back((*iter));
            iter++;
        }
    }

    delete [] visited;
    delete [] exists;

    return this->graph;
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
    printf("\n--- Krawedzie ---");

    cout << endl;

    for(int i = 0; i < g.size(); i++) {
        for (auto &iter : g[i]) {
            printf("%d -> %d (w: %d)    ", iter.source, iter.destination, iter.weight);
            cout << endl;
        }
    }
}

void AdjacencyList::prim() {
    // tablica informujaca o tym, czy dany wierzcholek byl odwiedzony
    bool* visited = new bool[this->graph.size()];

    // na poczatku wszystkie wierzcholki nieodwiedzone
    for(int i = 0; i < this->graph.size(); i++) {
        visited[i] = false;
    }

    // numer wierzcholka - zaczynamy od 0
    int node = 0;

    // ustawienie rozmiaru wektora zawierajacego drzewo rozpinajace
    this->spanningTree.resize(this->graph.size());

    // sumaryczna waga spanning tree
    int weights = 0;

    for (int i = 0; i < this->graph.size(); i++) {
        Edge minEdge;

        // jesli wierzcholek wczesniej nie byl odwiedzony to dodaje
        // go do kolejki piorytetowej
        if(!visited[node]) {
            auto iter = this->graph[node].begin();

            // dodanie wierzcholka do kolejki piorytetowej
            while(iter != this->graph[node].end()) {
                if(!visited[node] && (*iter).weight != MAX) {
                    priorQueue.push((*iter));
                }
                iter++;
            }

            // sciagniecie wierzcholka o najnizszej wadze
            minEdge = priorQueue.top();
            // usuniecie tego wierzcholka z kolejki
            this->priorQueue.pop();

            // jesli nie byl jeszcze odwiedzony - dodaje go do spanning tree i zwiekszam wage sumaryczna
            if(!visited[minEdge.destination]) {
                this->spanningTree[node].push_back(Edge(minEdge.source, minEdge.destination, minEdge.weight));
                this->spanningTree[minEdge.destination].push_back(Edge(minEdge.destination, minEdge.source, minEdge.weight));
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
                this->spanningTree[node].push_back(Edge(minEdge.source, minEdge.destination, minEdge.weight));
                this->spanningTree[minEdge.destination].push_back(Edge(minEdge.destination, minEdge.source, minEdge.weight));
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
    clear();
}

bool compareWeight(Edge const& e1, Edge const& e2) {
    return e1.weight < e2.weight;
}

void AdjacencyList::kruskal() {
    DisjointSet disjointSet(this->graph.size());

    // tu przechowywana bedzie sumaryczna waga
    int weights = 0;

    // posortowanie wierzcholkow wzgledem wagi - od najmniejszej do najwiekszej
    sort(this->allEdges.begin(), this->allEdges.end(), compareWeight);

    printf("\n--- Krawedzie z reprezentacji listowej ---");

    // przechodze po kazdej krawedzi
    auto iter = this->allEdges.begin();
    while(iter != this->allEdges.end()) {
        int v1 = (*iter).source;
        int v2 = (*iter).destination;
        int weight = (*iter).weight;

        // znajduje set dla kazdego z wierzcholkow
        int set_v1 = disjointSet.findParent(v1);
        int set_v2 = disjointSet.findParent(v2);

        // sprawdzenie czy jest cykl - czy oba wierzcholki sa w tym samym zbiorze
        // (cykl wystepuje jesli oba wierzcholki naleza do tego samego zbioru)
        if(set_v1 != set_v2) {
            printf("\n%d -> %d (w: %d)    ", v1, v2, weight);
            weights += weight;
            disjointSet.makeUnion(set_v1, set_v2);
        }
        iter++;
    }

    // wyswietlenie wag
    printf("\n\nSuma wag: %d\n", weights);

    clear();
}

// rekurencyjna funkcja do wyswietlania sciezki do do danego wierzcholka
void printPath(int parent[], int i) {
    if(parent[i] == -1) {
        return;
    }
    printPath(parent, parent[i]);
    printf("-> %d ", i);
}

void AdjacencyList::dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

    // numer wierzcholka startowego
    int node = this->startNodeSP;

    // zainicjalizowanie odleglosci dla kazdego wierzcholka
    int* distances = new int[this->graph.size()];
    for(int i = 0; i < this->graph.size(); i++) {
        distances[i] = MAX;
    }

    // tutaj przechowywane sa rodzice wierzcholka
    int * parent = new int[this->graph.size()];

    // zaladowanie pierwszego wierzcholka do kolejki
    Q.push(make_pair(0, node));

    // ustawienie dystansu do siebie na 0
    distances[node] = 0;

    // pierwszy wierzcholek nie ma zadnego poprzednika w sciezce
    parent[node] = -1;

    while(!Q.empty()) {
        // pobranie atrybutu source wierzcholka
        int v1 = Q.top().second;

        // usuniecie wierzcholka o najnizszej wadze z kolejki piorytetowej
        Q.pop();

        // itracja po kazdym sasiadujacym wierzcholku
        auto iter = this->graph[v1].begin();
        while (iter != this->graph[v1].end()) {
            int v2 = (*iter).destination;
            int weight = (*iter).weight;

            // jesli jest krotsza droga z wierzcholka v1 do v2 to aktualizuje ja
            if(distances[v2] > distances[v1] + weight) {
                distances[v2] = distances[v1] + weight;
                Q.push(make_pair(distances[v2], v2));

                // zapisuje rodzica wierzcholka na potrzeby wyswietlenia calej sciezki
                parent[v2] = v1;
            }
            iter++;
        }
    }

    printf("\n--- Algorytm wykonany na liscie sasiedztwa ---\n");
    printf("Odleglosc z wierzcholka %d do pozostalych wierzcholkow:\n", this->startNodeSP);
    printf("Z:    Do:       Waga:    Sciezka:\n");
    for(int i = 0; i < this->graph.size(); i++) {
        printf("%d  ->  %d        %d        %d ", this->startNodeSP, i, distances[i], this->startNodeSP);

        printPath(parent, i);
        cout << endl;
    }

    delete [] distances;
    delete [] parent;
    Q = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    clear();
}

void AdjacencyList::fordBellman() {
    // najkrotsze odleglosci
    int* distances = new int[this->graph.size()];

    // tutaj przechowywane sa rodzice wierzcholka
    int * parent = new int[this->graph.size()];

    // zainicjalizowanie odleglosci i rodzicow dla kazdego wierzcholka
    for(int i = 0; i < this->graph.size(); i++) {
        distances[i] = MAX;
        parent[i] = -1;
    }

    // numer wierzcholka startowego
    int node = this->startNodeSP;

    // ustawienie dystansu do siebie na 0
    distances[node] = 0;

    for(int i = 1; i < this->graph.size() - 1; i++) {
        for (auto &edge : allEdges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if(distances[u] != MAX && distances[v] > distances[u] + weight) {
                distances[v] = distances[u] + weight;
                parent[v] = u;
            }
        }
    }

    printf("\n--- Algorytm wykonany na liscie sasiedztwa ---\n");
    printf("Odleglosc z wierzcholka %d do pozostalych wierzcholkow:\n", this->startNodeSP);
    printf("Z:    Do:       Waga:    Sciezka:\n");
    for(int i = 0; i < this->graph.size(); i++) {
        printf("%d  ->  %d        %d        %d ", this->startNodeSP, i, distances[i], this->startNodeSP);

        printPath(parent, i);
        cout << endl;
    }

    // sprawdzenie czy sa ujemne cykle
    for (auto &edge : allEdges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;
        if(distances[u] != MAX && distances[v] > distances[u] + weight) {
            printf("\nGraf zawiera ujemny cykl.");
        }
    }

    delete [] distances;
    delete [] parent;
    clear();
}

void AdjacencyList::clear() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->startNodeSP = 0;
    this->graph.clear();
    this->graph.resize(0);
    this->allEdges.clear();
    this->allEdges.resize(0);
    this->spanningTree.clear();
    this->spanningTree.resize(0);
    priorQueue = priority_queue<Edge, vector<Edge>, CompareWeight>();
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