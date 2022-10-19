#include <iostream>
#include <fstream>
#include "Extract.h"

using namespace std;

vector<string> splitString(string str, char splitter)
{
    vector<string> result;
    string current = "";
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == splitter)
        {
            if (current != "")
            {
                result.push_back(current);
                current = "";
            }
            continue;
        }
        current += str[i];
    }
    if (current.size() != 0)
        result.push_back(current);
    return result;
}

void extractData(
    string filename,
    int *nOfEntities,
    int *nOfRooms,
    int *nOfFloors,
    int *nOfHardConstraints,
    int *nOfSoftConstraints,
    vector<Entity> *entities,
    vector<Room> *rooms,
    vector<Constraint> *softConstraints,
    vector<Constraint> *hardConstraints)
{
    // declare variables
    int
        ID,
        floor,
        sizeLA,
        type,
        constraintType,
        parameter1,
        parameter2,
        i;
    size_t j;
    list<int> adjacentRooms;
    double space, capacity;
    ifstream readFile(filename);
    string line;
    vector<string> v;
    // set n of entities
    getline(readFile, line);
    *nOfEntities = stoi(splitString(line, ':')[1]);
    // set n of rooms
    getline(readFile, line);
    *nOfRooms = stoi(splitString(line, ':')[1]);
    // set n of floors
    getline(readFile, line);
    *nOfFloors = stoi(splitString(line, ':')[1]);
    // set n of hard constraints
    getline(readFile, line);
    getline(readFile, line);
    *nOfHardConstraints = stoi(splitString(line, ':')[1]);
    // set n of soft constraints
    getline(readFile, line);
    *nOfSoftConstraints = stoi(splitString(line, ':')[1]);
    // set entities
    getline(readFile, line);
    getline(readFile, line);
    entities->reserve(*nOfEntities);
    for (i = 0; i < *nOfEntities; i++)
    {
        getline(readFile, line);
        v = splitString(line, ' ');
        ID = stoi(v[0]);
        space = stod(v[2]);
        Entity e(ID, space);
        (*entities).push_back(e);
    }
    // set rooms
    getline(readFile, line);
    getline(readFile, line);
    rooms->reserve(*nOfRooms);
    for (i = 0; i < *nOfRooms; i++)
    {
        getline(readFile, line);
        v = splitString(line, ' ');
        ID = stoi(v[0]);
        floor = stoi(v[1]);
        capacity = stod(v[2]);
        sizeLA = stoi(v[3]);
        for (j = 4; j < v.size(); j++)
            adjacentRooms.push_back(stoi(v[j]));
        Room r(ID, floor, capacity, sizeLA, adjacentRooms);
        (*rooms).push_back(r);
        adjacentRooms.clear();
    }
    // set constraints
    getline(readFile, line);
    getline(readFile, line);
    softConstraints->reserve(*nOfSoftConstraints);
    hardConstraints->reserve(*nOfHardConstraints);
    for (i = 0; i < *nOfHardConstraints + *nOfSoftConstraints; i++)
    {
        getline(readFile, line);
        v = splitString(line, ' ');
        ID = stoi(v[0]);
        type = stoi(v[1]);
        constraintType = stoi(v[2]);
        parameter1 = stoi(v[3]);
        parameter2 = stoi(v[4]);
        Constraint c(ID, type, constraintType, parameter1, parameter2);
        if (constraintType == 1)
            (*hardConstraints).push_back(c);
        else
            (*softConstraints).push_back(c);
    }
    readFile.close();
}