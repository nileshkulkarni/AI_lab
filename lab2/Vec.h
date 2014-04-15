//#IFNDEF Vec



#include <iostream>
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
	
	
	void prettyPrint(){
		 for(int i=0;i<dimension;i++)
		  cout<<arr[i]<<" ";
		 cout<<endl; 
	}	
	void invertWeights(){
		 for(int i=0;i<dimension;i++)
		  arr[i] = -arr[i];
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
