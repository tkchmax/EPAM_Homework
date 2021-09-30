CC=g++


SOURCES = MyVector.cpp MyVector.h LibraryEmployee.cpp \
		LibraryEmployee.h Database.cpp Database.h main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: main

main: $(OBJECTS)
	$(CC) $(OBJECTS) -o main
	@./main

main.o: main.cpp
	g++ -c main.cpp

MyVector.o: MyVector.cpp MyVector.h
	$(CC) -c MyVector.cpp 

LibraryEmployee.o: LibraryEmployee.h LibraryEmployee.cpp 
	$(CC) -c LibraryEmployee.cpp

Database.o: Database.h Database.cpp
	$(CC) -c Database.cpp 
	
clean:
	rm -rf *.o main