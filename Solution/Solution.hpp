#include <iostream>
#include <map>
#include <vector>
#include "../Extract/Extract.hpp"

/**
 * @brief	Genera una solución inicial aleatoria
 *
 * @param entities	Vector de entidades.
 * @param rooms 		Vector de salas.
 * @param nOfRooms 	Cantidad de salas en la lista,
 * @param solution 	Hashmap sobre el cual se construye una solución inicial aleatoria
 */
void initialSolution(
		vector<Entity> entities,
		vector<Room> rooms,
		int nOfRooms,
		vector<Constraint> hardConstraints,
		map<int, int> *solution);

/**
 * @brief	Aplica Hill Climbing First Improve a una instancia del OSAP
 *
 * @param nOfEntities 				Número de entidades
 * @param nOfRooms 						Número de salas
 * @param nOfFloors 					Número de pisos
 * @param nOfHardConstraints	Número de restricciones duras
 * @param nOfSoftConstraints 	Número de restricciones blandas
 * @param entities 						Vector de entidades
 * @param rooms 							Vector de salas
 * @param softConstraints 		Vector de restricciones blandas
 * @param hardConstraints 		Vector de restricciones duras
 * @param solution 						Hashmap sobre el cual se construye la solución del algoritmo
 */
void hillClimbing(
		int nOfEntities,
		int nOfRooms,
		int nOfFloors,
		int nOfHardConstraints,
		int nOfSoftConstraints,
		vector<Entity> entities,
		vector<Room> rooms,
		vector<Constraint> softConstraints,
		vector<Constraint> hardConstraints,
		map<int, int> *solution);