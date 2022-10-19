#include <iostream>
#include <map>
#include <vector>
#include "../Extract/Extract.h"

/**
 * @brief	Genera un número entero aleatorio
 *
 * @param 	n		Número que determina el límite superior del rango disponible
 * @return int	Número aleatorio entre 0 y n-1
 */
int randint(int n);

bool checkAllocation(int idEntity, int idRoom, map<int,int> solution);

bool checkCapacity(int idRoom, vector<Entity> entities, vector<Room> rooms, map<int, int> solution);

bool checkSameRoom(int idEntity1, int idEntity2, map<int, int> solution);

bool checkAdjacency(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

bool checkNearness(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

bool checkFeasible(vector<Entity> entities, vector<Room> rooms, vector<Constraint> hardConstraints, map<int, int> solution);

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

/**
 * @brief	Muestra por pantalla las asignaciones de una solución
 *
 * @param solution	Hashmap el cual contiene la solución que se quiere visualizar
 */
void printSolution(map<int, int> solution);