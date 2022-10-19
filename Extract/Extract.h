#include <string>
#include <vector>
#include "../Entity/Entity.h"
#include "../Room/Room.h"
#include "../Constraint/Constraint.h"

/**
 * split a string in a substrings separated by a splitter
 *
 * @param   str       string to split
 * @param   splitter  char that delimiter each substrin
 * @returns a vector with substrings from split
 */
vector<string> splitString(string str, char splitter);

/**
 * get data of an instance of OSAP from .txt file
 *
 * @param   filename path to file to read
 * @returns a Data class with data extracted from the instance
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