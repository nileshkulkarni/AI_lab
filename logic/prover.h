#ifndef _FORMULA_H
#define _FORMULA_H
#include "formula.h"

#include <vector>
#include <cassert>

class prover{
	
	vector<formula*> Hypothesis;
	int nH;
	vector<formula*> Introductory_formulae; //for Introduction in Axiom1
	int nI;
	
public:

	prover(int nH_ , int nI_);
	prover(int nH_ , int nI_ , vector<formula*> H, vector<formula*> I);
	prover(int nH_ , int nI_ , istream &in);
    void print(ostream &out);
	void input(istream &in);
    friend ostream &operator<<(ostream &out, prover A){   
		A.print(out);
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


};
#endif
