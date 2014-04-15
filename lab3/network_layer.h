#include "neuron.h"
#include <iostream>
#include <stdio.h>
#include <vector>

class NetworkLayer{
    private:    
        vector<Neuron> layer;
    public:
        feedForwardNeurons(NetworkLayer *prevLayer);
        

};
