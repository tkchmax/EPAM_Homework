CC=g++

CFLAGS=-c -Wall

SOURCES = main.cpp Logger.h Logger.cpp Logger2.h Logger2.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main
	@./main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Logger.o: Logger.cpp Logger.h
	$(CC) $(CFLAGS) Logger.cpp 

Logger2.o: Logger2.cpp Logger2.h 
	$(CC) $(CFLAGS) Logger2.cpp 

clean:
	rm -rf *.o main file.txt
	