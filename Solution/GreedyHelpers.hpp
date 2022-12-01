#include <iostream>
#include <map>
#include <vector>
#include "ConstraintsHelpers.hpp"

/**************************************************************
 * 	Funcion que ejecuta un algoritmo greedy considerando      *
 * 	que una entidad debe ser asignada a una sala              *
 * 	adyacente respecto a otra entidad ya asignada a una sala  * 
 *                                                            *
 **************************************************************/
void greedyApproach1(int *candidateRoomId, double *candidateRoomSpace, int eId1, double eSpace1, int eId2, vector<Room> rooms,
										 map<int, double> spaceAvailable, map<int, vector<int>> nonAllocation, vector<int> capacity,
										 map<int, vector<int>> sameRoom, map<int, vector<int>> notSameRoom, vector<int> notSharing,
										 map<int, vector<int>> adjacency, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms);

/*********************************************
 * 	Funcion que ejecuta un algoritmo greedy  * 
 *                                           *
 *********************************************/
void greedyApproach2(int eId, int *candidateRoomId, double *candidateRoomSpace, vector<Entity> entities, vector<Room> rooms,
										 map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
										 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
										 map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> spaceAvailable,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms);

/*************************************************************
 * 	Funcion que ejecuta un algoritmo greedy considerando     *
 * 	que una entidad debe quedar con una lista de adyacencia  *
 * 	no vacia dado que es la entidad que condicionara una     *
 * 	restriccion de adyacencia                                *
 *                                                           *
 *************************************************************/
void greedyApproach3(int eId, int *candidateRoomId, double *candidateRoomSpace, vector<Entity> entities, vector<Room> rooms,
										 map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
										 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
										 map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> spaceAvailable,
										 map<int, vector<int>> roomsProhibited, map<int, int> solution, int nOfRooms);

/****************************************************************
 * 	Funcion que gestiona que tipo de algoritmo greedy utilizar  * 
 *                                                              *
 ****************************************************************/
void greedy(int eId1, double eSpace1, int eId2, vector<Entity> entities, vector<Room> rooms,
						map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
						map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency,
						map<int, vector<int>> nearby, map<int, vector<int>> awayFrom, map<int, double> *spaceAvailable,
						map<int, vector<int>> *roomsProhibited, map<int, int> *solution, int greedyApproachType, int nOfRooms);