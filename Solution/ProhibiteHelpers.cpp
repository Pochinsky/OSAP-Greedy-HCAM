#include <algorithm>
#include <bits/stdc++.h>
#include "Helpers.hpp"

void notSameRoomProhibite(int eId, map<int, vector<int>> notSameRoom, map<int, int> solution, map<int, vector<int>> *roomsProhibited)
{
	if (notSameRoom.find(eId) != notSameRoom.end())
		for (int eIdAux : notSameRoom[eId])
			if (solution.find(eIdAux) != solution.end())
				if (find((*roomsProhibited)[eId].begin(), (*roomsProhibited)[eId].end(), solution[eIdAux]) == (*roomsProhibited)[eId].end())
					(*roomsProhibited)[eId].push_back(solution[eIdAux]);
}

void notSharingProhibite(int eId, vector<int> notSharing, map<int, int> solution, map<int, vector<int>> *roomsProhibited)
{
	if (find(notSharing.begin(), notSharing.end(), eId) != notSharing.end())
		for (auto it = solution.begin(); it != solution.end(); it++)
			if (find((*roomsProhibited)[eId].begin(), (*roomsProhibited)[eId].end(), it->second) == (*roomsProhibited)[eId].end())
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
						if (find((*roomsProhibited)[eId].begin(), (*roomsProhibited)[eId].end(), r.id) == (*roomsProhibited)[eId].end())
							(*roomsProhibited)[eId].push_back(r.id);
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
						if (find((*roomsProhibited)[eId].begin(), (*roomsProhibited)[eId].end(), r.id) == (*roomsProhibited)[eId].end())
							(*roomsProhibited)[eId].push_back(r.id);
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
