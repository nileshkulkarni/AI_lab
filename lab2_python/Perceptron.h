#include<iostream>
#include<vector>
#include<cmath>
#include<stdio.h>
using namespace std;
class Perceptron{
	int wSize;
	vector<int> weights;	
	
	vector< vector<int> > truthTable;
	public:
	Perceptron(int size);
	void initialize(int size);
	
	void train(vector< vector<int> > trainData);
	
	bool checkDotProduct(vector<int> w , vector<int> row);
	vector<int> addWeights(vector<int> w, vector<int> row);	
	void PTA();
	
	bool check(vector<int>);
	

};
