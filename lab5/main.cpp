#include<iostream>
#include "Astar.h"
#include "node.h"
#include "graph.h"
#include <cmath>


int heuristic(NodePtr n1, NodePtr n2){
    
    if(n1->id == 1)
        return 5;
    if(n1->id == 3)
        return 3;
    if(n1->id == 5)
        return 10;
    if(n1->id == 2)
        return 6;
    if(n1->id == 4) return 4;
    if(n1->id=0)
        return 10;
    if(n1->id==6)
        return 0;
    return 1;

}
int difference(NodePtr n1,NodePtr n2, int no){
    int start=-1 , end=-1;
    for(int i =0;i<n1->data._state.size();i++){
        if(n1->data._state[i] ==no){
            start = i;
            break;
        }
    }
    if(start == -1){
        printf("Unable to calculate heuristic start is -1\n");
        exit(0);
    }
    for(int i =0;i<n2->data._state.size();i++){
        if(n2->data._state[i] ==no){
            end = i;
            break;
        }
    }

    if(end == -1){
        printf("Unable to calculate heuristic end is -1\n");
        exit(0);
    }
    int startX = start %3;
    int startY = start /3;
    int endX = end %3;
    int endY = end /3;
   
    return abs(endX -startX) + abs(endY-startY);
}
int manhattan(NodePtr n1, NodePtr n2){
    int diff=0; 
    for(int i=0;i<9;i++){
        diff += difference(n1,n2,i); 
    }
    return diff;
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
    vector<int> state;
    state.push_back(0);
    state.push_back(1);
    state.push_back(2);
    state.push_back(3);
    for(int i = 4; i < 9 ; i++)
        state.push_back(i);
    Data d;
    d.vec_assign(state);
    NodePtr start = new Node(d);
    
    vector<int> finals;
     finals.push_back(3);
     finals.push_back(4);
     finals.push_back(2);
     finals.push_back(0);
     finals.push_back(1);
     finals.push_back(5);
    for(int j=6;j<9;j++){
        finals.push_back(j);
    }
    
    Data d2;
    d2.vec_assign(finals);
    NodePtr stop = new Node(d2);
    printf("Printing Start ");
    start->printData();
    printf("\nPrinting End ");
    stop->printData();
    printf(" \n");
    Graph graph(start); 
    AStar a(graph);
   // graph.print();
    a.setHeuristicFunction( & manhattan);
    a.getShortestPath(start,stop);

    /*
 
    
    int noOfNodes = 7;
    adjecencyMat.resize(noOfNodes);
    for(int i =0;i<noOfNodes;i++){
        adjecencyMat[i].resize(noOfNodes);
    }
 */
    /*
    adjecencyMat[0][1] =1;  
    adjecencyMat[0][2] = 1;
    adjecencyMat[0][5] = 1;
    adjecencyMat[1][3] = 1;
    adjecencyMat[2][4] = 1;
    adjecencyMat[3][6] = 1;
    adjecencyMat[5][6] = 1;
    adjecencyMat[4][6] = 1;
    Graph graph(adjecencyMat); 
     */
    /*vector<int> start_state;
    for(int i =0;i<10;i++){
        start_state.push_back(i);
    }
    Data d;
    d._state = start_state;
    Node startNode(d);
    Graph graph(&startNode); 

    AStar a(graph);
   // graph.print();
    a.setHeuristicFunction( & manhattan);
    a.getShortestPath(0,6);
    */
    return 1;
}
