#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
	//Call to python feature generator
	string file = "main.py -a";
	string ex = "python ";
	ex+=file;
	system(ex.c_str());

	//Now open the generated training data file
	vector< vector<int> > inputVec;
	vector<int> outputVec;
	string line;
	ifstream infile;
	infile.open("./TweetsCorpus/extracted-features.dump");
	cout<<"Generating input and output vectors for training.."<<endl;
	if(infile.is_open()) {
		while(getline(infile,line)) {
			int count = 0;
			int l = line.size();
			char c = (char)line[count];
			int outp = atoi(&c);
			outputVec.push_back(outp);
			count+=2;
			vector<int> inp;
			while(count<=l) {
				char c1 = (char)line[count];
				int in = atoi(&c1);
				inp.push_back(in);
				count+=2;
			}
			inputVec.push_back(inp);

		}
		infile.close();	
		cout<<"Vectors Generated!"<<endl;
		cout<<"Size of outputVec : "<<outputVec.size()<<endl;
		cout<<"Size of inputVec : "<<inputVec.size()<<endl;
	}
	
	else {
		cout<<"Unable to open file!"<<endl;
	} 
		 
	return 0;
}
