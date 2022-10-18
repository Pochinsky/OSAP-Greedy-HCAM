#include "Data.h"

// setters
void Data::setNofEntities(int nOfEntities) { this->nOfEntities = nOfEntities; }
void Data::setNofRooms(int nOfRooms) { this->nOfRooms = nOfRooms; }
void Data::setNofFloors(int nOfFloors) { this->nOfFloors = nOfFloors; }
void Data::setNofHardConstraints(int nOfHardConstraints) { this->nOfHardConstraints = nOfHardConstraints; }
void Data::setNofSoftConstraints(int nOfSoftConstraints) { this->nOfSoftConstraints = nOfSoftConstraints; }
void Data::setEntities(list<Entity> entities) { this->entities = entities; }
void Data::setRooms(list<Room> rooms) { this->rooms = rooms; }
void Data::setSoftConstraints(list<Constraint> softConstraints) { this->softConstraints = softConstraints; }
void Data::setHardConstraints(list<Constraint> hardConstraints) { this->hardConstraints = hardConstraints; }
// getters
int Data::getNofEntities() { return this->nOfEntities; }
int Data::getNofRooms() { return this->nOfRooms; }
int Data::getNofFloors() { return this->nOfFloors; }
int Data::getNofHardConstraints() { return this->nOfHardConstraints; }
int Data::getNofSoftConstraints() { return this->nOfSoftConstraints; }
list<Entity> Data::getEntities() { return this->entities; }
list<Room> Data::getRooms() { return this->rooms; }
list<Constraint> Data::getHardConstraints() { return this->hardConstraints; }
list<Constraint> Data::getSoftConstraints() { return this->softConstraints; }
// constructor
Data::Data(
    int nOfEntities, 
    int nOfRooms, 
    int nOfFloors, 
    int nOfHardConstraints, 
    int nOfSoftConstraints, 
    list<Entity> entities,
    list<Room> rooms,
    list<Constraint> softConstraints,
    list<Constraint> hardConstraints
) {
    this->setNofEntities(nOfEntities);
    this->setNofRooms(nOfRooms);
    this->setNofFloors(nOfFloors);
    this->setNofHardConstraints(nOfHardConstraints);
    this->setNofSoftConstraints(nOfSoftConstraints);
    this->setEntities(entities);
    this->setRooms(rooms);
    this->setHardConstraints(hardConstraints);
    this->setSoftConstraints(softConstraints);
}
void Data::print() {
    cout << "########## Data ##########" << endl;
    cout << "nOfEntities:\t\t" << this->getNofEntities() << endl;
    cout << "nOfRooms:\t\t" << this->getNofRooms() << endl;
    cout << "nOfFloors:\t\t" << this->getNofFloors() << endl;
    cout << "nOfHardConstraints:\t" << this->getNofHardConstraints() << endl;
    cout << "nOfSoftConstraints:\t" << this->getNofSoftConstraints() << endl;
    cout << endl << "Entities" << endl << endl;
    for (Entity e: this->getEntities()) e.print();
    cout << endl << "Rooms" << endl << endl;
    for (Room r: this->getRooms()) r.print();
    cout << endl << "Hard Constraints" << endl << endl;
    for (Constraint r: this->getHardConstraints()) r.print();
    cout << endl << "Soft Constraints" << endl << endl;
    for (Constraint r: this->getSoftConstraints()) r.print();
}