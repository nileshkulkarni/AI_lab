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
class Node{
    public:
    int id; 
    NodePtr came_from;
    vector<NodePtr> neighbours;
    int g_score ;
    int f_score ;
    Data data;
    Node(int i){
        id =i;
        g_score = 0 ;
        f_score = 0 ;
        came_from = NULL;
    }
    void addNeighbour(NodePtr n){
        for(int i =0;i<neighbours.size();i++){
            if(neighbours[i]->id == n->id){
                return;
            }
        }
        neighbours.push_back(n);
    }

    void print(){
        printf("** Node  %d\n", id);
        for(int i=0;i< neighbours.size();i++){
            printf("\t%d" , neighbours[i]->id);
        }
        printf("\n");
    }
};
#endif
