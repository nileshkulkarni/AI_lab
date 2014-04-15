#include "Vec.h"

class Perceptron{
	
	int dim;
	Vec weights;
	
public:	
	
	Perceptron(int ext_dim){
		
		dim = ext_dim;
		weights.initialize(dim); 
		weights.set(0);	
	}
	
	
	void initialize(int init){
		weights.set(init);
	}
	
	
	void train(Vec *vectors , int nVec , int steps){
		
		int i=0;
		while(i<nVec && steps-->0){
		 
		// cout<<i<<" "<<endl;
		 for(i=0;i<nVec;i++){
			 if(dotProduct(weights , vectors[i]) <= 0){
				 weights.add(vectors[i]);
				 break;
			 }
		 }
		}
	}
		
	void printWeights()	{	
		weights.print();
		cout<<endl;
	}	
};	
	
	
	

