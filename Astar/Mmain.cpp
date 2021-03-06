#include <iostream>
#include "Astar.h"
#include "node.h"
#include "graph.h"
#include <cmath>


int heuristic(Node n1, Node n2){
    
    if(n1.id == 1)
        return 5;
    if(n1.id == 3)
        return 3;
    if(n1.id == 5)
        return 10;
    if(n1.id == 2)
        return 6;
    if(n1.id == 4)
        return 4;
    if(n1.id=0)
        return 10;
    if(n1.id==6)
        return 0;
    return 1;

}
int difference(Node n1,Node n2, int no){
    int start=-1 , end=-1;
    for(int i =0;i<n1.data._state.size();i++){
        if(n1.data._state[i] ==no){
            start = i;
            break;
        }
    }
    if(start == -1){
        printf("Unable to calculate heuristic start is -1\n");
        exit(0);
    }
    for(int i =0;i<n2.data._state.size();i++){
        if(n2.data._state[i] ==no){
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
int manhattan(Node n1, Node n2){
    int diff=0; 
    for(int i=0;i<1;i++){
        diff += abs(n1.data._state[i] - n2.data._state[i]); 
    }
    diff += abs(n1.data._state[5] - n2.data._state[5]); 
    return diff;
}

int displace(Node n1, Node n2){
    int diff=0; 
    for(int i=0;i<1;i++){
        if(n1.data._state[i] !=n1.data._state[i]){
           diff++; 
        }
    }
    return diff;
}

int zero(Node n1,Node n2){
    return 0;
}

int main(int argc, char* argv[]){
    vector< vector <int> > adjecencyMat;
    vector<int> state;
   
   printf("Enter the Start Node in Row Major form");
   int j;
    for(int i =0;i<5;i++){
        cin>>j;
        state.push_back(j);
    }
    Data d;
    d.vec_assign(state);
    Node start(d);
    
    vector<int> finals;
    finals.push_back(0);
    finals.push_back(0);
    Data d2;
    finals.push_back(3);
    finals.push_back(3);
    finals.push_back(1);
    d2.vec_assign(finals);
    Node stop(d2);
    Graph graph(start); 
    AStar a(graph);
    string hue;
        
    INPUT:    printf("Enter Heuristic to use \n");
        cin>>hue;
        if(hue == "MANHATTEN"){
            a.setHeuristicFunction( & manhattan);
            a.getShortestPath(start,stop);
        }
        else if(hue== "DISPLACED"){

            a.setHeuristicFunction( & displace);
            a.getShortestPath(start,stop);
        }
        else if(hue=="ZERO"){
            a.setHeuristicFunction( & zero);
            a.getShortestPath(start,stop);
        }
        else{
            printf("Heuristic not found\n");
            goto INPUT; 
        }

    return 1;
}
