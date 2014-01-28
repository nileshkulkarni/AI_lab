#ifndef __EDGE_H__
#define __EDGE_H__

#include <stdio.h>
#include "neuron.h"
#include <ctime>
#include <stdio.h>
#include <iostream>
#include<cstdlib>

class Neuron;
class Edge{
private: 
    Neuron* start;
    Neuron* end;
    
    float weight;
public: 
    Edge();
    Neuron* getStart();
    Neuron* getEnd();
    void setStart(Neuron*);
    void setEnd(Neuron*);
    float getWeight();
    void setWeight(float w);		

};

#endif
