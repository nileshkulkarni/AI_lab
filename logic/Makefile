CC=g++-4.6
TARGET=formulaCheck


formulaCheck : formula.o prover.o main.cpp
	$(CC) -g -o $(TARGET) formula.o prover.o main.cpp


formula.o : formula.h formula.cpp 
	$(CC) -g -c formula.cpp

prover.o : prover.h prover.cpp
	$(CC) -g -c prover.cpp

clean :
	rm -rf *.o $(TARGET)
