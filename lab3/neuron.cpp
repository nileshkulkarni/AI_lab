#include "neuron.h"

using namespace std;
int Neuron::totalNeurons =0;









float dotProduct(Vec v1 , Vec v2){
    float ret=0;
    for(int i=0;i<v1.size();i++)
      ret += v1[i]*v2[i]; 
    return ret;
}


bool operator==(Vec &v1 , Vec &v2){
    bool ret = true;
    for(int i=0;i<v1.size();i++)
      ret = ret && (v1[i]==v2[i]); 
    return ret;
}





void add(Vec &destV , Vec W){
    for(int i=0;i<W.size();i++)
      destV[i] += W[i];
}

void sub(Vec &destV , Vec W){
    for(int i=0;i<W.size();i++)
      destV[i] -= W[i];

    
}



float mod(Vec v){
    float ret=0;
    for(int i=0;i<v.size();i++)
        ret += v[i]*v[i];
}



























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
    printf("\t\tNeuron ID  %d \n" ,id   );
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
   // printf("Neuron ID ** %d , %f \n", id, output);	
}

void Neuron :: updateDel(float t){
	
    del = (t - output) * output * (1 - output);
    
   //printf("computing del : %d %f %f %f\n" , id , t , output , del); 
 
}


float Neuron:: getDel(){
    return del;

}

void Neuron :: updateDel(){
	del = 0;
	for(int i=0;i<outputEdges.size();i++){
		del +=	outputEdges[i]->getWeight() * (outputEdges[i]->getEnd())->getDel() * output * (1 - output);
        
        //printf("computing del : %f %f %f %f \n" ,outputEdges[i]->getWeight()  , (outputEdges[i]->getEnd())->getDel() , output  , (1 - output)); 
        
	}
}

        
