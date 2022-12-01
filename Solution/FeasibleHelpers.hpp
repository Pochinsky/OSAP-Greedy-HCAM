#include <iostream>
#include <map>
#include <vector>
#include "ProhibiteHelpers.hpp"

/***********************************************
 * 	Funcion que corrobora si una entidad esta  *
 * 	asignada a una sala especifica             *
 *                                             *
 ***********************************************/
bool checkAllocation(int idEntity, int idRoom, map<int, int> solution);

/*****************************************************************
 * 	Funcion que corrobora si se respeta la capacidad de la sala  *
 *                                                               *
 *****************************************************************/
bool checkCapacity(int idRoom, vector<Entity> entities, vector<Room> rooms, map<int, int> solution);

/**********************************************
 * 	Funcion que corrobora si dos salas estan  *
 * 	asignadas a la misma sala                 *
 *                                            *
 **********************************************/
bool checkSameRoom(int idEntity1, int idEntity2, map<int, int> solution);

/**********************************************
 * 	Funcion que corrobora si dos salas estan  *
 * 	asignadas a salas adyacentes              *
 *                                            *
 **********************************************/
bool checkAdjacency(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

/**********************************************
 * 	Funcion que corrobora si dos salas estan  *
 * 	asignadas a salas cercanas                *
 *                                            *
 **********************************************/
bool checkNearness(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

/*******************************************************
 * 	Funcion que corrobora si una solucion es factible  *
 *                                                     *
 *******************************************************/
bool checkFeasible(vector<Entity> entities, vector<Room> rooms, vector<Constraint> hardConstraints, map<int, int> solution);