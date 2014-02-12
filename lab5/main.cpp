#include<iostream>
#include "Astar.h"
#include "node.h"
#include "graph.h"


int heuristic(NodePtr n1, NodePtr n2){
    
    if(n1->id == 1)
        return 5;
    if(n1->id == 3)
        return 3;
    if(n1->id == 5)
        return 10;
    if(n1->id == 2)
        return 6;
    if(n1->id == 4)
        return 4;
    if(n1->id=0)
        return 10;
    if(n1->id==6)
        return 0;
    return 1;

}

int main(){
   /* 
    NodePtr start = new Node(0); 
    NodePtr n1 = new Node(2); 
    NodePtr n2 = new Node(1);
    NodePtr goal = new Node(3); 
    start->addNeighbour(n1);
    start->addNeighbour(n2);
    n1->addNeighbour(start);
    n1->addNeighbour(n2);
    n2->addNeighbour(start);
    n2->addNeighbour(goal);
    goal->addNeighbour(n2);
    
    nodeVector l;
    l.push_back(start);
    l.push_back(n1);
    l.push_back(n2);
    l.push_back(goal);
    Graph graph(l);
   */
    vector< vector <int> > adjecencyMat;
    int noOfNodes = 7;
    adjecencyMat.resize(noOfNodes);
    for(int i =0;i<noOfNodes;i++){
        adjecencyMat[i].resize(noOfNodes);
    }
    adjecencyMat[0][1] =1;  
    adjecencyMat[0][2] = 1;
    adjecencyMat[0][5] = 1;
    adjecencyMat[1][3] = 1;
    adjecencyMat[2][4] = 1;
    adjecencyMat[3][6] = 1;
    adjecencyMat[5][6] = 1;
    adjecencyMat[4][6] = 1;
    Graph graph(adjecencyMat); 
    AStar a(graph);
    graph.print();
    a.setHeuristicFunction( & heuristic);
    a.getShortestPath(0,6);
    return 1;
}
