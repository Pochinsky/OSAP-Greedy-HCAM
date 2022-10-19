#include <iostream>
#include "Entity.h"

using namespace std;

// setters
void Entity::setID(int ID) { this->ID = ID; }

void Entity::setSpace(double space) { this->space = space; }

// getters
int Entity::getID() { return this->ID; }

double Entity::getSpace() { return this->space; }

// constructor
Entity::Entity(int ID, double space)
{
    this->setID(ID);
    this->setSpace(space);
}

// methods
void Entity::print()
{
    cout << "########## Entidad ##########" << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "espacio: " << this->getSpace() << endl;
}