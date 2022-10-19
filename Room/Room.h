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
     * Atributos
     */
    int ID;
    int floor;
    double capacity;
    int sizeLA;
    list<int> adjacentRooms;

    /**
     * @brief   Muestra por pantalla las salas adyacentes de la sala en cuestión
     * 
     */
    void printAdjacentList();

public:
    /**
     * Setters
     */
    void setID(int ID);
    void setFloor(int floor);
    void setCapacity(double capacity);
    void setSizeLA(int sizeLA);
    void setAdjacentRooms(list<int> adjacentRooms);

    /**
     * Getters
     */
    int getID();
    int getFloor();
    double getCapacity();
    int getSizeLA();
    list<int> getAdjacentRooms();

    /**
     * Constructor
     */
    Room(int ID, int floor, double capacity, int sizeLA, list<int> adjacentRooms);

    /**
     * @brief   Muestra por pantalla la información de la sala
     * 
     */
    void print();
};