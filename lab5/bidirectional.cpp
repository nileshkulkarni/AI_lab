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
    for(int i=0;i<9;i++){
        diff += difference(n1,n2,i); 
    }
    return diff;
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
	printf("Enter the Start Node in Row Major form");
    int j;
    vector<int> state;
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
    Graph graph_s(start); 
    AStar a(graph_s);

    Graph graph_e(stop); 
    AStar e(graph_e);
    
    string hue;
        
    INPUT:    printf("Enter Heuristic to use \n");
        cin>>hue;
        if(hue == "MANHATTEN"){
            a.setHeuristicFunction( & manhattan);
            e.setHeuristicFunction( & manhattan);
            
        }
        else if(hue== "DISPLACED"){

            a.setHeuristicFunction( & displace);
            e.setHeuristicFunction( & displace);
        }
        else if(hue=="ZERO"){
            a.setHeuristicFunction( & zero);
            e.setHeuristicFunction( & zero);
        }
        else{
            printf("Heuristic not found\n");
            goto INPUT; 
        }
        a.bidirectional(start,stop);
        e.bidirectional(stop,start);
        while(a.openSize()!=0 && e.openSize()!=0){
        	Node s1 = a.next();
        	Node s2 = e.next();

        	a.update(s1,stop);
        	e.update(s2,start);

        	if(a.findInClosedSet(s2)){
        		cout<<"Found path. Recontructing path"<<endl;
        		printNode(s2.id);
        		int steps=a.reconstructPath_bi(s2.id);
        		cout<<"----------------------------------------"<<endl;
        		cout<<"Goal Reached Destination"<<endl;
        		cout<<"----------------------------------------"<<endl;
        		
        		printNode(s2.id);
        		int steps2 = e.reconstructPath_bi(s2.id);
        		steps = steps + steps2;
        		cout<<"Took "<<steps<<" steps to complete"<<endl;
        		return 1;
        	}
        	if(e.findInClosedSet(s1)){
        		cout<<"Found path. Recontructing path"<<endl;
        		cout<<"----------------------------------------"<<endl;
        		printNode(s1.id);
        		int steps=a.reconstructPath_bi(s1.id);
        		cout<<"----------------------------------------"<<endl;
        		cout<<"Goal Reached Destination"<<endl;
        		cout<<"----------------------------------------"<<endl;
        		printNode(s1.id);
        		int steps2=e.reconstructPath_bi(s1.id);
        		steps = steps + steps2;
        		cout<<"Took "<<steps<<" steps to complete"<<endl;
        		return 1;
        	}
        }
        cout<<"Sigh! :( No path found"<<endl;
        
        
    return 1;
}
