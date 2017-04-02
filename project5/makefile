CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O0
O_FILES = main.o

all: $(O_FILES)
	$(CC) $(CXXFLAGS) $(O_FILES)

main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	del *.o