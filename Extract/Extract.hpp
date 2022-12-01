#include <string>
#include <vector>
#include "../Entity/Entity.hpp"
#include "../Room/Room.hpp"
#include "../Constraint/Constraint.hpp"

/*****************************************************
 *	Funcion que corta un string dado un delimitador  *
 * 	retornando un vector con el string cortado       *
 *                                                   *
 *****************************************************/
vector<string> splitString(string str, char splitter);

/*********************************************************
 *	Funcion que extrae todos los datos correspondientes  *
 *	la instancia ingresada por consola                   *
 *                                                       *
 *********************************************************/
void extractData(
		string filename,
		int *nOfEntities,
		int *nOfRooms,
		int *nOfFloors,
		int *nOfHardConstraints,
		int *nOfSoftConstraints,
		vector<Entity> *entities,
		vector<Room> *rooms,
		vector<Constraint> *softConstraints,
		vector<Constraint> *hardConstraints);