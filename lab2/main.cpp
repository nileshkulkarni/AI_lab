#include <iostream>
#include <map>
#include "Perceptron.h"
using namespace std;


int main(){
  	
	 int dim , nVec;

     dim = 8;
     nVec = (1<<7);
    	 
	 Vec* vectors = new Vec[nVec];
	 
	 
	// set<Vec> vectorSet;
	 
	
	for(int nv=0;nv<10;nv++){	 
	 
		for(int i=0;i<nVec;i++){
			vectors[i].initialize(dim);
			vectors[i].input();
		}
    
		Perceptron P(dim);
		P.train(vectors , nVec , 1000000); 
		P.printWeights();
	}    
   return 0;
}
