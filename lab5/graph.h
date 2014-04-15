#ifndef GRAPH_H
#define GRAPH_H
#include<list>
#include "node.h"
using namespace std;

class Graph{
    public:
    Graph(nodeVector l);
    vector<NodePtr> allNodes;
    NodePtr operator[](int i);
};
#endif
