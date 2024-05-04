/*
    \Name: ColaMedieval.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 19/03/21
    \brief: Archivo de cabecera donde se encuentra la clase Cola Medieval
*/

#ifndef REINO_H_INCLUDED
#define REINO_H_INCLUDED
#include "Persona.h"
#include "ColaMedieval.h"
#include "LinkedDataQueue.h"

/** \class Reino
*   Clase que simula el funcionamiento de el Reino del Rey Arturo
*/
class Reino{
public:
    /** \brief Constructor por defecto de la clase Reino
    *   \param unsigned tAtencion = 120 Tiempo de atención total del reino, por defecto es 120
    */
    explicit Reino(unsigned tAtencion = 120);

    /** \brief Destructor de Reino
    */
    ~Reino();

    /** \brief Permite saber si el Rey esta ocupado o no.
    *   \return True si el Rey está en ocupado, false en caso contrario.
    */
    bool EstaOcupado() const;

    /** \brief Ingresa una persona aleatoria a la cola de ciudadanos a la cola.
    */
    void IngresarACola();

    /** \brief Se atiende al primer ciudadano de la cola por atender y cambia el estado del Rey a "EstaOcupado(true)"
    *   \param const Persona &p referencia constante de la Persona a atender
    */
    void Atender(const Persona &p);

    /** \brief Termina el proceso da la persona que se encuentra con el Rey y cambia el estado del Rey a "EstaOcupado(false)"
    */
    void Desatender();

    /** \brief Permite saber la persona que se está atendiendo
    *   \return La persona que se esta atendiendo.
    */
    Persona SeEstaAtendiendo() const;

    /** \brief Permite saber el tiempo de atención que tendrá el Rey
    *   \param return Tiempo de atención del Rey.
    */
    unsigned ObtenerTiempoAtencion() const;

    /** \brief Permite gestionar el proceso del Reino paso a paso. (segundo a segundo)
    */
    void GestionarReino();

    /** \brief Imprime la cola de las personas por atender
    */
    void ImprimirPorAtender() const;

    /** \brief Imprime la cola de las personas que han sido atendidas.
    */
    void ImprimirAtendidos() const;

    /** \brief Imprime la cola de las personas que han sido atendidas.
    */
    void ImprimirNumeroCiudadanosAtendidos() const;
private:
    bool Ocupado; /*< Estado del Rey */
    Persona Atendiendo; /*< Persona que está siendo atendida */
    ColaMedieval PorAntender;   /*< Cola de personas por atender */
    ColaMedieval Atendidos;     /*> Cola de personas que han sido atendidas */
    unsigned TiempoAtencion;       /*< Tiempo de atención del Reino */
};


#endif // REINO_H_INCLUDED
