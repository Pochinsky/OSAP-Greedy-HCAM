class Constraint
{
private:
    /**
     * attributes
     */
    int ID;
    int type;
    int constraintType;
    int parameter1;
    int parameter2;

public:
    /**
     * setters
     */
    void setID(int ID);
    void setType(int type);
    void setConstraintType(int constraintType);
    void setParameter1(int parameter1);
    void setParameter2(int parameter2);

    /**
     * getters
     */
    int getID();
    int getType();
    int getConstraintType();
    int getParameter1();
    int getParameter2();

    /**
     * constructor
     */
    Constraint(int ID, int type, int constraintType, int parameter1, int parameter2);

    /**
     * Show the data of constraint on formated structure
     */
    void print();
};