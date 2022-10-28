#include <iterator>
#include "Room.h"

// constructor
Room::Room(int id, int floor, double capacity, vector<int> adjacentRooms)
{
    this->id = id;
    this->floor = floor;
    this->capacity = capacity;
    this->adjacentRooms = adjacentRooms;
}

// methods
void Room::printAdjacentList()
{
    cout << "[ ";
    for (int r : this->adjacentRooms)
        cout << r << " ";
    cout << "]" << endl;
}

void Room::print()
{
    cout << "########## Sala ##########" << endl;
    cout << "ID: " << this->id << endl;
    cout << "Piso: " << this->floor << endl;
    cout << "Capacidad: " << this->capacity << endl;
    cout << "Salas adyacentes: ";
    this->printAdjacentList();
}