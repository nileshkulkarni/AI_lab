#include <stdio.h>
#include "neuron.h"
class Edge{
private: 
    Neuron* start;
    Neuron* end;
    
    float weight;
public: 
    Edge():
    float getDel(){
		return end.getDel();
	}
    Neuron* getStart();
    Neuron* getEnd();
    void setStart(Neuron*);
    Neuron* setEnd(Neuron*);

};