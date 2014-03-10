#include "prover.h"
//#include "formula.h"


prover::prover(int nH_ , int nI_){

	nH = nH_;
	nI = nI_;
}

prover::prover(int nH_ , int nI_ , vector<formula*> H, vector<formula*> I) {
    nH = nH_;
    nI = nI_;
    Hypothesis = H;
    Introductory_formulae = I;
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
		Hypothesis.push_back(tH);
	}
	for(int i=0;i<nI;i++){
		formula *tI = new formula;
		tI->input(in);
		Introductory_formulae.push_back(tI);
	}
}

void prover::print(ostream &out){
    vector<formula*>:: iterator iH = Hypothesis.begin();
    out<<"Printing Hypothesis vector..\n";
    for(; iH!=Hypothesis.end(); iH++) {
        (*iH)->print(out);
    }
}

bool prover::Hmember(formula *f){
	
	assert(f!=NULL);
    vector<formula*>:: iterator it;
	//auto iterator it;
	for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
		if(*(*it)==*f) return true;
	}
	return false;
}



int prover::MPclosure(){
	
	int count=0;
    vector<formula*>:: iterator it;
	//auto it;
	
	vector<formula*> add;
	for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
		assert(*it!=NULL);
		if(((*it)->leaf)) continue;
		if(Hmember((*it)->lhs) && (!Hmember((*it)->rhs))){
			add.push_back((*it)->rhs);
			count++;
		}
	}
	Hypothesis.insert(Hypothesis.end() , add.begin() , add.end());
	return count;
}



int prover::Axiom1closure() {
   int count = 0;
   
   vector<formula*>:: iterator itrI = Introductory_formulae.begin();
   vector<formula*>:: iterator itrH = Hypothesis.begin();
   vector<formula*> add;
   for(; itrH!=Hypothesis.end(); itrH++) {
       formula* hyp = *itrH;                                    //hyp is A from Hypothesis
       for(; itrI!=Introductory_formulae.end(); itrI++) {
           if((*itrI)->leaf) continue;
           formula* toBeIntroduced = *itrI;                     //toBeIntroduced is B from Introductory_formulae
           formula* f1 = implication(toBeIntroduced,hyp);       //f1 is (B -> A)
           formula* f2 = implication(hyp,toBeIntroduced);       //f2 is (A -> B)
           formula* checkH = implication(hyp,f1);               //checkH is (A -> (B -> A))
           formula* checkI = implication(toBeIntroduced,f2);    //checkI is (B -> (A -> B))
           if(!Hmember(checkH)) {
               add.push_back(checkH);
               count++;
           }
           if(!Hmember(checkI)) {
               add.push_back(checkI);
               count++;
           }
       }
   }
   Hypothesis.insert(Hypothesis.end() , add.begin() , add.end());
   return count;
}

int prover::Axiom2closure() {
    int count=0;

    vector<formula*>:: iterator itrI = Introductory_formulae.begin();
    vector<formula*>:: iterator itrH = Hypothesis.begin();
}


int prover::Axiom3closure() {
    int count=0;
	//Fromula F
    F = new formula;
	F->leaf = true;
	F->val = 'F';
	F->False = true;
	F->length = 1;

    vector<formula*>:: iterator itrI = Introductory_formulae.begin();
    vector<formula*>:: iterator itrH = Hypothesis.begin();
	vector<formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
        formula* hyp = *itrH;                                //hyp is A from Hypothesis
        if(hyp->leaf) continue;
        formula* f1 = implication(hyp,F);                    //f1 is (A -> F)
        formula* f2 = implication(f1,F);                     //f2 is ((A -> F) -> F)
        formula* checkH = implication(f2,hyp);               //checkH is (((A -> F) -> F) -> A)
        if(!Hmember(checkH)) {
			add.push_back(checkH);
            count++;
        }
    }
    
    for(; itrI!=Introductory_formulae.end(); itrI++) {
        formula* Intr = *itrI;                               //hyp is B from Introductory_formulae
        if(Intr->leaf) continue;
        formula* f3 = implication(Intr,F);                   //f3 is (B -> F)
        formula* f4 = implication(f3,F);                     //f4 is ((B -> F) -> F)
        formula* checkI = implication(f4,Intr);              //checkI is (((B -> F) -> F) -> B)
        if(!Hmember(checkI)) {
            add.push_back(checkI);
            count++;
        }
    }
    Hypothesis.insert(Hypothesis.end() , add.begin() , add.end());
    return count;
}
	
	
	
	
	










