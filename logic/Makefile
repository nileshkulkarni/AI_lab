CC=g++-4.6 -g -std=c++0x
TARGET=formulaCheck


formulaCheck : formula.o prover.o problemTree.o main.cpp
	$(CC) -g -o $(TARGET) formula.o prover.o problemTree.o main.cpp


formula.o : formula.h formula.cpp 
	$(CC) -g -c formula.cpp

prover.o : prover.h prover.cpp
	$(CC) -g -c prover.cpp

problemTree.o : problemTree.h problemTree.cpp
	$(CC) -g -c problemTree.cpp


clean :
	rm -rf *.o $(TARGET)
