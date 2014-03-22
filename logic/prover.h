#ifndef _FORMULA_H
#define _FORMULA_H

#include "formula.h"
#include <map>
#include <vector>
#include <cassert>



class prover{
	
	map<string , formula*> Hypothesis;
	int nH;
	map<string , formula*> Introductory_formulae; //for Introduction in Axiom1
	int nI;
	int maxAllowedLength;
	
public:

	prover(int nH_ , int nI_);
	prover(int nH_ , int nI_ , map<string, formula*> H, map<string, formula*> I);
	prover(int nH_ , int nI_ , istream &in);
    void printH(ostream &out);
	void printI(ostream &out);
	
	void input(istream &in);
    friend ostream &operator<<(ostream &out, prover A){   
		A.printH(out);
		A.printI(out);
		return out;
    }
    
    friend istream &operator>>(istream &in, prover &A){   
		A.input(in);
		return in;
    }
	
	bool Hmember(formula *f);
	int MPclosure();
	int Axiom1closure();
    int Axiom2closure();
    int Axiom3closure();
    
    void step();


};
#endif
