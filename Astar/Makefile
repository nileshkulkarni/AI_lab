bidirectional: Astar.o 8puzzle.o 8main.cpp  bidirectional.cpp graph.o node.o header.h 
	g++ -g -o bidirectional bidirectional.cpp 8puzzle.o Astar.o  graph.o node.o
8puzzle: Astar.o 8puzzle.o 8main.cpp  graph.o node.o header.h 
	g++ -g -o 8puzzle 8main.cpp 8puzzle.o Astar.o  graph.o node.o
Missionary: Astar.o Missionary.o Mmain.cpp  graph.o node.o header.h 
	g++ -g -o Missionary Mmain.cpp Missionary.o Astar.o  graph.o node.o
Missionary.o: Missionary.cpp Missionary.h node.h header.h 
	g++ Missionary.cpp -c -g
8puzzle.o: 8puzzle.cpp 8puzzle.h node.h header.h 
	g++ 8puzzle.cpp -c -g
Astar.o: Astar.cpp Astar.h node.h header.h 
	g++ Astar.cpp -c -g
graph.o: graph.cpp graph.h node.h header.h 
	g++ graph.cpp -c -g 
node.o: node.cpp header.h 
	g++ node.cpp -c -g
clean : 
	rm -rf *.o 8puzzle Missionary

