#include <algorithm>
#include <limits>
#include "GreedyHelpers.hpp"

void greedyApproach1(int *candidateRoomId, double *candidateRoomSpace, int eId1, double eSpace1, int eId2, vector<Room> rooms,
										 map<int, double> spaceAvailable, map<int, vector<int>> nonAllocation, vector<int> capacity,
										 map<int, vector<int>> sameRoom, map<int, vector<int>> notSameRoom, vector<int> notSharing,
										 map<int, vector<int>> adjacency, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms)
{
	*candidateRoomId = -1;
	*candidateRoomSpace = -numeric_limits<double>::max();
	bool isFeasible = true;
	for (Room room : rooms)
	{
		if (find(roomsProhibited[eId1].begin(), roomsProhibited[eId1].end(), room.id) == roomsProhibited[eId1].end())
		{
			vector<int> adjacentRooms = getAdjacencyRooms(solution[eId2], rooms);
			if (adjacentRooms.size() > 0)
			{
				if (find(adjacentRooms.begin(), adjacentRooms.end(), room.id) != adjacentRooms.end())
				{
					// check constraints respect to solution
					isFeasible = checkAllConstraints(eId1, eSpace1, room.id, nonAllocation, capacity, sameRoom, notSameRoom,
																					 notSharing, adjacency, nearby, awayFrom, spaceAvailable, rooms, solution);
				}
				else
					isFeasible = false;
			}
			else
				isFeasible = false;
		}
		else
			isFeasible = false;
		for (auto it = roomsProhibited.begin(); it != roomsProhibited.end(); it++)
			if (static_cast<int>(it->second.size()) + 1 == nOfRooms)
				isFeasible = false;
		if (isFeasible && spaceAvailable[room.id] - eSpace1 > *candidateRoomSpace)
		{
			*candidateRoomId = room.id;
			*candidateRoomSpace = spaceAvailable[*candidateRoomId] - eSpace1;
		}
	}
}

void greedyApproach2(int eId, int *candidateRoomId, double *candidateRoomSpace, vector<Entity> entities, vector<Room> rooms,
										 map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
										 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
										 map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> spaceAvailable,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms)
{
	*candidateRoomId = -1;
	*candidateRoomSpace = -numeric_limits<double>::max();
	bool isFeasible = true;
	for (Room room : rooms)
	{
		if (find(roomsProhibited[eId].begin(), roomsProhibited[eId].end(), room.id) == roomsProhibited[eId].end())
		{
			isFeasible = checkAllConstraints(eId, getSpace(eId, entities), room.id, nonAllocation, capacity, sameRoom,
																			 notSameRoom, notSharing, adjacency, nearby, awayFrom, spaceAvailable, rooms, solution);
		}
		else
			isFeasible = false;
		for (auto it = roomsProhibited.begin(); it != roomsProhibited.end(); it++)
			if (static_cast<int>(it->second.size()) + 1 == nOfRooms)
				isFeasible = false;
		if (isFeasible && spaceAvailable[room.id] - getSpace(eId, entities) > *candidateRoomSpace)
		{
			*candidateRoomId = room.id;
			*candidateRoomSpace = spaceAvailable[*candidateRoomId] - getSpace(eId, entities);
		}
	}
}

void greedyApproach3(int eId, int *candidateRoomId, double *candidateRoomSpace, vector<Entity> entities, vector<Room> rooms,
										 map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
										 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
										 map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> spaceAvailable,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms)
{
	*candidateRoomId = -1;
	*candidateRoomSpace = -numeric_limits<double>::max();
	bool isFeasible = true;
	for (Room room : rooms)
	{
		if (find(roomsProhibited[eId].begin(), roomsProhibited[eId].end(), room.id) == roomsProhibited[eId].end())
		{
			vector<int> adjacentRooms = getAdjacencyRooms(room.id, rooms);
			if (adjacentRooms.size() > 0)
				// check constraints respect to solution
				isFeasible = checkAllConstraints(eId, getSpace(eId, entities), room.id, nonAllocation, capacity, sameRoom,
																				 notSameRoom, notSharing, adjacency, nearby, awayFrom, spaceAvailable, rooms, solution);
			else
				isFeasible = false;
		}
		else
			isFeasible = false;
		for (auto it = roomsProhibited.begin(); it != roomsProhibited.end(); it++)
			if (static_cast<int>(it->second.size()) + 1 == nOfRooms)
				isFeasible = false;
		if (isFeasible && spaceAvailable[room.id] - getSpace(eId, entities) > *candidateRoomSpace)
		{
			*candidateRoomId = room.id;
			*candidateRoomSpace = spaceAvailable[*candidateRoomId] - getSpace(eId, entities);
		}
	}
}

void greedy(int eId1, double eSpace1, int eId2, vector<Entity> entities, vector<Room> rooms,
						map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
						map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
						map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> *spaceAvailable,
						map<int, vector<int>> *roomsProhibited, map<int, int> *solution, int greedyApproachType, int nOfRooms)
{
	int candidateRoomId;
	double candidateRoomSpace;
	if (greedyApproachType == 1)
		greedyApproach1(&candidateRoomId, &candidateRoomSpace, eId1, eSpace1, eId2, rooms, *spaceAvailable, nonAllocation,
										capacity, sameRoom, notSameRoom, notSharing, adjacency, nearby, awayFrom, *roomsProhibited, *solution, nOfRooms);
	else if (greedyApproachType == 2)
		greedyApproach2(eId1, &candidateRoomId, &candidateRoomSpace, entities, rooms, nonAllocation, capacity, sameRoom,
										notSameRoom, notSharing, adjacency, nearby, awayFrom, *spaceAvailable, *roomsProhibited, *solution, nOfRooms);
	else if (greedyApproachType == 3)
		greedyApproach3(eId1, &candidateRoomId, &candidateRoomSpace, entities, rooms, nonAllocation, capacity, sameRoom,
										notSameRoom, notSharing, adjacency, nearby, awayFrom, *spaceAvailable, *roomsProhibited, *solution, nOfRooms);
	(*solution)[eId1] = candidateRoomId;
	(*spaceAvailable)[candidateRoomId] = candidateRoomSpace;
	// prohibite rooms to entities not allocated
	for (Entity e : entities)
		if (solution->find(e.id) == solution->end())
			prohibite(e.id, notSameRoom, notSharing, nearby, awayFrom, *solution, roomsProhibited, rooms);
}
