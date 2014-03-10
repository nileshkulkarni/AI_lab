CC=g++-4.6
TARGET=formulaCheck


formulaCheck : formula.o main.cpp
	$(CC) -g -o $(TARGET) formula.o main.cpp


formula.o : formula.h formula.cpp 
	$(CC) -g -c formula.cpp

clean :
	rm -rf *.o $(TARGET)
