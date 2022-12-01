#include <iostream>
#include <map>
#include <vector>
#include "../Extract/Extract.hpp"

/************************************************
 * 	Funcion que construye una solucion inicial  *
 * 	mediante algoritmo greedy                   *
 *                                              *
 ************************************************/
void initialSolution(
		vector<Entity> entities,
		vector<Room> rooms,
		int nOfRooms,
		vector<Constraint> hardConstraints,
		map<int, int> *solution);

/***************************************************
 * 	Funcion que aplica un algoritmo Hill Climbing  *
 * 	First Improvement para una instancia del OSAP  * 
 *                                                 *
 ***************************************************/
void hillClimbing(
    int nOfEntities,
		int nOfRooms,
		vector<Entity> entities,
		vector<Room> rooms,
		vector<Constraint> softConstraints,
		vector<Constraint> hardConstraints,
		map<int, int> *solution);
