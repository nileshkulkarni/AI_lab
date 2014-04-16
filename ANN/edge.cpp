#include "edge.h"


Edge::Edge(){
   weight = (float)(rand() % 1000 )/1000;
   prevError = 0;
   //cout<<"\n : "<<weight<<"\n";
}


float Edge::getPrevError(){
	return prevError;
}

void Edge::setPrevError(float x){
	prevError = x;
}





float Edge::getWeight(){
   return  weight ;

}
void  Edge::setStart(Neuron* s){
    start=s ;

}


void Edge::setEnd(Neuron* e){
    end =e ;
    
}

Neuron* Edge::getStart(){
    return start ;

}
Neuron* Edge::getEnd(){
    return end ;

}

void Edge::setWeight(float w){
    weight = w;

}
