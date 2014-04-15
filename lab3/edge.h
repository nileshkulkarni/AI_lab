#include <stdio.h>
#include "neuron.h"
class Edge{
private: 
    Neuron* start;
    Neuron* end;
    
    float weight;
public: 
    Edge():
    Neuron* getStart();
    Neuron* getEnd();
    void setStart(Neuron*);
    Neuron* setEnd(Neuron*);
    float getWeight();
    void setWeight(float w);		

};
