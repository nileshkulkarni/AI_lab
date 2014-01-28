#include "neuron.h"
#include <iostream>
#include <stdio.h>
#include <vector>



#define NETA 0.5


class NetworkLayer{
    private:    
        vector<Neuron> Neurons;
        int N;  //Neurons
        int layerId;
        
   
    public:
    
        NetworkLayer(int nNeurons , int id);
        
	    void updateLayer(Vec In);	
		void backPropagate();
	    void updateLayer();	
	    Vec  getOutput();	
		void backPropagate(Vec t);
		void updateWeights();
};
