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


NetworkLayer :: void updateWeights(){   //of input edges
	
	for(int i=0;i<N;i++){
			for(int j=0;j<Neurons[i].inputEdges.size();i++)
			   Neurons[i].inputEdges[j].setWeight(Neurons[i].inputEdges[j].getWeight() +  
			                                       (NETA *
			                                       Neurons[i].inputEdges[j].getStart().getDel() *
			                                       Neurons[i].getOutput()));	
		}	
	
}
