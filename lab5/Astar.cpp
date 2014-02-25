#include "Astar.h"


AStar::AStar(Graph g):G(g.allNodes){

}
void AStar::setHeuristicFunction(HeuristicF f){
    H =f; 
    return;
}
NodePtr AStar::getMinimumNode( list<NodePtr> l){
    if(l.size() == 0){
        return NULL;
    }
    NodePtr n = l.front();
    int min = n->f_score;
    list<NodePtr> ::iterator it ;
    for(it=l.begin();it!=l.end();it++){
        if( (*it)->f_score < min){
            n = *it;
            min = (*it)->f_score;
        }
    }
    printf("Minimum f_score node is %lld \n", n->id);
    return n;
}
bool AStar::findInList( list<NodePtr> l,NodePtr n){
    if(n==NULL){
        std::cout<<"Searching for a NULL element in the list\n";
        return false;
    }
    list<NodePtr> ::iterator it ;
    for(it=l.begin();it!=l.end();it++){
        if( n->data == (*it)->data)
            return true;
    }
    return false;
}

bool AStar::addNodeToList( list<NodePtr>& l,NodePtr n){
    
    if(n==NULL){
        std::cout<<"Searching for a NULL element in the list\n";
        return false;
    }
    l.push_back(n);

}
bool AStar::removeNodeFromList( list<NodePtr>& l,NodePtr n){
    
    if(n==NULL){
        std::cout<<"Searching for a NULL element in the list\n";
        return false;
    }
    list<NodePtr> ::iterator it ;
    for(it=l.begin();it!=l.end();it++){
        if( n->data == (*it)->data){
            l.erase(it);
            break;
        }
    }
    return false;

}
int AStar::distance(NodePtr from, NodePtr to ){
    return 1;    
}

bool AStar::getShortestPath(int _start, int _end){

  NodePtr goal = G.allNodes[_end]; 
  NodePtr start =G.allNodes[_start];
    getShortestPath(start,goal);
}

bool AStar::getShortestPath(NodePtr _start, NodePtr _end){

  NodePtr goal = _end; 
  NodePtr start =_start;

  if(goal==NULL){
    std::cout<<" Goal Node is set to NULL, cannot find a path\n";
    return false;
  } 
  if(start==NULL){
    std::cout<<" Start Node is set to NULL, cannot find a path\n";
    return false;
  }
  addNodeToList(openList,start);
  while(!(openList.size() == 0)){
        
     NodePtr current  = getMinimumNode(openList);
     printf("Expanding Node current id  %lld\n", current->id);
     if(current->data == goal->data){
         std::cout<<"Path found\n";
         reconstructPath(goal);
         return true;
     }

     removeNodeFromList(openList,current); 

     addNodeToList(closedList,current);
     printf("Adding node with id %lld to Closed list, no of Nbrs \n", current->id);

    printf(" printing Nodes here \n");
    current->print();
    vector< NodePtr> nodeNbrs = getNeighbours(current);
    
    for(int i=0;i<nodeNbrs.size();i++){
        NodePtr nbr = nodeNbrs[i];
        if(findInList(closedList,nbr)){
            continue;
        }
        int tentative_g_score = current->g_score + distance(current,nbr);
        printf("Printing nbrs doubtful about zero nbr , %lld\n",nbr->id);
        printf("printing node data\n");
        nbr->printData();
        printf("\n");
        if(!findInList(openList,nbr) || tentative_g_score < nbr->g_score){
            nbr->came_from = current;
            nbr->g_score = tentative_g_score;
            nbr->f_score = tentative_g_score + H(nbr,goal);
            printf("Setting came_from for the node %lld = %lld\n",nbr->id,current->id);
            if(!(findInList(openList,nbr))){
                addNodeToList(openList,nbr);
                printf("Adding node with id %lld to Open list with f_score %d \n", nbr->id,nbr->f_score);
            }
        }
    }
  }
  
  return false;
}

void AStar::reconstructPath(NodePtr node){
    NodePtr came_from = node->came_from;
    if(came_from==NULL){
        return;
    }
    else{
        std::cout<<came_from->id<<" \n";
        reconstructPath(came_from);
        return;
    }
}
