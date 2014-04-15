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

    
    int a,b;
    cin>>a>>b;
    prover *p1 = new prover(a,b);
    
    cin>>*p1;
    cout<<*p1<<endl;
    
    
    problemTree* pt = new problemTree(p1, 0);
  
    pt->expand();
    pt->print(cout);
    pt->step();
	cout<<"Found  = "<<pt->result<<endl;
	
	if(pt->result){
		cout<<"TRACING BACK.."<<endl;
		pt->traceBack();
	}
	//p1->step(40);
	//p1->printH(cout);
	
	cout<<"--------------------------------------------"<<endl;
//	cout<<*p1<<endl;

	return 0;
}
