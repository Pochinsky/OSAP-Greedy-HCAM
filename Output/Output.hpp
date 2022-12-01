#include <iostream>
#include <map>
#include <vector>
#include "../Solution/GreedyHelpers.hpp"

/***************************************************************
 * 	Funcion que retorna el indice de un elemento en un vector  *
 *                                                             *
 ***************************************************************/
int getIndex(vector<int> v, int K);

/**********************************************************
 * 	Funcion que genera el archivo de salida de extension  *
 * 	.out que contiene los datos de la solucion            *
 *                                                        *
 **********************************************************/
void output(map<int, int> solution, vector<Entity> entities, vector<Room> rooms,
						vector<Constraint> softConstraints, string outputFilename);