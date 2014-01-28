#include "edge.h"
Edge::Edge(){
   srand(time(NULL));
   weight = (rand() % 1000 )/1000;
    
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
<<<<<<< HEAD
void Edge::setWeight(float w){
=======

void Edge::setWeight(){
>>>>>>> 492b4b39bbe400aa222723ea7b496125822f8763
    weight = w;

}
