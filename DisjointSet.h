#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_DISJOINTSET_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_DISJOINTSET_H


class DisjointSet {
    int* parent;
    int* rank;
    int size;  // size

public:
    explicit DisjointSet(int size);
    ~DisjointSet();

    int findParent(int node);
    void makeUnion(int u, int v);
};


#endif
