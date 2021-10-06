CC=g++

CFLAGS=-c 

SOURCES = main.cpp MyShared_ptr.h MyShared_ptr.cpp MyUnique_ptr.h MyUnique_ptr.cpp 

OBJECTS = $(SOURCES:.cpp=.o)

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main
	@./main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

MyShared_ptr.o: MyShared_ptr.cpp MyShared_ptr.h
	$(CC) $(CFLAGS) MyShared_ptr.cpp 

<MyUnique_ptr.o: MyUnique_ptr.cpp MyUnique_ptr.h 
	$(CC) $(CFLAGS) MyUnique_ptr.cpp 

clean:
	rm -rf *.o main 

	