Astar: Astar.o 8puzzle.o main.cpp  graph.o node.o 
	g++ -g -o Astar main.cpp 8puzzle.o Astar.o  graph.o node.o
8puzzle.o: 8puzzle.cpp 8puzzle.h node.h
	g++ 8puzzle.cpp -c -g
Astar.o: Astar.cpp Astar.h node.h 
	g++ Astar.cpp -c -g
graph.o : graph.cpp graph.h node.h
	g++ graph.cpp -c -g 
node.o: node.cpp
	g++ node.cpp -c -g
clean : 
	rm *.o Astar

