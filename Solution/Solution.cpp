#include <cstdlib>
#include <algorithm>
#include "Solution.h"

int randint(int n) { return rand() % n; }

bool checkAllocation(int idEntity, int idRoom, map<int, int> solution)
{
	map<int, int>::iterator itS;
	for (itS = solution.begin(); itS != solution.end(); itS++)
		if (idEntity == itS->first && idRoom != itS->second)
			return false;
	return true;
}

bool checkCapacity(int idRoom, vector<Entity> entities, vector<Room> rooms, map<int, int> solution)
{
	vector<Room>::iterator itR;
	int roomCapacity;
	for (itR = rooms.begin(); itR != rooms.end(); itR++)
		if (idRoom == itR->id)
			roomCapacity = itR->capacity;
	map<int, int>::iterator itS;
	list<int> entitiesInRoom;
	entitiesInRoom.push_back(1);
	entitiesInRoom.clear();
	for (itS = solution.begin(); itS != solution.end(); itS++)
		if (idRoom == itS->second)
			entitiesInRoom.push_back(itS->first);
	vector<Entity>::iterator itE;
	int sizeUse = 0;
	for (itE = entities.begin(); itE != entities.end(); itE++)
		if (find(entitiesInRoom.begin(), entitiesInRoom.end(), itE->id) != entitiesInRoom.end())
			sizeUse += itE->space;
	if (sizeUse > roomCapacity)
		return false;
	return true;
}

bool checkSameRoom(int idEntity1, int idEntity2, map<int, int> solution)
{
	int idRoom1, idRoom2;
	map<int, int>::iterator itS;
	for (itS = solution.begin(); itS != solution.end(); itS++)
	{
		if (idEntity1 == itS->first)
			idRoom1 = itS->first;
		else if (idEntity1 == itS->second)
			idRoom1 = itS->second;
		if (idEntity2 == itS->first)
			idRoom2 = itS->first;
		else if (idEntity2 == itS->second)
			idRoom2 = itS->second;
	}
	if (idRoom1 != idRoom2)
		return false;
	return true;
}

bool checkAdjacency(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution)
{
	int idRoom1, idRoom2;
	map<int, int>::iterator itS;
	for (itS = solution.begin(); itS != solution.end(); itS++)
	{
		if (idEntity1 == itS->first)
			idRoom1 = itS->first;
		else if (idEntity1 == itS->second)
			idRoom1 = itS->second;
		if (idEntity2 == itS->first)
			idRoom2 = itS->first;
		else if (idEntity2 == itS->second)
			idRoom2 = itS->second;
	}
	vector<Room>::iterator itR;
	for (itR = rooms.begin(); itR != rooms.end(); itR++)
	{
		if (idRoom1 == itR->id)
			if (find(itR->adjacentRooms.begin(), itR->adjacentRooms.end(), idRoom2) == itR->adjacentRooms.end())
				return false;
		if (idRoom2 == itR->id)
			if (find(itR->adjacentRooms.begin(), itR->adjacentRooms.end(), idRoom1) == itR->adjacentRooms.end())
				return false;
	}
	return true;
}

bool checkNearness(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution)
{
	int idRoom1, idRoom2;
	map<int, int>::iterator itS;
	for (itS = solution.begin(); itS != solution.end(); itS++)
	{
		if (idEntity1 == itS->first)
			idRoom1 = itS->first;
		else if (idEntity1 == itS->second)
			idRoom1 = itS->second;
		if (idEntity2 == itS->first)
			idRoom2 = itS->first;
		else if (idEntity2 == itS->second)
			idRoom2 = itS->second;
	}
	int idFloor1, idFloor2;
	vector<Room>::iterator itR;
	for (itR = rooms.begin(); itR != rooms.end(); itR++)
	{
		if (idRoom1 == itR->id)
			idFloor1 = itR->floor;
		if (idRoom2 == itR->id)
			idFloor2 = itR->floor;
	}
	if (idFloor1 != idFloor2)
		return false;
	return true;
}

bool checkFeasible(vector<Entity> entities, vector<Room> rooms, vector<Constraint> hardConstraints, map<int, int> solution)
{
	vector<Constraint>::iterator itC;
	for (itC = hardConstraints.begin(); itC != hardConstraints.end(); itC++)
	{
		cout << "########## checkFeasible " << itC - hardConstraints.begin() << " ##########" << endl;
		switch (itC->type)
		{
		case 0: /* ALLOCATION_CONSTRAINT */
		{
			cout << "ALLOCATION_CONSTRAINT" << endl;
			if (!checkAllocation(itC->parameter1, itC->parameter2, solution))
				return false;
			break;
		}
		case 1: /* NONALLOCATION_CONSTRAINT */
		{
			cout << "NONALLOCATION_CONSTRAINT" << endl;
			if (checkAllocation(itC->parameter1, itC->parameter2, solution))
				return false;
			break;
		}
		case 3: /* CAPACITY_CONSTRAINT */
		{
			cout << "CAPACITY_CONSTRAINT" << endl;
			if (!checkCapacity(itC->id, entities, rooms, solution))
				return false;
			break;
		}
		case 4: /* SAMEROOM_CONSTRAINT */
		{
			cout << "SAMEROOM_CONSTRAINT" << endl;
			if (!checkSameRoom(itC->parameter1, itC->parameter2, solution))
				return false;
			break;
		}
		case 5: /* NOTSAMEROOM_CONSTRAINT */
		{
			cout << "NOTSAMEROOM_CONSTRAINT" << endl;
			if (checkSameRoom(itC->parameter1, itC->parameter2, solution))
				return false;
			break;
		}
		case 6: /* NOTSHARING_CONSTRAINT */
		{
			cout << "NOTSHARING_CONSTRAINT" << endl;
			map<int, int>::iterator itS;
			for (itS = solution.begin(); itS != solution.end(); itS++)
				if (checkSameRoom(itC->parameter1, itS->first, solution))
					return false;
			break;
		}
		case 7: /* ADJACENCY_CONSTRAINT */
		{
			cout << "ADJACENCY_CONSTRAINT" << endl;
			if (!checkAdjacency(itC->parameter1, itC->parameter2, rooms, solution))
				return false;
			break;
		}
		case 8: /* NEARBY_CONSTRAINT */
		{
			cout << "NEARBY_CONSTRAINT" << endl;
			if (!checkNearness(itC->parameter1, itC->parameter2, rooms, solution))
				return false;
			break;
		}
		case 9: /* AWAYFROM_CONSTRAINT */
		{
			cout << "AWAYFROM_CONSTRAINT" << endl;
			if (checkNearness(itC->parameter1, itC->parameter2, rooms, solution))
				return false;
			break;
		}
		default:
			break;
		}
	}
	return true;
}

void initialSolution(vector<Entity> entities, vector<Room> rooms, int nOfRooms, map<int, int> *solution)
{
	vector<Room>::iterator it;
	for (Entity e : entities)
	{
		int i = randint(nOfRooms);
		Room r = rooms.at(i);
		(*solution).insert(pair<int, int>(e.id, r.id));
	}
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
	bool local = true;
	// se genera una solución candidata aleatoria
	initialSolution(
			entities,
			rooms,
			nOfRooms,
			solution);
	cout << checkFeasible(entities, rooms, hardConstraints, *solution) << endl;
	map<int, int> newSolution;
}

void printSolution(map<int, int> solution)
{
	cout << "########## Solución ##########" << endl;
	map<int, int>::iterator it;
	for (it = solution.begin(); it != solution.end(); ++it)
		cout << "e" << it->first << "\tto\tr" << it->second << endl;
}