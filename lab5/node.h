#ifndef NODE_H
#define NODE_H
#include<list>
#include "header.h"

using namespace std;

class Node{
    public:
    int id; 
    vector<Node*> neighbours
    bool visted;  
    NodePtr parent;
    int dS;
    vector<Node*> getNeighbours();
    int g_score 
    bool operator =(Node n){
       id = n.id; 
    }
};
typedef Node* NodePtr;
#endif
