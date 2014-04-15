#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<list>

using namespace std;
class Node;
typedef Node* NodePtr;

class Node{
    public:
    int id; 
    NodePtr came_from;
    vector<NodePtr> neighbours;
    bool visted;  
    NodePtr parent;
    int dS;
    int g_score ;
    int f_score ;
};
#endif
