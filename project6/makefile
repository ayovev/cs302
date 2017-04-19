CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O0
O_FILES = bn.o bst.o main.o

all: $(O_FILES)
	$(CC) $(CXXFLAGS) $(O_FILES)
	del *.o
	
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o
	
bst.o: binarySearchTree.cpp
	$(CC) $(CXXFLAGS) -c binarySearchTree.cpp -o bst.o
	
bn.o: binaryNode.cpp
	$(CC) $(CXXFLAGS) -c binaryNode.cpp -o bn.o
	
clean:
	del *.o