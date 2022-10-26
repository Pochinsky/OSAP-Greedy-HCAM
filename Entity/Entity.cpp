#include <iostream>
#include "Entity.h"

using namespace std;

// constructor
Entity::Entity(int id, double space)
{
    this->id = id;
    this->space = space;
}

// methods
void Entity::print()
{
    cout << "########## Entidad ##########" << endl;
    cout << "ID: " << this->id << endl;
    cout << "espacio: " << this->space << endl;
}