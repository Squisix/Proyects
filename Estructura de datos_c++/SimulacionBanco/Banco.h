/*
    \Name: Banco.h
    \Author: Marco Antonio Guerrero Vasquez // 219202704
    \Date: 03/06/21
    \brief: Archivo de cabecera donde se encuentra la clase Banco
*/

#ifndef BANCO_H_INCLUDED
#define BANCO_H_INCLUDED
#include <iostream>
#include "Persona.h"
#include "LinkedDataQueue.h"
/** \class Banco
*   Clase que simula el funcionamiento de la caja de un banco
*/
class Banco{
public:
    /** \brief Constructor por defecto de la calse Banco
    *   \param unsigned tAtencion = 120 Tiempo de atención total del banco, por defecto es 120
    */
    explicit Banco(unsigned tAtencion = 120);

    /** \brief Destructor de Banco
    */
    ~Banco();

    /** \brief Permite saber si el banco está ocupado o no.
    *   \return True si el banco está en uso, false en calso contrario.
    */
    bool EstaEnUso() const;

    /** \brief Ingresa una persona aleatoria a la cola de clientes por atender
    */
    void IngresarACola();

    /** \brief Se atiende a la primera persona de la cola por atender y cambia el estado de la caja a "EnUso(true)"
    *   \param const Persona &p referencia constante de la Persona a atener
    */
    void Atender(const Persona &p);

    /** \brief Termina el proceso da la persona que se encuentra en la caja y cambia el estado de la caja a "EnUso(false)"
    */
    void Desatender();

    /** \brief Permite saber la persona que se está atendiendo
    *   \return La persona que se esta atendiendo.
    */
    Persona SeEstaAtendiendo() const;

    /** \brief Permite saber el tiempo de atención que tendrá el banco
    *   \param return Tiempo de atención del banco.
    */
    unsigned ObtenerTiempoAtencion() const;

    /** \brief Permite gestionar el proceso del banco paso a paso. (segundo a segundo)
    */
    void GestionarBanco();

    /** \brief Imprime la cola de las personas por atender
    */
    void ImprimirPorAtender() const;

    /** \brief Imprime la cola de las personas que han sido atendidas.
    */
    void ImprimirAtendidos() const;


private:
    bool EnUso; /*< Estado de la caja del banco */
    Persona Atendiendo; /*< Persona que está siendo atendida */
    LinkedDataQueue<Persona> PorAntender;   /*< Cola de personas por atender */
    LinkedDataQueue<Persona> Atendidos;     /*> Cola de personas que han sido atendidas */
    unsigned TiempoAtencion;       /*< Tiempo de atención del banco */
};


#endif // BANCO_H_INCLUDED
