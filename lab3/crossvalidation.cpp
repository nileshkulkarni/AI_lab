#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <stdio.h>
#include <math.h>
#include "neural_network.h"

using namespace std;

int getFilesize() {
   // ifstream infile;
    string line;
    ifstream infile("extracted-features.dump", ios::in);
    //infile.open("exctracted-features.dump");
    int nlines=0;
    if(infile.is_open()) {
        while(getline(infile,line)) {
            nlines++;
        }
        infile.close();
        return nlines;
    }
    else {
        cout<<"Unable to open file!";
        return -1;
    }
}

vector<Vec> getTrainingInput(int nfold, int partForValidation) {
    vector<Vec> input;
    int nlines = getFilesize();
    cout<<"nlines : "<<nlines<<endl;
    double linesInaPart = ceil((double)nlines/nfold);
    int partSize = (int)linesInaPart;
    cout<<"partsize : "<<partSize<<endl;
    if(nlines == -1) cout<<"Unable to get file size!"<<endl;
    else {
        string line;
        ifstream infile("extracted-features.dump", ios::in);
        int nlines=0;
        int current_part=1;
        if(infile.is_open()) {
            while(current_part <= nfold) {
                if(current_part==partForValidation) {
                    cout<<"Skipping current part "<<current_part<<endl;
                    //Skip all lines in this partition
                    //Do not add to vector
                    current_part++;
                    int c=0;
                    while(c!=linesInaPart) {
                        getline(infile,line);
                        c++;
                    }
                    cout<<"Lines skipped : "<<c<<endl;
                }
                else if(current_part < nfold) {
                    int count=0;
                    while(count!=partSize) {
                        getline(infile,line);
                        int l = line.size();
                        Vec inp;
                        int index = 2;
                        while(index<=l) {
                            char c1 = (char)line[index];
                            float in = (float)atoi(&c1);
                            inp.push_back(in);
                            index+=2;
                        }
                        input.push_back(inp);
                        count++;
                    }
                    current_part++;
                }
                //Every remaining line goes to last partition.
                else {
                    while(getline(infile,line)) {
                        int l = line.size();
                        Vec inp;
                        int index = 2;
                        while(index<=l) {
                            char c1 = (char)line[index];
                            float in = (float)atoi(&c1);
                            inp.push_back(in);
                            index+=2;
                        }
                        input.push_back(inp);
                    }
                    current_part++;
                }
            }
        }
        else cout<<"Unable to open file while creating input!"<<endl;
    }
    return input;        
}



vector<Vec> getTrainingOutput(int nfold, int partForValidation) {
    vector<Vec> output;
    int nlines = getFilesize();
    double linesInaPart = ceil((double)nlines/nfold);
    int partSize = (int)linesInaPart;
    if(nlines == -1) cout<<"Unable to get file size!"<<endl;
    else {
        string line;
        ifstream infile("extracted-features.dump", ios::in);
        int nlines=0;
        int current_part=1;
        if(infile.is_open()) {
            while(current_part<=nfold) {
                if(current_part==partForValidation) {
                    //Skip all lines in this partition
                    //Do not add to vector
                    current_part++;
                    int c=0;
                    while(c!=linesInaPart) {
                        getline(infile,line);
                        c++;
                    }
                }
                else if(current_part < nfold) {
                    int count=0;
                    while(count!=partSize) {
                        getline(infile,line);
                        Vec outp;
                        int index=0;
                        char ch = (char)line[index]; //First char
                        int a = atoi(&ch);
                        if(a==-1) {
                            outp.push_back(0);
                            outp.push_back(0);
                        }
                        else if(a==0) {
                            outp.push_back(0);
                            outp.push_back(1);
                        }
                        else if(a==1) {
                            outp.push_back(1);
                            outp.push_back(1);
                        }

                        output.push_back(outp);
                        count++;
                    }
                    current_part++;
                }
                //Every remaining line goes to last partition.
                else {
                    while(getline(infile,line)) {
                        Vec outp;
                        int index = 0;
                        char c1 = (char)line[index];
                        float a = (float)atoi(&c1);
                        if(a==-1) {
                            outp.push_back(0);
                            outp.push_back(0);
                        }
                        else if(a==0) {
                            outp.push_back(0);
                            outp.push_back(1);
                        }
                        else if(a==1) {
                            outp.push_back(1);
                            outp.push_back(1);
                        }

                        output.push_back(outp);
                    }
                    current_part++;
                }
            }
        }
        else cout<<"Unable to open file while creating output!"<<endl;
    }
    return output;        
}


int main() {
    vector <Vec> in = getTrainingInput(5,2);
    cout<<"Size of vec : "<<in.size()<<endl;
    for(int i=0; i<in.size(); i++) {
        cout<<"Printing vector : "<<i<<" size : "<<in[i].size()<<endl;
        for(int j=0; j<in[i].size(); j++) {
            cout<<in[i][j]<<" ";
        }
        cout<<"********************************************************************"<<endl;
        cout<<endl;
    }
    return 0;
}
