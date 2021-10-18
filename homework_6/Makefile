CC=g++

CFLAGS=-c 

SOURCES = main.cpp Logger.h Logger.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main
	@./main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Logger.o: Logger.cpp Logger.h
	$(CC) $(CFLAGS) Logger.cpp 

clean:
	rm -rf *.o main 

	