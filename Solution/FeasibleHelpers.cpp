#include <algorithm>
#include <bits/stdc++.h>
#include "FeasibleHelpers.hpp"

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
	int roomCapacity;
	for (Room r : rooms)
		if (idRoom == r.id)
			roomCapacity = r.capacity;
	map<int, int>::iterator itS;
	list<int> entitiesInRoom;
	entitiesInRoom.push_back(1);
	entitiesInRoom.clear();
	for (itS = solution.begin(); itS != solution.end(); itS++)
		if (idRoom == itS->second)
			entitiesInRoom.push_back(itS->first);
	int sizeUse = 0;
	for (Entity e : entities)
		if (find(entitiesInRoom.begin(), entitiesInRoom.end(), e.id) != entitiesInRoom.end())
			sizeUse += e.space;
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
			idRoom1 = itS->second;
		if (idEntity2 == itS->first)
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
			idRoom1 = itS->second;
		if (idEntity2 == itS->first)
			idRoom2 = itS->second;
	}
	for (Room r : rooms)
	{
		if (idRoom1 == r.id)
		{
			if (find(r.adjacentRooms.begin(), r.adjacentRooms.end(), idRoom2) == r.adjacentRooms.end())
				return false;
		}
		if (idRoom2 == r.id)
		{
			if (find(r.adjacentRooms.begin(), r.adjacentRooms.end(), idRoom1) == r.adjacentRooms.end())
				return false;
		}
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
			idRoom1 = itS->second;
		if (idEntity2 == itS->first)
			idRoom2 = itS->second;
	}
	int idFloor1, idFloor2;
	for (Room r : rooms)
	{
		if (idRoom1 == r.id)
			idFloor1 = r.floor;
		if (idRoom2 == r.id)
			idFloor2 = r.floor;
	}
	if (idFloor1 != idFloor2)
		return false;
	return true;
}

bool checkFeasible(vector<Entity> entities, vector<Room> rooms, vector<Constraint> hardConstraints, map<int, int> solution)
{
	for (Constraint c : hardConstraints)
	{
		switch (c.type)
		{
		case 0: /* ALLOCATION_CONSTRAINT */
		{
			if (!checkAllocation(c.parameter1, c.parameter2, solution))
			{
				cout << "ALLOCATION_CONSTRAINT" << endl;
				return false;
			}
			break;
		}
		case 1: /* NONALLOCATION_CONSTRAINT */
		{
			if (checkAllocation(c.parameter1, c.parameter2, solution))
			{
				cout << "NONALLOCATION_CONSTRAINT" << endl;
				return false;
			}
			break;
		}
		case 3: /* CAPACITY_CONSTRAINT */
		{
			if (!checkCapacity(c.id, entities, rooms, solution))
			{
				cout << "CAPACITY_CONSTRAINT" << endl;
				return false;
			}
			break;
		}
		case 4: /* SAMEROOM_CONSTRAINT */
		{
			if (!checkSameRoom(c.parameter1, c.parameter2, solution))
			{
				cout << "SAMEROOM_CONSTRAINT" << endl;
				return false;
			}
			break;
		}
		case 5: /* NOTSAMEROOM_CONSTRAINT */
		{
			if (checkSameRoom(c.parameter1, c.parameter2, solution))
			{
				cout << "NOTSAMEROOM_CONSTRAINT" << endl;
				return false;
			}
			break;
		}
		case 6: /* NOTSHARING_CONSTRAINT */
		{
			map<int, int>::iterator itS;
			for (itS = solution.begin(); itS != solution.end(); itS++)
				if (c.parameter1 != itS->first)
				{
					if (checkSameRoom(c.parameter1, itS->first, solution))
					{
						cout << "NOTSHARING_CONSTRAINT" << endl;
						cout << "e" << c.parameter1 << "\tr" << solution[c.parameter1] << endl;
						return false;
					}
				}
			break;
		}
		case 7: /* ADJACENCY_CONSTRAINT */
		{
			if (!checkAdjacency(c.parameter1, c.parameter2, rooms, solution))
			{
				cout << "ADJACENCY_CONSTRAINT" << endl;
				cout << "e" << c.parameter1 << "\tr" << solution[c.parameter1] << endl;
				cout << "e" << c.parameter2 << "\tr" << solution[c.parameter2] << endl;
				return false;
			}
			break;
		}
		case 8: /* NEARBY_CONSTRAINT */
		{
			if (!checkNearness(c.parameter1, c.parameter2, rooms, solution))
			{
				cout << "NEARBY_CONSTRAINT" << endl;
				return false;
			}
			break;
		}
		case 9: /* AWAYFROM_CONSTRAINT */
		{
			if (checkNearness(c.parameter1, c.parameter2, rooms, solution))
			{
				cout << "AWAYFOM_CONSTRAINT" << endl;
			}
			break;
		}
		default:
			break;
		}
	}
	return true;
}
