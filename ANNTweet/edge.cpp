#include "edge.h"


Edge::Edge(){
   weight = (double)(rand() % 1000)/500 - 1.0;
   prevError = 0;
   //cout<<"\n : "<<weight<<"\n";
}


double Edge::getPrevError(){
	return prevError;
}

void Edge::setPrevError(double x){
	prevError = x;
}





double Edge::getWeight(){
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

void Edge::setWeight(double w){
    weight = w;

}
