/**
 * @brief   Representación de una restricción
 *
 */
class Constraint
{

public:
    /**
     * Atributos
     */
    int id;
    int type;
    int constraintType;
    int parameter1;
    int parameter2;

    /**
     * Constructor
     */
    Constraint(int id, int type, int constraintType, int parameter1, int parameter2);

    /**
     * @brief   Muestra por pantalla la información de la restricción
     *
     */
    void print();
};