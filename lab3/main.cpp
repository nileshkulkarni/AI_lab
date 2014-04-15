#include "neural_network.h"
#include <vector>

string OP;
float NETA;
//char *OP = malloc(10*sizeof(char));
void  genTT(string op	,vector<Vec> &reti , vector<Vec> &reto);
void getTruthTableLsd(int n, vector< Vec > &input, vector< Vec > &output);
void printTT(vector <Vec> , vector <Vec>);

using namespace std;

int getInputSize(string op) {
	if(op.compare("XOR") == 0) return 2;
	else if(op.compare("NAND") == 0) return 2;
	else if(op.compare("NOR") == 0) return 2;
	else if(op.compare("PALINDROME") == 0) return 5;
	else if(op.compare("Majority") == 0) return 5;
	else if(op.compare("Parity") == 0) return 6;
	else return -1;
}

int main(){
  
    NETA =0.2;
    printf("Enter Learning rate \n");
    scanf("%f",&NETA);
    
    cout<<"Give the OPERATOR to train on:"<<endl;
    cin>>OP;
    cout<<OP<<endl;		
    	
    Vec in2;
    int vsize = getInputSize(OP);	
    in2.resize(vsize);
    
    int nlayers;
		
    cout<<"Enter number of layers in the Neural Network:"<<endl;
    cin>>nlayers;		
    NeuralNetwork nn(nlayers,1);
    
    nn.addInputLayer(vsize);
    //nn.addHiddenLayer(7);
    int hl=1;
    while(hl<=nlayers-2) {	//No. of hidden layers is 2 less than total
	 int nneuron; 	
	 cout<<"Enter number of neurons in hidden layer "<<hl<<" :"<<endl;
	 cin>>nneuron;
   	 nn.addHiddenLayer(nneuron);
	 hl++;
    }	

    nn.addOutputLayer(1);
    
    nn.generateEdges();
  //  printf("************\n");
    vector< Vec> ins;
    vector< Vec > outs;
    genTT(OP,ins,outs);
    //getTruthTableLsd(1,ins,outs);
    //printTT(ins,outs);
    nn.addAllTrainData(ins, outs);
    int rem;
    while(1){
        printf("Enter inputs \n");
        for(rem=0; rem<vsize; rem++) {
            scanf("%f",&in2[rem]);
        }
    nn.getOutput(in2);
    nn.print();
    }
    
    return 1;
}
