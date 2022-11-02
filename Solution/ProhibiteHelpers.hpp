#include <iostream>
#include <map>
#include <vector>
#include "Solution.hpp"

void notSameRoomProhibite(int eId, map<int, vector<int>> notSameRoom, map<int, int> solution, map<int, vector<int>> *roomsProhibited);

void notSharingProhibite(int eId, vector<int> notSharing, map<int, int> solution, map<int, vector<int>> *roomsProhibited);

void nearbyProhibite(int eId, map<int, vector<int>> nearby, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

void awayFromProhibite(int eId, map<int, vector<int>> awayFrom, map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);

void prohibite(int eId, map<int, vector<int>> notSameRoom, vector<int> notSharing, map<int, vector<int>> nearby, map<int, vector<int>> awayFrom,
							 map<int, int> solution, map<int, vector<int>> *roomsProhibited, vector<Room> rooms);