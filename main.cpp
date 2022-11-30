#include <iostream>
#include <chrono>
#include "./Output/Output.hpp"

#define RESET "\033[0m"
#define RED "\033[31m"

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv)
{
    // se corrobora que se haya pasado el nombre del archivo por consola
    if (argc > 1)
    {
        // variables para guardar la información de la instancia
        int nOfEntities,
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
        extractData(path,
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
        auto startHC = high_resolution_clock::now();
        hillClimbing(nOfEntities,
                     nOfRooms,
                     entities,
                     rooms,
                     softConstraints,
                     hardConstraints,
                     &solution);
        auto stopHC = high_resolution_clock::now();
        auto durationHC = duration_cast<seconds>(stopHC - startHC);
        cout << "Execution time = " << durationHC.count() << " seconds" << endl;
        // cout << "hill climbing first improvement executed in " << durationHC.count() << " seconds" << endl;
        output(solution, entities, rooms, softConstraints, instance);
    }
    else
    {
        cout << RED << "Error:" << RESET << " nombre de la instancia no ingresado." << endl;
    }

    return 0;
}
