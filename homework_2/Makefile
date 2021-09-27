CC=g++

CFLAGS=-c -Wall

all: main

main: main.o StudentData.o
	$(CC) main.o StudentData.o -o main
	@./main

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

StudentData.o: StudentData.cpp StudentData.h
	$(CC) $(CFLAGS) StudentData.cpp 

clean:
	rm -rf *.o main file.txt
	