#ifndef _PROVER_H
#define _PROVER_H

#include "formula.h"
#include <unordered_map>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>

struct trace {
	formula* self;
	string axiom_used;
	formula* f1;
	formula* f2;
	bool done;
};


bool comp_tr(pair<int,pair<string,formula*> >v1, pair<int,pair<string, formula*> > v2);	

	
class prover{
	
	
public:
	unordered_map<string , formula*> Hypothesis;
	int nH;
	unordered_map<string , formula*> Introductory_formulae; //for Introduction in Axiom1
	int nI;
	unordered_map<string, trace> traceMap;
	formula *destination;
	formula *originalDestination;
	unordered_map<string , formula*> originalHypothesis;
	int maxAllowedLength;
	vector<trace> traceVec1;
	vector< pair<int, pair <string, formula*> > > traceVec;
	
public:


	prover();
	prover(int nH_ , int nI_);
	prover(int nH_ , int nI_ , unordered_map<string, formula*> H, unordered_map<string, formula*> I);
	prover(int nH_ , int nI_ , istream &in);
    void printH(ostream &out);
	void printI(ostream &out);
	void printOH(ostream &out);
	
	
	void indentedPrintH(ostream &out ,  int nspaces);
	void indentedPrintI(ostream &out , int nspaces);
	void indentedPrintOH(ostream &out , int nspaces);
	
	bool check();
	bool checkUseful(formula *t);
	
	
	void input(istream &in);
	
	int simplify();
    void simpilifyDestination();
    void setDummyTrace();

    friend ostream &operator<<(ostream &out, prover A){   
		out<<"Destination is : "<<*(A.destination)<<endl;
		A.printH(out);
		A.printI(out);
		return out;
    }
    
    friend istream &operator>>(istream &in, prover &A){   
		A.input(in);
		return in;
    }
	
	int computeMaxFormulalength();
	/********Trace****************/
	void setTrace(formula* self, formula* MP_1, formula* MP_2, string axiom);
	void fillTraceVec(formula* f);
	void printTraceVec(int nspaces);
	void traceBack(int nspaces);
	/*****************************/
	bool Hmember(formula *f);
	int MPclosure();
	int Axiom1closure();
    int Axiom2closure();
    int Axiom3closure();
    
    int Axiom2finish();
    void cutDownAxiom3();
    bool step(int nSteps);


};
#endif
