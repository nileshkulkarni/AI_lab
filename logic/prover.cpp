#include "prover.h"
//#include "formula.h"

inline int next(int i){
	return i+1;
}


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

prover::prover(int nH_ , int nI_ , map<string, formula*> H, map<string, formula*> I) {
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
		tH->inputInfix(in);
		cout<<*tH<<endl;
		cout<<" : is the Input formula"<<endl;
		Hypothesis.insert(pair<string,formula*>(tH->stringify(),tH));
	}
	
	for(int i=0;i<nI;i++){
		formula *tI = new formula;
		tI->inputInfix(in);
		Introductory_formulae.insert(pair<string,formula*>(tI->stringify(),tI));
	}
}


void prover::printH(ostream &out){
    map<string , formula*>:: iterator iH = Hypothesis.begin();
    out<<"Printing Hypothesis vector..\n";
    for(; iH!=Hypothesis.end(); iH++) {
        (iH->second)->print(out);
        out<<endl;
    }
}


void prover::printI(ostream &out){
    map<string , formula*>:: iterator iH = Introductory_formulae.begin();
    out<<"Printing Introductory vector..\n";
    for(; iH!=Introductory_formulae.end(); iH++) {
        (iH->second)->print(out);
        out<<endl;
    }
}


bool prover::Hmember(formula *f){
	
	assert(f!=NULL);
    return (Hypothesis.find(f->stringify()) != Hypothesis.end());
}

int prover::computeMaxFormulalength() {
	int maxL=-1;
	map<string , formula*>:: iterator iH = Hypothesis.begin();
	for(; iH!=Hypothesis.end();iH++) {
		maxL=max(maxL, (iH->second)->length);
	}
	return maxL;	
}


int prover::MPclosure(){
	
	int totalCount;
	int count;
    map<string, formula*>:: iterator it;
	totalCount = 0;
    count = 1; //some non-zero number
    while(count > 0){
		count=0;
		map<string, formula*> add;
		for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
			formula *itf = it->second;
			assert(itf!=NULL);
			if(itf->leaf) continue;
			if(Hmember(itf->lhs) && (!Hmember(itf->rhs))){
				//cout<<"here : "<<*(itf)<<" : "<<*(itf->lhs)<<endl;
				add.insert(pair<string,formula*>(itf->rhs->stringify() , itf->rhs));
				count++;
			}
		}
		totalCount += count;
		Hypothesis.insert(add.begin() , add.end());
		//printH(cout);
    }		
	return totalCount;
}



int prover::Axiom1closure() {
	int count=0;   
 
    map<string, formula*>:: iterator itrH[2];
    map<string, formula*>:: iterator itrHstart[2];
    map<string, formula*>:: iterator itrHend[2];
    
    map<string, formula*> add;
    int iteration = 0;
    while(iteration < (1<<2)){
		
		cout<<iteration<<endl;
		for(int i=0;i<2;i++){
			itrHstart[i] = getbit(iteration , i)? Hypothesis.begin() : Introductory_formulae.begin();	
			itrHend[i] = getbit(iteration , i)? Hypothesis.end() : Introductory_formulae.end();	
		}
		
		for(itrH[0] = itrHstart[0]; itrH[0]!=itrHend[0]; itrH[0]++) {
			for(itrH[1] = itrHstart[1]; itrH[1]!=itrHend[1]; itrH[1]++) {
					formula *f6 = Axiom1(itrH[0]->second , itrH[1]->second);
					if(!Hmember(f6) && (f6->length <= maxAllowedLength)) {
						add.insert(pair<string, formula*>(f6->stringify() , f6));
						count++;
					}
					else
						destroyAxiom1(f6);
				}
			}
			
	iteration++;
	}
	
	
//	cout<<"add.size :"<<add.size()<<endl;
	Hypothesis.insert(add.begin() , add.end());
	return count;
}




int prover::Axiom2closure() {
    int count=0;   
 
    map<string, formula*>::  iterator itrH[3];
    map<string, formula*>::  iterator itrHstart[3];
    map<string, formula*>::  iterator itrHend[3];
    
    map<string, formula*> add;
    int iteration = 0;
    while(iteration < (1<<3)){
		
		//cout<<iteration<<endl;
		for(int i=0;i<3;i++){
			itrHstart[i] = getbit(iteration , i)? Hypothesis.begin() : Introductory_formulae.begin();	
			itrHend[i] = getbit(iteration , i)? Hypothesis.end() : Introductory_formulae.end();	
		}
		
		int t=0;
		for(itrH[0] = itrHstart[0]; itrH[0]!=itrHend[0]; itrH[0]++) {
			for(itrH[1] = itrHstart[1]; itrH[1]!=itrHend[1]; itrH[1]++) {
				for(itrH[2] = itrHstart[2]; itrH[2]!=itrHend[2]; itrH[2]++) {
					//cout<<"comes here: "<<iteration<<" : "<<t++<<" : "<<Hypothesis.size()<<endl;
					formula *f6 = Axiom2(itrH[0]->second , itrH[1]->second , itrH[2]->second);
					if(!Hmember(f6) && (f6->length <= maxAllowedLength)) {
						add.insert(pair<string, formula*>(f6->stringify() , f6));
						count++;
					} 
					else destroyAxiom2(f6);
				}
			}
		}	
			
	iteration++;
	}
	
	Hypothesis.insert(add.begin() , add.end());
	return count;
}


int prover::Axiom3closure() {

    int count=0;

    map<string, formula*>:: iterator itrI = Introductory_formulae.begin();
    map<string, formula*>:: iterator itrH = Hypothesis.begin();
	map<string, formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
        formula* hyp = itrH->second;                                //hyp is A from Hypothesis
        formula* checkH = Axiom3(hyp);               //checkH is (((A -> F) -> F) -> A)
        if(!Hmember(checkH) && (checkH->length <= maxAllowedLength)) {
			add.insert(pair<string, formula*>(checkH->stringify(), checkH));
            count++;
        }
        else
			destroyAxiom3(checkH);
        
    }
    
    for(; itrI!=Introductory_formulae.end(); itrI++) {
        formula* Intr = itrI->second;                               //hyp is B from Introductory_formulae
        formula* checkI = Axiom3(Intr);              //checkI is (((B -> F) -> F) -> B)
        if(!Hmember(checkI) && (checkI->length <= maxAllowedLength)) {
            add.insert(pair<string, formula*>(checkI->stringify(), checkI));
            count++;
        }
        else
			destroyAxiom3(checkI);
    }
    
    Hypothesis.insert(add.begin() , add.end());
    return count;
}


void prover::cutDownAxiom3(){
	map<string, formula*>:: iterator itrH = Hypothesis.begin();
	map<string, formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
		Axiom3Form(itrH->second);
		if(Axiom3Form(itrH->second)){
			formula *f = implication(itrH->second , ((itrH->second)->lhs)->lhs);
			add.insert(pair<string, formula*>(f->stringify(), f));
		}
	}
   Hypothesis.insert(add.begin(), add.end());	
}

	
	
	
void prover::step(){
	
	maxAllowedLength = computeMaxFormulalength() + 1;
	for(int i=0; i<8;i++){
		Axiom1closure();
		//Axiom2closure();
		//Axiom3closure();
		cutDownAxiom3();
		MPclosure();
		cout<<"mAL is : "<<maxAllowedLength<<endl;
		cout<<"Size of Hypothesis : "<<Hypothesis.size()<<endl;
		maxAllowedLength = next(maxAllowedLength);
	}
	
	cout<<*this<<endl;
	cout<<"Size of Hypothesis : "<<Hypothesis.size()<<endl;

}	
	
	










