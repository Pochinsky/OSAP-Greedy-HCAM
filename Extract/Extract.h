#include <string>
#include <vector>
#include "../Entity/Entity.h"
#include "../Room/Room.h"
#include "../Constraint/Constraint.h"

/**
 * @brief	Divide un string en varios substrings utilizando como punto de corte un delimitador dado
 * 
 * @param 	str 						String a dividir
 * @param 	splitter 				Separador que indica el carácter que se utilizará como delimitador
 * @return	vector<string>	Vector de strings con todos los substrings de str obtenidos
 */
vector<string> splitString(string str, char splitter);

/**
 * @brief	Extrae los datos de una instancia del OSAP
 * 
 * @param filename 						Nombre del archivo en el cual se almacenan los datos de la instancia
 * @param nOfEntities 				Número de entidades
 * @param nOfRooms 						Número de salas
 * @param nOfFloors 					Número de pisos
 * @param nOfHardConstraints	Número de restricciones duras
 * @param nOfSoftConstraints	Número de restricciones blandas
 * @param entities 						Vector de entidades
 * @param rooms 							Vector de salas
 * @param softConstraints 		Vector de restricciones blandas
 * @param hardConstraints 		Vector de restricciones duras
 */
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