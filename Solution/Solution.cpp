#include <algorithm>
#include <limits>
#include <chrono>
#include "GreedyHelpers.hpp"

using namespace std;
using namespace std::chrono;
using namespace std::chrono_literals;

void initialSolution(vector<Entity> entities, vector<Room> rooms, int nOfRooms, vector<Constraint> hardConstraints, map<int, int> *solution)
{
	// set variables
	map<int, double> spaceAvailable;
	for (Room r : rooms)
		spaceAvailable[r.id] = r.capacity;
	vector<int> capacity;
	vector<int> notSharing;
	map<int, int> allocation;
	map<int, vector<int>> nonAllocation;
	map<int, vector<int>> sameRoom;
	map<int, vector<int>> notSameRoom;
	map<int, vector<int>> adjacency;
	map<int, vector<int>> nearby;
	map<int, vector<int>> awayFrom;
	map<int, vector<int>> roomsProhibited;
	// save parameter or parameters of all constraint by type
	for (Constraint c : hardConstraints)
	{
		switch (c.type)
		{
		case 0:
		{
			allocation[c.parameter1] = c.parameter2;
			break;
		}
		case 1:
		{
			nonAllocation[c.parameter1].push_back(c.parameter2);
			break;
		}
		case 3:
		{
			capacity.push_back(c.parameter1);
			break;
		}
		case 4:
		{
			sameRoom[c.parameter1].push_back(c.parameter2);
			break;
		}
		case 5:
		{
			notSameRoom[c.parameter1].push_back(c.parameter2);
			break;
		}
		case 6:
		{
			notSharing.push_back(c.parameter1);
			break;
		}
		case 7:
		{
			adjacency[c.parameter1].push_back(c.parameter2);
			break;
		}
		case 8:
		{
			nearby[c.parameter1].push_back(c.parameter2);
			break;
		}
		case 9:
		{
			awayFrom[c.parameter1].push_back(c.parameter2);
			break;
		}
		default:
			break;
		}
	}
	// ALLOCATION_CONSTRAINT
	for (Entity entity : entities)
	{
		if (allocation.find(entity.id) != allocation.end())
		{
			(*solution)[entity.id] = allocation[entity.id];
			spaceAvailable[allocation[entity.id]] -= entity.space;
		}
	}
	// ADJACENCY_CONSTRAINT handless
	for (Entity entity : entities) // entity == e1
	{
		// e1 es el parametro 1 de una ADJACENCY_CONSTRAINT
		if (adjacency.find(entity.id) != adjacency.end())
		{
			for (int entityId : adjacency[entity.id]) // entityId == e2
			{
				// e2 esta en la solucion y e1 tiene que ser asignada a
				// una sala adyacente a la que fue asignada e2
				if (solution->find(entityId) != solution->end())
					greedy(entity.id, entity.space, entityId, entities, rooms, nonAllocation, capacity, sameRoom, notSameRoom,
								 notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 1, nOfRooms);
				// e2 no esta en la solucion, entonces se tiene que
				// asignar e2 y luego asignar e1 a una sala adyacente
				// de la asignada a e2
				else
				{
					// allocate e2
					greedy(entityId, getSpace(entityId, entities), -1, entities, rooms, nonAllocation, capacity, sameRoom,
								 notSameRoom, notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 3, nOfRooms);
					// allocate e1
					greedy(entity.id, entity.space, entityId, entities, rooms, nonAllocation, capacity, sameRoom, notSameRoom,
								 notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 1, nOfRooms);
				}
			}
		}
		// e1 puede ser el parametro 2 de una ADJACENCY_CONSTRAINT
		else
		{
			for (auto it = adjacency.begin(); it != adjacency.end(); it++)
			{
				// e1 es el parametro 2 de una ADJACENCY_CONSTRAINT
				if (find(it->second.begin(), it->second.end(), entity.id) != it->second.end())
				{
					// la entidad parametro 1 de la ADJACENCY_CONSTRAINT esta en la solucion
					// y e1 tiene que ser asignada a una sala adyacente a la del parametro 1
					if (solution->find(it->first) != solution->end())
						greedy(entity.id, entity.space, it->first, entities, rooms, nonAllocation, capacity, sameRoom, notSameRoom,
									 notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 1, nOfRooms);
					// la entidad parametro 1 de la ADJACENCY_CONSTRAINT no esta en la solucion
					// y e1 tiene que ser asignada
					else
						greedy(entity.id, entity.space, -1, entities, rooms, nonAllocation, capacity, sameRoom, notSameRoom,
									 notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 3, nOfRooms);
				}
			}
		}
	}
	// NOTSHARING_CONSTRAINT handless
	for (Entity entity : entities)
		if (solution->find(entity.id) == solution->end())
			if (find(notSharing.begin(), notSharing.end(), entity.id) != notSharing.end())
				greedy(entity.id, entity.space, -1, entities, rooms, nonAllocation, capacity, sameRoom, notSameRoom,
							 notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 2, nOfRooms);
	// start greedy
	for (Entity entity : entities)
		if (solution->find(entity.id) == solution->end())
			greedy(entity.id, entity.space, -1, entities, rooms, nonAllocation, capacity, sameRoom, notSameRoom,
						 notSharing, adjacency, nearby, awayFrom, &spaceAvailable, &roomsProhibited, solution, 2, nOfRooms);
}

void hillClimbing(
    int nOfEntities,
		int nOfRooms,
		vector<Entity> entities,
		vector<Room> rooms,
		vector<Constraint> softConstraints,
		vector<Constraint> hardConstraints,
		map<int, int> *solution)
{
	int neighbors = 0;
	initialSolution(
			entities,
			rooms,
			nOfRooms,
			hardConstraints,
			solution);
  auto startHC = high_resolution_clock::now();
  bool timeFlag = true;
	do
	{
		map<int, int> candidateSolution = movementToSolution(*solution, neighbors, nOfRooms);
		neighbors++;
		bool candidateSolutionIsFeasible = checkFeasible(entities, rooms, hardConstraints, candidateSolution);
		if (candidateSolutionIsFeasible)
		{
			double valueCurrentSolution = evaluateSolution(*solution, entities, rooms, softConstraints);
			double valueCandidateSolution = evaluateSolution(candidateSolution, entities, rooms, softConstraints);
			if (valueCandidateSolution < valueCurrentSolution)
			{
				solution->clear();
				for (auto it = candidateSolution.begin(); it != candidateSolution.end(); it++)
					(*solution)[it->first] = it->second;
				neighbors = 0;
			}
		}
    auto intermediateHC = high_resolution_clock::now();
    auto delta = duration_cast<seconds>(intermediateHC - startHC);
    if (delta > 180s)
      timeFlag = false;
	} while (neighbors < nOfRooms && timeFlag);
	cout << "value of = " << evaluateSolution(*solution, entities, rooms, softConstraints) << endl;
}
