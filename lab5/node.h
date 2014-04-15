#ifndef NODE_H
#define NODE_H
#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include "header.h"
//#include "Missionary.h"
#include "8puzzle.h"
using namespace std;

typedef Node* NodePtr;
typedef vector<Node> nodeVector;
typedef vector<Node> (*AdjacentGenerator)(Node) ;

class Node{
    
    public:
        static int totalNodes; 
        long long  int id; 
        NodePtr came_from;
        vector<Node> neighbours;
        int g_score ;
        int f_score ;
        struct Data data;
        AdjacentGenerator ag; 
        bool operationEqual; 
        Node(int i);
        
        Node(Data d);

        void addNeighbour(Node n);
        void printData();
        void setgenerator(AdjacentGenerator _gen);

        void print();
        bool operator<(const Node& n)const;
        bool operator==(const Node& n)const;

};
#endif
