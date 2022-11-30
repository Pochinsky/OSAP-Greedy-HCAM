#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include "Output.hpp"

int getIndex(vector<int> v, int K)
{
	int index = -1;
	auto it = find(v.begin(), v.end(), K);
	if (it != v.end())
		index = it - v.begin();
	return index;
}

void output(map<int, int> solution, vector<Entity> entities, vector<Room> rooms,
						vector<Constraint> softConstraints, string outputFilename)
{
	int nOfSoftConstraintsViolated = 0;
	vector<int> softConstraintsViolated;
  vector<int> roomsSpaceChecked;
  double totalRoomsSpace = 0.0;
	double totalSpaceMisused = 0.0;
	double totalSpaceUnderused = 0.0;
	double totalSpaceOverused = 0.0;
	map<int, double> spaceUnderused;
	map<int, double> spaceOverused;
	map<int, int> nOfEntitiesAllocated;
	map<int, vector<int>> entitiesAllocated;
	map<int, double> spaceAvailable;
	map<int, vector<int>> allocations;
	// initialize data
	for (Room room : rooms)
	{
    totalRoomsSpace += room.capacity;
		spaceUnderused[room.id] = room.capacity;
		spaceOverused[room.id] = 0.0;
		nOfEntitiesAllocated[room.id] = 0;
		spaceAvailable[room.id] = room.capacity;
	}
	// update data
	for (auto it = solution.begin(); it != solution.end(); it++)
	{
		nOfEntitiesAllocated[it->second]++;
		entitiesAllocated[it->second].push_back(it->first);
		spaceAvailable[it->second] -= getSpace(it->first, entities);
    if (spaceAvailable[it->second] > 0)
    {
      spaceUnderused[it->second] -= getSpace(it->first, entities);
      spaceOverused[it->second] = 0.0;
    }
    else if (spaceAvailable[it->second] < 0)
    {
      spaceUnderused[it->second] = 0.0;
      spaceOverused[it->second] = -spaceAvailable[it->second];
    }
    else
    {
      spaceUnderused[it->second] = 0.0;
      spaceOverused[it->second] = 0.0;
    }
	}
  vector<int> roomsSpaceAvailableChecked;
	for (auto it = solution.begin(); it != solution.end(); it++)
	{
		// get soft constraint violated data
		for (Constraint constraint : softConstraints)
		{
			switch (constraint.type)
			{
			case 0: /* ALLOCATION_CONSTRAINT */
			{
				for (auto it = solution.begin(); it != solution.end(); it++)
				{
					if (it->first == constraint.parameter1 && it->second != constraint.parameter2)
					{
						if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
						{
							nOfSoftConstraintsViolated++;
							softConstraintsViolated.push_back(constraint.id);
						}
					}
				}
				break;
			}
			case 1: /* NONALLOCATION_CONSTRAINT */
			{
				for (auto it = solution.begin(); it != solution.end(); it++)
				{
					if (it->first == constraint.parameter1 && it->second == constraint.parameter2)
					{
						if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
						{
							nOfSoftConstraintsViolated++;
							softConstraintsViolated.push_back(constraint.id);
						}
					}
				}
				break;
			}
			case 3: /* CAPACITY_CONSTRAINT */
			{
				for (auto it = solution.begin(); it != solution.end(); it++)
				{
					if (it->second == constraint.parameter1 && spaceAvailable[it->second] < 0)
					{
						if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
						{
							nOfSoftConstraintsViolated++;
							softConstraintsViolated.push_back(constraint.id);
						}
					}
				}
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
				{
					if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
					{
						nOfSoftConstraintsViolated++;
						softConstraintsViolated.push_back(constraint.id);
					}
				}
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
				{
					if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
					{
						nOfSoftConstraintsViolated++;
						softConstraintsViolated.push_back(constraint.id);
					}
				}
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
							{
								if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
								{
									nOfSoftConstraintsViolated++;
									softConstraintsViolated.push_back(constraint.id);
								}
							}
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
				{
					if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
					{
						nOfSoftConstraintsViolated++;
						softConstraintsViolated.push_back(constraint.id);
					}
				}
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
				{
					if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
					{
						nOfSoftConstraintsViolated++;
						softConstraintsViolated.push_back(constraint.id);
					}
				}
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
				{
					if (find(softConstraintsViolated.begin(), softConstraintsViolated.end(), constraint.id) == softConstraintsViolated.end())
					{
						nOfSoftConstraintsViolated++;
						softConstraintsViolated.push_back(constraint.id);
					}
				}
				break;
			}
			default:
				break;
			}
		}
		// get space misused data
    if (find(roomsSpaceAvailableChecked.begin(),roomsSpaceAvailableChecked.end(),it->second) == roomsSpaceAvailableChecked.end())
    {
      if (spaceAvailable[it->second] > 0)
      {
        totalSpaceMisused += spaceUnderused[it->second];
        totalSpaceUnderused += spaceUnderused[it->second];
      }
      else if (spaceAvailable[it->second] < 0)
      {
        totalSpaceMisused += spaceOverused[it->second];
        totalSpaceOverused += spaceOverused[it->second];
      }
      roomsSpaceAvailableChecked.push_back(it->second);
    }
	}
	// set output data
	for (auto it = entitiesAllocated.begin(); it != entitiesAllocated.end(); it++)
	{
		allocations[it->first] = it->second;
	}
  // print relevant data
  cout << "Total rooms capacity      = " << totalRoomsSpace << endl;
  cout << "Total space underused     = " << totalSpaceUnderused << endl;
  cout << "Total space overused      = " << totalSpaceOverused  << endl;
  cout << "Total soft constraints    = " << softConstraints.size() << endl;
  cout << "Soft Constraints Violated = " << nOfSoftConstraintsViolated << endl;
	// generate output file
	ofstream writeFile(outputFilename + ".out");
	writeFile << nOfSoftConstraintsViolated;
	for (int constraintId : softConstraintsViolated)
	{
		if (getIndex(softConstraintsViolated, constraintId) == 0)
			writeFile << "\t\t\t\t" << constraintId;
		else
			writeFile << " " << constraintId;
	}
	writeFile << "\n";
	double intPart;
	if (modf(totalSpaceMisused, &intPart) == 0.0)
		writeFile << totalSpaceMisused << "\t\t\t" << totalSpaceUnderused << " " << totalSpaceOverused << "\n";
	else
		writeFile << totalSpaceMisused << "\t\t" << totalSpaceUnderused << " " << totalSpaceOverused << "\n";
	for (auto it = allocations.begin(); it != allocations.end(); it++)
	{
		if (it->first < 10)
			writeFile << it->first << "\t\t\t\t\t" << spaceUnderused[it->first] << " " << spaceOverused[it->first] << " " << nOfEntitiesAllocated[it->first];
		else
			writeFile << it->first << "\t\t\t\t" << spaceUnderused[it->first] << " " << spaceOverused[it->first] << " " << nOfEntitiesAllocated[it->first];
		for (int entityId : entitiesAllocated[it->first])
			writeFile << " " << entityId;
		writeFile << "\n";
	}
	writeFile.close();
}
