#include <iostream>
#include "Constraint.hpp"

using namespace std;

Constraint::Constraint(int id, int type, int constraintType, int parameter1, int parameter2)
{
    this->id = id;
    this->type = type;
    this->constraintType = constraintType;
    this->parameter1 = parameter1;
    this->parameter2 = parameter2;
}
