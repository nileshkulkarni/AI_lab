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
        
    public:
        void NeuralNetwork();
        void addTrainData(vector<float> input, vector<float> outputs); 
        void addHiddenLayer(); 
        void addAllTrainData(vector< vector <float>> input,vector< vector<float> > output); 
        vector<float> getOuput(vector<float> input);    
}
