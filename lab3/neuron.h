#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>



typedef vector<float> Vec


using namespace std;


float dotProduct(Vec v1 , Vec v2);
bool operator==(Vec &v1 , Vec &v2);
void print(Vec &v1);
void add(Vec &destV , Vec W);
 
 
class Neuron{


    private:
        int id;
        bool outputNeuron;
        Vec weights;
        vector<Edge*> inputEdges;
        vector<Edge*> outputEdges;
        int noOfInputs; 
        Vec inputs;
        float output;
        float del;

    public:
        Neuron(int noOfInputs);
        void setInputs(Vec in);
        void collectInputs();  //and generate output
        void collectInputs(Vec in);
        float getOutput();  
        float getDel();
        void updateDel();
        void updateDel(Vec t);

};



void Neuron :: updateDel(Vec t){
	del = (t[id] - output) * output * (1 - output);
}


void Neuron :: updateDel(){
	del = 0;
	for(int i=0;i<outputEdges.size();i++){
		del +=	outputEdges[i] * (outputEdges[i].getEnd())->getDel() * output * (1 - output);
	}
}



