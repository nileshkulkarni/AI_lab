#include "node.h"

int Node::totalNodes = 0;

Node:: Node(int i){
        id =i;
        g_score = 0 ;
        f_score = 0 ;
        came_from = NULL;
        totalNodes++;
        operationEqual =false;
    }
    
Node:: Node(Data d){
        data.assign(d);
        //printData();
        id=getHash(d._state);
        g_score = 0 ;
        f_score = 0 ;
        came_from = NULL;
        operationEqual =false;
}
bool Node::operator==(const Node &n1)const{
    return id==n1.id;
}
bool Node::operator<(const Node &n1)const{
   //w printf("called\n");
 /*   printf("Nodes comparing with %lld\n", n1.id);
    if(n1.operationEqual){
        printf("Does do a equality check\n");
        printf("Check returned %d \n", id== n1.id);
        return id == n1.id;
        
    }
    printf("Does do a less then check\n");
   */
    return f_score<n1.f_score;


}
void Node:: addNeighbour(Node n){
    for(int i =0;i<neighbours.size();i++){
        if(neighbours[i].id == n.id){
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
    printf("Node:print->  %lld\n", id);
    for(int i=0;i< neighbours.size();i++){
        printf("\t%lld" , neighbours[i].id);
    }
    printf("\n");
}
