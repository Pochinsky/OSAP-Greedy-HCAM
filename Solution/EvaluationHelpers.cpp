#include <algorithm>
#include "EvaluationHelpers.hpp"

double softConstraintsViolatedPenalize(vector<Constraint> softConstraints, map<int, int> solution, map<int, double> spaceAvailable, vector<Room> rooms)
{
	double value = 0.0;
	for (Constraint constraint : softConstraints)
	{
		switch (constraint.type)
		{
		case 0: /* ALLOCATION_CONSTRAINT */
		{
			for (auto it = solution.begin(); it != solution.end(); it++)
				if (it->first == constraint.parameter1 && it->second != constraint.parameter2)
					value += 20.0;
			break;
		}
		case 1: /* NONALLOCATION_CONSTRAINT */
		{
			for (auto it = solution.begin(); it != solution.end(); it++)
				if (it->first == constraint.parameter1 && it->second == constraint.parameter2)
					value += 10.0;
			break;
		}
		case 3: /* CAPACITY_CONSTRAINT */
		{
			for (auto it = solution.begin(); it != solution.end(); it++)
				if (it->second == constraint.parameter1 && spaceAvailable[it->second] < 0)
					value += 10.0;
			break;
		}
		case 4: /* SAMEROOM_CONSTRAINT */
		{
			int roomId1;
			int roomId2;
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first == constraint.parameter1)
					roomId1 = it->second;
				if (it->first == constraint.parameter2)
					roomId2 = it->second;
			}
			if (roomId1 != roomId2)
				value += 10.0;
			break;
		}
		case 5: /* NOTSAMEROOM_CONSTRAINT */
		{
			int roomId1;
			int roomId2;
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first == constraint.parameter1)
					roomId1 = it->second;
				if (it->first == constraint.parameter2)
					roomId2 = it->second;
			}
			if (roomId1 == roomId2)
				value += 10.0;
			break;
		}
		case 6: /* NOTSHARING_CONSTRAINT */
		{
			int entityId;
			int roomId;
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first == constraint.parameter1)
				{
					entityId = it->first;
					roomId = it->second;
				}
			}
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first != entityId)
				{
					if (it->second == roomId)
					{
						value += 50.0;
						break;
					}
				}
			}
			break;
		}
		case 7: /* ADJACENCY_CONSTRAINT */
		{
			int roomId1;
			int roomId2;
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first == constraint.parameter1)
					roomId1 = it->second;
				else if (it->first == constraint.parameter2)
					roomId2 = it->second;
			}
			vector<int> adjacencyRooms = getAdjacencyRooms(roomId1, rooms);
			if (find(adjacencyRooms.begin(), adjacencyRooms.end(), roomId2) == adjacencyRooms.end())
				value += 10.0;
			break;
		}
		case 8: /* NEARBY_CONSTRAINT */
		{
			int roomId1;
			int roomId2;
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first == constraint.parameter1)
					roomId1 = it->second;
				else if (it->first == constraint.parameter2)
					roomId2 = it->second;
			}
			int floor1 = getFloor(roomId1, rooms);
			int floor2 = getFloor(roomId2, rooms);
			if (floor1 != floor2)
				value += 10.0;
			break;
		}
		case 9: /* AWAYFROM_CONSTRAINT */
		{
			int roomId1;
			int roomId2;
			for (auto it = solution.begin(); it != solution.end(); it++)
			{
				if (it->first == constraint.parameter1)
					roomId1 = it->second;
				else if (it->first == constraint.parameter2)
					roomId2 = it->second;
			}
			int floor1 = getFloor(roomId1, rooms);
			int floor2 = getFloor(roomId2, rooms);
			if (floor1 == floor2)
				value += 10.0;
			break;
		}
		default:
			break;
		}
	}
	return value;
}

double evaluateSolution(map<int, int> solution, vector<Entity> entities, vector<Room> rooms, vector<Constraint> softConstraints)
{
	double value = 0;
	// initialize space available of all rooms with capacity default
	map<int, double> spaceAvailable;
	for (Room room : rooms)
		spaceAvailable[room.id] = room.capacity;
	// calculate space available of all rooms respect to solution
	for (auto it = solution.begin(); it != solution.end(); it++)
		spaceAvailable[it->second] -= getSpace(it->first, entities);
	for (auto it = spaceAvailable.begin(); it != spaceAvailable.end(); it++)
	{
		// penalize underuse
		if (it->second > 0)
			value += it->second;
		// penalize overuse
		else if (it->second < 0)
			value += -(2 * it->second);
	}
	// penalize soft constraint violated
	value += softConstraintsViolatedPenalize(softConstraints, solution, spaceAvailable, rooms);
	return value;
}