#include "NeuralNetwork.h"


void NeuralNetwork::_init(){
            



}

NeuralNetwork::NeuralNetwork(int n){
    _init();


} 



NeuralNetwork :: backPropagate(){
	
	for(int i=noOfLayers-1 ; i>=0 ; i++){
		layers[i].backPropagate();
	}
}
