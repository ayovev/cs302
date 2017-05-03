CC = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O0
O_FILES = main.o player.o overview.o suit.o

all: $(O_FILES)
	$(CC) $(CXXFLAGS) $(O_FILES)
	del *.o
	
main.o: main.cpp
	$(CC) $(CXXFLAGS) -c main.cpp -o main.o
	
player.o: player.cpp
	$(CC) $(CXXFLAGS) -c player.cpp -o player.o
	
overview.o: overview.cpp
	$(CC) $(CXXFLAGS) -c overview.cpp -o overview.o
	
suit.o: suit.cpp
	$(CC) $(CXXFLAGS) -c suit.cpp -o suit.o