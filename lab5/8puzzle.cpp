#include "8puzzle.h"


using namespace std;
int findpos(vector<int>& vec){
    for(int i=0;i<vec.size();i++){
        if(vec[i]==0){
            return i;
        }
    }
    return -1;
}
long long int getHash(vector<int> _state){
  long long int id =0;
    for(int i =0;i<9;i++){
        id= id*10 + _state[i];
    }
    return id;

}

vector< Node > getNeighbours(Node np){
    vector<int> v = np.data._state;
#if DEBUG
    printf("Getting Nbrs of ***  ");
    np.printData();
#endif
    int _0pos = findpos(v);
    vector< Node > neighbors;
    vector<int> left;
    vector<int> right;
    vector<int> top;
    vector<int> down;
    int temp;
    if(_0pos!=0 && _0pos!=3 && _0pos!=6){
        left.assign(v.begin(),v.end());
        temp = left[_0pos-1];
        left[_0pos]=temp;
        left[_0pos-1]=0;
        Data d;
        d._state.assign(left.begin(),left.end());
        Node n(d);
        neighbors.push_back(n);
#if DEBUG
        n.printData();
#endif
    }
    if(_0pos!=0 && _0pos!=1 && _0pos!=2){
        top.assign(v.begin(),v.end());
        temp = top[_0pos-3];
        top[_0pos]=temp;
        top[_0pos-3]=0;
        Data d;
        d._state.assign(top.begin(),top.end());
        Node n(d);
        neighbors.push_back(n);
#if DEBUG
        n.printData();
#endif

    }
    if(_0pos!=2 && _0pos!=5 && _0pos!=8){
        right.assign(v.begin(),v.end());
        temp = right[_0pos+1];
        right[_0pos]=temp;
        right[_0pos+1]=0; 
        Data d;
        d._state.assign(right.begin(),right.end());
        Node n(d);
        neighbors.push_back(n);
#if DEBUG
        n.printData();
#endif

    }
    if(_0pos!=6 && _0pos!=7 && _0pos!=8){
        down.assign(v.begin(),v.end());
        temp = down[_0pos+3];
        down[_0pos]=temp;
        down[_0pos+3]=0;
        Data d;
        d._state.assign(down.begin(),down.end());
        Node n(d);
        neighbors.push_back(n);
#if DEBUG
        n.printData();
#endif

    }

    return neighbors;
}

void printstate(vector<int>& v){
    for(int i=0;i<9;i++){
        if(i%3==2){
            cout<<" "<<v[i]<<endl;
        }
        else{
            cout<<" "<<v[i];
        }
    }
    return;
}
void printNode(long long int id){
    std::vector<int> v;
    long long int a;
    for(int i=1;i<10;i++){
        a=pow(10,9-i);
        v.push_back(id/a);
        id=id%a;    
    }
    printstate(v);
    cout<<"------------------\n";
    return;
}

