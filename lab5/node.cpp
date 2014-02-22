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
    }

    void Node:: addNeighbour(NodePtr n){
        for(int i =0;i<neighbours.size();i++){
            if(neighbours[i]->id == n->id){
                return;
            }
        }
        neighbours.push_back(n);
    }

    void Node::setgenerator(AdjacentGenerator _gen){
        ag = _gen;
    }

    void Node::print(){
        printf("** Node  %d\n", id);
        for(int i=0;i< neighbours.size();i++){
            printf("\t%d" , neighbours[i]->id);
        }
        printf("\n");
    }
