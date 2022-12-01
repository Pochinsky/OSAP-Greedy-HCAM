#include <iostream>
#include <map>
#include <vector>
#include "EvaluationHelpers.hpp"

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de no asignacion                               *
 *                                                      *
 ********************************************************/
bool checkNonAllocationConstraint(int eId, int rId, map<int, vector<int>> nonAllocation);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de capcidad                                    *
 *                                                      *
 ********************************************************/
bool checkCapacityConstraint(int rId, double eSpace, vector<int> capacity, map<int, double> spaceAvailable);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura sala compartida                                *
 *                                                      *
 ********************************************************/
bool checkSameRoomConstraint(int eId, int rId, map<int, vector<int>> sameRoom, map<int, int> solution);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de no compartir salas                          *
 *                                                      *
 ********************************************************/
bool checkNotSameRoomConstraint(int eId, int rId, map<int, vector<int>> notSameRoom, map<int, int> solution);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de sala no compartida                          *
 *                                                      *
 ********************************************************/
bool checkNotSharingConstraint(int eId, int rId, vector<int> notSharing, map<int, int> solution);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de adyacencia                                  *
 *                                                      *
 ********************************************************/
bool checkAdjacencyConstraint(int eId, int rId, vector<Room> rooms, map<int, vector<int>> adjacency, map<int, int> solution);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de cercania                                    *
 *                                                      *
 ********************************************************/
bool checkNearbyConstraint(int eId, int rId, map<int, vector<int>> nearby, vector<Room> rooms, map<int, int> solution);

/********************************************************
 * 	Funcion que corrobora si se cumple una restriccion  *
 * 	dura de lejania                                     *
 *                                                      *
 ********************************************************/
bool checkAwayFromConstraint(int eId, int rId, map<int, vector<int>> awayFrom, vector<Room> rooms, map<int, int> solution);

/**************************************************
 * 	Funcion que corrobora si se cumple todas las  *
 * 	restricciones duras                           *
 *                                                *
 **************************************************/
bool checkAllConstraints(int eId, double eSpace, int rId, map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
												 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency, map<int, vector<int>> nearby,
												 map<int, vector<int>> awayFrom, map<int, double> spaceAvailable, vector<Room> rooms, map<int, int> solution);