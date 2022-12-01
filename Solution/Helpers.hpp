#include <iostream>
#include <map>
#include <vector>
#include "FeasibleHelpers.hpp"

/***********************************
 * 	Funcion que retorna un numero  *
 * 	aleatorio entre 0 y n          *
 *                                 *
 ***********************************/
int randint(int n);

/*********************************************
 * 	Operador de movimiento de Hill Climbing  *
 *                                           *
 *********************************************/
map<int, int> movementToSolution(map<int, int> currentSolution, int entityId, int nOfRooms);

/**************************************************************************
 * 	Funcion que retorna el indice de una entidad en el vector notSharing  *
 *                                                                        *
 **************************************************************************/
int getNotSharingIndex(vector<int> notSharing, int entityId);

/******************************************
 * 	Funcion que dada una id de una sala,  *
 * 	retorna su lista de adyacencia        *
 *                                        *
 ******************************************/
vector<int> getAdjacencyRooms(int roomId, vector<Room> rooms);

/**************************************************
 * 	Funcion que dada una id de una entidad,       *
 * 	retorna el espacio que utiliza dicha entidad  *
 *                                                *
 **************************************************/
int getSpace(int entityId, vector<Entity> entities);

/**************************************************
 * 	Funcion que dada una id de una sala, retorna  *
 * 	el piso en el que se ubica dicha sala         *
 *                                                *
 **************************************************/
int getFloor(int roomId, vector<Room> rooms);
