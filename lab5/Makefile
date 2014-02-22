Astar: Astar.o main.cpp  graph.o node.o 
	g++ -g -o Astar 8puzzle.cpp Astar.o  graph.o node.o
Astar.o: Astar.cpp Astar.h node.h 
	g++ Astar.cpp -c -g
graph.o : graph.cpp graph.h node.h
	g++ graph.cpp -c -g 
node.o: node.cpp
	g++ node.cpp -c -g
clean : 
	rm *.o Astar

