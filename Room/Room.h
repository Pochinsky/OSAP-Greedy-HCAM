#include <iostream>
#include <list>

using namespace std;

/**
 * @brief   Representación de una sala
 * 
 */
class Room
{
private:

    /**
     * @brief   Muestra por pantalla las salas adyacentes de la sala en cuestión
     * 
     */
    void printAdjacentList();

public: 
    /**
     * Atributos
     */
    int id;
    int floor;
    double capacity;
    list<int> adjacentRooms;

    /**
     * Constructor
     */
    Room(int id, int floor, double capacity, list<int> adjacentRooms);

    /**
     * @brief   Muestra por pantalla la información de la sala
     * 
     */
    void print();
};