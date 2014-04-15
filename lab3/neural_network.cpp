#include "neural_network.h"


NeuralNetwork::NeuralNetwork(){
}





void NeuralNetwork::_init(){
}


NeuralNetwork::NeuralNetwork(int nlayers){
    _init();
    nHiddenLayers = 0;
    noOfLayers = nlayers;
    cout<<"size is layers : "<<nlayers<<endl;
    layers.resize(nlayers);
    cout<<"size is layers : "<<layers.size()<<endl;
}


NeuralNetwork::NeuralNetwork(int nLayers,int noOfNeurons){
    _init();
    noOfLayers = nLayers;
    nHiddenLayers = 0;
    for(int i =0;i<nLayers;i++){
        NetworkLayer lay(noOfNeurons);        
        layers.push_back(lay);
    }
} 


void NeuralNetwork::addInputLayer(int nNeurons){
	layers[0].init(nNeurons);
}


void NeuralNetwork::addHiddenLayer(int nNeurons){
	assert(nHiddenLayers < noOfLayers-1);
	layers[++nHiddenLayers].init(nNeurons);
}


void NeuralNetwork::addOutputLayer(int nNeurons){
	
	cout<<"size of layers is : "<<layers.size()<<" : "<<noOfLayers - 1<<endl;
	layers[noOfLayers - 1].init(nNeurons);
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
	
	for(int i=noOfLayers-2 ; i>0 ; i++){
		layers[i].backPropagate();
	}

	for(int i=noOfLayers-1; i>0 ; i++){
		layers[i].updateWeights();
	}
}	


void NeuralNetwork::addTrainData(Vec in, Vec out){
	
	this->feedForward(in);
	Vec o = layers[noOfLayers-1].getOutput(); 
    cout<< o[0] << endl;
	
}


void print(){
	
	for(int i=noOfLayers-1 ; i>=0 ; i++){
		layers[i].print();
		cout<<endl<<endl<<endl<<endl<<endl;
	}
	
}
