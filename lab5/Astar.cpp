#include "Astar.h"


AStar::AStar(Graph g){
   G.allNodes =g.allNodes; 

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
    return n;
}
bool AStar::findInList( list<NodePtr> l,NodePtr n){
    if(n==NULL){
        std::cout<<"Searching for a NULL element in the list\n";
        return false;
    }
    list<NodePtr> ::iterator it ;
    for(it=l.begin();it!=l.end();it++){
        if( n->id == (*it)->id)
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
        if( n->id == (*it)->id)
            l.erase(it);
    }
    return false;

}
int AStar::distance(NodePtr from, NodePtr to ){
    return 1;    
}


bool AStar::getShortestPath(int _start, int _end){

  NodePtr goal = G[_end]; 
  NodePtr start = G[_start];
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
     if(current->id==goal->id){
         std::cout<<"Path found\n";
         reconstructPath(goal);
         return true;
     }

     removeNodeFromList(openList,current); 

     addNodeToList(closedList,current);
      
     for(int i=0;i<(current->neighbours).size();i++){
        NodePtr nbr = current->neighbours[i];
        if(findInList(closedList,nbr)){
            continue;
        }
        int tentative_g_score = current->g_score + distance(current,nbr);
        
        if(!findInList(openList,nbr) || tentative_g_score < nbr->g_score){
            nbr->came_from = current;
            nbr->g_score = tentative_g_score;
            nbr->f_score = tentative_g_score + H(current,nbr);
            if(!(findInList(openList,nbr))){
                addNodeToList(openList,nbr);
            }
        }
        if(findInList(openList,nbr)){
            addNodeToList(openList,nbr);
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
