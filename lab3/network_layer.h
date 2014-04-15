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
<<<<<<< HEAD
        
	void backPropagate();
	void updateLayer();
	void updateLayer(Vec In);	
=======
		void backPropagate();
	    void updateLayer();	
	    Vec  getOutput();	
>>>>>>> 492b4b39bbe400aa222723ea7b496125822f8763
        feedForwardNeurons(NetworkLayer *prevLayer);
		void backPropagate(Vec t);
		void updateWeights();
};
