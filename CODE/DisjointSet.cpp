#include "DisjointSet.h"

DisjointSet::DisjointSet(int size) {
    this->size = size;

    parent = new int[size+1];
    rank = new int[size+1];

    for(int i = 0; i <= size; i++) {
        rank[i] = 0;
        parent[i] = i;
    }
}

DisjointSet::~DisjointSet() {
    delete [] parent;
    delete [] rank;
    this->size = 0;
}

// znajduje rodzica podanego wierzcholka - sprawdza w jakim zbiorze jest dany element
int DisjointSet::findParent(int node) {
    if(node != parent[node]) {
        parent[node] = findParent(parent[node]);
    }
    return parent[node];
}


// laczy 2 zbiory w jeden
void DisjointSet::makeUnion(int u, int v) {
    u = findParent(u);
    v = findParent(v);

    if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[u] = v;
    }

    if (rank[u] == rank[v]) {
        rank[v]++;
    }
}
