#include "neural_network.h"
#include <vector>



void  genTT(string op	,vector<Vec> &reti , vector<Vec> &reto);
void getTruthTableLsd(int n, vector< Vec > &input, vector< Vec > &output);
void printTT(vector <Vec> , vector <Vec>);

using namespace std;
int main(){
    
  
    
    NeuralNetwork nn(4,1);
    
    nn.addInputLayer(5);
    nn.addHiddenLayer(3);
    nn.addHiddenLayer(3);
    nn.addOutputLayer(1);
    
    nn.generateEdges();
    vector< Vec> ins;
	vector< Vec > outs;
    
   genTT("PALINDROME",ins,outs);
    //getTruthTableLsd(1,ins,outs);
    //printTT(ins,outs);
  nn.addAllTrainData(ins, outs);
	
	
    Vec in2;
    in2.push_back(1);
    in2.push_back(0);
    in2.push_back(0);
    in2.push_back(0);
    in2.push_back(0);
    nn.getOutput(in2);
    
    nn.print();
    

    return 1;
}
