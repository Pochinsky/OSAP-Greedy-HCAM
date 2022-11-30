#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <bits/stdc++.h>
#include "Helpers.hpp"

int randint(int n)
{
  srand(time(0));
	return rand() % n;
}

map<int, int> movementToSolution(map<int, int> currentSolution, int entityId, int nOfRooms)
{
	map<int, int> candidateSolution;
	int roomId;
	while (true)
	{
		roomId = randint(nOfRooms);
		if (roomId != currentSolution[entityId])
			break;
	}
	for (auto it = currentSolution.begin(); it != currentSolution.end(); it++)
	{
		if (it->first == entityId)
			candidateSolution[it->first] = roomId;
		else
			candidateSolution[it->first] = it->second;
	}
	return candidateSolution;
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
