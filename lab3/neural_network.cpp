#include "neural_network.h"

int Neuron::totalNeurons = 0;

NeuralNetwork::NeuralNetwork(){
}





void NeuralNetwork::_init(){
}



NeuralNetwork::NeuralNetwork(int nlayers){
    _init();
    layers.resize(nlayers);
} 

void NeuralNetwork::feedForward(Vec in){
    
    for(int i =0;i<layers.size();i++){
        if(i==0){
            layers[i].updateLayer(in);
        }
        else{
           layers[i].updateLayer(); 
        }
    }
}



Vec NeuralNetwork::getOutput(Vec in){
    feedForward(in); 
    int size = layers.size();  
    return layers[size-1].getOutput();
}


void NeuralNetwork :: backPropagate(){
	
	layers[noOfLayers-1].backPropagate(outputs);
	
	for(int i=noOfLayers-2 ; i>=0 ; i++){
		layers[i].backPropagate();
	}

	for(int i=noOfLayers-1; i>0 ; i++){
		layers[i].updateWeights();
	}
}	
