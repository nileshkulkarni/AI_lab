#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
using namespace std;

class Graph{
    public:
    vector<Node> allNodes;
    Node* operator[](int i){
        if(i<allNodes.size()){
            return allNodes[i];
        }
        return NULL;
        
    }
};
#endif
