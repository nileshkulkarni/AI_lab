#include "neuron.h"
#include <iostream>
#include <stdio.h>
#include <vector>

class NetworkLayer{
    private:    
        vector<Neuron> Neurons;
        int N;  //Neurons
        int layerId;
        
   
    public:
    
        NetworkLayer(int nNeurons , int id);
        
		void backPropagate();
		void backPropagate(Vec t);
		
        feedForwardNeurons(NetworkLayer *prevLayer);
};


NetworkLayer :: void backPropagate(){
	
		for(int i=0;i<N;i++){
			Neurons[i].collectInputs();
			Neurons[i].updateDel();
		}	
}



NetworkLayer :: void backPropagate(Vec t){
	
		for(int i=0;i<N;i++){
			Neurons[i].collectInputs();
			Neurons[i].updateDel(t);
		}	
}






