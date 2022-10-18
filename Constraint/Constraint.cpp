#include <iostream>
#include "Constraint.h"

using namespace std;

// setters
void Constraint::setID(int ID) { this->ID = ID; }
void Constraint::setType(int type) { this->type = type; }
void Constraint::setConstraintType(int constraintType) { this->constraintType = constraintType; }
void Constraint::setParameter1(int parameter1) { this->parameter1 = parameter1; }
void Constraint::setParameter2(int parameter2) { this->parameter2 = parameter2; }
// getters
int Constraint::getID() { return this->ID; }
int Constraint::getType() { return this->type; }
int Constraint::getConstraintType() { return this->constraintType; }
int Constraint::getParameter1() { return this->parameter1; }
int Constraint::getParameter2() { return this->parameter2; }
// constructors
Constraint::Constraint(int ID, int type, int constraintType, int parameter1, int parameter2) {
    this->setID(ID);
    this->setType(type);
    this->setConstraintType(constraintType);
    this->setParameter1(parameter1);
    this->setParameter2(parameter2);
}
// methods
void Constraint::print() {
    cout << "##### Restriccion ";
    if (this->getConstraintType() == 0) cout << "Blanda #####" << endl;
    else cout << "Dura #####" << endl;
    cout << "ID: " << this->getID() << endl;
    cout << "Tipo: ";
    switch (this->getType()) {
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
    cout << "Parametro 1: " << this->getParameter1() << endl;
    cout << "Parametro 2: " << this->getParameter2() << endl;
}