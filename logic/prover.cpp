#include "prover.h"
//#include "formula.h"


inline int getbit(int n , int bit){ //bit is 0 indexed
	return (n>>bit)%2;
}


bool member(formula *f , vector<formula*>::iterator start , vector<formula*>::iterator end){
	while(start!=end){
		if(*(*start)==*f) return true;
		start++;
	}
	return false;
}



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

void prover::printH(ostream &out){
    vector<formula*>:: iterator iH = Hypothesis.begin();
    out<<"Printing Hypothesis vector..\n";
    for(; iH!=Hypothesis.end(); iH++) {
        (*iH)->print(out);
        out<<endl;
    }
}


void prover::printI(ostream &out){
    vector<formula*>:: iterator iH = Introductory_formulae.begin();
    out<<"Printing Introductory vector..\n";
    for(; iH!=Introductory_formulae.end(); iH++) {
        (*iH)->print(out);
        out<<endl;
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
	
	int totalCount;
	int count;
    vector<formula*>:: iterator it;
	totalCount = 0;
    count = 1; //some non-zero number
    while(count > 0){
		count=0;
		vector<formula*> add;
		for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
			assert(*it!=NULL);
			if(((*it)->leaf)) continue;
			if(Hmember((*it)->lhs) && (!Hmember((*it)->rhs))){
				//cout<<"here : "<<*(*it)<<endl;
				add.push_back((*it)->rhs);
				count++;
			}
		}
		totalCount += count;
		Hypothesis.insert(Hypothesis.end() , add.begin() , add.end());
    }		
	return totalCount;
}


/*
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
           formula* checkH = Axiom1(hyp , toBeIntroduced);              //checkH is (A -> (B -> A))
           formula* checkI = Axiom1(toBeIntroduced, hyp);    //checkI is (B -> (A -> B))
           
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
*/


int prover::Axiom1closure() {
	int count=0;   
 
    vector<formula*>:: iterator itrH[2];
    vector<formula*>:: iterator itrHstart[2];
    vector<formula*>:: iterator itrHend[2];
    
    vector<formula*> add;
    int iteration = 0;
    while(iteration < (1<<2)){
		
		cout<<iteration<<endl;
		for(int i=0;i<2;i++){
			itrHstart[i] = getbit(iteration , i)? Hypothesis.begin() : Introductory_formulae.begin();	
			itrHend[i] = getbit(iteration , i)? Hypothesis.end() : Introductory_formulae.end();	
		}
		
		for(itrH[0] = itrHstart[0]; itrH[0]!=itrHend[0]; itrH[0]++) {
			for(itrH[1] = itrHstart[1]; itrH[1]!=itrHend[1]; itrH[1]++) {
					formula *f6 = Axiom1(*itrH[0] , *itrH[1]);
					if(!Hmember(f6) && !member(f6 , add.begin() , add.end())) {
						add.push_back(f6);
						count++;
					} 
				}
			}
			
	iteration++;
	}
	
	Hypothesis.insert(Hypothesis.end() , add.begin() , add.end());
	return count;
}




int prover::Axiom2closure() {
    int count=0;   
 
    vector<formula*>:: iterator itrH[3];
    vector<formula*>:: iterator itrHstart[3];
    vector<formula*>:: iterator itrHend[3];
    
    vector<formula*> add;
    int iteration = 0;
    while(iteration < (1<<3)){
		
		//cout<<iteration<<endl;
		for(int i=0;i<3;i++){
			//cout<<" : "<<getbit(iteration , i)<<endl;
			itrHstart[i] = getbit(iteration , i)? Hypothesis.begin() : Introductory_formulae.begin();	
			itrHend[i] = getbit(iteration , i)? Hypothesis.end() : Introductory_formulae.end();	
		}
		
		int t=0;
		for(itrH[0] = itrHstart[0]; itrH[0]!=itrHend[0]; itrH[0]++) {
			for(itrH[1] = itrHstart[1]; itrH[1]!=itrHend[1]; itrH[1]++) {
				for(itrH[2] = itrHstart[2]; itrH[2]!=itrHend[2]; itrH[2]++) {
					cout<<"comes here: "<<iteration<<" : "<<t++<<" : "<<Introductory_formulae.size()<<endl;
					formula *f6 = Axiom2(*itrH[0] , *itrH[1] , *itrH[2]);
					if(!Hmember(f6) && !member(f6 , add.begin() , add.end())) {
						add.push_back(f6);
						count++;
					} 
					else destroy(f6);
				}
			}
		}	
			
	iteration++;
	}
	
	Hypothesis.insert(Hypothesis.begin() , add.begin() , add.end());
	return count;
}


int prover::Axiom3closure() {

    int count=0;

    vector<formula*>:: iterator itrI = Introductory_formulae.begin();
    vector<formula*>:: iterator itrH = Hypothesis.begin();
	vector<formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
        formula* hyp = *itrH;                                //hyp is A from Hypothesis
        formula* checkH = Axiom3(hyp);               //checkH is (((A -> F) -> F) -> A)
        if(!Hmember(checkH) && !member(checkH , add.begin() , add.end())) {
			add.push_back(checkH);
            count++;
        }
    }
    
    for(; itrI!=Introductory_formulae.end(); itrI++) {
        formula* Intr = *itrI;                               //hyp is B from Introductory_formulae
        formula* checkI = Axiom3(Intr);              //checkI is (((B -> F) -> F) -> B)
        if(!Hmember(checkI) && !member(checkI , add.begin() , add.end())) {
            add.push_back(checkI);
            count++;
        }
    }
    
    Hypothesis.insert(Hypothesis.end() , add.begin() , add.end());
    return count;
}
	
	
	
	
	










