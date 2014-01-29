
CC=g++-4.6
TARGET=NeuralNetwork



NeuralNetwork : edge.o neuron.o network_layer.o neural_network.o generateTT.cpp main.cpp lsd.cpp
	$(CC) -g -o $(TARGET) neuron.o edge.o network_layer.o neural_network.o lsd.cpp generateTT.cpp main.cpp
neural_network.o : neural_network.cpp network_layer.h neural_network.h edge.h neuron.h 
	$(CC) -g -c neural_network.cpp
network_layer.o : network_layer.cpp network_layer.h edge.h neuron.h
	$(CC) -g -c network_layer.cpp
neuron.o : neuron.cpp neuron.h edge.h  
	$(CC) -g -c neuron.cpp

edge.o : edge.cpp edge.h neuron.h
	$(CC) -g -c edge.cpp
clean :
	rm -rf *.o $(TARGET)
