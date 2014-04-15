
#include "NeuralNetwork.h"



NeuralNetwork :: backPropagate(){
	
	
	layers[noOfLayers-1].backPropagate(outputs);
	
	for(int i=noOfLayers-2 ; i>=0 ; i++){
		layers[i].backPropagate();
	}
}
