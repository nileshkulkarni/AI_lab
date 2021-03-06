#ifndef __NETWORK_LAYER_H__
#define __NETWORK_LAYER_H__
#include <iostream>
#include <stdio.h>
#include <vector>

#include "neuron.h"

class NetworkLayer{
    private:    
        vector<Neuron> Neurons;
        int N;  //Neurons
        static int totalLayers;
        
   
    public:
        int layerId;
    
    
    
        NetworkLayer();
        NetworkLayer(int nNeurons);
        void init(int nNeurons);
        void initInput(int nNeurons);
        
	    void updateLayer(Vec In);	
		void backPropagate();
	    void updateLayer();	
	    Vec  getOutput();	
		void backPropagate(Vec t);
	    vector<Neuron>* getAllNeuronsPtr();	
		
		void updateWeights();
		void setLayerId(int id);
		
		void print();
        
        
};
#endif
