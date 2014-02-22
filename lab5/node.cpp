#include "node.h"
 int Node::totalNodes = 0;

Node:: Node(int i){
        id =i;
        g_score = 0 ;
        f_score = 0 ;
        came_from = NULL;
        totalNodes++;
    }
    
Node:: Node(Data d){
        id = totalNodes;
        totalNodes++;
        data = d;
        string s;      
        id=d.getHash();
}
void Node:: addNeighbour(NodePtr n){
    for(int i =0;i<neighbours.size();i++){
        if(neighbours[i]->id == n->id){
            return;
        }
    }
    neighbours.push_back(n);
}
void Node::printData(){
    data.print();
    printf("\n");
}
void Node::setgenerator(AdjacentGenerator _gen){
    ag = _gen;
}

void Node::print(){
    printf("** Node  %ld\n", id);
    for(int i=0;i< neighbours.size();i++){
        printf("\t%ld" , neighbours[i]->id);
    }
    printf("\n");
}
