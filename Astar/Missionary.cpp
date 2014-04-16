#include "Missionary.h"


using namespace std;

int findpos(vector<int>& vec){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==0){
            return i;
        }
    }
    return -1;
}
bool checkValid(vector<int> v){
    if(v[0]>0 && v[2] > 0){
      return v[0]>=v[1] && v[2]>=v[3];
    }
    else if(v[0]==0){
      return v[2]>=v[3];
    }
    else if(v[2]==0) {
      return v[0]>=v[1];
    }
    
}
vector< Node > getNeighbours(Node np){
    vector<int> v = np.data._state;
    vector< Node > neighbors;
    
    int Boat = v[4];  
    if(Boat){
       if(v[2]>0){
           vector<int> v1 = v;
           v1[2] = v1[2]-1;
           v1[0] = v1[0] +1;
           v1[4] =0;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
           }

       }
       if(v[3]>0){
           vector<int> v1 = v;
           v1[3] = v1[3]-1;
           v1[1] = v1[1] +1;
           v1[4] =0;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
           }
       }
       if(v[2]>1){
           vector<int> v1 = v;
           v1[2] = v1[2]-2;
           v1[0] = v1[0] +2;
           v1[4] =0;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
           }
       }
       if(v[3]>1){
           vector<int> v1 = v;
           v1[3] = v1[3]-2;
           v1[1] = v1[1] +2;
           v1[4] =0;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
           }
       }
       if(v[2]>0 && v[3]>0){
           vector<int> v1 = v;
           v1[2] = v1[2]-1;
           v1[0] = v1[0] +1;
           v1[3] = v1[3]-1;
           v1[1] = v1[1] +1;
           v1[4] =0;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
           }
       }
       return neighbors;
    }
    else{
       if(v[0]>0){
           vector<int> v1 = v;
           v1[2] = v1[2]+1;
           v1[0] = v1[0] -1;
           v1[4] =1;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
               
           }
       }
       if(v[1]>0){
           vector<int> v1 = v;
           v1[3] = v1[3]+1;
           v1[1] = v1[1] -1;
           v1[4] =1;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
               
           }
       }
       if(v[0]>1){
           vector<int> v1 = v;
           v1[2] = v1[2]+2;
           v1[0] = v1[0] -2;
           v1[4] =1;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
               
           }
       }
       if(v[1]>1){
           vector<int> v1 = v;
           v1[3] = v1[3]+2;
           v1[1] = v1[1] -2;
           v1[4] =1;
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
               
           }
       }
       if(v[2]>0 && v[3]>0){
           vector<int> v1 = v;
           v1[2] = v1[2]+1;
           v1[0] = v1[0] -1;
           
           v1[3] = v1[3]+1;
           v1[1] = v1[1] -1;
           v1[4] =1;
           
           if(checkValid(v1)){
               Data d;
               d._state.assign(v1.begin(),v1.end());
               Node n(d);
               neighbors.push_back(n);
               
           }
       }

       return neighbors;
    } 
}

void printstate(vector<int>& v){
    cout<<"Left Bank:"<<endl;
    cout<<"\tMissionaries: "<<v[0]<<" , "<<"Cannibals: "<<v[1]<<endl;
    if(v[4]==0){
        cout<<"\tBoat is on left bank"<<endl;
    }
    cout<<"Right Bank:"<<endl;
    cout<<"\tMissionaries: "<<v[2]<<" , "<<"Cannibals: "<<v[3]<<endl;
    if(v[4]==1){
        cout<<"\tBoat is on right bank"<<endl;
    }
    return;
}
void printNode(long long int id){
    std::vector<int> v;
    long long int a;
    for(int i=1;i<6;i++){
        a=pow(10,5-i);
        v.push_back(id/a);
        id=id%a;    
    }
    printstate(v);
    cout<<"-----------------------------------\n";
    return;
}


