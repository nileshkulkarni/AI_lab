#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
using namespace std;
class Neuron{


    private:
        int id;
        vector<float> weights;
        vector<neuron*> inputNeurons;
        int noOfInputs; 
        

    public:
        Neuron(int noOfInputs);
        void setInputs(float* in);
        float getOutput();  

};
