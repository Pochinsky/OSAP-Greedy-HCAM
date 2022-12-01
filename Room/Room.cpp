#include <iterator>
#include "Room.hpp"

Room::Room(int id, int floor, double capacity, vector<int> adjacentRooms)
{
    this->id = id;
    this->floor = floor;
    this->capacity = capacity;
    this->adjacentRooms = adjacentRooms;
}