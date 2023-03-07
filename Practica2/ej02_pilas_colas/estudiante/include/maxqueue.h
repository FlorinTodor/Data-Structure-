/**
 * @file maxqueue.h
 * @brief  Archivo de definición del TDA MaxQueue
 */


#include <iostream>
#include <stack>
#include <cassert>
#include <ostream>

#ifndef _MAXQUEUEH
#define _MAXQUEUEH
using namespace std;


struct element{

    int value;
    int maximum;
    //element(int i);

    friend ostream& operator<<(ostream &o,  const element &p);
};

class MaxQueue{
    /**
    * @brief T.D.A MaxQueue
    *
    * Implementación de una Cola (queue) a través del uso de una pila (stack) de la biblioteca STL y del uso de la estructura element.
    *
    * Se basa en el uso de una cola con un contenedor subyacente de pila formada por objetos de la estructura element
    * @author Florin Emanuel Todor
    * @author José Antonio Villarejo Caballero
    * @date Octubre 2022
    */


private:

    stack <element> pila;
public:

    MaxQueue(MaxQueue const &otraCola);
    MaxQueue();
    ~MaxQueue();

    /**
    * @brief Devuelve una referencia a la posición N-1 de la cola.
    * @return Devuelve la posicion en memoria del ultimo valor introducido en la cola.
    */
    element & back();

    /**
    * @brief devuelve la posicion en memoria del primer valor introducido en la cola.
    * @return Devuelve una referencia a la posición del primer elemento introducido.
    */
    element & front();

    /**
    * @brief Introduce un elemento en la posición back (última posición) de la cola y comprueba si es el mayor valor introducido.
    * @param n Elemento a introducir en la cola.
    * @return Introduce un elemento en la posición N-1 de la cola.
    */
    void push(int i);

    /**
    * @brief Elimina el elemento en la primera posición (front) de la cola.
    * @return Devuelve la cola con un elemento menos y asigna un nuevo front.
    */
    void pop();

    /**
    * @brief Calcula el tamaño total de la cola.
    * @return Devuelve el número de elementos introducidos en la cola.
    */
    unsigned long size();

    /**
    * @brief Comprueba si la cola está vacía.
    * @return Devuelve un boolean para indicar si la cola está vacía.
    */
    bool empty();

    friend ostream& operator<<(ostream &o, const MaxQueue &p);
};

#endif // _MAXQUEUE_H