#ifndef NODE_H
#define NODE_H
#include<iostream>
#include<vector>
#include<list>

using namespace std;
class Node;
typedef Node* NodePtr;
typedef vector<NodePtr> nodeVector;

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
    Node(int i){
        id =i;
        g_score = 1000 ;
        f_score = 1000 ;
    }
    void addNeighbour(NodePtr n){
        neighbours.push_back(n);
    }
};
#endif
