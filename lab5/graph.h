#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include "node.h"
using namespace std;

class Graph{
    public:
    vector<NodePtr> allNodes;
    NodePtr operator[](int i);
};
#endif
