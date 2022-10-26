#include <iterator>
#include "Room.h"

// constructor
Room::Room(int id, int floor, double capacity, list<int> adjacentRooms)
{
    this->id = id;
    this->floor = floor;
    this->capacity = capacity;
    this->adjacentRooms = adjacentRooms;
}

// methods
void Room::printAdjacentList()
{
    list<int>::iterator it;
    cout << "[ ";
    for (it = this->adjacentRooms.begin(); it != this->adjacentRooms.end(); ++it)
        cout << *it << " ";
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