#include "neural_network.h"

int main(){
    NeuralNetwork nn(3);
    
   nn.addInputLayer(2);
    nn.addHiddenLayer(2);
    nn.addOutputLayer(1);
    
    
    Vec in;
    in.push_back(1);
    in.push_back(0);
    
    Vec out;
    out.push_back(1);


    addTrainData(in, out);
    
    return 1;
}
