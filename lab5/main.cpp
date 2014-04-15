#include<iostream>
#include "Astar.h"
#include "node.h"
#include "graph.h"


int heuristic(NodePtr n1, NodePtr n2){
    return 1;

}

int main(){
    
    NodePtr start = new Node(0); 
    NodePtr goal = new Node(2); 
    NodePtr n1 = new Node(2); 
    NodePtr n2 = new Node(1);
    //start->addNeighbour(n1);
    start->addNeighbour(n2);
   // n1->addNeighbour(start);
    //n1->addNeighbour(n2);
    n2->addNeighbour(start);
    n2->addNeighbour(goal);
    goal->addNeighbour(n2);
    
    nodeVector l;
    l.push_back(start);
    l.push_back(n2);
    l.push_back(goal);
    Graph graph(l);
    
    AStar a(graph);
    a.setHeuristicFunction( & heuristic);
    a.getShortestPath(0,2);
    return 1;
}
