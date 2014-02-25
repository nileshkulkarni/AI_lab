#include "Astar.h"

void printlist(list<NodePtr> l){
  list<NodePtr> ::iterator it ;
  for(it=l.begin();it!=l.end();it++){
        (*it)->data.print();
        cout<<" , ";
    }
    cout<<endl;
}

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

NodePtr AStar::findInOpenList(NodePtr n){
    if(n==NULL){
        std::cout<<"Searching for a NULL element in the list\n";
        return NULL;
    }
    list<NodePtr> ::iterator it ;
    for(it=openList.begin();it!=openList.end();it++){
        if( n->data == (*it)->data){
           return (*it);
        }
    }
    return NULL;
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
     printf("Expanding node:id= %lld\n", current->id);
     if(current->data == goal->data){
         std::cout<<"Path found. Reconstructing now\n";
         reconstructPath(current);
         return true;
     }
     removeNodeFromList(openList,current); 

     addNodeToList(closedList,current);
     printf("Adding node= %lld to Closed list\n", current->id);
     vector< NodePtr> nodeNbrs = getNeighbours(current);
    
    for(int i=0;i<nodeNbrs.size();i++){
        //nbr is a neighbouring node
        NodePtr nbr = nodeNbrs[i];
        if(findInList(closedList,nbr)){
            //TODO: remove the node from the closed and shift in open
            cout<<"Node found in closed list"<<endl;
            continue;
        }
        int tentative_g_score = current->g_score + distance(current,nbr);
        nbr->printData();
        printf("\n");

        //TODO update this with the follwing logic.
        // update if it is found in open list with higher g score
        // or else it is not in open list.
        NodePtr check_node = findInOpenList(nbr);
        if(check_node!=NULL && tentative_g_score < check_node->g_score){
            check_node->came_from = current;
            check_node->g_score = tentative_g_score;
            check_node->f_score = tentative_g_score + H(check_node,goal);
            printf("Updating node in open list %lld with new parent = %lld\n",check_node->id,current->id);
        }
        else if(check_node==NULL){
            nbr->came_from = current;
            nbr->g_score = tentative_g_score;
            nbr->f_score = tentative_g_score + H(nbr,goal);
            addNodeToList(openList,nbr);
            printf("Adding node= %lld to Open list with f_score %d \n", nbr->id,nbr->f_score);
        }
      }

    cout<<"------------------------------------------------------------------------------------"<<endl;
  }
  
  return false;
}

void AStar::reconstructPath(NodePtr node){
    NodePtr came_from = node->came_from;
    if(came_from==NULL){
        cout<<"came from is null"<<endl;
        return;
    }
    else{
        std::cout<<came_from->id<<" \n";
        reconstructPath(came_from);
        return;
    }
}
