#ifndef GRAPH_H
#define GRAPH_H
#include<list>
#include "node.h"
#include <stdio.h>
using namespace std;

class Graph{
    public:
    Graph(nodeVector l);
    Graph(vector< vector<int> >);
    Graph();
    vector<NodePtr> allNodes;
    NodePtr operator[](int i);
    void print();
};
#endif
