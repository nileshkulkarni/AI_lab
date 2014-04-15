#ifndef __EDGE_H__
#define __EDGE_H__

#include <stdio.h>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include<cstdlib>
<<<<<<< HEAD

=======
#include "neuron.h"
>>>>>>> dd79049bc655091074cc73c0e54ba38969332c2b
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
