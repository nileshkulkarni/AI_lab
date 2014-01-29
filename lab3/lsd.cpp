#include <bitset>
#include <vector>
#include "neuron.h"
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

void generateZeros(int N, vector< Vec > &input){
	int i =0;	
	input.resize(pow(2,SEGMENTS));
	while( i< N){
		std::bitset<SEGMENTS>  bits(i);	
		
		for(int j=0;j<SEGMENTS;j++){
			input[i].push_back((int)bits[j]);	
		}
	}
	return ;
}

void generateZerosOutput(int N, vector<Vec> &output){
    output.resize(N); 
    for(int i =0;i<N;i++){
        output[i].push_back(0);
    }
}

void printVect(Vec v){

	Vec :: iterator it;
	for(it = v.begin();it!= v.end();it++){
		printf("%d ",*it);
	}
}	
void printTT(vector <Vec> ins, vector <Vec> out ){

	vector< Vec > :: iterator it;
	vector< Vec > :: iterator itO;
	for(it = ins.begin(),itO = out.begin();it!= ins.end();it++,itO++){
		printVect(*it);
        printf("\t");
        printVect(*itO);
	}
	printf("\n");	
}	
void getTruthTableLsd(int n, vector< Vec > &input, vector< Vec > &output){

	
	generateZeros(pow(2,SEGMENTS),input);
    generateZerosOutput(pow(2,SEGMENTS),output);
	printf("Here\n");
    switch(n){
		case 0:	
			//printf("Filled here\n");
			output[ZERO][0] =1;
			break ;	
		case 1:	
			output[ONE][0] =1;
			break ;	
		case 2:	
			output[TWO][0] =1;
			break ;	
		case 3:	
			output[THREE][0] =1;
			break ;	
		case 4:	
			output[FOUR][0] =1;
			break ;	
		case 5:	
			output[FIVE][0] =1;
			break ;	
		case 6:	
			output[SIX][0] =1;
			break ;	
		case 7:	
			output[SEVEN][0] =1;
			break ;	
		case 8:	
			output[EIGHT][0] =1;
			break ;	
		case 9:	
			output[NINE][0] =1;
			break ;	
				
	}	
}

