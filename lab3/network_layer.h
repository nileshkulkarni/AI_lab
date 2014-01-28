#include "neuron.h"
#include <iostream>
#include <stdio.h>
#include <vector>

class NetworkLayer{
    private:    
        vector<Neuron> Neurons;
        int N;  //Neurons
        int layerId;
        
   
    public:
    
        NetworkLayer(int nNeurons , int id);
        
	void backPropagate();
	void updateLayer();
	void updateLayer(Vec In);	
        feedForwardNeurons(NetworkLayer *prevLayer);
};
