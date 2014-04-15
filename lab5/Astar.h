#ifndef ASTAR_H
#define ASTAR_H
#include<list>
#include "graph.h"
using namespace std;

class AStar{
    
    public:
        Graph G;
        AStar(Garph g);
        list<Node> closedList;
        list<Node> openList;
        int (*function)(Node*,Node*) H;

        void getShortestPath(int start, int end);
        void setHeuristicFunction(int (*function)(Node*,Node*) f){
            H =f; 
            return;
        }

};
#endif
