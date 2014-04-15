#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include<list>
#include<set>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include "graph.h"
#include "node.h"
#include "header.h"
#include "8puzzle.h"
#include <map>
using namespace std;
typedef int (*HeuristicF)(Node, Node) ;
class AStar{
    
    public:
        Graph G;
        AStar(Graph g);
        set<Node> closedSet;
        set<Node> openSet;
        HeuristicF H ;
        bool getShortestPath(int start, int end);
        bool getShortestPath(Node start, Node end);
        void setHeuristicFunction(HeuristicF f );
        bool findInSet( set<Node> l,Node n);
        bool addNodeToSet( set<Node>& l,Node n);
        Node getMinimumNode( set<Node> l);
        bool removeNodeFromSet( set<Node>& l,Node n);
        int  distance(Node from, Node to );
        void reconstructPath(long long int);
        pair<Node,bool> findInOpenSet(Node n);
        map<long long int, long long int> came_from_map;
};
#endif
