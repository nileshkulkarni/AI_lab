#include "edge.h"
Edge::Edge(){
   srand(time(NULL));
   weight = (rand() % 1000 )/1000;
    
}

float Edge::getWeight(float w){
   return  weight ;

}
void  Edge::getStart(Neuron* s){
    start=s ;

}

void Edge::getEnd(Neuron* e){
    end =e ;
    
}

Neuron* Edge::getStart(){
    return start ;

}
Neuron* Edge::getEnd(){
    return end ;

}

void Edge::setWeight(){
    weight = w;

}
