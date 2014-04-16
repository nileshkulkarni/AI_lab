#ifndef GRAPH_H
#define GRAPH_H
#include<list>
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

class Graph{
    public:
    Graph(nodeVector l);
    Graph(vector< vector<int> >);
    Graph();
    Graph(Node startNode); 
    vector<Node> allNodes;
    Node operator[](int i);
    void print();
};
#endif
