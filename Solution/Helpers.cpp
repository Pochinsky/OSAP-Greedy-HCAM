#include <algorithm>
#include <bits/stdc++.h>
#include "Helpers.hpp"

int randint(int n) { return rand() % n; }

bool checkNonAllocationConstraint(int eId, int rId, map<int, vector<int>> nonAllocation)
{
	int check = true;
	if (nonAllocation.find(eId) != nonAllocation.end())
		if (find(nonAllocation[eId].begin(), nonAllocation[eId].end(), rId) != nonAllocation[eId].end())
			check = false;
	return check;
}

bool checkCapacityConstraint(int rId, double eSpace, vector<int> capacity, map<int, double> spaceAvailable)
{
	bool check = true;
	if (find(capacity.begin(), capacity.end(), rId) != capacity.end())
		if (spaceAvailable[rId] - eSpace < 0)
			check = false;
	return check;
}

bool checkSameRoomConstraint(int eId, int rId, map<int, vector<int>> sameRoom, map<int, int> solution)
{
	bool check = true;
	if (sameRoom.find(eId) != sameRoom.end())
	{
		for (int eIdAux : sameRoom[eId])
			if (solution.find(eIdAux) != solution.end())
				if (rId != solution[eIdAux])
					check = false;
	}
	else
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (sameRoom.find(it->first) != sameRoom.end())
				for (int eIdAux : sameRoom[it->first])
					if (eIdAux == eId)
						if (rId != it->second)
							check = false;
	return check;
}

bool checkNotSameRoomConstraint(int eId, int rId, map<int, vector<int>> notSameRoom, map<int, int> solution)
{
	bool check = true;
	if (notSameRoom.find(eId) != notSameRoom.end())
	{
		for (int eIdAux : notSameRoom[eId])
			if (solution.find(eIdAux) != solution.end())
				if (rId == solution[eIdAux])
					check = false;
	}
	else
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (notSameRoom.find(it->first) != notSameRoom.end())
				for (int eIdAux : notSameRoom[it->first])
					if (eIdAux == eId)
						if (rId == it->second)
							check = false;
	return check;
}

bool checkNotSharingConstraint(int eId, int rId, vector<int> notSharing, map<int, int> solution)
{
	bool check = true;
	if (find(notSharing.begin(), notSharing.end(), eId) != notSharing.end())
	{
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (rId == it->second)
				check = false;
	}
	else
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (find(notSharing.begin(), notSharing.end(), it->first) != notSharing.end())
				if (rId == it->second)
					check = false;
	return check;
}

bool checkNearbyConstraint(int eId, int rId, map<int, vector<int>> nearby, vector<Room> rooms, map<int, int> solution)
{
	bool check = true;
	if (nearby.find(eId) != nearby.end())
	{
		for (int eIdAux : nearby[eId])
		{
			if (solution.find(eIdAux) != solution.end())
			{
				int floor1 = getFloor(rId, rooms);
				int floor2 = getFloor(solution[eIdAux], rooms);
				if (floor1 != floor2)
					check = false;
			}
		}
	}
	else
	{
		for (auto it = solution.begin(); it != solution.end(); it++)
		{
			if (nearby.find(it->first) != nearby.end())
			{
				for (int eIdAux : nearby[it->first])
				{
					if (eIdAux == eId)
					{
						int floor1 = getFloor(rId, rooms);
						int floor2 = getFloor(it->second, rooms);
						if (floor1 != floor2)
							check = false;
					}
				}
			}
		}
	}
	return check;
}

bool checkAwayFromConstraint(int eId, int rId, map<int, vector<int>> awayFrom, vector<Room> rooms, map<int, int> solution)
{
	bool check = true;
	if (awayFrom.find(eId) != awayFrom.end())
	{
		for (int eIdAux : awayFrom[eId])
		{
			if (solution.find(eIdAux) != solution.end())
			{
				int floor1 = getFloor(rId, rooms);
				int floor2 = getFloor(solution[eIdAux], rooms);
				if (floor1 == floor2)
					check = false;
			}
		}
	}
	else
	{
		for (auto it = solution.begin(); it != solution.end(); it++)
		{
			if (awayFrom.find(it->first) != awayFrom.end())
			{
				for (int eIdAux : awayFrom[it->first])
				{
					if (eIdAux == eId)
					{
						int floor1 = getFloor(rId, rooms);
						int floor2 = getFloor(it->second, rooms);
						if (floor1 == floor2)
							check = false;
					}
				}
			}
		}
	}
	return check;
}

bool checkAllConstraints(
		int eId, double eSpace, int rId, map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
		map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
		map<int, double> spaceAvailable, vector<Room> rooms, map<int, int> solution)
{
	bool check = true;
	if (!checkNonAllocationConstraint(eId, rId, nonAllocation))
		check = false;
	if (!checkCapacityConstraint(rId, eSpace, capacity, spaceAvailable))
		check = false;
	if (!checkSameRoomConstraint(eId, rId, sameRoom, solution))
		check = false;
	if (!checkNotSameRoomConstraint(eId, rId, notSameRoom, solution))
		check = false;
	if (!checkNotSharingConstraint(eId, rId, notSharing, solution))
		check = false;
	if (!checkNearbyConstraint(eId, rId, nearby, rooms, solution))
		check = false;
	if (!checkAwayFromConstraint(eId, rId, awayFrom, rooms, solution))
		check = false;
	return check;
}

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

void notSameRoomProhibite(int eId, map<int, vector<int>> notSameRoom, map<int, int> solution, map<int, vector<int>> *roomsProhibited)
{
	if (notSameRoom.find(eId) != notSameRoom.end())
	{
		for (int eIdAux : notSameRoom[eId])
			if (solution.find(eIdAux) != solution.end())
				(*roomsProhibited)[eId].push_back(solution[eIdAux]);
	}
	else
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (notSameRoom.find(it->first) != notSameRoom.end())
				for (int eIdAux : notSameRoom[it->first])
					if (eIdAux == eId)
						(*roomsProhibited)[eId].push_back(it->second);
}

void notSharingProhibite(int eId, vector<int> notSharing, map<int, int> solution, map<int, vector<int>> *roomsProhibited)
{
	if (find(notSharing.begin(), notSharing.end(), eId) != notSharing.end())
		for (auto it = solution.begin(); it != solution.end(); it++)
			(*roomsProhibited)[eId].push_back(it->second);
	else
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (find(notSharing.begin(), notSharing.end(), it->first) != notSharing.end())
				(*roomsProhibited)[eId].push_back(it->second);
}

void nearbyProhibite(int eId, map<int, vector<int>> nearby, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms)
{
	if (nearby.find(eId) != nearby.end())
	{
		for (int eIdAux : nearby[eId])
		{
			if (solution.find(eIdAux) != solution.end())
			{
				for (Room r : rooms)
				{
					int floor1 = getFloor(solution[eIdAux], rooms);
					int floor2 = r.floor;
					if (floor1 != floor2)
						(*roomsProhibited)[eId].push_back(r.id);
				}
			}
		}
	}
	else
	{
		for (auto it = solution.begin(); it != solution.end(); it++)
		{
			if (nearby.find(it->first) != nearby.end())
			{
				for (int eIdAux : nearby[it->first])
				{
					if (eId == eIdAux)
					{
						for (Room r : rooms)
						{
							int floor1 = getFloor(it->second, rooms);
							int floor2 = r.floor;
							if (floor1 != floor2)
								(*roomsProhibited)[eId].push_back(r.id);
						}
					}
				}
			}
		}
	}
}

void awayFromProhibite(int eId, map<int, vector<int>> awayFrom, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms)
{
	if (awayFrom.find(eId) != awayFrom.end())
	{
		for (int eIdAux : awayFrom[eId])
		{
			if (solution.find(eIdAux) != solution.end())
			{
				for (Room r : rooms)
				{
					int floor1 = getFloor(solution[eIdAux], rooms);
					int floor2 = r.floor;
					if (floor1 == floor2)
						(*roomsProhibited)[eId].push_back(r.id);
				}
			}
		}
	}
	else
	{
		for (auto it = solution.begin(); it != solution.end(); it++)
		{
			if (awayFrom.find(it->first) != awayFrom.end())
			{
				for (int eIdAux : awayFrom[it->first])
				{
					if (eId == eIdAux)
					{
						for (Room r : rooms)
						{
							int floor1 = getFloor(it->second, rooms);
							int floor2 = r.floor;
							if (floor1 == floor2)
								(*roomsProhibited)[eId].push_back(r.id);
						}
					}
				}
			}
		}
	}
}

void prohibite(int eId, map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
							 map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms)
{
	notSameRoomProhibite(eId, notSameRoom, solution, roomsProhibited);
	notSharingProhibite(eId, notSharing, solution, roomsProhibited);
	nearbyProhibite(eId, nearby, solution, roomsProhibited, rooms);
	awayFromProhibite(eId, awayFrom, solution, roomsProhibited, rooms);
}

int getNotSharingIndex(vector<int> notSharing, int entityId)
{
	auto it = find(notSharing.begin(), notSharing.end(), entityId);
	if (it != notSharing.end())
		return it - notSharing.begin();
	else
		return -1;
}

vector<int> getAdjacencyRooms(int roomId, vector<Room> rooms)
{
	vector<int> adjacentRooms;
	for (Room r : rooms)
		if (r.id == roomId)
			adjacentRooms = r.adjacentRooms;
	return adjacentRooms;
}

int getSpace(int entityId, vector<Entity> entities)
{
	int space;
	for (Entity e : entities)
		if (e.id == entityId)
			space = e.space;
	return space;
}

int getFloor(int roomId, vector<Room> rooms)
{
	int floor;
	for (Room r : rooms)
		if (r.id == roomId)
			floor = r.floor;
	return floor;
}

void printSolution(map<int, int> solution)
{
	cout << "########## Solución ##########" << endl;
	map<int, int>::iterator it;
	for (it = solution.begin(); it != solution.end(); ++it)
		cout << "e" << it->first << "\tto\tr" << it->second << endl;
}

void printConstraints(vector<Constraint> constraints)
{
	for (Constraint c : constraints)
		c.print();
}
