#include <iostream>
#include "formula.h"

#include "prover.h"

using namespace std;

formula* F; //global variable for False


int main(){

/* Initialize F */	
	F = new formula;
	F->leaf = true;
	F->val = 'F';
	F->False = true;
	F->length = 1;
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
    
    cout<<*p1;
    formula *dest = new formula;
    cin>>*dest;
    cout<<"Destination formula is "<<*dest<<endl;
    cout<<*p1<<endl;
    
	p1->step();
	p1->printH(cout);
	cout<<"came here: "<<endl;
	cout<<"Found  = "<<p1->Hmember(dest)<<endl;
	
	cout<<"--------------------------------------------"<<endl;
//	cout<<*p1<<endl;

	return 0;
}
