#include <iostream>
#include <map>
#include <vector>
#include "Helpers.hpp"

double softConstraintsViolatedPenalize(vector<Constraint> softConstraints,map<int,int> solution, map<int,double> spaceAvailable, vector<Room> rooms);

double evaluateSolution(map<int, int> solution, vector<Entity> entities, vector<Room> rooms, vector<Constraint> softConstraints);