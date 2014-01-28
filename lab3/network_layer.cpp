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


NetworkLayer :: void updateWeights(){
	
	for(int i=0;i<N;i++){
			for(int j=0;j<Neurons[i].outputEdges.size();i++)
			   Neurons[i].outputEdges[j].setWeight(Neurons[i].outputEdges[j].getWeight() +  
			                                       (NETA *
			                                       Neurons[i].getDel() *
			                                       Neurons[i].outputEdges[j].getEnd().getOutput()));	
		}	
	
}
