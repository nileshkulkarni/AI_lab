#ifndef __NEURON_H__
#define __NEURON_H__
#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <cmath>
#include "edge.h"

using namespace std;

typedef vector<float> Vec;

float dotProduct(Vec v1 , Vec v2);
bool operator==(Vec &v1 , Vec &v2);
void print(Vec &v1);
void add(Vec &destV , Vec W);
void sub(Vec &destV , Vec W);
float mod(Vec v);


 
class Edge;

class Neuron{


    private:
        int id;
        bool outputNeuron;
        int noOfInputs; 
        Vec inputs;
        float output;
        float del;
    public:
        
        vector<Edge*> inputEdges;
        vector<Edge*> outputEdges;
        
        static int totalNeurons;
        void print();
        Neuron(int noOfInputs);
	    vector<Edge*> getInputEdges();
        void setWeightsZero();
        void collectInputs();//and generate output
        void updateOutput();
        void collectInputs(float in); // to be called for the outermost input layer
        float getOutput();  
        float getDel();
        void addInputEdge(Edge *e);
        void addOutputEdge(Edge *e);
        void updateDel();
        void updateDel(float t);
        void update();
        int getID(); 

};


#endif
