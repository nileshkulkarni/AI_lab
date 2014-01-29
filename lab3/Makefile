



NeuralNetwork : edge.o neuron.o network_layer.o neural_network.o generateTT.cpp main.cpp lsd.cpp
	g++ -g -o NeuralNetwork neuron.o edge.o network_layer.o neural_network.o lsd.cpp generateTT.cpp main.cpp
neural_network.o : neural_network.cpp network_layer.h neural_network.h edge.h neuron.h 
	g++ -g -c neural_network.cpp
network_layer.o : network_layer.cpp network_layer.h edge.h neuron.h
	g++ -g -c network_layer.cpp
neuron.o : neuron.cpp neuron.h edge.h  
	g++ -g -c neuron.cpp

edge.o : edge.cpp edge.h neuron.h
	g++ -g -c edge.cpp
clean :
	rm -rf *.o NeuralNetwork
