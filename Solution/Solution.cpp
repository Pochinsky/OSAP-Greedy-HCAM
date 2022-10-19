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
		if (idRoom == itR->getID())
			roomCapacity = itR->getCapacity();
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
		if (find(entitiesInRoom.begin(), entitiesInRoom.end(), itE->getID()) != entitiesInRoom.end())
			sizeUse += itE->getSpace();
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
		if (idRoom1 == itR->getID())
			if (find(itR->getAdjacentRooms().begin(), itR->getAdjacentRooms().end(), idRoom2) == itR->getAdjacentRooms().end())
				return false;
		if (idRoom2 == itR->getID())
			if (find(itR->getAdjacentRooms().begin(), itR->getAdjacentRooms().end(), idRoom1) == itR->getAdjacentRooms().end())
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
		if (idRoom1 == itR->getID())
			idFloor1 = itR->getFloor();
		if (idRoom2 == itR->getID())
			idFloor2 = itR->getFloor();
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
		switch (itC->getType())
		{
		case 0: /* ALLOCATION_CONSTRAINT */
		{
			if (!checkAllocation(itC->getParameter1(), itC->getParameter2(), solution))
				return false;
			break;
		}
		case 1: /* NONALLOCATION_CONSTRAINT */
		{
			if (checkAllocation(itC->getParameter1(), itC->getParameter2(), solution))
				return false;
			break;
		}
		case 3: /* CAPACITY_CONSTRAINT */
		{
			if (!checkCapacity(itC->getID(), entities, rooms, solution))
				return false;
			break;
		}
		case 4: /* SAMEROOM_CONSTRAINT */
		{
			if (!checkSameRoom(itC->getParameter1(), itC->getParameter2(), solution))
				return false;
			break;
		}
		case 5: /* NOTSAMEROOM_CONSTRAINT */
		{
			if (checkSameRoom(itC->getParameter1(), itC->getParameter2(), solution))
				return false;
			break;
		}
		case 6: /* NOTSHARING_CONSTRAINT */
		{
			map<int, int>::iterator itS;
			for (itS = solution.begin(); itS != solution.end(); itS++)
				if (checkSameRoom(itC->getParameter1(), itS->first, solution))
					return false;
			break;
		}
		case 7: /* ADJACENCY_CONSTRAINT */
		{
			if (!checkAdjacency(itC->getParameter1(), itC->getParameter1(), rooms, solution))
				return false;
			break;
		}
		case 8: /* NEARBY_CONSTRAINT */
		{
			if (!checkNearness(itC->getParameter1(), itC->getParameter1(), rooms, solution))
				return false;
			break;
		}
		case 9: /* AWAYFROM_CONSTRAINT */
		{
			if (checkNearness(itC->getParameter1(), itC->getParameter1(), rooms, solution))
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
		(*solution).insert(pair<int, int>(e.getID(), r.getID()));
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