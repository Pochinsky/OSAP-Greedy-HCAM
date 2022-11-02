#include <iostream>
#include <map>
#include <vector>
#include "Helpers.hpp"

bool checkNonAllocationConstraint(int eId, int rId, map<int, vector<int>> nonAllocation);

bool checkCapacityConstraint(int rId, double eSpace, vector<int> capacity, map<int, double> spaceAvailable);

bool checkSameRoomConstraint(int eId, int rId, map<int, vector<int>> sameRoom, map<int, int> solution);

bool checkNotSameRoomConstraint(int eId, int rId, map<int, vector<int>> notSameRoom, map<int, int> solution);

bool checkNotSharingConstraint(int eId, int rId, vector<int> notSharing, map<int, int> solution);

bool checkAdjacencyConstraint(int eId, int rId, vector<Room> rooms, map<int, vector<int>> adjacency, map<int, int> solution);

bool checkNearbyConstraint(int eId, int rId, map<int, vector<int>> nearby, vector<Room> rooms, map<int, int> solution);

bool checkAwayFromConstraint(int eId, int rId, map<int, vector<int>> awayFrom, vector<Room> rooms, map<int, int> solution);

bool checkAllConstraints(int eId, double eSpace, int rId, map<int, vector<int>> nonAllocation, vector<int> capacity, map<int, vector<int>> sameRoom,
												 map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> adjacency, map<int, vector<int>> nearby,
												 map<int, vector<int>> awayFrom, map<int, double> spaceAvailable, vector<Room> rooms, map<int, int> solution);