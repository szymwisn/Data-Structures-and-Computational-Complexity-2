#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->directed = false;
}

AdjacencyList::AdjacencyList(string fileName, string type) : AdjacencyList() {
    loadFromFile(fileName, type);
}

AdjacencyList::AdjacencyList(int nodes, double density) : AdjacencyList() {
    generate(nodes, density);
}

AdjacencyList::~AdjacencyList() {
    clear();
}

void AdjacencyList::loadFromFile(string fileName, string type) {
    ifstream file;
    string str;

    clear();

    file.open(fileName);

    if(file.is_open()) {
        file >> str;
        this->edges = stoi(str);

        file >> str;
        this->nodes = stoi(str);

        printf("edges: %d, nodes: %d\n", edges, nodes);

        element element;

        // TODO zerknac na to
//        if (type == "shortest_path") {
//            file >> str;
//            element.source = stoi(str);
//        }

        // wczytywanie kolejnych wersow z pliku
        for(int i = 0; i < this->edges; i++) {

            file >> str;
            element.source = stoi(str);

            file >> str;
            element.destination = stoi(str);

            file >> str;
            element.weight = stoi(str);

            printf("   s: %d, d: %d, w: %d\n", element.source, element.destination, element.weight);
//            addNode(element.source, element.destination, element.weight, this->graph);
//            this->graph[element.source].push_back(element(element.source, element.destination, element.weight));
        }

        file.close();
    } else {
        cout << "Nie udalo sie otworzyc pliku." << endl;
    }
}

void AdjacencyList::generate(int nodes, double density) {
    for(int i = 0; i < nodes; i++) {
        addNode(rand() % this->nodes, // source
                rand() % this->nodes, // destination
                rand() % 10,          // weight
                graph);
    }
}

void AdjacencyList::display() {
    for(int i = 0; i < graph.size(); i++) {
        printf("element[%d]: ", i);
//        list<element>::iterator iter = graph[i].begin();
        auto iter = graph[i].begin();

        while(iter != graph[i].end()){
            printf("%d -> %d(%d)", (*iter).source, (*iter).destination, (*iter).weight);
            iter++;
        }
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
    this->directed = false;
    this->graph.clear(); //TODO zastanowic sie nad tym
}

void AdjacencyList::addNode(int src, int dest, int weight, vector<list<element>>& graph) {
    graph[src].push_back(element(src, dest, weight));
    nodes++;
}