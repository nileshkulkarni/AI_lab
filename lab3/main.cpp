#include "neural_network.h"
#include <vector>
using namespace std;
int main(){
    NeuralNetwork nn(3,1);
    
    nn.addInputLayer(2);
    nn.addHiddenLayer(4);
    nn.addOutputLayer(1);
    
    nn.generateEdges();
    
    Vec in0;
    in0.push_back(0);
    in0.push_back(0);
  
  
    Vec in1;
    in1.push_back(0);
    in1.push_back(1);
  
  
    Vec in2;
    in2.push_back(1);
    in2.push_back(0);
  
  
    Vec in3;
    in3.push_back(1);
    in3.push_back(1);
    
    vector< Vec> ins;
    ins.push_back(in0);
    ins.push_back(in1);
    ins.push_back(in2);
    ins.push_back(in3);
    

    Vec out0;
    Vec out1;
    Vec out2;
    Vec out3;
    out0.push_back(0);
    out1.push_back(1);
    out2.push_back(1);
    out3.push_back(0);
    
    vector< Vec > outs;
    outs.push_back(out0);
    outs.push_back(out1);
    outs.push_back(out2);
    outs.push_back(out3);
    
    
    nn.addAllTrainData(ins, outs);
    
    nn.getOutput(in2);
    
    nn.print();
    
    
    return 1;
}
