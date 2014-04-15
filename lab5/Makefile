Astar: Astar.o main.cpp  graph.o 
	g++ -g -o Astar main.cpp Astar.o  graph.o
Astar.o: Astar.cpp Astar.h node.h 
	g++ Astar.cpp -c -g
graph.o : graph.cpp graph.h node.h
	g++ graph.cpp -c -g 
clean : 
	rm *.o Astar

