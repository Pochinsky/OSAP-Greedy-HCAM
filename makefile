##### Variables #####
CC 				= g++
CFLAGS			= -g -Wall
RM 				= rm -f *.o

all: main

main: main.o extract.o data.o entity.o room.o constraint.o
	$(CC) $(CFLAGS) -o main main.o Extract.o Data.o Entity.o Room.o Constraint.o

main.o:  main.cpp
	$(CC) $(CFLAGS) -c main.cpp 

extract.o: Extract/Extract.cpp
	$(CC) $(CFLAGS) -c Extract/Extract.cpp

data.o: Data/Data.cpp 
	$(CC) $(CFLAGS) -c Data/Data.cpp 

entity.o: Entity/Entity.cpp
	$(CC) $(CFLAGS) -c Entity/Entity.cpp

room.o: Room/Room.cpp
	$(CC) $(CFLAGS) -c Room/Room.cpp

constraint.o: Constraint/Constraint.cpp
	$(CC) $(CFLAGS) -c Constraint/Constraint.cpp

run:
	./main

clean:
	$(RM)

.PHONY: all clean