#include <iostream>
#include <map>
using namespace std;


struct Vec{
	int dimension;
	int *arr;
		 
	void initialize(int dim){
		 dimension = dim;
		 arr = new int[dim];
	} 
	 
	void input(){
		for(int i=0;i<dimension;i++)
		 cin>>arr[i];
	}
	
	void set(int setval){
		for(int i=0;i<dimension;i++)
		 arr[i] = setval;
	}
	 
	 void add(Vec v1){
		 for(int i=0;i<dimension;i++)
		  arr[i] += v1.arr[i];
	}	 
		 
	 void print(){
		 cout<<"(";
		 for(int i=0;i<dimension;i++)
		  cout<<arr[i]<<" ";
		  cout<<")";
	}
	
		  
};


int dotProduct(Vec v1 , Vec v2){
	int ret=0;
	for(int i=0;i<v1.dimension;i++)
	  ret+= v1.arr[i] * v2.arr[i];
	return ret;  	
}	 


bool operator==(Vec &v1 , Vec &v2){
	
	bool ret = true;
	for(int i=0;i<v1.dimension;i++)
	  ret = ret && (v1.arr[i] == v2.arr[i]);
	 return ret; 
	
}

	

int main(){
  	
	 int dim , nVec;
	 cin>>dim >> nVec;
	 
	 Vec* vectors = new Vec[nVec];
	 
	 
	 set<Vec> vectorSet;
	 
	 for(int i=0;i<nVec;i++){
	   vectors[i].initialize(dim);
	   vectors[i].input();
    }    
	    
	 Vec W;
	 W.initialize(dim); 
	 W.set(0);
	 
	 int i=0;
	 
	 int steps;
	 cout<<"Enter the no of steps that you want the program to run for :";
	 cin>>steps;
	 
	 while(i<nVec && steps-->0){
		 
		 
		 
		 W.print();
		 cout<<endl;
		 for(i=0;i<nVec;i++){
			 if(dotProduct(W , vectors[i]) <= 0){
				 W.add(vectors[i]);
				 break;
			 }
		 }
	}
	 
   W.print();
   return 0;
}
