#include <iostream>
#include <list>

using namespace std;

class Room
{
private:
    /**
     * attributes
     */
    int ID;
    int floor;
    double capacity;
    int sizeLA;
    list<int> adjacentRooms;

    /**
     * Show the list of adjacent rooms of the current room on formated structure
     */
    void printAdjacentList();

public:
    /**
     * setters
     */
    void setID(int ID);
    void setFloor(int floor);
    void setCapacity(double capacity);
    void setSizeLA(int sizeLA);
    void setAdjacentRooms(list<int> adjacentRooms);

    /**
     * getters
     */
    int getID();
    int getFloor();
    double getCapacity();
    int getSizeLA();
    list<int> getAdjacentRooms();

    /**
     * constructor
     */
    Room(int ID, int floor, double capacity, int sizeLA, list<int> adjacentRooms);

    /**
     * Show the data of instance on formated structure
     */
    void print();
};