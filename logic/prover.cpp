#include "prover.h"
//#include "formula.h"
#define AST_NODE_SPACE "               "



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



bool comp_tr(pair<int,pair<string, formula*> > v1, pair<int,pair<string,formula*> > v2) {
		return (v1.first > v2.first);
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




void prover::input(istream &in){
	
	for(int i=0;i<nH;i++){
		formula *tH = new formula;
		tH->inputInfix(in);
		Hypothesis.insert(pair<string,formula*>(tH->s,tH));
	}
	
	for(int i=0;i<nI;i++){
		formula *tI = new formula;
		tI->inputInfix(in);
		Introductory_formulae.insert(pair<string,formula*>(tI->s,tI));
	}

   destination = new formula;
   destination->inputInfix(in);
   destination_orig = destination;		
   
   while(destination->leaf == false){
	   assert(destination->lhs && destination->rhs);
	   Hypothesis.insert(pair<string,formula*>(destination->lhs->s , destination->lhs));
	   /**Dummy trace to terminate trace back**/ 
	   string s="DT";
	   setTrace(destination->lhs,NULL,NULL,s);
	   destination = destination->rhs;
   }
   
   if(destination->val != 'F'){
	   formula *t = implication(destination , F);
	   Hypothesis.insert(pair<string,formula*>(t->s, t));
	   /**Dummy trace to terminate trace back**/
	   string s="DT";
	   setTrace(t,NULL,NULL,s);
	   destination = F;
	}
   
}


void prover::printH(ostream &out){
    unordered_map<string , formula*>:: iterator iH = Hypothesis.begin();
    out<<"Printing Hypothesis vector..\n";
    for(; iH!=Hypothesis.end(); iH++) {
        (iH->second)->print(out);
        out<<endl;
    }
}


void prover::printI(ostream &out){
    unordered_map<string , formula*>:: iterator iH = Introductory_formulae.begin();
    out<<"Printing Introductory vector..\n";
    for(; iH!=Introductory_formulae.end(); iH++) {
        (iH->second)->print(out);
        out<<endl;
    }
}



bool prover::check(){
	
	return(Hmember(destination));
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
		cout<<"comes here "<<*self<<endl;
	}
	
	string st = self->s;
	pair<string, trace> p;
	p.first = st;
	p.second = tr;
	traceMap.insert(p);
}
				
void prover:: fillTraceVec(formula* f,int entry, string msg) {
	cout<<"Entry: "<<entry<<" Msg: "<<msg<<endl;
	pair<int, pair<string, formula*> > p1;
	p1.first=entry;
	cout<<"bp 1"<<endl;
	pair<string, formula*> p;
	cout<<"bp 2"<<endl;
	p.first=msg;
	cout<<"bp 2.33"<<endl;
	p.second=f;
	cout<<"bp 2.66"<<endl;
	p1.second=p;
	cout<<"bp 3"<<endl;
	traceVec.push_back(p1);
	
	unordered_map<string,trace>::const_iterator it = traceMap.find(f->s);
	cout<<"**********************************"<<endl;
	//f->print(cout);
	if(it==traceMap.end()) {
	//	assert(f->leaf);
		return;
	//	cout<<" "<<Hmember(f)<<" "<<"Not found"<<endl;
	}
	else {
		trace tr = it->second;
		bool terminate = (tr.axiom_used == "DT");
		string m="";
		cout<<"terminate is :"<<terminate<<endl;
		if(terminate) return;
			if(tr.axiom_used == "A1") {
				m = "A1";
				formula* f1 = f->lhs;
				formula* f2 = (f->rhs)->lhs;
				cout<<"ENDED1"<<endl;
				fillTraceVec(f1,entry+1,m);
				cout<<"ENDED1.2"<<endl;
				fillTraceVec(f2,entry+2,m);
			}
			
			else if(tr.axiom_used == "A2") {
				m = "A2";
				//cout<<"A2222222222"<<endl;
				formula* f1 = (f->lhs)->lhs;
				formula* f2 = ((f->lhs)->rhs)->lhs;
				formula* f3 = ((f->lhs)->rhs)->rhs;
				//cout<<*f2<<"lkdjsfkljdsflkjskdlfjkldsjfkl"<<endl;
				cout<<"ENDED2"<<endl;
				fillTraceVec(f1,entry+1,m);
				//assert(f2==NULL);
				fillTraceVec(f2,entry+2,m);
				fillTraceVec(f3,entry+3,m);
			}
			
			else if(tr.axiom_used == "A3") {
				m = "A3";
				formula* f1 = ((f->lhs)->lhs)->lhs;
				cout<<"ENDED3"<<endl;
				fillTraceVec(f1,entry+1,m);
			}
			
			else if(tr.axiom_used == "MP") {
				m = "MP";
				formula* f_1 = tr.f1;
				formula* f_2 = tr.f2;
				//assert(f_2==NULL);
				cout<<"ENDED4"<<endl;
				fillTraceVec(f_1,entry+1,m);
				cout<<"ENDED5"<<endl;
				fillTraceVec(f_2,entry+2,m);
			}
			
			else {}
	
	}
					
}


void prover::printTraceVec() {
	int index=0;
	while(index!=traceVec.size()-2) {
		string msg = (traceVec[index].second).first;
		if(msg.compare("Destination found!") == 0) break;
		formula* f = (traceVec[index].second).second;
		if(msg == "A1") {
			formula* f2 = (traceVec[index+1].second).second;
			cout<<"Applying axiom-1 on : ";
			cout<<*f<<" and "<<*f2<<endl;
			index+=2;
		}
		
		else if(msg == "A2") {
			formula* f2 = (traceVec[index+1].second).second;
			formula* f3 = (traceVec[index+2].second).second;
			cout<<"Applying axiom-2 on : ";
			cout<<*f<<" , "<<*f2<<" and "<<*f3<<endl;
			index+=3;
		}
		
		else if(msg == "A3") {
			cout<<"Applying axiom-3 on : ";
			cout<<*f;
			index+=1;
		}
		
		else if(msg == "MP") {
			formula* f2 = (traceVec[index+1].second).second;
			cout<<"Applying Modus ponens on : ";
			cout<<*f<<" and "<<*f2<<" --------->   "<<endl;
			index+=2;
		}
	}
	formula* dest = (traceVec[index].second).second;
	cout<<*dest<<endl;
	cout<<"Proved!"<<endl; 
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
				if(itf->rhs->leaf)
					cout<<"In MP closure : "<<*(itf->rhs)<<endl;
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
				/******************For tracing back*****************/
				string s = "A2";
				if(t->leaf){
				cout<<endl;
				cout<<"In A2 finish: "<<t->s<<endl;
				cout<<endl;
			   }
				setTrace(t,NULL,NULL,s);
				/****************************************************/
				count++;
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
						/******************For tracing back*****************/
						string s="A2";
						if(f6->leaf){
						cout<<endl;
						cout<<"In A2: "<<f6->s<<endl;
						cout<<endl;
					  }
						setTrace(f6,NULL,NULL,s);
						/****************************************************/
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

    unordered_map<string, formula*>:: iterator itrI = Introductory_formulae.begin();
    unordered_map<string, formula*>:: iterator itrH = Hypothesis.begin();
	unordered_map<string, formula*> add; 
    for(; itrH!=Hypothesis.end(); itrH++) {
        formula* hyp = itrH->second;                                //hyp is A from Hypothesis
        formula* checkH = Axiom3(hyp);               //checkH is (((A -> F) -> F) -> A)
        if(!Hmember(checkH) && (checkH->length <= maxAllowedLength)) {
			add.insert(pair<string, formula*>(checkH->s, checkH));
			/******************For tracing back*****************/
			string s="A3";
			cout<<endl;
			cout<<"In A3: "<<checkH->s<<endl;
			cout<<endl;
			setTrace(checkH,NULL,NULL,s);
			/****************************************************/
            count++;
        }
        else
			destroyAxiom3(checkH);
        
    }
    
    for(; itrI!=Introductory_formulae.end(); itrI++) {
        formula* Intr = itrI->second;                               //hyp is B from Introductory_formulae
        formula* checkI = Axiom3(Intr);              //checkI is (((B -> F) -> F) -> B)
        if(!Hmember(checkI) && (checkI->length <= maxAllowedLength)) {
            add.insert(pair<string, formula*>(checkI->s, checkI));
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
			formula *f = Axiom3(itrH->second->lhs->lhs);
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

	
	
	
void prover::step(){
	
	maxAllowedLength = computeMaxFormulalength() + 1;
	for(int i=0; i<50;i++){
		
		int old_size = Hypothesis.size();
		cutDownAxiom3();
		Axiom2finish();
		
		if(i%2){
			Axiom1closure();
		}//Axiom2closure();
		//Axiom3closure();
		
		if(!(i%2)){
			MPclosure();
		}
		cout<<"mAL is : "<<maxAllowedLength<<endl;
		cout<<"Size of Hypothesis: "<<Hypothesis.size()<<endl;
		if(Hypothesis.size() == old_size)
			maxAllowedLength = next(maxAllowedLength);
		if(check()){
			cout<<"Mil gya"<<endl;
			fillTraceVec(destination,1,"Destination found!");
			//sort(traceVec.begin(), traceVec.end(),comp_tr);
			cout<<"****************************************Printing Trace*******************************************"<<endl;
			//printTraceVec();
			cout<<"##################################################################################################"<<endl;
			break;
		}
	}
	
	//cout<<*this<<endl;
	cout<<"Size of Hypothesis : "<<Hypothesis.size()<<endl;
}	
	
	










