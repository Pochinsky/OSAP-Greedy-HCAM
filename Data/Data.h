#include "../Entity/Entity.h"
#include "../Room/Room.h"
#include "../Constraint/Constraint.h"

/**
 * Storage all data of an instance of OSAP
 */
class Data {
    private:
        /**
         * attributes
         */
        int nOfEntities;
        int nOfRooms;
        int nOfFloors;
        int nOfHardConstraints;
        int nOfSoftConstraints;
        list<Entity> entities;
        list<Room> rooms;
        list<Constraint> softConstraints;
        list<Constraint> hardConstraints;
    public:
        /**
         * setters
         */
        void setNofEntities(int nOfEntities);
        void setNofRooms(int nOfRooms);
        void setNofFloors(int nOfFloors);
        void setNofHardConstraints(int nOfHardConstraints);
        void setNofSoftConstraints(int nOfSoftConstraints);
        void setEntities(list<Entity> entities);
        void setRooms(list<Room> rooms);
        void setSoftConstraints(list<Constraint> softConstraints);
        void setHardConstraints(list<Constraint> hardConstraints);
        /**
         * getters
         */
        int getNofEntities();
        int getNofRooms();
        int getNofFloors();
        int getNofHardConstraints();
        int getNofSoftConstraints();
        list<Entity> getEntities();
        list<Room> getRooms();
        list<Constraint> getHardConstraints();
        list<Constraint> getSoftConstraints();
        /**
         * constructor
         */
        Data(
            int nOfEntities, 
            int nOfRooms, 
            int nOfFloors, 
            int nOfHardConstraints, 
            int nOfSoftConstraints, 
            list<Entity> entities,
            list<Room> rooms,
            list<Constraint> softConstraints,
            list<Constraint> hardConstraints
        );
        /**
         * Show the data of instance on formated structure
         */
        void print();
};