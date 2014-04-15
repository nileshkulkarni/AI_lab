#include "neuron.h"

using namespace std;
int Neuron::totalNeurons =0;

Neuron::Neuron(int N){
    noOfInputs = N;    
    id = totalNeurons;
    totalNeurons++;
    output=0;
}

vector<Edge*> Neuron :: getInputEdges() {
	return inputEdges;
}
void Neuron::addInputEdge(Edge *e){
    inputEdges.push_back(e);
}
void Neuron::addOutputEdge(Edge *e){
   outputEdges.push_back(e); 

}
void Neuron ::print(){
    printf("\t\t(Neuron ID , del) %d %f \n" ,id , del);
    printf("\t\tOutput Weights ");
    for(int i =0;i<outputEdges.size();i++){
        printf("%d: %f ",i,outputEdges[i]->getWeight()); 
    }

    printf("\n\t\tInput Weights ");
    for(int i =0;i<inputEdges.size();i++){
        printf("%d: %f ",i,inputEdges[i]->getWeight()); 
    
    }
    
    printf("\n\t\t Output %f ", output);
    printf("\n");

}
int Neuron::getID(){
    return id;
}
void Neuron :: collectInputs() {
	float collectedOut=0;
	vector<Edge*> input = getInputEdges();
	for(int i=0; i<input.size(); i++) {
		Neuron* start = input[i]->getStart();
		float w = input[i]->getWeight();
		float out = start->getOutput();
		collectedOut+=w*out;
	}
	output = collectedOut;
}

float Neuron::getOutput(){
    return output;
}


void Neuron :: collectInputs(float in) {
	float collectedOut=in;
/*	
	vector<Edge*> input = getInputEdges();	
	for(int i=0; i<In.size(); i++) {
		float w = input[i]->getWeight();
		collectedOut+=w*In[i];
	}
*/ 
	output = collectedOut;
    printf("Neuron ID ** %d , %f \n", id, output);	
}

void Neuron :: updateDel(float t){
	
        
    del = (t - output) * output * (1 - output);
    
   printf("computing del : %d %f %f %f\n" , id , t , output , del); 
 
}


float Neuron:: getDel(){
    return del;

}

void Neuron :: updateDel(){
	del = 0;
	for(int i=0;i<outputEdges.size();i++){
		del +=	outputEdges[i]->getWeight() * (outputEdges[i]->getEnd())->getDel() * output * (1 - output);
        
        printf("computing del : %f %f %f %f \n" ,outputEdges[i]->getWeight()  , (outputEdges[i]->getEnd())->getDel() , output  , (1 - output)); 
        
	}
}

        
