#include <algorithm>
#include <bits/stdc++.h>
#include "ConstraintsHelpers.hpp"

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
