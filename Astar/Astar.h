#ifndef ASTAR_H
#define ASTAR_H
#include <iostream>
#include <list>
#include <set>
#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include "graph.h"
#include "node.h"
#include "header.h"
#include "Missionary.h"
#include <map>
#include <cmath>

using namespace std;
typedef int (*HeuristicF)(Node, Node) ;
class AStar{
    
    public:
        Graph G;
        AStar(Graph g);
        multiset<Node> closedSet;
        multiset<Node> openSet;
        HeuristicF H ;
        bool getShortestPath(int start, int end);
        bool getShortestPath(Node start, Node end);
        void setHeuristicFunction(HeuristicF f );
        bool findInSet( multiset<Node> l,Node n);
        Node getNodeFromSet( multiset<Node> l,Node n);
        bool addNodeToSet( multiset<Node>& l,Node n);
        Node getMinimumNode( multiset<Node> l);
        bool removeNodeFromSet( multiset<Node>& l,Node n);
        bool removeMinimum( multiset<Node>& l,Node n);
        int  distance(Node from, Node to );
        void reconstructPath(long long int,int);
        pair<Node,bool> findInOpenSet(Node n);
        map<long long int, long long int> came_from_map;
        Node next();
        void update(Node,Node);
        void bidirectional(Node,Node);
        bool findInClosedSet(Node n);
        int openSize();
        int closedSize();
        int reconstructPath_bi(long long int);


};
#endif
