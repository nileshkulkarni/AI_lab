#include "Astar.h"


AStar::AStar(Graph g){
   G.allNodes =g.allNodes; 

}

bool AStat::findInList( list<NodePtr> l,NodePtr n){
    if(n==NULL){
        std::cout<<"Searching for a NULL element in the list\n";
        return false;
    }
    list<NodePtr> ::iterator it ;
    for(it=l.begin();it<l.end();it++){
        if( n->id == (*it)->id)
            return true;
    }
    return false;
}

int Astar::distance(NodePtr from, NodePtr to ){


}
AStar::getShortestPath(int start, int end){

  NodePtr goal = G[end]; 
  NodePtr start = G[start];
  if(goal==NULL){
    std::cout<<" Goal Node is set to NULL, cannot find a path\n";
    return;
  } 
  if(start==NULL){
    std::cout<<" Start Node is set to NULL, cannot find a path\n";
    return;
  }
  openList.push_back(start);
  while(!(openList.size() == 0)){
        
     NodePtr current  = getMinimumNode(openList);
     if(currentNodePtr->id==goal->id){
         std::cout<<"Path found\n";
         reconstructPath(came_from,goal);
         return true;
     }

     removeNodeFromList(openList,currentNodePtr); 

     addNodeToList(closedList,currentNodePtr);
      
     for(int i=0;i<current->neighbours.size();i++){
        NodePtr nbr = neighbours[i];
        if(findInList(nbr,closedList)){
            continue;
        }
        int tentative_g_score = current->g_score + dist(current,nbr->n);
        
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

Astar::re
