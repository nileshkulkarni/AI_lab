#include <iostream>
#include <bitset>

using namespace std;


inline int getbit(int integer , int i){ //0 indexed
	return (integer / (1<<i)) % 2;
}
	

void gen(){
	int i=0;
	bool result;
	cout<<"**********Nand*******"<<endl;
	int bits = 2;
	while(i<4){
		result = true;
		for(int bit=0;bit<bits;bit++)
		
		  result  = result && (bool)(getbit(i , bit));   //Nand
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++)
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   cout<<endl; 
	    i++;
	}
	
	cout<<"*****NOR****"<<endl;
	i=0;
	while(i<4){
		result = false;
		for(int bit=0;bit<bits;bit++)
		  result  = result || (bool)(getbit(i , bit));   //Nor
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++)
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   cout<<endl; 
	    i++;
	}
	
	
	cout<<"*****XOR****"<<endl;
	i=0;
	while(i<4){
		result = false;
		for(int bit=0;bit<bits;bit++)
		  result  = result ^ (bool)(getbit(i , bit));   //Xor
		result  = !result;
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++)
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   cout<<endl; 
	    i++;
	}
	
	
	
	cout<<"*********Palindrome******"<<endl;
	i=0;
	bits=5;
	while(i<(1<<bits)){
		result = true;
		for(int bit=0;bit<=bits/2;bit++)
		  result  = result && (bool)(getbit(i , bit) == getbit(i , bits - bit -1));  
		result  = !result;
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++)
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   cout<<endl; 
	    i++;
	}
	
	cout<<"*********5 Majority******"<<endl;
	i=0;
	bits=5;
	while(i<(1<<bits)){
		int count = 0;
		for(int bit=0;bit<bits;bit++)
		  count += (int)(getbit(i , bit) == 1); 
		bool result = !(count>=3);  
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++)
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   cout<<endl; 
	    i++;
	}
	
	
	cout<<"*********Parity******"<<endl;
	i=0;
	bits=6;
	while(i<(1<<bits)){
		int count = 0;
		for(int bit=0;bit<bits;bit++)
		  count += (int)(getbit(i , bit) == 1); 
		bool result = !(count%2 == 0);  
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++)
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   cout<<endl; 
	    i++;
	}
}


int main(){
	gen();
	return 0;
}
