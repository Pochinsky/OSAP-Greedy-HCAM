#include <iostream>
#include <map>
#include <vector>
#include "Solution.hpp"

/**
 * @brief	Genera un número entero aleatorio
 *
 * @param 	n		Número que determina el límite superior del rango disponible
 * @return int	Número aleatorio entre 0 y n-1
 */
int randint(int n);

bool checkNonAllocationConstraint(int eId, int rId, map<int, vector<int>> nonAllocation);

bool checkCapacityConstraint(int rId, double eSpace, vector<int> capacity, map<int, double> spaceAvailable);

bool checkSameRoomConstraint(int eId, int rId, map<int, vector<int>> sameRoom, map<int, int> solution);

bool checkNotSameRoomConstraint(int eId, int rId, map<int, vector<int>> notSameRoom, map<int, int> solution);

bool checkNotSharingConstraint(int eId, int rId, vector<int> notSharing, map<int, int> solution);

bool checkNearbyConstraint(int eId, int rId, map<int, vector<int>> nearby, vector<Room> rooms, map<int, int> solution);

bool checkAwayFromConstraint(int eId, int rId, map<int, vector<int>> awayFrom, vector<Room> rooms, map<int, int> solution);

bool checkAllConstraints(
		int eId, double eSpace, int rId, map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
		map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
		map<int, double> spaceAvailable, vector<Room> rooms, map<int, int> solution);

bool checkAllocation(int idEntity, int idRoom, map<int, int> solution);

bool checkCapacity(int idRoom, vector<Entity> entities, vector<Room> rooms, map<int, int> solution);

bool checkSameRoom(int idEntity1, int idEntity2, map<int, int> solution);

bool checkAdjacency(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

bool checkNearness(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

bool checkFeasible(vector<Entity> entities, vector<Room> rooms, vector<Constraint> hardConstraints, map<int, int> solution);

void notSameRoomProhibite(int eId, map<int, vector<int>> notSameRoom, map<int, int> solution, map<int, vector<int>> *roomsProhibited);

void notSharingProhibite(int eId, vector<int> notSharing, map<int, int> solution, map<int, vector<int>> *roomsProhibited);

void nearbyProhibite(int eId, map<int, vector<int>> nearby, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

void awayFromProhibite(int eId, map<int, vector<int>> awayFrom, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

void prohibite(int eId, map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
							 map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

int getNotSharingIndex(vector<int> notSharing, int entityId);

vector<int> getAdjacencyRooms(int roomId, vector<Room> rooms);

int getSpace(int entityId, vector<Entity> entities);

int getFloor(int roomId, vector<Room> rooms);

/**
 * @brief	Muestra por pantalla las asignaciones de una solución
 *
 * @param solution	Hashmap el cual contiene la solución que se quiere visualizar
 */
void printSolution(map<int, int> solution);

void printConstraints(vector<Constraint> constraints);