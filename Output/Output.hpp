#include <iostream>
#include <map>
#include <vector>
#include "../Solution/GreedyHelpers.hpp"

int getIndex(vector<int> v, int K);

void output(map<int, int> solution, vector<Entity> entities, vector<Room> rooms,
						vector<Constraint> softConstraints, string outputFilename);