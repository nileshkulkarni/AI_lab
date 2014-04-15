#include "NeuralNetwork.h"


void NeuralNetwork::_init(){
            



}

NeuralNetwork::NeuralNetwork(int layers,int noOfNeurons){
    _init();
    
    for(int i =0;i<n;i++){
        NetworkLayer lay(noOfNeurons);        
        layers.push(lay);
    }


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

NeuralNetwork :: backPropagate(){
	
	for(int i=noOfLayers-1 ; i>=0 ; i++){
		layers[i].backPropagate();
	}
}
