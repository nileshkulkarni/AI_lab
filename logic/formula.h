#include <iostream>
using namespace std;

struct formula{
	
	char val;
	formula *lhs;
	formula *rhs;
	bool leaf;
	bool False;
	int length;
	
 void input(istream &in);
 void print(ostream &out);
 
 };


extern formula *F; //global variable to store F


formula *implication(formula *A , formula *B);

formula *Axiom1(formula *A , formula *B);  //Introduction Axiom , introduces B
formula *Axiom2(formula *A , formula *B , formula *C);
formula *Axiom3(formula *A);


//Gotta do something about this
//bool operator==(const formula *A ,const formula* B);

bool equal(formula *A , formula *B);
