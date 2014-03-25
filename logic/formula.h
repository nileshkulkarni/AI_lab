#ifndef FORMULA_H
#define FORMULA_H
#include <iostream>
#include <cassert>
using namespace std;




struct formula{
	
	char val;
	formula *lhs;
	formula *rhs;
	bool leaf;
	bool False;
	string s;
	int length; //Useful for search strategies
	
 void input(istream &in);
 void inputInfix(istream &in);
 void print(ostream &out);
 
 friend ostream &operator<<(ostream &out, formula A){   
		A.print(out);
		return out;
 }
  friend istream &operator>>(istream &in, formula &A){   
		A.input(in);
		return in;
 }
 
 string stringify();
};

extern formula *F; //global variable to store F



formula *implication(formula *A , formula *B);

formula *Axiom1(formula *A , formula *B);  //Introduction Axiom , introduces B
formula *Axiom2(formula *A , formula *B , formula *C);
formula *Axiom3(formula *A);

void destroyAxiom1(formula *f);
void destroyAxiom2(formula *f);
void destroyAxiom3(formula *f);

bool Axiom3Form(formula *f);
bool Axiom2lhsForm(formula *f);
//Gotta do something about this

bool equal(formula *A , formula *B);
bool operator==(formula A , formula B);

#endif
