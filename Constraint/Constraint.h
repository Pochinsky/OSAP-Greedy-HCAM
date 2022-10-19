/**
 * @brief   Representación de una restricción
 * 
 */
class Constraint
{
private:
    /**
     * Atributos
     */
    int ID;
    int type;
    int constraintType;
    int parameter1;
    int parameter2;

public:
    /**
     * Setters
     */
    void setID(int ID);
    void setType(int type);
    void setConstraintType(int constraintType);
    void setParameter1(int parameter1);
    void setParameter2(int parameter2);

    /**
     * Getters
     */
    int getID();
    int getType();
    int getConstraintType();
    int getParameter1();
    int getParameter2();

    /**
     * Constructor
     */
    Constraint(int ID, int type, int constraintType, int parameter1, int parameter2);

    /**
     * @brief   Muestra por pantalla la información de la restricción
     * 
     */
    void print();
};