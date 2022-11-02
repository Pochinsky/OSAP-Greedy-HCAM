/**
 * @brief   Representación de una entidad
 *
 */
class Entity
{
public:
    /**
     * Atributos
     */
    int id;
    double space;

    /**
     * Constructor
     */
    Entity(int id, double space);

    /**
     * @brief   Muestra por pantalla la información de la entidad
     *
     */
    void print();
};