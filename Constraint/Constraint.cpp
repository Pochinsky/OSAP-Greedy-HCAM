#include <iostream>
#include "Constraint.h"

using namespace std;

// constructor
Constraint::Constraint(int id, int type, int constraintType, int parameter1, int parameter2)
{
    this->id = id;
    this->type = type;
    this->constraintType = constraintType;
    this->parameter1 = parameter1;
    this->parameter2 = parameter2;
}

// methods
void Constraint::print()
{
    cout << "##### Restriccion ";
    if (this->constraintType == 0)
        cout << "Blanda #####" << endl;
    else
        cout << "Dura #####" << endl;
    cout << "ID: " << this->id << endl;
    cout << "Tipo: ";
    switch (this->type)
    {
    case 0:
        cout << "ALLOCATION_CONSTRAINT" << endl;
        break;
    case 1:
        cout << "NONALLOCATION_CONSTRAINT" << endl;
        break;
    case 2:
        cout << "ONEOF_CONSTRAINT" << endl;
        break;
    case 3:
        cout << "CAPACITY_CONSTRAINT" << endl;
        break;
    case 4:
        cout << "SAMEROOM_CONSTRAINT" << endl;
        break;
    case 5:
        cout << "NOTSAMEROOM_CONSTRAINT" << endl;
        break;
    case 6:
        cout << "NOTSHARING_CONSTRAINT" << endl;
        break;
    case 7:
        cout << "ADJACENCY_CONSTRAINT" << endl;
        break;
    case 8:
        cout << "NEARBY_CONSTRAINT" << endl;
        break;
    case 9:
        cout << "AWAYFROM_CONSTRAINT" << endl;
        break;
    default:
        cout << "No vàlido" << endl;
    }
    cout << "Parametro 1: " << this->parameter1 << endl;
    cout << "Parametro 2: " << this->parameter2 << endl;
}