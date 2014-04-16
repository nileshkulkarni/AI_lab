#ifndef __EDGE_H__
#define __EDGE_H__

#include <stdio.h>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include<cstdlib>
#include "neuron.h"


extern double MOMENTUM_FACTOR;


class Neuron;
class Edge{
private: 
    Neuron* start;
    Neuron* end;
  
    double weight;
    double prevError;
public: 
    Edge();
    Neuron* getStart();
    Neuron* getEnd();
    void setStart(Neuron*);
    void setEnd(Neuron*);
    double getWeight();
    void setWeight(double w);		
    double getPrevError();
	void setPrevError(double x);


};

#endif
