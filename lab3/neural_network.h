#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include "network_layer.h"

using namespace std;


class NeuralNetwork{
    private:    
        vector<NetworkLayer>layers;
        int noOfLayers; 
        void _init();
        Vec inputs;
        Vec outputs;
        
    public:
        void NeuralNetwork();
        void addTrainData(Vec input, Vec outputs); 
        void addHiddenLayer(); 
        void addAllTrainData(vector<Vec> input,vector<Vec> output); 
        Vec getOuput(Vec input);
        void backPropagate(int Layer);
        void feedForward();      
}
