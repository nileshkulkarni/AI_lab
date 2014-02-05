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
	infile.open("./TweetsCorpus/trainData.txt");
	if(infile.is_open()) {
		while(getline(infile,line)) {
			int count = 0;
			int l = line.size();
			char c = (char)line[count];
			int outp = atoi(&c);
			outputVec.push_back(outp);
			cout<<"out "<<outputVec[count]<<endl;
			count+=2;
			vector<int> inp;
			while(count<=l) {
				char c1 = (char)line[count];
				int in = atoi(&c1);
				inp.push_back(in);
				count+=2;
			}
			for(int k=0; k<inp.size(); k++) {
				cout<<k<<" : "<<inp[k]<<endl;
			}
			inputVec.push_back(inp);

		}
		infile.close();	
	}
	
	else {
		cout<<"Unable to open file!"<<endl;
	} 
		 
	return 0;
}
