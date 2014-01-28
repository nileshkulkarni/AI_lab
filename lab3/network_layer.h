#ifndef __NETWORK_LAYER_H__
#define __NETWORK_LAYER_H__
#include <iostream>
#include <stdio.h>
#include <vector>

#include "neuron.h"
#define NEURON_INPUTS 5
#define NETA 0.5


class NetworkLayer{
    private:    
        vector<Neuron> Neurons;
        int N;  //Neurons
        int layerId;
        
        static int totalLayers;
        
   
    public:
    
    
        NetworkLayer();
        NetworkLayer(int nNeurons);
        void init(int nNeurons);
        
	    void updateLayer(Vec In);	
		void backPropagate();
	    void updateLayer();	
	    Vec  getOutput();	
		void backPropagate(Vec t);
		
		
		void updateWeights();
		void setLayerId(int id);
		
		
		void print();
};
#endif
