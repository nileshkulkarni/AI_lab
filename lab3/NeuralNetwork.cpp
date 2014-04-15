
#include "NeuralNetwork.h"



NeuralNetwork :: backPropagate(){
	
	for(int i=noOfLayers-1 ; i>=0 ; i++){
		layers[i].backPropagate();
	}
}
