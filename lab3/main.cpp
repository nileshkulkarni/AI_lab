#include<iostream>
#include<stdio.h>
#include "Perceptron.h"
#include <bitset>
#include <vector>
using namespace std;
#define SEGMENTS 7
#define ZERO 63
#define ONE 6 
#define TWO 91
#define THREE 79 
#define FOUR 102
#define FIVE 109
#define SIX 125
#define SEVEN 7  
#define EIGHT 127
#define NINE 111

vector< vector<int> >  generateZeros(int N){
	int i =0;
	vector < vector <int> > input;	
	input.resize(pow(2,SEGMENTS));
	while( i< N){
		std::bitset<SEGMENTS>  bits(i);	
		
		for(int j=0;j<SEGMENTS;j++){
			input[i].push_back(-bits[j]);	
		}
		input[i].push_back(1);	
		i++;
		//printf("Size of a particluar row %d \n", input[i-1].size());	
	}
	return input;
}

void fillCorrect(vector< vector<int> > &trainData, int num){
	std::bitset<SEGMENTS>  bits(num);		
	for(int j=0;j<SEGMENTS;j++){
		trainData[num][j] =bits[j];	
	}
	trainData[num][SEGMENTS] = -1;
	return;	
}

void printVect(vector<int> v){

	vector<int > :: iterator it;
	for(it = v.begin();it!= v.end();it++){
		printf("%d ",*it);
	}
	printf("\n");	
}	
Perceptron trainPerceptron(int n){
	vector< vector <int> > trainData;

	
	trainData = generateZeros(pow(2,SEGMENTS));	
	switch(n){
		case 0:	
			//printf("Filled here\n");
			fillCorrect(trainData,ZERO);
				
			break ;	
		case 1:	
			fillCorrect(trainData,ONE);
			break ;	
		case 2:	
			fillCorrect(trainData,TWO);
			break ;	
		case 3:	
			fillCorrect(trainData,THREE);
			break ;	
		case 4:	
			fillCorrect(trainData,FOUR);
			break ;	
		case 5:	
			fillCorrect(trainData,FIVE);
			break ;	
		case 6:	
			fillCorrect(trainData,SIX);
			break ;	
		case 7:	
			fillCorrect(trainData,SEVEN);
			break ;	
		case 8:	
			fillCorrect(trainData,EIGHT);
			break ;	
		case 9:	
			fillCorrect(trainData,NINE);
			break ;	
				
	}	

	/*printf("Printing1 train data\n ");

	vector< vector <int> > :: iterator it;
	for(it = trainData.begin();it!= trainData.end();it++){
		printVect(*it);
	}*/	
	Perceptron p(SEGMENTS);
	p.train(trainData);
	return p;
}


int main(){

	vector<Perceptron> allP;
	
	for(int i =0;i<10;i++){
	
		allP.push_back(trainPerceptron(i));
	}

	printf("All Perceptrons Trained\n");
	vector<int> input;
	input.resize(SEGMENTS);
	while(1){
		scanf("%d %d %d %d %d %d %d",&input[0] ,&input[1] ,&input[2] ,&input[3] ,&input[4] ,&input[5] ,&input[6] );	
		for(int i =0;i<allP.size();i++){
			bool stat = allP[i].check(input);
		//	printf(" Answer  %d  %d", i ,stat);
			if (stat){
				printf("Haha  %d ",i);	
				break;
			}	
		}
	}


///	trainPerceptron(0);
	
//	printf("All Perceptrons Trained");
}

