#include "neuron.h"

using namespace std;
int Neuron::totalNeurons =0;



Neuron::Neuron(int N){
    noOfInputs = N;    
    id = totalNeurons;
    totalNeurons++;
    
}

vector<Edge*> Neuron :: getInputEdges() {
	return inputEdges;
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
void Neuron :: collectInputs(Vec In) {
	float collectedOut=0;
	vector<Edge*> input = getInputEdges();
	for(int i=0; i<In.size(); i++) {
		float w = input[i]->getWeight();
		collectedOut+=w*In[i];
	}
	output = collectedOut;	
}

void Neuron :: updateDel(Vec t){
	del = (t[id] - output) * output * (1 - output);
}
float Neuron:: getDel(){
    return del;

}

void Neuron :: updateDel(){
	del = 0;
	for(int i=0;i<outputEdges.size();i++){
		del +=	outputEdges[i]->getWeight() * (outputEdges[i]->getEnd())->getDel() * output * (1 - output);
	}
}

        
