#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include <assert.h>


#include "neuron.h"
#include "network_layer.h"

extern double ERROR_THRESHOLD;
//#define ERROR_THRESHOLD 1
#define PRINTRATE 5
#define MAXSTEPS 200

using namespace std;


class NeuralNetwork{
    private:    
        int noOfLayers; 
        void _init();
        Vec inputs;
        Vec outputs;
        int nHiddenLayers;
		
    public:
        
        
        
        vector<NetworkLayer>layers;
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
        void putEdges(int from , int to);
        void generateEdges();
        
       
        
};
