#ifndef __NEURON_H__
#define __NEURON_H__
#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include "edge.h"

using namespace std;

typedef vector<float> Vec;

float dotProduct(Vec v1 , Vec v2);
bool operator==(Vec &v1 , Vec &v2);
void print(Vec &v1);
void add(Vec &destV , Vec W);
 
class Edge;

class Neuron{


    private:
        int id;
        bool outputNeuron;
        vector<Edge*> inputEdges;
        vector<Edge*> outputEdges;
        int noOfInputs; 
        Vec inputs;
        float output;
        float del;
        static int totalNeurons;
    public:
        Neuron(int noOfInputs);
	    vector<Edge*> getinputEdges();
        void collectInputs();  //and generate output
        void collectInputs(Vec in); // to be called for the outermost input layer
        float getOutput();  
        float getDel();
        void updateDel();
        void updateDel(Vec t);
        void update();

};


#endif
