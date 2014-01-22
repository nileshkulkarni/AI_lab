#include <iostream>
#include <map>
#include "Perceptron.h"
using namespace std;


int main(){
  	
	 int dim , nVec;
	 cin>>dim >> nVec;
	 
	 Vec* vectors = new Vec[nVec];
	 
	 
	// set<Vec> vectorSet;
	 
	
	 
	 
	 for(int i=0;i<nVec;i++){
	   vectors[i].initialize(dim);
	   vectors[i].input();
    }
    
    
      int steps;
	 cout<<"Enter the no of steps that you want the program to run for :";
	 cin>>steps;
    
	    
	 Perceptron P(dim);
	 P.train(vectors , nVec , steps); 
	 
     P.printWeights();
   return 0;
}
