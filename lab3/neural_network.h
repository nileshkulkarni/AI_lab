#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include <assert.h>



#include "network_layer.h"




using namespace std;


class NeuralNetwork{
    private:    
        vector<NetworkLayer>layers;
        int noOfLayers; 
        void _init();
        Vec inputs;
        Vec outputs;
        int nHiddenLayers;
        
    public:
        NeuralNetwork();
        NeuralNetwork(int nlayers);
        NeuralNetwork(int layers,int noOfNeurons);
        
        
        void addInputLayer(int nNeurons);
        void addHiddenLayer(int nNeurons); 
        void addOutputLayer(int nNeurons); 
        
        
        
        void addTrainData(Vec input, Vec outputs); 
        void addAllTrainData(vector<Vec> input,vector<Vec> output); 
        
        
        
        
        Vec getOutput(Vec in);
        void backPropagate();
        
        void feedForward(Vec in);     
        void feedForward(); 
        
        void print(); 
};
