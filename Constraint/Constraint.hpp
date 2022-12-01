/******************************************
 *  Clase que representa una restriccion  *
 *                                        *
 ******************************************/
class Constraint
{

public:
    int id;
    int type;
    int constraintType;
    int parameter1;
    int parameter2;

    Constraint(int id, int type, int constraintType, int parameter1, int parameter2);
};