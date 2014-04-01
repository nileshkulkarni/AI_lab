#include "problemTree.h"



problemTree::problemTree(int _depth){
	depth = _depth;
	nodeInfo = 0;
}


problemTree::problemTree(prover *_p, int _depth){
	p = _p;
	depth = _depth;
	nodeInfo = 0;
}


void problemTree::expand(){
	
	if(depth >= MAXDEPTH) return;
	unordered_map<string, formula*>:: iterator it;
	
//	cout<<endl<<"Printing Parent"<<endl;
//	cout<<*p;
	
	for(it = p->Hypothesis.begin();it != p->Hypothesis.end(); it++){
		formula *t = it->second;
	   //cout<<*t<<" : this is the formula"<<endl;
	    if(p->checkUseful(t)){
			problemTree *child = new problemTree(depth+1);
			child->p = new prover;
			*(child->p) = *p;
			child->p->Hypothesis.erase(t->s);
			child->p->originalHypothesis.erase(t->s);
			child->p->destination = t->lhs;
			child->p->originalDestination = t->lhs;
			child->p->simpilifyDestination();
			child->nodeInfo = 1;
			//cout<<endl<<"Printing child1:"<<endl;
			//cout<<*(child->p)<<endl;
			children.push_back(child);
			if(t->rhs->val != 'F'){
				problemTree *child2 = new problemTree(depth+1);
				child2->p = new prover;
				*(child2->p) = *p;
				child2->p->Hypothesis.erase(t->s);
				child2->p->destination = t->rhs->lhs;
				child2->p->originalHypothesis.erase(t->s);
				child2->p->originalDestination = t->rhs->lhs;
				child2->p->simpilifyDestination();
				child2->nodeInfo = 2;
				children.push_back(child2);
			}
		}
	}
  list<problemTree *>:: iterator cI;
  for(cI = children.begin(); cI!=children.end(); cI++){
			(*cI)->expand();
	  
  }
}
	

void problemTree::print(ostream &out){
	
	for(int i=0; i<WIDTH*depth; i++) out<<" ";
	out<<"PRINTING PROBLEM : "<<endl;
	for(int i=0; i<WIDTH*depth; i++) out<<" ";
	out<<"DESTINATION IS : "<<*(p->originalDestination)<<endl;
	
	p->indentedPrintOH(out , WIDTH * depth);
	//p->indentedPrintI(out , 5*depth);
	list<problemTree *>:: iterator cI;
	for(cI = children.begin(); cI!=children.end(); cI++){
			(*cI)->print(out);
	  
	}
}



void problemTree::step(){
	result = p->step(STEPS);
	if(result){
		return;
	}
	
	list<problemTree *>:: iterator cI;
	for(cI = children.begin(); cI!=children.end(); cI++){
			(*cI)->step();
	}
	cI = children.begin();
	while(cI!=children.end()){
		assert((*cI)->nodeInfo == 1);
		problemTree *pT = *cI;
		cI++; 
		if(pT->result && ((cI == children.end()) || (((*cI)->nodeInfo==2) && ((*cI)->result)))){
			//solution found
			result = true;
			return;
		}
		if((cI!=children.end()) && ((*cI)->nodeInfo==2))
				cI++;
	}
	result = false;
}



void problemTree::traceBack(){
	
	
	cout<<"---------------------------------------------------------------------------------"<<endl;
	
	for(int i=0;i<WIDTH*depth;i++) cout<<" ";
	cout<<"PROBLEM: "<<depth<<endl;
	p->indentedPrintOH(cout , WIDTH * depth);
	for(int i=0;i<WIDTH*depth;i++) cout<<" ";
	cout<<"DESTINATION IS :"<<*p->originalDestination<<endl;
	
	cout<<"**********************************************************************************"<<endl;
	
	list<problemTree *>:: iterator cI = children.begin();
	while(cI!=children.end()){
		assert((*cI)->nodeInfo == 1);
		problemTree *pT = *cI;
		cI++; 
		if(pT->result && ((cI == children.end()) || (((*cI)->nodeInfo==2) && ((*cI)->result)))){
			//solution found
			pT->traceBack();
			if(cI != children.end() && (((*cI)->nodeInfo==2) && ((*cI)->result))){
				(*cI)->traceBack();
			}
			return;
		}
		if((cI!=children.end()) && ((*cI)->nodeInfo==2))
				cI++;
	}
}	
	
	


