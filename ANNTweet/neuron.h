#ifndef __NEURON_H__
#define __NEURON_H__
#include <iostream>
#include <stdio.h>
#include <list>
#include <vector>
#include <cmath>
#include "edge.h"

using namespace std;

typedef vector<double> Vec;

double dotProduct(Vec v1 , Vec v2);
bool operator==(Vec &v1 , Vec &v2);
void printVec(Vec &v1);
void add(Vec &destV , Vec W);
void sub(Vec &destV , Vec W);
double mod(Vec v);
double mod2(Vec v);
bool equal(Vec v1 , Vec v2);


 
class Edge;

class Neuron{


    private:
        int id;
        bool outputNeuron;
        int noOfInputs; 
        Vec inputs;
        double output;
        double del;
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
        void collectInputs(double in); // to be called for the outermost input layer
        double getOutput();  
        double getDel();
        void addInputEdge(Edge *e);
        void addOutputEdge(Edge *e);
        void updateDel();
        void updateDel(double t);
        void update();
        int getID(); 

};


#endif
