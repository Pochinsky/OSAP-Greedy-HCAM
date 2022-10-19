/**
 * @brief   Representación de una entidad
 * 
 */
class Entity
{
private:
    /**
     * Atributos
     */
    int ID;
    double space;

public:
    /**
     * Setters
     */
    void setID(int ID);
    void setSpace(double space);

    /**
     * Getters
     */
    int getID() const;
    double getSpace();

    /**
     * Constructor
     */
    Entity(int ID, double space);

    /**
     * @brief   Muestra por pantalla la información de la entidad
     * 
     */
    void print();
};