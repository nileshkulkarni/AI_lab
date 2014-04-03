#include "problemTree.h"



problemTree::problemTree(int _depth){
	depth = _depth;
}


problemTree::problemTree(prover *_p, int _depth){
	p = _p;
	depth = _depth;
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
			list<problemTree*> * newList = new list<problemTree*>;
			formula *temp = t;
			formula *previous = NULL;
			while(!temp->leaf){
				problemTree *child = new problemTree(depth+1);
				child->p = new prover;
				*(child->p) = *p;
				child->p->Hypothesis.erase(t->s);
				child->p->originalHypothesis.erase(t->s);
				if(previous){
					child->p->Hypothesis.insert(pair<string,formula*>(previous->s,previous));
					child->p->originalHypothesis.insert(pair<string,formula*>(previous->s,previous));
				}
				child->p->destination = temp->lhs;
				child->p->originalDestination = temp->lhs;
				child->p->simpilifyDestination();
				child->p->setDummyTrace();
				//cout<<endl<<"Printing child:"<<endl;
				//cout<<*(child->p)<<endl;
				newList->push_back(child);
				previous = temp->lhs;
				temp = temp->rhs;
			}
			assert(temp->val == 'F');	
			children.push_back(newList);
		}
	}
  list<list<problemTree *>*>:: iterator cI;
  list<problemTree *>:: iterator problem;
  
  for(cI = children.begin(); cI != children.end(); cI++){
	 for(problem = (*cI)->begin(); problem != (*cI)->end(); problem++)		
			(*problem)->expand();
	  
  }
}
	

void problemTree::print(ostream &out){
	
	out<<endl;
	for(int i=0; i<WIDTH*depth; i++) out<<" ";
	out<<"PRINTING PROBLEM : "<<endl;
	for(int i=0; i<WIDTH*depth; i++) out<<" ";
	out<<"DESTINATION IS : "<<*(p->originalDestination)<<endl;
	
	p->indentedPrintOH(out , WIDTH * depth);
	//p->indentedPrintI(out , 5*depth);
	
	list<list<problemTree *>*>:: iterator cI;
	list<problemTree *>:: iterator problem;
  
  for(cI = children.begin(); cI!=children.end(); cI++){
	 for(int i=0; i<WIDTH*depth; i++) out<<" ";
	 out<<"////////////////////////////////////////////////////////////"<<endl;
	 for(problem = (*cI)->begin(); problem != (*cI)->end(); problem++)		
			(*problem)->print(out);
	  
  }
}



void problemTree::step(){
	result = p->step(STEPS);
	if(result){
		solvedFromFirstPrinciples = true;
		return;
	}

	solvedFromFirstPrinciples = false;
	list<list<problemTree *>*>:: iterator cI;
	list<problemTree *>:: iterator problem;

	
	for(cI = children.begin(); cI!=children.end(); cI++){
	 for(problem = (*cI)->begin(); problem != (*cI)->end(); problem++)		
			(*problem)->step();
	  
   }
   
	for(cI = children.begin(); cI!=children.end(); cI++){
		bool ans = true;
		for(problem = (*cI)->begin(); problem != (*cI)->end(); problem++)		
			ans = ans && (*problem)->result;
		if(ans == true){
			result = true;
			return;
		}
	}
	
	result = false;
}



void problemTree::traceBack(){
	
	
	cout<<"---------------------------------------------------------------------------------"<<endl;
	for(int i=0;i<WIDTH*depth;i++) cout<<" ";
	cout<<"DEPTH: "<<depth<<endl;
	p->indentedPrintOH(cout , WIDTH * depth);
	for(int i=0;i<WIDTH*depth;i++) cout<<" ";
	cout<<"DESTINATION IS :"<<*p->originalDestination<<endl;
	if(solvedFromFirstPrinciples){
		p->traceBack(WIDTH * depth);
	}
	cout<<"**********************************************************************************"<<endl;
	
	if(solvedFromFirstPrinciples){
		return;
	}
	
	list<list<problemTree *>*>:: iterator cI;
	list<problemTree *>:: iterator problem;
  
	for(cI = children.begin(); cI!=children.end(); cI++){
		bool ans = true;
		for(problem = (*cI)->begin(); problem != (*cI)->end(); problem++)		
			ans = ans && (*problem)->result;
		if(ans == true){
			for(problem = (*cI)->begin(); problem != (*cI)->end(); problem++)		
				(*problem)->traceBack();
			return;
		}
   }
	
}	
	
	


