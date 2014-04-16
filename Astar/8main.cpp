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
int euclidian(Node n1,Node n2, int no){
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
   
    return floor(sqrt(pow((endX -startX),2) + pow((endY-startY),2)));
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

int starightDistanceOver(Node n1, Node n2){
    int diff=0; 
    for(int i=1;i<9;i++){
        diff += pow(euclidian(n1,n2,i),2); 
    }
    return diff;
}
int straightDistance(Node n1, Node n2){
    int diff=0; 
    for(int i=1;i<9;i++){
        diff += euclidian(n1,n2,i); 
    }
    return diff;
}

int manhattan(Node n1, Node n2){
    int diff=0; 
    for(int i=1;i<9;i++){
        diff += difference(n1,n2,i); 
    }
    return diff;
}

int linearConflict(Node n1,Node n2){
    int conflict  = manhattan(n1,n2);
    int count1 =0;
    vector<int> state = n1.data._state;
    for(int i =0;i<3;i++){
        if(state[i] ==1 || state[i] ==2 || state[i] ==3 ){
            count1++;
        }

    }
    if(count1 >=2){
        //  common pairs
       for(int i =0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if((state[i] ==1 || state[i] ==2 || state[i] ==3))
                    if((state[j] ==1 || state[j] ==2 || state[j] ==3))
                        if(state[i] > state[j]){
                            conflict +=2;
                        }
            }
       }
    
    }
    count1 =0;
    for(int i =3;i<6;i++){
        if(state[i] ==4 || state[i] ==5 || state[i] ==6 ){
            count1++;
        }


    }
    if(count1 >=2){
        //  common pairs
       for(int i =3;i<6;i++){
            for(int j=i+1;j<6;j++){
                if((state[i] ==4 || state[i] ==5 || state[i] ==6))
                    if((state[j] ==4 || state[j] ==5 || state[j] ==6))
                        if(state[i] > state[j]){
                            conflict +=2;
                        }
            }
       }
    }
    count1 =0;
    for(int i =6;i<9;i++){

        if(state[i] ==7 || state[i] ==8){
            count1++;
        }

    }
    if(count1 >=2){
        //  common pairs
       for(int i =6;i<9;i++){
            for(int j=i+1;j<9;j++){
                if(state[i] ==7 || state[i] ==8)
                    if((state[j] ==7 || state[j] ==8))
                        if(state[i] > state[j]){
                            conflict +=2;
                        }
            }
       }
    }
    return conflict;

}
int inversionPairs(Node n1,Node n2){
   int inversion =0;
   for(int i =1;i<n1.data._state.size();i++){
       for(int j =i+1;j<n1.data._state.size();j++){
           if(n1.data._state[i] < n1.data._state[j])
               inversion++;
       }
   }
}

int displace(Node n1, Node n2){
    int diff=0; 
    for(int i=0;i<9;i++){
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
    for(int i =0;i<9;i++){
        cin>>j;
        state.push_back(j);
    }
    Data d;
    d.vec_assign(state);
    Node start(d);
    
    vector<int> finals;
    for(int i =1;i<9;i++){
        finals.push_back(i);
    }
    finals.push_back(0);
    Data d2;
    d2.vec_assign(finals);
    Node stop(d2);
    
        printf("Start Node is: \n");
        start.printData();
        printf("\nEnd Node is: \n");
        stop.printData();
        printf("\n");
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
        else if(hue=="EUCLIDEAN"){
            a.setHeuristicFunction( &straightDistance );
            a.getShortestPath(start,stop);
        }
        else if(hue=="LINEAR_CONFLICT"){
            a.setHeuristicFunction( & linearConflict);
            a.getShortestPath(start,stop);
        }
        else if(hue=="OVER_ESTIMATE"){
            a.setHeuristicFunction( & starightDistanceOver);
            a.getShortestPath(start,stop);
        }
        else if(hue=="INVERSION"){
            a.setHeuristicFunction( & inversionPairs);
            a.getShortestPath(start,stop);
        }
        else{
            printf("Heuristic not found\n");
            goto INPUT; 
        }
    return 1;
}
