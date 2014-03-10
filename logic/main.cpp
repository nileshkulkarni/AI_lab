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
	
	/*formula *f1 = new formula;
	cin>>*f1;
	formula *f2 = new formula;
	cin>>*f2;
	cout<<*f1<<" : "<<*f2<<endl;
	
	cout<<(*f1==*f2)<<endl;
	
	formula *f3 = Axiom1(f1, f2);
	cout<<*f3<<endl;
	formula *f4 = Axiom3(f3);
	cout<<*f4<<" : "<<f4->length<<endl;
	formula *f5 = implication(f2, f4);
	cout<<*f5<<" : "<<f5->length<<endl;
    */
    vector<formula*> Hypt;
    vector<formula*> Intr;
    prover *p1 = new prover(2,2,Hypt,Intr);
    cin>>*p1;
    cout<<*p1;
    cout<<"here : "<<endl;
	p1->MPclosure();
	p1->Axiom1closure();
	p1->Axiom3closure();
	cout<<*p1;
	return 0;
}
