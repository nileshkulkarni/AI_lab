#include "neural_network.h"
#include <vector>
#include <cstdlib>
#include <fstream>
string OP;
float NETA;
float MOMENTUM_FACTOR;
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
	else if(op.compare("LSD") == 0) return 7;
	else return -1;
}

int main(){
  
    NETA =0.2;
    printf("Enter Learning rate \n");
    scanf("%f",&NETA);
    
    printf("Enter Momentum \n");
    scanf("%f",&MOMENTUM_FACTOR );
    
    cout<<"Give the OPERATOR to train on:"<<endl;
    cin>>OP;
    //cout<<OP<<endl;		
    	
    Vec in2;	
    int vsize;	
    if(OP!="Tweet"){
    	vsize = getInputSize(OP);	
	in2.resize(vsize);
	}
    
    int nlayers;
		
    cout<<"Enter number of layers in the Neural Network:"<<endl;
    cin>>nlayers;		
    NeuralNetwork nn(nlayers,1);
    
    if(OP!="Tweet"){
    	nn.addInputLayer(vsize);
	}
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
    
   // nn.generateEdges();
  //  printf("************\n");
    vector< Vec> ins;
    vector< Vec > outs;
    if(OP == "LSD") {
	nn.generateEdges();
        getTruthTableLsd(1,ins,outs);
    	nn.addAllTrainData(ins, outs);
    }
    else if(OP == "Tweet") {
	cout<<"In1"<<endl;
    	//Call to python feature generator
    	string file = "main.py -a";
    	string ex = "python ";
    	ex+=file;
    	system(ex.c_str());
    	
	//Now open the generated training data file
    	vector< Vec > inputVec;
    	vector< Vec > outputVec;
    	string line;
    	ifstream infile;
    	infile.open("./TweetsCorpus/extracted-features.dump");
    	cout<<"Generating input and output vectors for training.."<<endl;
      	if(infile.is_open()) {
		int nLines=0;
     		while(getline(infile,line)) {
			nLines++;
    			int count = 0;
    			int l = line.size();
    	    		char c = (char)line[count];
    			Vec outp;
			int a = atoi(&c);	
			if(a== -1){
				outp.push_back(0);	
				outp.push_back(0);	
			}
			else if(a== 0){
				outp.push_back(0);	
				outp.push_back(1);	
			}
			else if(a== 1){
				outp.push_back(1);	
				outp.push_back(1);	
			}
			
			
			outputVec.push_back(outp);
			count+=2;
			Vec inp;
			while(count<=l) {
				char c1 = (char)line[count];
				float in = (float)atoi(&c1);
				inp.push_back(in);
				count+=2;
			}
			inputVec.push_back(inp);

		}
		infile.close();	
		cout<<"Vectors Generated!"<<endl;
		cout<<"Size of outputVec : "<<outputVec.size()<<endl;
		cout<<"Size of inputVec : "<<inputVec.size()<<endl;
       		//genTT(OP,inputVec,outputVec);
    		nn.addInputLayer(inputVec[0].size());
		cout<<"Input Layer added!"<<endl;
		nn.generateEdges();
		cout<<"Edges Generated!"<<endl;
    		nn.addAllTrainData(inputVec, outputVec);
            printf("Training Done!\n");
	}
	
	else {
		cout<<"Unable to open file!"<<endl;
	}
    }		
    else {
	nn.generateEdges();   
       	genTT(OP,ins,outs);
    	nn.addAllTrainData(ins, outs);
   }	
>>>>>>> tsa

    //printTT(ins,outs);
//    nn.addAllTrainData(ins, outs);
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
