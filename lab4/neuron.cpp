#include "neuron.h"

using namespace std;
int Neuron::totalNeurons =0;


Neuron::Neuron(int N){
    noOfInputs = N+1;    
    id = totalNeurons;
    totalNeurons++;
    output=0;
    Edge *E = new Edge();
    E->setEnd(this);  
    E->setStart(NULL);
    inputEdges.push_back(E);
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
void Neuron:: setWeightsZero(){

    for(int i =0;i<inputEdges.size();i++){
        inputEdges[i]->setWeight(0); 
    }
}
void Neuron ::print(){
    printf("\t\tNeuron ID , del (%d ,  %f) \n" ,id , del  );
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
	double collectedOut=0;
	vector<Edge*> input = getInputEdges();
	for(int i=0; i<input.size(); i++) {
        Neuron* start = input[i]->getStart();
		if(start == NULL){
            double w = input[i]->getWeight();
            collectedOut+=-1*w;
        }
        else{
            double w = input[i]->getWeight();
            double out = start->getOutput();
            collectedOut+=w*out;
        }
	}

	output = collectedOut;
    updateOutput();
}

double Neuron::getOutput(){
    return output;
}

void Neuron :: collectInputs(double in) {
	double collectedOut=in;
	output = collectedOut;
}

void Neuron :: updateDel(double t){
	
    del = (t - output) * output * (1 - output);
   //printf("computing del : %d %f %f %f\n" , id , t , output , del); 
}

double Neuron:: getDel(){
    return del;

}

void Neuron::updateOutput(){
    output = double(1)/(double)(1 + exp(-output));
}

void Neuron :: updateDel(){
	del = 0;
	for(int i=0;i<outputEdges.size();i++){
		del +=	outputEdges[i]->getWeight() * (outputEdges[i]->getEnd())->getDel() * output * (1 - output);
        //printf("computing del : %f %f %f %f \n" ,outputEdges[i]->getWeight()  , (outputEdges[i]->getEnd())->getDel() , output  , (1 - output)); 
	}
}


double dotProduct(Vec v1 , Vec v2){
    double ret=0;
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

double mod(Vec v){
    double ret=0;
    for(int i=0;i<v.size();i++)
        ret += v[i]*v[i];
//    return ret;    
}


double mod2(Vec v){
    double ret=0;
    for(int i=0;i<v.size();i++)
        ret += v[i]*v[i];
    return ret;    
}



void printVec(Vec &v){
    cout<<"(";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<",";
    cout<<")";    
}



bool equal(Vec v1 , Vec v2){
	
	bool ret = true;
    for(int i=0;i<v1.size();i++){
      double t = v1[i] - v2[i];
      t = (t>0)?t:-t;
      ret = ret && (t < 0.2);
  } 
    return ret;
}


