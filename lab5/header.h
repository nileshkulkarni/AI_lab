#ifndef HEADER_H
#define HEADER_H
#include <vector>
using namespace std;

class Node;
struct Data{
   vector<int> _state;
   bool operator == (Data d){
       bool flag;
       for(int i =0;i<_state.size();i++){
            if(_state[i] = d._state[i]){
                continue;
            }
            else{
                return false;
            }
       }
       return true;
   }
} ;

vector< Node* > getNeighbours(Node* n);
#endif
