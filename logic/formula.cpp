#include "formula.h"



formula *implication(formula *A , formula *B){
	
	formula *ret = new formula;
	ret->val = '-';
	ret->leaf = false;
	ret->lhs = A;
	ret->rhs = B;
	return ret;
}



formula *Axiom1(formula *A , formula *B){

	return implication(A , implication(B , A));
}



formula *Axiom2(formula *A , formula *B , formula *C){
	
	return implication(implication(A , implication(B , C)) , implication(implication(A , B) , implication(A , C)));
}



formula *Axiom3(formula *A){
	
	return implication(implication(implication(A , F) ,F) , A);
}
