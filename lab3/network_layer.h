#ifndef __NETWORK_LAYER_H__
#define __NETWORK_LAYER_H__
#include <iostream>
#include <stdio.h>
#include <vector>

#include "neuron.h"
//#define NEURON_INPUTS 5
//#define NETA 0.2

//float NEURON_INPUTS= 5;
//float NETA= 0.2;

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
