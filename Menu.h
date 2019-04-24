#ifndef DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_MENU_H
#define DATA_STRUCTURES_AND_COMPUTATIONAL_COMPLEXITY_2_MENU_H

#include<string>
#include<iostream>
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

using namespace std;

class Menu {
public:
    void displayMenuMST();
    void displayMenuShortestPath();
    void menuMST();
    void menuShortestPath();
};


#endif
