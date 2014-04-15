#include "neural_network.h"
#include <vector>
#include <cstdlib>
#include <fstream>
string OP;
double NETA;
double MOMENTUM_FACTOR;
double ERROR_THRESHOLD;
//char *OP = malloc(10*sizeof(char));
void  genTT(string op	,vector<Vec> &reti , vector<Vec> &reto);
void getTruthTableLsd(int n, vector< Vec > &input, vector< Vec > &output);
void printTT(vector <Vec> , vector <Vec>);
int getFilesize() ;
vector<Vec> getTrainingInput(int nfold, int partForValidation) ;
vector<Vec> crossValinput(int nfold, int partForValidation);
vector<Vec> crossValOutput(int nfold, int partForValidation);
vector<Vec> getTrainingOutput(int nfold, int partForValidation);

vector<Vec> getTrainingInputIris(int nfold, int partForValidation) ;
vector<Vec> crossValinputIris(int nfold, int partForValidation);
vector<Vec> crossValOutputIris(int nfold, int partForValidation);
vector<Vec> getTrainingOutputIris(int nfold, int partForValidation);

vector<Vec> getTrainingInputMonks(int nfold, int partForValidation) ;
vector<Vec> crossValinputMonks(int nfold, int partForValidation);
vector<Vec> crossValOutputMonks(int nfold, int partForValidation);
vector<Vec> getTrainingOutputMonks(int nfold, int partForValidation);

Vec inputForOneTweet();

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
    scanf("%lf",&NETA);
    
    printf("Enter Momentum \n");
    scanf("%lf",&MOMENTUM_FACTOR );
    
    cout<<"Give the OPERATOR to train on:"<<endl;
    cin>>OP;
    //cout<<OP<<endl;		
    cout<<"Give ERROR_THRESHOLD value:"<<endl;
    cin>>ERROR_THRESHOLD;

    Vec in2;	
    int vsize;	
    if(OP!="Tweet" && OP != "Iris" && OP != "Monks"){
    	vsize = getInputSize(OP);	
	in2.resize(vsize);
	}
    
    int nlayers;
		
    cout<<"Enter number of layers in the Neural Network:"<<endl;
    cin>>nlayers;		
    NeuralNetwork nn(nlayers,1);
    
    if(OP!="Tweet" && OP != "Iris" && OP != "Monks"){
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

   // nn.addOutputLayer(1);
    
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
		cout<<"In1----------"<<endl;
	    cout<<"Part for validation? : ";
        int i;
        cin>>i;
		vector<Vec> inputVec = getTrainingInput(5 , i);
    	
    	
    	vector<Vec> outputVec = getTrainingOutput(5, i); 
    	vector<Vec> validatingInputs = crossValinput(5, i);
    	vector<Vec> validatingOutputs = crossValOutput(5, i);

		assert(validatingInputs.size() == validatingOutputs.size());
		printf("Sizes are %d %d %d %d \n", validatingInputs.size() , validatingOutputs.size() , inputVec.size() , outputVec.size()); 
		
    	
    	printf("Sizes are %d %d \n" , inputVec[0].size() , inputVec[0].size());
    	
    	
    		
/*		for(int nhj=0;nhj<inputVec.size();nhj++){
			printVec(outputVec[nhj]);
			cout<<" : ";
			printVec(inputVec[nhj]);
		}
  */  	
    	
    	
		Vec OutputResult;

		
		
		nn.addInputLayer(inputVec[0].size());
		nn.addOutputLayer(2);
    
		cout<<"Input Layer added!"<<endl;
		nn.generateEdges();
		cout<<"Edges Generated!"<<endl;
    	nn.addAllTrainData(inputVec, outputVec);
        printf("Training Done!\n");
		printf("Generating validation inputs \n");
		
		
		
		
		int NumberSucceeded = 0;
		
		
		for(int nhj=0;nhj<inputVec.size();nhj++){
			OutputResult = nn.getOutput(inputVec[nhj]);
			cout<<"\n---------------------------"<<nhj<<"    "<<OutputResult.size()<<endl;
			cout<<"Expected: ";
			printVec(outputVec[nhj]);
			cout<<"\n Result : ";
			printVec(OutputResult);
			NumberSucceeded += equal(OutputResult , outputVec[nhj]);
		}
		
		
		cout<<"Accuracy  on Trained % is : "<<(NumberSucceeded * 100)/inputVec.size()<<endl;
		
		
		
		NumberSucceeded = 0;
		
		for(int nhj=0;nhj<validatingInputs.size();nhj++){
			OutputResult = nn.getOutput(validatingInputs[nhj]);
			cout<<"\n---------------------------"<<nhj<<"    "<<OutputResult.size()<<endl;
			cout<<"Expected: ";
			printVec(validatingOutputs[nhj]);
			cout<<"\n Result : ";
			printVec(OutputResult);
			NumberSucceeded += equal(OutputResult , validatingOutputs[nhj]);
		}
		
		
		cout<<"Accuracy  % is : "<<(NumberSucceeded * 100)/validatingInputs.size()<<endl;
	//	nn.print();
		string tw;
        
		string file = "main.py -o";
		string ex = "python ";
		ex+=file;
		system(ex.c_str());
		
	    Vec v_in = inputForOneTweet();
	    
	    OutputResult = nn.getOutput(v_in);
        Vec postv,negtv,objtv;
        postv.push_back(1);
        postv.push_back(1);

        negtv.push_back(0);
        negtv.push_back(0);

        objtv.push_back(0);
        objtv.push_back(1);
        
        int c=-1;
        if(equal(postv,OutputResult)) c=1;
        else if(equal(negtv,OutputResult)) c=2;
        else if(equal(objtv,OutputResult)) c=0;
        else c=-1;
        
        
		cout<<"\n Result : ";
		printVec(OutputResult);
        cout<<endl;
        cout<<"The tweet seems to be : ";
        if(c==1) cout<<"Positive!"<<endl;
        else if(c==0) cout<<"Neutral!"<<endl;
        else if(c==2) cout<<"Negative!"<<endl;
        else cout<<c<<endl;
		
        

		return 0;
    }
    
    /*else if(OP == "NewTweet") {
		vector<Vec> inputVec = getTrainingInput(5 , 0);
    	vector<Vec> outputVec = getTrainingOutput(5, 0); 
		
		nn.addInputLayer(inputVec[0].size());
		nn.addOutputLayer(2);
    
		cout<<"Input Layer added!"<<endl;
		nn.generateEdges();
		cout<<"Edges Generated!"<<endl;
    	nn.addAllTrainData(inputVec, outputVec);
        printf("Training Done!\n");
		Vec OutputResult;
	    Vec Input;	
		OutputResult = nn.getOutput(Input[0]);
		cout<<"\n Result : ";
		printVec(OutputResult);
        
    }*/

    else if(OP == "Iris") {
		cout<<"In Iris----------"<<endl;
		
		vector<Vec> inputVec = getTrainingInputIris(5 , 5);
    	
    	vector<Vec> outputVec = getTrainingOutputIris(5, 5); 
    	vector<Vec> validatingInputs = crossValinputIris(5, 5);
    	vector<Vec> validatingOutputs = crossValOutputIris(5, 5);

		assert(validatingInputs.size() == validatingOutputs.size());
		printf("Sizes are %d %d %d %d \n", validatingInputs.size() , validatingOutputs.size() , inputVec.size() , outputVec.size()); 
		
    	
    	printf("Sizes are %d %d \n" , inputVec[0].size() , inputVec[0].size());
    	
    	
    		
		for(int nhj=0;nhj<inputVec.size();nhj++){
			printVec(outputVec[nhj]);
			cout<<" : ";
			printVec(inputVec[nhj]);
		}
    	
    	
    	
		Vec OutputResult;

		
		
		nn.addInputLayer(inputVec[0].size());
		nn.addOutputLayer(2);
    
		cout<<"Input Layer added!"<<endl;
		nn.generateEdges();
		cout<<"Edges Generated!"<<endl;
    	nn.addAllTrainData(inputVec, outputVec);
        printf("Training Done!\n");
		printf("Generating validation inputs \n");
		
		
		
		
		int NumberSucceeded = 0;
		
		
		for(int nhj=0;nhj<inputVec.size();nhj++){
			OutputResult = nn.getOutput(inputVec[nhj]);
			cout<<"\n---------------------------"<<nhj<<"    "<<OutputResult.size()<<endl;
			cout<<"Expected: ";
			printVec(outputVec[nhj]);
			cout<<"\n Result : ";
			printVec(OutputResult);
			NumberSucceeded += equal(OutputResult , outputVec[nhj]);
		}
		
		
		cout<<"Accuracy  on Trained % is : "<<(NumberSucceeded * 100)/inputVec.size()<<endl;
		
		
		
		NumberSucceeded = 0;
		
		for(int nhj=0;nhj<validatingInputs.size();nhj++){
			OutputResult = nn.getOutput(validatingInputs[nhj]);
			cout<<"\n---------------------------"<<nhj<<"    "<<OutputResult.size()<<endl;
			cout<<"Expected: ";
			printVec(validatingOutputs[nhj]);
			cout<<"\n Result : ";
			printVec(OutputResult);
			NumberSucceeded += equal(OutputResult , validatingOutputs[nhj]);
		}
		
		
		cout<<"Accuracy  % is : "<<(NumberSucceeded * 100)/validatingInputs.size()<<endl;
		return 0;
    }
	
    else if(OP == "Monks") {
		cout<<"In Monks----------"<<endl;
		
		vector<Vec> inputVec = getTrainingInputMonks(5 , 5);
    	
    	
    	vector<Vec> outputVec = getTrainingOutputMonks(5, 5); 
    	vector<Vec> validatingInputs = crossValinputMonks(5, 5);
    	vector<Vec> validatingOutputs = crossValOutputMonks(5, 5);

		assert(validatingInputs.size() == validatingOutputs.size());
		printf("Sizes are %d %d %d %d \n", validatingInputs.size() , validatingOutputs.size() , inputVec.size() , outputVec.size()); 
		
    	
    	printf("Sizes are %d %d \n" , inputVec[0].size() , outputVec[0].size());
    	
    	
    		
		for(int nhj=0;nhj<inputVec.size();nhj++){
			printVec(outputVec[nhj]);
			cout<<" : ";
			printVec(inputVec[nhj]);
		}
    	
    	
    	
		Vec OutputResult;

		
		
		nn.addInputLayer(inputVec[0].size());
		nn.addOutputLayer(outputVec[0].size());
    
		cout<<"Input Layer added!"<<endl;
		nn.generateEdges();
		cout<<"Edges Generated!"<<endl;
    	nn.addAllTrainData(inputVec, outputVec);
        printf("Training Done!\n");
		printf("Generating validation inputs \n");
		
		
		
		
		int NumberSucceeded = 0;
		
		
		for(int nhj=0;nhj<inputVec.size();nhj++){
			OutputResult = nn.getOutput(inputVec[nhj]);
		//	cout<<"\n---------------------------"<<nhj<<"    "<<OutputResult.size()<<endl;
		//	cout<<"Expected: ";
		//	printVec(outputVec[nhj]);
		//	cout<<"\n Result : ";
		//	printVec(OutputResult);
			NumberSucceeded += equal(OutputResult , outputVec[nhj]);
		}
		
		
		cout<<"Accuracy  on Trained % is : "<<(NumberSucceeded * 100)/inputVec.size()<<endl;
		
		
		
		NumberSucceeded = 0;
		
		for(int nhj=0;nhj<validatingInputs.size();nhj++){
			OutputResult = nn.getOutput(validatingInputs[nhj]);
		//	cout<<"\n---------------------------"<<nhj<<"    "<<OutputResult.size()<<endl;
		//	cout<<"Expected: ";
		//	printVec(validatingOutputs[nhj]);
		//	cout<<"\n Result : ";
		//	printVec(OutputResult);
			NumberSucceeded += equal(OutputResult , validatingOutputs[nhj]);
		}
		
		
		cout<<"Accuracy  % is : "<<(NumberSucceeded * 100)/validatingInputs.size()<<endl;
		
		nn.print();
    
		
		return 0;
    }
    else {
		nn.addOutputLayer(1);
		nn.generateEdges();   
       	genTT(OP,ins,outs);
    	nn.addAllTrainData(ins, outs);
	}	

    //printTT(ins,outs);
//    nn.addAllTrainData(ins, outs);
    int rem;
   
   
    while(1){
        printf("Enter inputs \n");
        for(rem=0; rem<vsize; rem++) {
            scanf("%lf",&in2[rem]);
        }
    nn.getOutput(in2);
    nn.print();
    }
    
    return 1;
}
