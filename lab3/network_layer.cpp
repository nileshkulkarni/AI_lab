#include "network_layer.h"



int NetworkLayer::totalLayers = 0;


NetworkLayer :: NetworkLayer (){
	layerId = totalLayers++;
			
} 


NetworkLayer ::  NetworkLayer(int nNeurons){
			layerId = totalLayers++;
			init(nNeurons);
}


	
void NetworkLayer :: init(int nNeurons){
			N = nNeurons;
			for(int i =0;i<nNeurons;i++){
                Neuron neuron(nNeurons);
                Neurons.push_back(neuron); 
            }
}

	



void NetworkLayer :: updateLayer() {
	for(int i=0; i<Neurons.size(); i++) {
		Neurons[i].collectInputs();
	}
}


Vec  NetworkLayer:: getOutput(){
    Vec output; 
    
    for(int i=0;i<Neurons.size();i++){
        output.push_back(Neurons[i].getOutput());       
    }
    return output;
}

void NetworkLayer :: updateLayer(Vec In) {
	
	for(int i=0;i<Neurons.size();i++ ){
		Neurons[i].collectInputs(In[i]);
	}
}

void NetworkLayer ::backPropagate(){
		for(int i=0;i<N;i++){
			Neurons[i].collectInputs();
			Neurons[i].updateDel();
		}	
}



void NetworkLayer ::backPropagate(Vec t){
		for(int i=0;i<N;i++){
			Neurons[i].collectInputs();
			Neurons[i].updateDel(t);
		}	
}

void NetworkLayer ::updateWeights(){   //of input edges
    for(int i=0;i<N;i++){
			for(int j=0;j<Neurons[i].inputEdges.size();j++)
			   (Neurons[i].inputEdges[j])->setWeight(Neurons[i].inputEdges[j]->getWeight() +  
			                                       (NETA *
			                                       Neurons[i].inputEdges[j]->getStart()->getDel() *
			                                       Neurons[i].getOutput()));	
		}	
}


void NetworkLayer::print(){
	
	for(int i=0;i<N;i++){
		Neurons[i].print();
		cout<<"   " 
	}

}
