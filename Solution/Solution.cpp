#include <cstdlib>
#include "Solution.h"

int randint(int n) { return rand() % n; }

void initialSolution(int nOfRooms, vector<Entity> entities, vector<Room> rooms, map<int, int> *solution)
{
	vector<Room>::iterator it;
	for (Entity e : entities)
	{
		int i = randint(nOfRooms);
		Room r = rooms.at(i);
		(*solution).insert(pair<int, int>(e.getID(), r.getID()));
	}
}

void printSolution(map<int, int> solution)
{
	cout << "########## Solución ##########" << endl;
	map<int, int>::iterator it;
	for (it = solution.begin(); it != solution.end(); ++it)
		cout << "e" << it->first << "\tto\tr" << it->second << endl;
}

void hillClimbing(
		int nOfEntities,
		int nOfRooms,
		int nOfFloors,
		int nOfHardConstraints,
		int nOfSoftConstraints,
		vector<Entity> entities,
		vector<Room> rooms,
		vector<Constraint> softConstraints,
		vector<Constraint> hardConstraints,
		map<int, int> *solution)
{
	// variable para finalizar el algoritmo
	bool local = false;
	// se genera una solución candidata aleatoria
	initialSolution(
			entities,
			rooms,
			nOfRooms,
			solution);
	printSolution(*solution);
}