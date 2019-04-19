#include "AdjacencyList.h"

AdjacencyList::AdjacencyList() {
    this->nodes = 0;
    this->edges = 0;
    this->density = 0;
    this->directed = true;
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
    Node node;

    clear();

    file.open(fileName);

    if(file.is_open()) {
        file >> str;
        this->edges = stoi(str);

        file >> str;
        this->nodes = stoi(str);

        printf("edges: %d, nodes: %d\n", edges, nodes);

        // TODO zerknac na to
//        if (type == "shortest_path") {
//            file >> str;
//            Node.source = stoi(str);
//        }

        // wczytywanie kolejnych wersow z pliku
        for(int i = 0; i < this->edges; i++) {
            file >> str;
            node.source = stoi(str);

            file >> str;
            node.destination = stoi(str);

            file >> str;
            node.weight = stoi(str);

            addNode(node.source, node.destination, node.weight);
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

    cout << "\nEdges: " << this->edges << endl;

    this->nodes = nodes;

    this->graph.resize(this->nodes, list<Node>(0));

    for(int i = 0; i < this->edges; i++) {
        addNode(rand() % this->nodes, // source
                rand() % this->nodes, // destination
                rand() % 10 + 1);     // weight
    }
}

void AdjacencyList::display() {
    if(directed) {
        printf("\n--- Graf skierowany ---");
        for(int i = 0; i < graph.size(); i++) {
            printf("\nNode[%d]: ", i);

            for (auto &iter : graph[i]) {
                printf(" -> %d(w: %d)   ", iter.destination, iter.weight);
            }
        }
        cout << endl;
    } else {
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
    this->graph.resize(this->nodes, list<Node>(0));

    if(this->directed) {
        this->graph[src].push_back(Node(src, dest, weight));
    } else {
        this->graph[src].push_back(Node(src, dest, weight));
        this->graph[dest].push_back(Node(dest, src, weight));
    }
}