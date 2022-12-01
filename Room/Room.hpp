#include <iostream>
#include <vector>

using namespace std;

/***********************************
 *  Clase que representa una sala  *
 *                                 *
 ***********************************/
class Room
{
public:
    int id;
    int floor;
    double capacity;
    vector<int> adjacentRooms;

    Room(int id, int floor, double capacity, vector<int> adjacentRooms);
};