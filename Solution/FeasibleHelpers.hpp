#include <iostream>
#include <map>
#include <vector>
#include "ProhibiteHelpers.hpp"

bool checkAllocation(int idEntity, int idRoom, map<int, int> solution);

bool checkCapacity(int idRoom, vector<Entity> entities, vector<Room> rooms, map<int, int> solution);

bool checkSameRoom(int idEntity1, int idEntity2, map<int, int> solution);

bool checkAdjacency(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

bool checkNearness(int idEntity1, int idEntity2, vector<Room> rooms, map<int, int> solution);

bool checkFeasible(vector<Entity> entities, vector<Room> rooms, vector<Constraint> hardConstraints, map<int, int> solution);