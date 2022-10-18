class Entity {
    private:
        /**
         * attributes
         */
        int ID;
        double space;
    public:
        /**
         * setters
         */
        void setID(int ID);
        void setSpace(double space);
        /**
         * getters
         */
        int getID();
        double getSpace();
        /**
         * constructor
         */
        Entity(int ID, double space);
        /**
         * Show the data of entity on formated structure
         */
        void print();
};