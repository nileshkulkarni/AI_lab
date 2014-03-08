#include "formula.h"
#include <vector>

class prover{
	
	vector<formula*> Hypothesis;
	int nH;
	vector<formula*> Introductory_formulae; //for Introduction in Axiom1
	int nI;
	
public:

	prover(int nH_ , int nI_);
	prover(int nH_ , int nI_ , istream &in);

	void input(istream &in);


};
