#include <algorithm>
#include <bits/stdc++.h>
#include "Helpers.hpp"

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
