#ifndef HEADER_H
#define HEADER_H
#include <vector>
#define DEBUG 1
using namespace std;

class Node;

struct Data{
   vector<int> _state;
   int _size;
   inline bool operator== (const Data &d) const{
       
       for(int i =0;i<_state.size();i++){
            if(_state[i] == d._state[i]){
                continue;
            }
            else{
                return false;
            }
       }
       return true;
   }
   
   void print(){
       for(int i=0;i<9;i++){
        if(i%3==2){
            cout<<" "<<_state[i]<<endl;
        }
        else{
            cout<<" "<<_state[i];
        }
    }
    return;
   }

   //this works now
   Data& operator=(const Data &d){
      _state.clear();
      for(int i=0;i<d._state.size();i++){
        _state[i]=(d._state)[i];
      }
      return *this;
    } 

    void assign(Data d){
      for(int i=0;i<d._state.size();i++){
          _state.push_back(d._state[i]);
      }
      return;
   }

   void vec_assign(std::vector<int> v){
      for(int i=0;i< v.size();i++){
          _state.push_back(v[i]);
      }
      return;
   }
   long long int getHash(){
      long long int id =0;
        for(int i =0;i<_state.size();i++){
            id= id*10 + _state[i];
        }
        return id;

    }


} ;

vector< Node > getNeighbours(Node n);
#endif
