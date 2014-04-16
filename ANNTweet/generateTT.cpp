#include "neuron.h"
#include <vector>
using namespace std;

inline int getbit(int integer , int i){ //0 indexed
	return (integer / (1<<i)) % 2;
}
	
	
void  genTT(string op	,vector<Vec> &reti , vector<Vec> &reto){
	
	
	int i=0;
	bool result;
	int bits = 2;
	if(op == "NAND"){
	cout<<"**********Nand*******"<<endl;

	while(i<4){
		
		result = true;
	
		for(int bit=0;bit<bits;bit++)
			result  = result && (bool)(getbit(i , bit));   //Nand
		cout<<((!result)?-1:1)<<" ";
		Vec vi;
		Vec vo;
		for(int bit=0;bit<bits;bit++){
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
		  vi.push_back(getbit(i,bit));
	   }
	   vo.push_back(1-result);
	   reti.push_back(vi);
	   reto.push_back(vo);
	   
	   cout<<endl; 
	    i++;
	}
	return;
   }
   
   
   
   
	cout<<"*****NOR****"<<endl;
	
    if(op == "NOR"){
	i=0;
	while(i<4){
		result = false;
		for(int bit=0;bit<bits;bit++)
		  result  = result || (bool)(getbit(i , bit));   //Nor
		cout<<((!result)?-1:1)<<" ";
		Vec vi;
		Vec vo;
		for(int bit=0;bit<bits;bit++){
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
		  vi.push_back(getbit(i,bit));
	   }
	   vo.push_back(1-result);
	   reti.push_back(vi);
	   reto.push_back(vo);
	   
	   cout<<endl; 
	    i++;
	}
   return;	
  }	
	
	cout<<"*****XOR****"<<endl;
	
	
	if(op == "XOR"){
	i=0;
	while(i<4){
		result = false;
		for(int bit=0;bit<bits;bit++)
		  result  = result ^ (bool)(getbit(i , bit));   //Xor
		result  = !result;
		cout<<((!result)?-1:1)<<" ";
		Vec vi;
		Vec vo;
		for(int bit=0;bit<bits;bit++){
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" ";
		  vi.push_back(getbit(i,bit));
	   }
	   
	   vo.push_back(1-result);
	   reti.push_back(vi);
	   reto.push_back(vo);

	    cout<<endl; 
	    i++;
	}
	return;
  }
	
	
	
	
	if(op == "PALINDROME"){
	cout<<"*********Palindrome******"<<endl;
	i=0;
	bits=5;
	while(i<(1<<bits)){
		result = true;
		for(int bit=0;bit<=bits/2;bit++)
		  result  = result && (bool)(getbit(i , bit) == getbit(i , bits - bit -1));  
		result  = !result;
		cout<<((!result)?-1:1)<<" ";
		
		Vec vi;
		Vec vo;
		for(int bit=0;bit<bits;bit++){
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
		  vi.push_back(getbit(i,bit));
	   }
	   
	   vo.push_back(1-result);
	   reti.push_back(vi);
	   reto.push_back(vo);

	   
	   
	   cout<<endl; 
	    i++;
	}
	return;
  }
	
	
	
	if(op == "Majority"){
	cout<<"*********5 Majority******"<<endl;
	i=0;
	bits=5;
	while(i<(1<<bits)){
		int count = 0;
		for(int bit=0;bit<bits;bit++)
		  count += (int)(getbit(i , bit) == 1); 
		bool result = !(count>=3);  
		
		Vec vi;
		Vec vo;
		
		cout<<((!result)?-1:1)<<" ";
		for(int bit=0;bit<bits;bit++){
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" ";
		  vi.push_back(getbit(i,bit)); 
	    }
	    
	    
	   vo.push_back(1-result);
	   reti.push_back(vi);
	   reto.push_back(vo);

	    
	   cout<<endl; 
	    i++;
	}
	return; 
   }
	
	
	
	if(op == "Parity"){
	cout<<"*********Parity******"<<endl;
	i=0;
	bits=6;
	while(i<(1<<bits)){
		int count = 0;
		for(int bit=0;bit<bits;bit++)
		  count += (int)(getbit(i , bit) == 1); 
		bool result = !(count%2 == 0);  
		cout<<((!result)?-1:1)<<" ";
		
		Vec vi;
		Vec vo;
		
		for(int bit=0;bit<bits;bit++){
		  cout<<((!result)?getbit(i,bit):-getbit(i,bit))<<" "; 
	   }
	   
	   
	   vo.push_back(1-result);
	   reti.push_back(vi);
	   reto.push_back(vo);

	   
	   cout<<endl; 
	    i++;
	}
	return;
  }
}


