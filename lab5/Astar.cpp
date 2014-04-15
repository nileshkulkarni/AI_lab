#include "Astar.h"

void printSet(set<Node> l){
  set<Node> ::iterator it ;
  for(it=l.begin();it!=l.end();it++){
        ((struct Data)(*it).data).print();
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
Node AStar::getMinimumNode( set<Node> l){
    if(l.size()>=1){
        set<Node>::iterator it = l.begin();
        printf("Minimum f_score node is %lld \n", (*it).id);
        return *it;
    }
    else{
        printf("Set is empty, no nodes left to expand");
        //exit(0);
    }
}
bool AStar::findInSet( set<Node> l,Node n){
    set<Node> ::iterator it ;
    for(it=l.begin();it!=l.end();it++){
        if( n.data == (*it).data)
            return true;
    }
    return false;
}

pair<Node,bool> AStar::findInOpenSet(Node n){
   printf("Looking fo node existing is openset id is %lld",n.id);
    
    set<Node>::iterator it = openSet.find(n);
    if(it == openSet.end()){
            printf( "   Node not found\n");
         pair<Node,bool>p = make_pair(n,false);
         return p;
    }
            printf( "   Node  found\n");
    pair<Node,bool>p = make_pair((*it),true);
    return p;
}

bool AStar::addNodeToSet( set<Node>& l,Node n){
    
    l.insert(n);
    return true;
}
bool AStar::removeNodeFromSet( set<Node>& l,Node n){
    
    set<Node> ::iterator it =l.find(n);
    if(it==l.end()){
        std::cout<<"Shouldn't come here, should be called after ensuring that the element exists in the list\n";
        return false;
    }
    else{
        l.erase(it);
        return true;
    }

}
int AStar::distance(Node from, Node to ){
    return 1;    
}

bool AStar::getShortestPath(int _start, int _end){

  Node goal = G.allNodes[_end]; 
  Node start =G.allNodes[_start];
  getShortestPath(start,goal);
}

bool AStar::getShortestPath(Node _start, Node _end){

  Node goal = _end; 
  Node start =_start;
  came_from_map[start.id] = -1;
  addNodeToSet(openSet,start);
  while(!(openSet.size() == 0)){
        
     Node current  = getMinimumNode(openSet);
     printf("Expanding node:id= %lld\n", current.id);
     if(current.data == goal.data){
         std::cout<<"Path found. Reconstructing now\n";
         reconstructPath(current.id);
         return true;
     }
     removeNodeFromSet(openSet,current); 

     addNodeToSet(closedSet,current);
     printf("Adding node= %lld to Closed set\n", current.id);
     vector<Node> nodeNbrs = getNeighbours(current);
     
    for(int i=0;i<nodeNbrs.size();i++){
        //nbr is a neighbouring node
        Node nbr = nodeNbrs[i];
        if(findInSet(closedSet,nbr)){
            //TODO: remove the node from the closed and shift in open
            cout<<"Node found in closed set"<<endl;
            continue;
        }
        int tentative_g_score = current.g_score + distance(current,nbr);
        printf("Here printing  ");
        nbr.printData();
        printf("\n");

        //TODO update this with the follwing logic.
        // update if it is found in open set with higher g score
        // or else it is not in open set.
        pair<Node,bool> check = findInOpenSet(nbr);
        
        if(check.second && tentative_g_score < check.first.g_score){
            removeNodeFromSet(openSet,nbr);
            came_from_map[check.first.id] = current.id;
            //check.first.came_from = &current;
            check.first.g_score = tentative_g_score;
            check.first.f_score = tentative_g_score + H(check.first,goal);
            addNodeToSet(openSet,check.first);
            printf("Updating node in open set %lld with new parent = %lld\n",check.first.id,current.id);
        }
        else if(check.second==false){
            came_from_map[check.first.id] = current.id;
            //nbr.came_from = &current;
            nbr.g_score = tentative_g_score;
            nbr.f_score = tentative_g_score + H(nbr,goal);
            addNodeToSet(openSet,nbr);
            printf("Adding node= %lld to Open set with f_score %d \n", nbr.id,nbr.f_score);
        }
      }

    cout<<"------------------------------------------------------------------------------------"<<endl;
  }
  
  return false;
}

void AStar::reconstructPath(int long long id){
    long long int came_from = came_from_map[id]; 
    if(came_from == -1){
        cout<<"reached "<<endl;
        return;
    }
    else{
        std::cout<<came_from<<" \n";
        reconstructPath(came_from);
        return;
    }
}
