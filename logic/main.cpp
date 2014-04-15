#include <iostream>
#include "formula.h"
#include "prover.h"
#include "problemTree.h"

using namespace std;

formula* F; //global variable for False


int main(){

/* Initialize F */	
	F = new formula;
	F->leaf = true;
	F->val = 'F';
	F->length = 1;
	F->s = "F";

/*Initialization Done */
	
/*	
	cout<<(*f1==*f2)<<endl;
	
	formula *f3 = Axiom1(f1, f2);
	cout<<*f3<<endl;
	formula *f4 = Axiom3(f3);
	cout<<*f4<<" : "<<f4->length<<endl;
	formula *f5 = implication(f2, f4);
	cout<<*f5<<" : "<<f5->length<<endl;
    */

    formula *ftemp = new formula;
    ftemp->inputInfix(cin);
    cout<<*ftemp<<endl;
    int a,b;
    cin>>a>>b;
    prover *p1 = new prover(a,b);
    cin>>*p1;
    prover *itp;
    
    
    char c=' ';
	while(c!='0'){
		
		itp = new prover();
		*itp = *p1;
		problemTree* pt = new problemTree(itp, 0);
		pt->expand();
		pt->print(cout);
		pt->step();
		cout<<"Found  = "<<pt->result<<endl;
		if(pt->result){
			cout<<"TRACING BACK... "<<endl;
			pt->traceBack();
			break;
		}
		
		else{
			cout<<"NOT FOUND"<<endl;
			cout<<"ENTER HUMAN INPUT:(ENTER Formula (after 1) to Use, 0 for no- "<<endl;
			formula *f = new formula;
			cin>>c;
			if(c=='1'){
				f->inputInfix(cin);
				p1->Hypothesis.insert(pair<string,formula*>(f->s,f));
				p1->originalHypothesis.insert(pair<string,formula*>(f->s,f));
				p1->simpilifyDestination();
				pt->destroy();
			}
		}
	}
	cout<<"--------------------------------------------"<<endl;

	return 0;
}
