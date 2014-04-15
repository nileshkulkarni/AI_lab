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



prover::prover(){
}



prover::prover(int nH_ , int nI_){

	nH = nH_;
	nI = nI_;
}

prover::prover(int nH_ , int nI_ , unordered_map<string, formula*> H, unordered_map<string, formula*> I) {
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


bool comp_tr(pair<int,pair<string, formula*> > v1, pair<int,pair<string,formula*> > v2) {
		return (v1.first > v2.first);
}	



void prover::input(istream &in){
	
	for(int i=0;i<nH;i++){
		formula *tH = new formula;
		tH->inputInfix(in);
		Hypothesis.insert(pair<string,formula*>(tH->s,tH));
		/**Dummy trace to terminate trace back**/ 
	   //cout<<"comes here"<<endl;
		originalHypothesis.insert(pair<string,formula*>(tH->s,tH));
	}
	
	for(int i=0;i<nI;i++){
		formula *tI = new formula;
		tI->inputInfix(in);
		Introductory_formulae.insert(pair<string,formula*>(tI->s,tI));
		
	}

  setDummyTrace();

   destination = new formula;
   destination->inputInfix(in);		
   originalDestination = destination;	
   simpilifyDestination();
   
}



void prover::setDummyTrace(){
	
	unordered_map<string , formula*>:: iterator iH = Hypothesis.begin();
    for(; iH!=Hypothesis.end(); iH++) {
    /**Dummy trace to terminate trace back**/ 
	   string s="DT";
	   setTrace(iH->second,NULL,NULL,s);
	}
}


void prover::printH(ostream &out){
	indentedPrintH(out , 0);
}


void prover::printOH(ostream &out){
	indentedPrintOH(out , 0);
}



void prover::printI(ostream &out){
	indentedPrintI(out , 0);
}	



void prover::indentedPrintH(ostream &out , int nspaces){
    unordered_map<string , formula*>:: iterator iH = Hypothesis.begin();
    for(int i=0;i<nspaces;i++) out<<" ";
	out<<"Printing Hypothesis vector..\n";
    for(; iH!=Hypothesis.end(); iH++) {
        for(int i=0;i<nspaces;i++) out<<" ";
		(iH->second)->print(out);
        out<<endl;
    }
}



void prover::indentedPrintOH(ostream &out , int nspaces){
    unordered_map<string , formula*>:: iterator iH = originalHypothesis.begin();
    for(int i=0;i<nspaces;i++) out<<" ";
	out<<"Printing Original Hypothesis vector..\n";
    for(; iH!=originalHypothesis.end(); iH++) {
        for(int i=0;i<nspaces;i++) out<<" ";
		(iH->second)->print(out);
        out<<endl;
    }
}




void prover::indentedPrintI(ostream &out , int nspaces){
    unordered_map<string , formula*>:: iterator iH = Introductory_formulae.begin();
    for(int i=0;i<nspaces;i++) out<<" ";
    out<<"Printing Introductory vector..\n";
    for(; iH!=Introductory_formulae.end(); iH++) {
        for(int i=0;i<nspaces;i++) out<<" ";
        (iH->second)->print(out);
        out<<endl;
    }
}


bool prover::check(){
	
	return(Hmember(destination));
}


bool prover::checkUseful(formula *t){
	assert(destination->val == 'F');
	//cout<<"t is "<<*t<<" t->leaf "<<t->leaf<<endl;
	formula *temp = t;
	while(t->leaf == false){ 
		t = t->rhs;
	}
	if((t->val == 'F') && !(temp->leaf)) return (!temp->lhs->leaf && !Hmember(temp->lhs));
	return false;
}

/***************************************Trace******************************************/

void prover:: setTrace(formula* self, formula* MP_1, formula* MP_2, string axiom) {
	assert(self!=NULL);
	trace tr;
	tr.self = self;
	tr.axiom_used=axiom;
	tr.f1=MP_1;
	tr.f2=MP_2;
	if(self->leaf){
		//cout<<"comes here "<<*self<<endl;
	}
	string st = self->s;
	pair<string, trace> p;
	tr.done = false;
	p.first = st;
	p.second = tr;
	traceMap.insert(p);
}


void prover:: fillTraceVec(formula* f) {
	
	queue<trace> cloud;
	unordered_map<string,trace>::const_iterator it = traceMap.find(f->s);
	assert(it!=traceMap.end());
	cloud.push(it->second);
	
	while(!cloud.empty()){
		trace tempTr = cloud.front();
		cloud.pop();
		bool terminate = (tempTr.axiom_used == "DT");
		if(tempTr.done) continue;
		
		tempTr.done = true;
		traceVec1.push_back(tempTr);
		formula *f = tempTr.self;
		
		if(terminate) continue;
		if(tempTr.axiom_used == "A1") {
			formula* f1 = f->lhs;
			formula* f2 = (f->rhs)->lhs;
			cloud.push(traceMap.find(f1->s)->second);
			cloud.push(traceMap.find(f2->s)->second);
		}
		
		else if(tempTr.axiom_used == "A2") {
			formula* f1 = (f->lhs)->lhs;
			formula* f2 = ((f->lhs)->rhs)->lhs;
			formula* f3 = ((f->lhs)->rhs)->rhs;
			cloud.push(traceMap.find(f1->s)->second);
			cloud.push(traceMap.find(f2->s)->second);
			cloud.push(traceMap.find(f3->s)->second);
		}
		
		else if(tempTr.axiom_used == "A3") {
			formula* f1 = ((f->lhs)->lhs)->lhs;
			cloud.push(traceMap.find(f1->s)->second);
		}
		
		else if(tempTr.axiom_used == "MP") {
			formula* f_1 = tempTr.f1;
			formula* f_2 = tempTr.f2;
			cloud.push(traceMap.find(f_1->s)->second);
			cloud.push(traceMap.find(f_2->s)->second);
		}
		else {
			}
	}
}



void prover::printTraceVec(int nspace){
	
	vector<trace>::reverse_iterator it;
	for(it = traceVec1.rbegin() ; it != traceVec1.rend() ; it++){ 
		trace t = (*it);
		if(t.axiom_used == "MP"){	
					for(int i=0; i<nspace; i++) cout<<" ";
					cout<<"Applying Modus ponens on : ";
					cout<<*t.f2<<" and "<<*t.f1<<" --------->   "<<*t.self<<endl;
				}
		else if(t.axiom_used== "A3"){
					for(int i=0; i<nspace; i++) cout<<" ";
					cout<<"Applying axiom-3 on : ";
					cout<<*t.self;
				}
		
		else if(t.axiom_used== "DT"){
					for(int i=0; i<nspace; i++) cout<<" ";
					cout<<"Hypothesis : ";
					cout<<*t.self<<endl;
				}
		else{
					 cout<<"should not come here"<<endl;
					 exit(0);			
		}
	}
}

/***************************************************************************************/


bool prover::Hmember(formula *f){
	
	assert(f!=NULL);
    return (Hypothesis.find(f->s) != Hypothesis.end());
}

int prover::computeMaxFormulalength() {
	int maxL=-1;
	unordered_map<string , formula*>:: iterator iH = Hypothesis.begin();
	for(; iH!=Hypothesis.end();iH++) {
		maxL=max(maxL, (iH->second)->length);
	}
	return maxL;	
}




void prover::simpilifyDestination(){
	
	//cout<<"Destination Is "<<*destination<<endl;
	while(!destination->leaf){
	   assert(destination->lhs && destination->rhs);
	   Hypothesis.insert(pair<string,formula*>(destination->lhs->s , destination->lhs));
	   originalHypothesis.insert(pair<string,formula*>(destination->lhs->s , destination->lhs));
	   destination = destination->rhs;
	}

	if(destination->val != 'F'){
	   formula *t = implication(destination , F);
	   Hypothesis.insert(pair<string,formula*>(t->s, t));
	   originalHypothesis.insert(pair<string,formula*>(t->s, t));
	   destination = F;
	}
	
   originalDestination = F;
}



int prover::simplify(){
	
		int flag,count;
		flag = 1;
		count = 0;
		unordered_map<string, formula*>:: iterator it;
		while(flag == 1){
			flag=0;
			for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
				formula *itf = it->second;
				if(!(itf->leaf) && (itf->rhs->val == 'F') && (!itf->lhs->leaf)){
					cout<<*itf<<endl;
					Hypothesis.erase(itf->s);
					destination = itf->lhs;
					simpilifyDestination();
					flag = 1;
					count++;
					break;
				}
			}	
		}
	 return count;	
}



int prover::MPclosure(){
	
	int totalCount;
	int count;
    unordered_map<string, formula*>:: iterator it;
	totalCount = 0;
    count = 1; //some non-zero number
   	
    while(count > 0){
		count=0;
		unordered_map<string, formula*> add;
		for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
			formula *itf = it->second;
			assert(itf!=NULL);
			if(itf->leaf) continue;
			if(Hmember(itf->lhs) && (!Hmember(itf->rhs))){
				//cout<<"here : "<<*(itf)<<" : "<<*(itf->lhs)<<endl;
				add.insert(pair<string,formula*>(itf->rhs->s , itf->rhs));
				/******************For tracing back*****************/
				string s = "MP";
				/*cout<<endl;
				cout<<"In MP : "<<itf->rhs->s<<" "<<itf->s<<endl;
				cout<<endl;*/
				setTrace(itf->rhs,itf->lhs,itf,s);
				/****************************************************/
				count++;
			}
		}
		totalCount += count;
		Hypothesis.insert(add.begin() , add.end());
	/*	
		printH(cout);
		cout<<"2)^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<" add.size : "<<add.size();
		cout<<" Hypothesis.size() :"<<Hypothesis.size()<<endl;
		for(it = add.begin();it!=add.end();it++)
			cout<<*(it->second)<<endl;
		
		cout<<"-----------------------------"<<endl;
    */
    }		
	return totalCount;
}



int prover::Axiom1closure() {
	int count=0;   
 
    unordered_map<string, formula*>:: iterator itrH[2];
    unordered_map<string, formula*>:: iterator itrHstart[2];
    unordered_map<string, formula*>:: iterator itrHend[2];
    
    unordered_map<string, formula*> add;
    int iteration = 0;
    while(iteration < (1<<2)){
		
		//cout<<iteration<<endl;
		for(int i=0;i<2;i++){
			itrHstart[i] = getbit(iteration , i)? Hypothesis.begin() : Introductory_formulae.begin();	
			itrHend[i] = getbit(iteration , i)? Hypothesis.end() : Introductory_formulae.end();	
		}
		
		for(itrH[0] = itrHstart[0]; itrH[0]!=itrHend[0]; itrH[0]++) {
			if(2*(itrH[0]->second)->length > maxAllowedLength)
				continue;
			for(itrH[1] = itrHstart[1]; itrH[1]!=itrHend[1]; itrH[1]++) {
					formula *f6 = Axiom1(itrH[0]->second , itrH[1]->second);
					if(!Hmember(f6) && (f6->length <= maxAllowedLength)) {
						add.insert(pair<string, formula*>(f6->s , f6));
						count++;
						/******************For tracing back*****************/
						string s = "A1";
						if(f6->leaf){
						cout<<endl;
						cout<<"In A1 : "<<f6->s<<endl;
						cout<<endl;
						}
						setTrace(f6,NULL,NULL,s);	
						/****************************************************/

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




int prover::Axiom2finish() {
	
	//cout<<"Inside:"<<endl;
	int count = 0;
	unordered_map<string, formula*>::  iterator it;
    unordered_map<string, formula*> add;
    for(it = Hypothesis.begin();it!=Hypothesis.end();it++){
		formula *itf = it->second;
		assert(itf!=NULL);
		//cout<<"here :"<<*itf<<endl;
		if(Axiom2lhsForm(itf)){
			//cout<<"here :"<<endl;
			formula *t = Axiom2(itf->lhs , itf->rhs->lhs , itf->rhs->rhs);
			if(t->length <= maxAllowedLength){
				add.insert(pair<string, formula*>(t->s , t));
				count++;
				/******************For tracing back*****************/
				string s = "A2";
				setTrace(t,NULL,NULL,s);
				/****************************************************/

			}
			else
				destroyAxiom2(t);
		}
		//cout<<"cont :"<<endl;	
	}
	//printH(cout);
	//cout<<"add.size :"<<add.size()<<" Hypothesis.size() "<<Hypothesis.size()<<endl;
	Hypothesis.insert(add.begin() , add.end());
	return count;
}



int prover::Axiom2closure() {
    int count=0;   
 
    unordered_map<string, formula*>::  iterator itrH[3];
    unordered_map<string, formula*>::  iterator itrHstart[3];
    unordered_map<string, formula*>::  iterator itrHend[3];
    
    unordered_map<string, formula*> add;
    int iteration = 0;
    while(iteration < (1<<3)){
		
		//cout<<iteration<<endl;
		
		
		for(int i=0;i<3;i++){
			itrHstart[i] = getbit(iteration , i)? Hypothesis.begin() : Introductory_formulae.begin();	
			itrHend[i] = getbit(iteration , i)? Hypothesis.end() : Introductory_formulae.end();	
		}
		
		int t=0;
		for(itrH[0] = itrHstart[0]; itrH[0]!=itrHend[0]; itrH[0]++) {
			if(3*(itrH[0]->second->length) > maxAllowedLength)
				continue;
			for(itrH[1] = itrHstart[1]; itrH[1]!=itrHend[1]; itrH[1]++) {
				if(3*(itrH[0]->second->length) + 2 *(itrH[1]->second->length) > maxAllowedLength)
					continue;
				for(itrH[2] = itrHstart[2]; itrH[2]!=itrHend[2]; itrH[2]++) {
					//cout<<"comes here: "<<iteration<<" : "<<t++<<" : "<<Hypothesis.size()<<endl;
					formula *f6 = Axiom2(itrH[0]->second , itrH[1]->second , itrH[2]->second);
					if(!Hmember(f6) && (f6->length <= maxAllowedLength)) {
						add.insert(pair<string, formula*>(f6->s , f6));
						count++;
						/******************For tracing back*****************/
						string s="A2";
						if(f6->leaf){
						cout<<endl;
						cout<<"In A2: "<<f6->s<<endl;
						cout<<endl;
					  }
						setTrace(f6,NULL,NULL,s);
						/****************************************************/

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

    unordered_map<string, formula*>:: iterator itrI = Introductory_formulae.begin();
    unordered_map<string, formula*>:: iterator itrH = Hypothesis.begin();
	unordered_map<string, formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
        formula* hyp = itrH->second;                                //hyp is A from Hypothesis
        formula* checkH = Axiom3(hyp);               //checkH is (((A -> F) -> F) -> A)
        if(!Hmember(checkH) && (checkH->length <= maxAllowedLength)) {
			add.insert(pair<string, formula*>(checkH->s, checkH));
            count++;
   			/******************For tracing back*****************/
			string s="A3";
			cout<<endl;
			cout<<"In A3: "<<checkH->s<<endl;
			cout<<endl;
			setTrace(checkH,NULL,NULL,s);
			/****************************************************/

        }
        else
			destroyAxiom3(checkH);
        
    }
    
    for(; itrI!=Introductory_formulae.end(); itrI++) {
        formula* Intr = itrI->second;                               //hyp is B from Introductory_formulae
        formula* checkI = Axiom3(Intr);              //checkI is (((B -> F) -> F) -> B)
        if(!Hmember(checkI) && (checkI->length <= maxAllowedLength)) {
            add.insert(pair<string, formula*>(checkI->s, checkI));
            count++;
            /******************For tracing back*****************/
			string s1="A3";
			cout<<endl;
			cout<<"In A3: "<<checkI->s<<endl;
			cout<<endl;
			setTrace(checkI,NULL,NULL,s1);
			/****************************************************/

        }
        else
			destroyAxiom3(checkI);
    }
    
    Hypothesis.insert(add.begin() , add.end());
    return count;
}


void prover::cutDownAxiom3(){
	unordered_map<string, formula*>:: iterator itrH = Hypothesis.begin();
	unordered_map<string, formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
		Axiom3Form(itrH->second);
		if(Axiom3Form(itrH->second)){
			formula *f = implication(itrH->second , ((itrH->second)->lhs)->lhs);
			add.insert(pair<string, formula*>(f->s, f));
			/******************For tracing back*****************/
			string s="A3";
			if(f->leaf){
			cout<<endl;
			cout<<"In cutDown A3: "<<f->s<<endl;
			cout<<endl;
		    }
			setTrace(f,NULL,NULL,s);
			/****************************************************/
			cout<<"This is useful :"<<endl;
		}
	}
   Hypothesis.insert(add.begin(), add.end());	
}

	
	
	
bool prover::step(int nSteps){
	
	//maxAllowedLength = computeMaxFormulalength() + 1;
	maxAllowedLength = 1;
	for(int i=0; i<nSteps;i++){
		int old_size = Hypothesis.size();
		//	cutDownAxiom3();
		//	Axiom2finish();
		if(i%2){
		//	Axiom1closure();
		}
		
		//if(i%3==0)
		//	Axiom2closure();
		//Axiom3closure();
		
		MPclosure();
		
		//cout<<"Size of Hypothesis: "<<Hypothesis.size()<<endl;
		if(Hypothesis.size() == old_size)	
			maxAllowedLength = next(maxAllowedLength);
		if(check()){
			//cout<<"Mil gya"<<endl;
			//break;
			return true;
		}
	}
	
	return false;
}	
	
	

void prover::traceBack(int nspaces){
	
	assert(Hmember(destination));
	for(int i=0; i<nspaces; i++) cout<<" ";
	cout<<"**************************Printing Trace********************"<<endl;
	fillTraceVec(destination);
	//sort(traceVec.begin(), traceVec.end(),comp_tr);
	printTraceVec(nspaces);
	for(int i=0; i<nspaces; i++) cout<<" ";
	cout<<"##############################################################"<<endl;
	
}









