#include <iostream>

using namespace std;

#define TOTAL_SYMBOLS 5

char a[]  = {'a', 'b', 'c', 'd',  'e', 'f', 'g'};




string majority(int m , int k){
	
	if(m < k){
		return "false";
	}
	
	if(k==0){
		return "true";
	}
	
	string ret;
	string a1 = majority(m-1,k);
	string a2 = majority(m-1, k-1);
	string v2;
	
	if(a1 == "true"){
		return "true";
	}
	
	if(a2=="true")
		v2 = string(1, a[TOTAL_SYMBOLS-m]);
	
	else if(a2=="false")
		v2 = "false";
	
	else
		v2 = "(" + a2 + "&" + string(1,a[TOTAL_SYMBOLS-m]) + ")";
	
	
	if(a1 == "false" && v2=="false")
		return "false";

	if(a1 == "false"){
	    return v2;	
	}	

	else{
	 ret = "(" + a1  + "|" + v2 + ")";
	}
	
	return ret; 
}



int main(){
   int a,b;
   cin>>a>>b;
   cout<<majority(a,b)<<endl;
}
