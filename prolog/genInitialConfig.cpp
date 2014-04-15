#include <iostream>
#include <cassert>
#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <set>
#include <sstream>


using namespace std;

set<char> variables;

int curr_term;
int curr_gate;

string itoa(int n){
	stringstream ss;
	ss << n;
	string str = ss.str();
	return str;
}



struct exp{
	
	char val;
	exp *lhs;
	exp *rhs;
	
	void input(){
		char a;
		cin>>a;
		lhs = NULL;
		rhs = NULL;
		if(a=='('){
			lhs = new exp;
			lhs->input();
			cin>>val;
			rhs = new exp;
			rhs->input();
			cin>>a;
		}
		else if(a=='!'){
			val = '!';
			lhs = new exp;
			lhs->input();
		}
		else{
			val = a;
			if(variables.find(val) != variables.end())
				variables.insert(val);
		}	
	}
	
	
	void print(){
	  cout<<"(";
	  if(val=='!'){
		  cout<<"!";
		  lhs->print();
		  cout<<")";
		  return;
	  }
	  
	  if(lhs != NULL) lhs->print();
	  cout<<val;
	  if(rhs != NULL) rhs->print();
	  cout<<")";
	}
	string genconfg(){

		if((lhs == NULL) && (rhs==NULL)) 
			return string(1,val);
		
		
		if((lhs != NULL) && (rhs==NULL)){
			assert(val == '!');
			string a1 = lhs->genconfg();
			string out = "t" + string(itoa(curr_term));
			curr_term++;
			
			
			string gatename = "g" + string(itoa(curr_gate));
			curr_gate++;
			string type;
			type = "not";
			
			cout<<"type("<<gatename<<","<<type<<")."<<endl;
			cout<<"in(1,"<<a1<<","<<gatename<<")."<<endl;
			cout<<"out("<<out<<","<<gatename<<")."<<endl;
			return out;
		}
		
		string a1 = lhs->genconfg();
		string a2 = rhs->genconfg();
		string out = "t" + string(itoa(curr_term));
		curr_term++;
		
		
		string gatename = "g" + string(itoa(curr_gate));
		curr_gate++;
		string type;
		if(val == '&') type = "and";
		if(val == '|') type = "or";
		if(val == '^') type = "xor";
		
		
		cout<<"type("<<gatename<<","<<type<<")."<<endl;
		cout<<"in(1,"<<a1<<","<<gatename<<")."<<endl;
		cout<<"in(2,"<<a2<<","<<gatename<<")."<<endl;
		cout<<"out("<<out<<","<<gatename<<")."<<endl;
		return out;
	}	
};



int main(){
	
	exp* expr = new exp;
	expr->input();
	expr->print();
	curr_term = 0;
	curr_gate = 0;
	
	cout<<endl;
	expr->genconfg();
	return 0;
}
