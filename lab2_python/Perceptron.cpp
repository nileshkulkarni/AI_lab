#include "Perceptron.h"

Perceptron::Perceptron(int size){
	initialize(size);	
	
	
}

void Perceptron:: initialize(int size){ // size only includes the weights not the theta
	wSize=size+1;
//	weights.resize(wSize+1);
	int truthValues = pow(2,size);
	truthTable.resize(truthValues);
	vector< vector <int> > :: iterator it;
	for(it = truthTable.begin();it!= truthTable.end();it++){
		(*it).resize(wSize);
	}	

	for(int i =0;i< wSize;i++){
		weights.push_back(0);
	}	
return;
}
	
void Perceptron:: train(vector< vector<int> > trainData){
/*	int class0Size = class0.size();
	int class1Size = class1.size();
	int truthRow =0;	
	for(int i =0;i<class0Size;i++){
		for(int j =0j<wSize-1;j++){
			truthTable[truthRow].push_back(-(class0[i][j]);	
		}			
		truthTable[truthRow].push_back(1);	
		truthRow++;
	}	
	
	for(int i =0;i<class1Size;i++){
		for(int j =0j<wSize-1;j++){
			truthTable[truthRow].push_back((class1[i][j]);	
		}			
		truthTable[truthRow].push_back(-1);	
	}	

*/
	truthTable = trainData;
	PTA();
}

bool  Perceptron::checkDotProduct(vector<int> w, vector<int> row){
	
	int wS = w.size();	
	int rowS = row.size();
	if(wS != rowS){
		printf(" Incomptible vectors for dot product\n");
	}
	int sum=0;
	for(int i=0;i<wS;i++){
		sum +=w[i]*row[i];	
	}	
	if(sum >0)
		return true;
	else
		return false;
}
vector<int> Perceptron::addWeights(vector<int> w, vector<int> row){


	int wS = w.size();	
	for(int i=0;i<wS;i++){
		w[i] =w[i]+row[i];	
	}	

	return w;
} 

void Perceptron::PTA(){
	int start=0;
	while(true){
		
		if(!checkDotProduct(weights,truthTable[start])){
			weights = addWeights(weights,truthTable[start]);			
			
			start =0;
		}
		else{
			start++;
		}	
		if(start >= pow(2,wSize-1)){
			//printf("Training Completed");
			break;
		}
	}
	printf(" Weights are %d %d %d %d %d %d %d %d \n",weights[0],weights[1],weights[2],weights[3],weights[4],weights[5],weights[6],weights[7]);

}

bool Perceptron::check(vector<int> input){
	
	input.push_back(-1);
	int wS = weights.size();	
	int rowS = input.size();
	printf("%d w  %d row \n",wS,rowS);
	if(wS != rowS){
		printf(" Incomptible input for dot product\n");
	}
	int sum;
	for(int i=0;i<wS;i++){
		sum +=weights[i]*input[i];	
	}	
	if(sum >0)
		return true;
	else
		return false;
}	
