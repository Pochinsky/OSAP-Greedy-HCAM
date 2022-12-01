#include <iostream>
#include <map>
#include <vector>
#include "Helpers.hpp"

/************************************************
 * 	Funcion que calcula la penalizacion por no  *
 * 	cumplir con restricciones blandas           *
 *                                              *
 ************************************************/
double softConstraintsViolatedPenalize(vector<Constraint> softConstraints,map<int,int> solution, map<int,double> spaceAvailable, vector<Room> rooms);

/*******************************************************
 * 	Funcion de evaluacion del algoritmo Hill Climbing  *
 *                                                     *
 *******************************************************/
double evaluateSolution(map<int, int> solution, vector<Entity> entities, vector<Room> rooms, vector<Constraint> softConstraints);