#ifndef _PROBLEMTREE_H
#define _PROBLEMTREE_H

#include "prover.h"
#include <list>


#define MAXDEPTH 4
#define STEPS 10
#define WIDTH 10

class problemTree{
public:
	int depth;
	bool result;
	bool solvedFromFirstPrinciples;
	prover *p;
	list<list<problemTree *>*> children;
	problemTree(int _depth);
	problemTree(prover *_p, int _depth);
	void expand();
	void traceBack();
	void print(ostream& out);
	void step();
	void destroy();
};




#endif

