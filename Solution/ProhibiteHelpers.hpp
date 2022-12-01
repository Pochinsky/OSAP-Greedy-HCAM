#include <iostream>
#include <map>
#include <vector>
#include "Solution.hpp"

/**************************************************
 * 	Funcion que registra las salas que no pueden  *
 * 	ser asignadas para ciertas entidades segun    *
 * 	restricciones de distintas salas              *
 *                                                *
 **************************************************/
void notSameRoomProhibite(int eId, map<int, vector<int>> notSameRoom, map<int, int> solution, map<int, vector<int>> *roomsProhibited);

/**************************************************
 * 	Funcion que registra las salas que no pueden  *
 * 	ser asignadas para ciertas entidades segun    *
 * 	restricciones de sala no compartida           *
 *                                                *
 **************************************************/
void notSharingProhibite(int eId, vector<int> notSharing, map<int, int> solution, map<int, vector<int>> *roomsProhibited);

/**************************************************
 * 	Funcion que registra las salas que no pueden  *
 * 	ser asignadas para ciertas entidades segun    *
 * 	restricciones de cercania                     *
 *                                                *
 **************************************************/
void nearbyProhibite(int eId, map<int, vector<int>> nearby, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

/**************************************************
 * 	Funcion que registra las salas que no pueden  *
 * 	ser asignadas para ciertas entidades segun    *
 * 	restricciones de lejania                      *
 *                                                *
 **************************************************/
void awayFromProhibite(int eId, map<int, vector<int>> awayFrom, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

/**************************************************
 * 	Funcion que registra las salas que no pueden  *
 * 	ser asignadas para ciertas entidades segun    *
 * 	las restricciones                             *
 *                                                *
 **************************************************/
void prohibite(int eId, map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
							 map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);