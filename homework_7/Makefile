CC=g++

CFLAGS=-c -Wall

SOURCES = main.cpp HashTable.h HashTable.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main
	@./main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

HashTable.o: HashTable.cpp HashTable.h
	$(CC) $(CFLAGS) HashTable.cpp 

clean:
	rm -rf *.o main 

	