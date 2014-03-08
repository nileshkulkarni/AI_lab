#include <iostream>
using namespace std;

struct formula{
	
	char val;
	formula *lhs;
	formula *rhs;
	bool leaf;
	bool False;
	
 void input(istream &in){
	in>>val;
	leaf = true;
	if(val == '-'){
		lhs = new formula;
		rhs = new formula;
		lhs->input(in);
		rhs->input(in);
		leaf = false;
	}
	if(val == 'F')
		False = true;
	
 }
};


extern formula *F; //global variable to store F


formula *implication(formula *A , formula *B);
formula *Axiom1(formula *A , formula *B);
formula *Axiom2(formula *A , formula *B , formula *C);
formula *Axiom3(formula *A);
