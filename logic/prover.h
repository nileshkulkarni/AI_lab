#ifndef _PROVER_H
#define _PROVER_H

#include "formula.h"
#include <unordered_map>
#include <vector>
#include <cassert>



class prover{
	
	
public:
	unordered_map<string , formula*> Hypothesis;
	int nH;
	unordered_map<string , formula*> Introductory_formulae; //for Introduction in Axiom1
	int nI;
	formula *destination;
	formula *originalDestination;
	unordered_map<string , formula*> originalHypothesis;
	int maxAllowedLength;


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
