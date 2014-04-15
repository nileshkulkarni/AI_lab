#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include<list>
#include "graph.h"
#include "node.h"
using namespace std;
typedef int (*HeuristicF)(NodePtr, NodePtr) ;

class AStar{
    
    public:
        Graph G;
        AStar(Graph g);
        list<NodePtr> closedList;
        list<NodePtr> openList;
        HeuristicF H ;
        bool getShortestPath(int start, int end);
        void setHeuristicFunction(HeuristicF f );
        bool findInList( list<NodePtr> l,NodePtr n);
        bool addNodeToList( list<NodePtr>& l,NodePtr n);
        NodePtr getMinimumNode( list<NodePtr> l);
        bool removeNodeFromList( list<NodePtr>& l,NodePtr n);
        int  distance(NodePtr from, NodePtr to );
        void reconstructPath(NodePtr node);

};
#endif
