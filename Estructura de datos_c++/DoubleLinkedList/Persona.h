/*
    \Name: Persona.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/06/21
    \brief: Archivo de cabecera donde se encuentra la clase Persona
*/
#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
/** \class Persona
*   Clase que simboliza a una persona con un Nombre y Apellido
*/
class Persona{

        /** \brief Operador de funcion. Auxiliar para imprimir a una Persona (Para pruebas).
        *   Imprime el Nombre y Apellido de una persona
        *   \param std::ostream& Flujo de salida donde se imprimirá a la perosna.
        *   \param const Persona &p Persona a imprimir.
        *   \return std::ostream El mismo flujo recibido. Permite la aplicación de cascada.
        */
    friend std::ostream& operator<< (std::ostream &fSalida, const Persona &p);
public:

    /** \brief Constructor de la clase persona
    *   Crea a una persona con Nombre y apellido aleatorio extraido de una lista de estatica de nombres
    */
    Persona();

    /** \brief Destructor de la clase persona
    */
    ~Persona();

    /** \brief Permite obtener el Nombre de la persona
    *   \return El nombre de la persona
    */
    char* ObtenerNombre() const;

    /** \brief Permite obtener el Apellido de la persona
    *   \return El Apellido de la persona
    */
    char* ObtenerApellido() const;

    /** \brief Operador de función. Copia los datos de una persona en otra.
    *   \param const Persona &p Persona a copiar
    *   \return La copia de la persona
    */
    Persona& operator= (const Persona &p);


private:
    char *Nombre; /*< Nombre de la persona */
    char *Apellido; /*< Apellido de la persona */
};


#endif // PERSONA_H_INCLUDED
