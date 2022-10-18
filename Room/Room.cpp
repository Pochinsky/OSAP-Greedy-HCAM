#include <iterator>
#include "Room.h"

// setters
void Room::setID(int ID) { this->ID = ID; }
void Room::setFloor(int floor) { this->floor = floor; }
void Room::setCapacity(double capacity) { this->capacity = capacity; }
void Room::setSizeLA(int sizeLA) { this->sizeLA = sizeLA; }
void Room::setAdjacentRooms(list<int> adjacentRooms) { this->adjacentRooms = adjacentRooms; }
// getters
int Room::getID() { return this->ID; }
int Room::getFloor() { return this->floor; }
double Room::getCapacity() { return this->capacity; }
int Room::getSizeLA() { return this->sizeLA; }
list<int> Room::getAdjacentRooms() { return this->adjacentRooms; }
// constructor
Room::Room(int ID, int floor, double capacity, int sizeLA, list<int> adjacentRooms) {
    this->setID(ID);
    this->setFloor(floor);
    this->setCapacity(capacity);
    this->setSizeLA(sizeLA);
    this->setAdjacentRooms(adjacentRooms);
}
// methods
void Room::printAdjacentList() {
    list<int>::iterator it;
    cout << "[ ";
    for (it=this->adjacentRooms.begin(); it!=this->adjacentRooms.end(); ++it) cout << *it << " ";
    cout << "]" << endl;
}
void Room::print() {
    cout << "########## Sala ##########" << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Piso: " << this->getFloor() << endl;
    cout << "Capacidad: " << this->getCapacity() << endl;
    cout << "Tamaño L-A: " << this->getSizeLA() << endl;
    cout << "Salas adyacentes: ";
    this->printAdjacentList();
}