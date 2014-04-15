#include "neural_network.h"
NeuralNetwork::NeuralNetwork(){ } 




void NeuralNetwork::_init(){
      srand(time(NULL));
 
}


NeuralNetwork::NeuralNetwork(int nlayers){
    _init();
    nHiddenLayers = 0;
    noOfLayers = nlayers;
    //cout<<"size is layers : "<<nlayers<<endl;
    //layers.resize(nlayers);
   // cout<<"size is layers : "<<layers.size()<<endl;
}


NeuralNetwork::NeuralNetwork(int nLayers,int noOfNeurons){
    _init();
    noOfLayers = nLayers;
    nHiddenLayers = 0;
    for(int i =0;i<nLayers;i++){
        NetworkLayer lay;        
        layers.push_back(lay);
    }
} 


void NeuralNetwork::addInputLayer(int nNeurons){
	layers[0].initInput(nNeurons);
}


void NeuralNetwork::addHiddenLayer(int nNeurons){
	assert(nHiddenLayers < noOfLayers-1);
	layers[++nHiddenLayers].init(nNeurons);
}


void NeuralNetwork::addOutputLayer(int nNeurons){
	
	//cout<<"size of layers is : "<<layers.size()<<" : "<<noOfLayers - 1<<endl;
	layers[noOfLayers - 1].init(nNeurons);
}
        




void NeuralNetwork::feedForward(Vec in){
    
    for(int i =0;i<layers.size();i++){
        if(i==0){
            layers[i].updateLayer(in);
        }
        else{
           layers[i].updateLayer(); 
        }
    }
}


 
Vec NeuralNetwork::getOutput(Vec in){
    feedForward(in); 
    int size = layers.size();  
    return layers[size-1].getOutput();
}


//I wrote a comment in vim. This one. 
void NeuralNetwork :: backPropagate(){
	
	layers[noOfLayers-1].backPropagate(outputs);

	for(int i=noOfLayers-2; i>=0 ; i--){
		layers[i].backPropagate();
	}

   for(int i=noOfLayers-1; i>0 ; i--){
       layers[i].updateWeights();
       //cout<<"i is : "<<i<<endl; 
	}
}	


void NeuralNetwork::addTrainData(Vec in, Vec out){
	
	this->feedForward(in);
    outputs = out;
    this->backPropagate();
  
}

void NeuralNetwork::addAllTrainData(vector <Vec > ins, vector< Vec> outs){
    double maxError = 10 ;
    double meanError = 10;
    Vec outp;
    int printRate = PRINTRATE;
	int steps=0;
  while(meanError>ERROR_THRESHOLD){ 
		meanError = 0;
		maxError = 0;
		steps++;
        for(int i =0;i< ins.size();i++){
            addTrainData(ins[i],outs[i]);
            outp = layers[noOfLayers-1].getOutput();
            sub(outp , outs[i]); 
            maxError = max(maxError , mod(outp));
            meanError += mod(outp);
            //cout<<mod(outp)<<" "<<endl;
        }	
        if(!printRate--){
			printf("%d mean:%f max:%f\n",steps, meanError , maxError);
			printVec(outp);
            cout<<endl;
         	printRate =PRINTRATE;
		}
		
    }
    
    printf("Training Done Error %f \n",meanError);
	printf("Total steps : %d\n",steps);	    
    printf("\n\n"); 
}




void NeuralNetwork::print(){
	
	for(int i=noOfLayers-1 ; i>=0 ; i--){
		layers[i].print();
		cout<<endl<<endl;
	}
	
}

void NeuralNetwork::putEdges(int from , int to){
    vector<Neuron> *fromNeuronsPtr  = layers[from].getAllNeuronsPtr();
    vector<Neuron> *toNeuronsPtr  = layers[to].getAllNeuronsPtr();

    //printf("Layer from %d ID from %d ,to %d layer id to %d \n",from,layers[from].layerId,to,layers[to].layerId);
    for (int i =0;i<fromNeuronsPtr->size();i++){
        for (int j =0;j<toNeuronsPtr->size();j++){
            Edge *E = new Edge; 
            E->setStart(&(*fromNeuronsPtr)[i]);
            (*fromNeuronsPtr)[i].addOutputEdge(E);
            //printf("Start Neuron ID %d ", E->getStart()->getID()) ;
            E->setEnd(&(*toNeuronsPtr)[j]);
            (*toNeuronsPtr)[j].addInputEdge(E);
            //printf("End Neuron ID %d \n", (E->getEnd())->getID()) ;
        }
    }
    return;
}






void NeuralNetwork::generateEdges(){
   // printf("here 1\n");
    for(int i = 0;i<noOfLayers-1;i++){
        putEdges(i,i+1);
    }
}
