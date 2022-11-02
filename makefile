##### Variables #####
CC 				= g++
CFLAGS		= -g -Wall
RM 				= rm -f *.o

all: main

main: constraint.o room.o entity.o extract.o solution.o helpers.o main.o
	$(CC) $(CFLAGS) -o main main.o Helpers.o Solution.o Extract.o Entity.o Room.o Constraint.o

main.o:  main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

helpers.o: Solution/Helpers.cpp
	$(CC) $(CFLAGS) -c Solution/Helpers.cpp

solution.o: Solution/Solution.cpp
	$(CC) $(CFLAGS) -c Solution/Solution.cpp

extract.o: Extract/Extract.cpp
	$(CC) $(CFLAGS) -c Extract/Extract.cpp

entity.o: Entity/Entity.cpp
	$(CC) $(CFLAGS) -c Entity/Entity.cpp

room.o: Room/Room.cpp
	$(CC) $(CFLAGS) -c Room/Room.cpp

constraint.o: Constraint/Constraint.cpp
	$(CC) $(CFLAGS) -c Constraint/Constraint.cpp

run:
	./main $(instance)

clean:
	$(RM)

.PHONY: all clean