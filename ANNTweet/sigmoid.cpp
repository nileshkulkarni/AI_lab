#include <iostream>
#include <cmath>
using namespace std;


int main(){
 
  double n;
  cout<<"Enter the number : ";
  cin>>n;
  cout<<endl<<1/(1 + exp(-n))<<endl;
  
  return 0;
  }
