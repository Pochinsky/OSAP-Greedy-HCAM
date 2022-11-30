#include <iostream>
#include <map>
#include <vector>
#include "FeasibleHelpers.hpp"

/**
 * @brief	Genera un número entero aleatorio
 *
 * @param 	n		Número que determina el límite superior del rango disponible
 * @return int	Número aleatorio entre 0 y n-1
 */
int randint(int n);

map<int, int> movementToSolution(map<int, int> currentSolution, int entityId, int nOfRooms);

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
