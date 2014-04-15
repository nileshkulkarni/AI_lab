#include "network_layer.h"



NetworkLayer ::  NetworkLayer(int nNeurons , int id){
			layerId = id;
			N = nNeurons;
			Neurons.resize(N);
}

void NetworkLayer :: updateLayer() {
	for(int i=0; i<Neurons.size(); i++) {
		Neurons[i].collectInputs();
	}
}

void NetworkLayer :: updateLayer(Vec In) {
	collectInputs(In);
}

