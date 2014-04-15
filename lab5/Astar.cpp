#include "Astar.h"
void printSet(multiset<Node> l){
  multiset<Node> ::iterator it ;
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
Node AStar::getMinimumNode( multiset<Node> l){
    if(l.size()>=1){
        multiset<Node>::iterator it = l.begin();
#if DEBUG
        printf("Minimum f_score node is %lld \n", (*it).id);
#endif
        return *it;
    }
    else{
        printf("Set is empty, no nodes left to expand");
        //exit(0);
    }
}
bool AStar::findInSet( multiset<Node> l,Node n){

    multiset<Node> ::iterator it;
    for(it = l.begin();it!=l.end();it++){
        if(n.id == (*it).id){
            return true;
        }

    }

    return false;
}

Node AStar::getNodeFromSet( multiset<Node> l,Node n){

    multiset<Node> ::iterator it;
    for(it = l.begin();it!=l.end();it++){
        if(n.id == (*it).id){
            return *it;
        }

    }
}


pair<Node,bool> AStar::findInOpenSet(Node n){
   
    multiset<Node> ::iterator it;
    for(it = openSet.begin();it!=openSet.end();it++){
        if(n.id == (*it).id){
         pair<Node,bool>p = make_pair((*it),true);
            return p;
        }

    }
         pair<Node,bool>p = make_pair(n,false);
         return p;
}

bool AStar::addNodeToSet( multiset<Node>& l,Node n){
    
    l.insert(n);
    return true;
}
bool AStar::removeMinimum( multiset<Node>& l,Node n){
    
    multiset<Node>::iterator it = l.begin();
    if(l.size()>=1){
        l.erase(it);
    }
}
bool AStar::removeNodeFromSet( multiset<Node>& l,Node n){
    
    n.operationEqual = true; 
    //printf("Equality check before removing\n");
    multiset<Node> ::iterator it;
    for(it = l.begin();it!=l.end();it++){
        if(n.id == (*it).id){
            break;
        }

    }
#if DEBUG
    printf("Trying to remove node %lld\n",n.id);
#endif
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

#if DEBUG
     printf("Size of open list is %d \n", openSet.size()); 
#endif
     Node current  = getMinimumNode(openSet);
#if DEBUG
     printf("Expanding node:id= %lld\n", current.id);
#endif
     if(current.data == goal.data){
         cout<<"\nPath found.Reconstructing the path.\n";
         reconstructPath(current.id,0);
         return true;
     }
     removeMinimum(openSet,current); 

     addNodeToSet(closedSet,current);
#if DEBUG
     printf ("Adding node= %lld to Closed multiset\n", current.id);
#endif
     vector<Node> nodeNbrs = getNeighbours(current);
     
    for(int i=0;i<nodeNbrs.size();i++){
        //nbr is a neighbouring node
        Node nbr = nodeNbrs[i];
        if(findInSet(closedSet,nbr)){
            //TODO: remove the node from the closed and shift in open
#if DEBUG
            cout<<"Node found in closed multiset "<< nbr.id<<endl;
#endif
            Node nodeInClosedList = getNodeFromSet(closedSet,nbr);
            
            int temp_g_score = current.g_score + distance(current,nbr);
            
            if(temp_g_score <  nodeInClosedList.g_score){
                removeNodeFromSet(closedSet,nodeInClosedList);
            }
            continue;

        }
        int tentative_g_score = current.g_score + distance(current,nbr);
#if DEBUG
        nbr.printData();
#endif
        //TODO update this with the follwing logic.
        // update if it is found in open multiset with higher g score
        // or else it is not in open multiset.
        pair<Node,bool> check = findInOpenSet(nbr);
        
        if(check.second && tentative_g_score < check.first.g_score){
            removeNodeFromSet(openSet,nbr);
            came_from_map[check.first.id] = current.id;
#if DEBUG
            printf("Setting parent of %lld to %lld\n", check.first.id, current.id);
#endif
            //check.first.came_from = &current;
            check.first.g_score = tentative_g_score;
            check.first.f_score = tentative_g_score + H(check.first,goal);
            addNodeToSet(openSet,check.first);
#if DEBUG
            printf("Updating node in open multiset %lld with new parent = %lld\n",check.first.id,current.id);
#endif
        }
        else if(check.second==false){
            came_from_map[check.first.id] = current.id;
#if DEBUG
            printf("Setting parent of %lld to %lld\n", check.first.id, current.id);
#endif
            //nbr.came_from = &current;
            nbr.g_score = tentative_g_score;
            nbr.f_score = tentative_g_score + H(nbr,goal);
            addNodeToSet(openSet,nbr);
#if DEBUG
            printf("Adding node= %lld to Open multiset with f_score %d \n", nbr.id,nbr.f_score);
#endif
        }
      }

#if DEBUG
    cout<<"------------------------------------------------------------------------------------"<<endl;
#endif
  }
  printf("Solution Not Found. Goal is not reachable from start\n");  
  return false;
}

void AStar::reconstructPath(int long long id,int steps){
    long long int came_from = came_from_map[id]; 
    if(came_from == -1){
        cout<<"Reached Destination"<<endl;
        cout<<"Took "<<steps<<" steps to complete"<<endl;
        cout<<"Expanded "<<closedSet.size()<<" nodes in the Graph"<<endl;
        return;
    }
    else{
        printNode(came_from);
        reconstructPath(came_from,steps+1);
        return;
    }
}
