#include "neuron.h"

using namespace std;

vector<Edge*> Neuron :: getinputEdges() {
	return inputEdges;
}

void Neuron :: collectInputs() {
	float collectedOut=0;
	vector<Edge*> input = getinputEdges();
	for(int i=0; i<input.size(); i++) {
		Neuron* start = input[i]->getStart();
		float w = input[i]->getWeight();
		float out = start->getOutput();
		collectedOut+=w*out;
	}
	output = collectedOut;
}

void Neuron :: collectInputs(Vec In) {
	float collectedOut=0;
	vector<Edge*> input = getinputEdges();
	for(int i=0; i<In.size(); i++) {
		float w = input[i]->getWeight();
		collectedOut+=w*In[i];
	}
	output = collectedOut;	
}
