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

vector< NodePtr > getNeighbours(NodePtr np){
    vector<int> v = np->data._state;
    printf("Getting Nbrs of ***  ");
    np->printData();
    int _0pos = findpos(v);
    vector< NodePtr > neighbors;
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
        d._state = left;
        NodePtr n = new Node(d);
        neighbors.push_back(n);
        n->printData();
    }
    if(_0pos!=0 && _0pos!=1 && _0pos!=2){
        top.assign(v.begin(),v.end());
        temp = top[_0pos-3];
        top[_0pos]=temp;
        top[_0pos-3]=0;
        Data d;
        d._state = top;
        NodePtr n = new Node(d);
        neighbors.push_back(n);
        n->printData();
    }
    if(_0pos!=2 && _0pos!=5 && _0pos!=8){
        right.assign(v.begin(),v.end());
        temp = right[_0pos+1];
        right[_0pos]=temp;
        right[_0pos+1]=0; 
        Data d;
        d._state = right;
        NodePtr n = new Node(d);
        neighbors.push_back(n);
        n->printData();
    }
    if(_0pos!=6 && _0pos!=7 && _0pos!=8){
        down.assign(v.begin(),v.end());
        temp = down[_0pos+3];
        down[_0pos]=temp;
        down[_0pos+3]=0;
        Data d;
        d._state = down;
        NodePtr n = new Node(d);
        neighbors.push_back(n);
        n->printData();
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
