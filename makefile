##### Variables #####
CC 				= g++
CFLAGS		= -g -Wall
RM 				= rm -f *.o

all: main

main: constraint.o room.o entity.o extract.o solution.o prohibitehelpers.o feasiblehelpers.o helpers.o constraintshelpers.o main.o
	$(CC) $(CFLAGS) -o main main.o ConstraintsHelpers.o Helpers.o FeasibleHelpers.o ProhibiteHelpers.o Solution.o Extract.o Entity.o Room.o Constraint.o

main.o:  main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

constraintshelpers.o: Solution/ConstraintsHelpers.cpp
	$(CC) $(CFLAGS) -c Solution/ConstraintsHelpers.cpp

helpers.o: Solution/Helpers.cpp
	$(CC) $(CFLAGS) -c Solution/Helpers.cpp

feasiblehelpers.o: Solution/FeasibleHelpers.cpp
	$(CC) $(CFLAGS) -c Solution/FeasibleHelpers.cpp

prohibitehelpers.o: Solution/ProhibiteHelpers.cpp
	$(CC) $(CFLAGS) -c Solution/ProhibiteHelpers.cpp

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