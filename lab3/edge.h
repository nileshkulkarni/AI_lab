#ifndef __EDGE_H__
#define __EDGE_H__

#include <stdio.h>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include<cstdlib>
#include "neuron.h"


extern float MOMENTUM_FACTOR;


class Neuron;
class Edge{
private: 
    Neuron* start;
    Neuron* end;
    
    float weight;
    float prevError;
public: 
    Edge();
    Neuron* getStart();
    Neuron* getEnd();
    void setStart(Neuron*);
    void setEnd(Neuron*);
    float getWeight();
    void setWeight(float w);		
    float getPrevError();
	void setPrevError(float x);


};

#endif
