#include <iostream>
#include <map>
#include <vector>
#include "ConstraintsHelpers.hpp"

void greedyApproach1(int *candidateRoomId, double *candidateRoomSpace, int eId1, double eSpace1, int eId2, vector<Room> rooms,
										 map<int, double> spaceAvailable, map<int, vector<int>> nonAllocation, vector<int> capacity,
										 map<int, vector<int>> sameRoom, map<int, vector<int>> notSameRoom, vector<int> notSharing,
										 map<int, vector<int>> adjacency, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms);

void greedyApproach2(int eId, int *candidateRoomId, double *candidateRoomSpace, vector<Entity> entities, vector<Room> rooms,
										 map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
										 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
										 map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> spaceAvailable,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms);

void greedyApproach3(int eId, int *candidateRoomId, double *candidateRoomSpace, vector<Entity> entities, vector<Room> rooms,
										 map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
										 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
										 map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> spaceAvailable,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms);

void greedy(int eId1, double eSpace1, int eId2, vector<Entity> entities, vector<Room> rooms,
						map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
						map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
						map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> *spaceAvailable,
						map<int, vector<int>> *roomsProhibited, map<int, int> *solution, int greedyApproachType, int nOfRooms);