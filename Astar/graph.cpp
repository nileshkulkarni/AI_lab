#include "graph.h"
Graph:: Graph(nodeVector l){
       allNodes  =l; 
}
Graph:: Graph(Node startNode){
    allNodes.push_back(startNode);
}
Graph:: Graph(vector< vector<int> > adjacencyMat){

    int noOfNodes = adjacencyMat.size();
    for(int i =0;i<noOfNodes;i++){
        Node n(i);
        allNodes.push_back(n);
    }
    for(int i =0;i<noOfNodes;i++){
        for(int j=0;j<noOfNodes;j++){
            if(adjacencyMat[i][j] ==1){
                //printf("adding nbr pair %d %d \n", allNodes[i].id, allNodes[j].id);
                allNodes[i].addNeighbour(allNodes[j]);
                allNodes[j].addNeighbour(allNodes[i]);
            }
        }
    }

}
void Graph::print(){
    for(int i =0;i<allNodes.size();i++){
       allNodes[i].print(); 
       printf("\n");
    }

}
Node Graph:: operator[](int i){
        if(i<allNodes.size()){
            return allNodes[i];
        }
        else{
            printf("Trying to get operator out of index\n");
            //exit(0);
        }
}
