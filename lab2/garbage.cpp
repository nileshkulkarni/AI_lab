#include <iostream>
#include <bitset>
#include "Vec.h"

using namespace std;


inline int getbit(int integer , int i){ //0 indexed
	return (integer / (1<<i)) % 2;
}
	


void gen_vectors(Vec v){
	
	Vec t;
	
	Vec t2;
	t.initialize(v.dimension+1);
	t2.initialize(v.dimension+1);
	
	
	t2.arr[0] = -1;
	
	for(int i=1;i<v.dimension + 1;i++)
	 t2.arr[i] = v.arr[i-1];

	
	
	for(int i=0;i<(1<<v.dimension);i++){
		t.arr[0] = -1;
		for(int bit = 1; bit<= v.dimension; bit++)
		   t.arr[bit] = getbit(i , bit-1); 
		 if(!(t2==t)) 
			t.invertWeights();
		t.prettyPrint();
	}	
}


int main(){
	
	Vec v;
	v.initialize(7);
	
	for(int i=0;i<10;i++){
		v.input();
		gen_vectors(v);
	}
return 0;
}	
	
	
	
	
