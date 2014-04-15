#include "formula.h"


void destroy(formula *f){
	
	assert(f!=NULL);
	if(!f->leaf){
		delete(f->lhs);
		delete(f->rhs);
	}
	delete(f);
}






void formula::input(istream &in) {

	in>>val;
	leaf = true;
	length = 1;
	if(val == '-'){
		lhs = new formula;
		rhs = new formula;
		lhs->input(in);
		rhs->input(in);
		leaf = false;
		length = lhs->length + rhs->length;
	}
	if(val == 'F')
		False = true;
}



void formula::inputInfix(istream &in){
	
	char a;
	in>>a;
	if(a=='('){
		lhs = new formula;
		lhs->inputInfix(in);
		in>>a;
		assert(a=='-');
		val = '-';
		rhs = new formula;
		rhs->inputInfix(in);
		leaf = false;
		length = lhs->length + rhs->length;
		in>>a;
		assert(a==')');
		return;
	}
	
	//else
	length = 1;
	leaf = true;
	val = a;
	if(val=='F')
		False = true;
}



string formula::stringify(){
	string s;
	s.push_back(val);
	if(leaf == false){
		assert((lhs!=NULL) && (rhs!=NULL));
		s = s + lhs->stringify() + rhs->stringify();
	}
	return s;
}


void formula::print(ostream &out){
	
	if(leaf == true){
		out<<val;
		return;
	}
    out<<"(";
	lhs->print(out);
	out<<val;
	rhs->print(out);
	out<<")";
}

bool equal(formula *A , formula *B){
	
	if(A==NULL && B==NULL) return true;
	if(A==NULL || B==NULL) return false;
	if(A->val == B->val){
		return (equal(A->lhs , B->lhs) && equal(A->rhs , B->rhs));
	}
	return false;
}



bool operator==(const formula A ,const formula B){
	
	if(A.val != B.val) return false;
	bool ret = equal(A.lhs,B.lhs) && equal(A.rhs , B.rhs);
	return ret;
}



formula *implication(formula *A , formula *B){
	
	formula *ret = new formula;
	ret->val = '-';
	ret->leaf = false;
	ret->lhs = A;
	ret->rhs = B;
	ret->length = A->length + B->length;
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
