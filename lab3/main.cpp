#include "neural_network.h"
#include <vector>


float NETA;

void  genTT(string op	,vector<Vec> &reti , vector<Vec> &reto);
void getTruthTableLsd(int n, vector< Vec > &input, vector< Vec > &output);
void printTT(vector <Vec> , vector <Vec>);

using namespace std;
int main(){
  
    NETA =0.2;
    printf("Enter Learning rate \n");
    scanf("%f",&NETA);
    NeuralNetwork nn(3,1);
    
    nn.addInputLayer(2);
    //nn.addHiddenLayer(7);
    nn.addHiddenLayer(2);
    nn.addOutputLayer(1);
    
    nn.generateEdges();
    vector< Vec> ins;
	vector< Vec > outs;
    genTT("XOR",ins,outs);
    //getTruthTableLsd(1,ins,outs);
    //printTT(ins,outs);
    nn.addAllTrainData(ins, outs);
	
    Vec in2;
    in2.resize(2);
    while(1){
        printf("Enter inputs \n");
        scanf("%f %f",&in2[0],&in2[1]);
    /*    in2.push_back(1);
        in2.push_back(1);
     in2.push_back(0);
    in2.push_back(1);
    in2.push_back(1);
    in2.push_back(1);
    in2.push_back(1);
   */ 
	nn.getOutput(in2);
    
    nn.print();
    }
    return 1;
}
