#ifndef NODE_H
#define NODE_H
#include<stdio.h>
#include<iostream>
#include<vector>
#include<list>
#include "header.h"
using namespace std;
class Node;
typedef Node* NodePtr;
typedef vector<NodePtr> nodeVector;
typedef vector<NodePtr> (*AdjacentGenerator)(NodePtr) ;
class Node{
    
    public:
    static int totalNodes; 
    int id; 
    NodePtr came_from;
    vector<NodePtr> neighbours;
    int g_score ;
    int f_score ;
    Data data;
    AdjacentGenerator ag; 
    
    Node(int i);
    
    Node(Data d);

    void addNeighbour(NodePtr n);

    void setgenerator(AdjacentGenerator _gen);

    void print();

};
#endif
