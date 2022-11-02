#include <iostream>
#include "./Solution/Solution.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

using namespace std;

int main(int argc, char **argv)
{
    // se corrobora que se haya pasado el nombre del archivo por consola
    if (argc > 1)
    {
        // variables para guardar la información de la instancia
        int
            nOfEntities,
            nOfRooms,
            nOfFloors,
            nOfHardConstraints,
            nOfSoftConstraints;
        vector<Entity> entities;
        vector<Room> rooms;
        vector<Constraint> softConstraints, hardConstraints;
        // se almacena la información de la instancia
        string instance = argv[1];
        string path = "Instances/" + instance + ".txt";
        extractData(
            path,
            &nOfEntities,
            &nOfRooms,
            &nOfFloors,
            &nOfHardConstraints,
            &nOfSoftConstraints,
            &entities,
            &rooms,
            &softConstraints,
            &hardConstraints);
        // se aplica hill climbing first improvement
        map<int, int> solution;
        hillClimbing(
            nOfEntities,
            nOfRooms,
            nOfFloors,
            nOfHardConstraints,
            nOfSoftConstraints,
            entities,
            rooms,
            softConstraints,
            hardConstraints,
            &solution);
    }
    else
    {
        cout << RED << "Error:" << RESET << " nombre de la instancia no ingresado." << endl;
    }

    return 0;
}