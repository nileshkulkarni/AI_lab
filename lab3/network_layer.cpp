#include "network_layer.h"



NetworkLayer ::  NetworkLayer(int nNeurons , int id){
			layerId = id;
			N = nNeurons;
			Neurons.resize(N);
}



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
