#include "neural_network.h"

int main(){
    NeuralNetwork nn(3,1);
    
   nn.addInputLayer(2);
   nn.addHiddenLayer(4);
   nn.addOutputLayer(1);
    
    
    Vec in;
    in.push_back(1);
    in.push_back(0);
    
    Vec out;
    out.push_back(1);

    nn.generateEdges();
//  nn.addTrainData(in, out);
    nn.print();    
    //nn.layers[0].print();
    //nn.layers[1].print();
    return 1;
}
