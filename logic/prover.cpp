#include "prover.h"



prover::prover(int nH_ , int nI_){

	nH = nH_;
	nI = nI_;
}
	
prover::prover(int nH_ , int nI_ , istream &in){

	nH = nH_;
	nI = nI_;
	input(in);
}

void prover::input(istream &in){
	
	for(int i=0;i<nH;i++){
		formula *tH = new formula;
		tH->input(in);
		Hypothesis->push_back(tH);
	}
	for(int i=0;i<nI;i++){
		formula *tI = new formula;
		tH->input(in);
		Introductory_formulae->push_back(tH);
	}
}


bool prover::Hmember(formula *f){
	
	assert(f!=NULL);
	auto iterator it;
	for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
		if(*(*it)==*f) return true;
	}
	return false;
}



int prover::MPclosure(){
	
	int count=0;
	auto iterator it;
	for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
		if((*it)->leaf) continue;
		if(Hmember((*it)->lhs) && (!Hmember(*it)->rhs)){
			Hypothesis.push_back((*it)->rhs);
			count++;
		}
	}
	return count;
}	
	
	
	
	
	










