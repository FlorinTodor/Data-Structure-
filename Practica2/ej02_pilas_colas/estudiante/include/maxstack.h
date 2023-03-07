/**
 * @file maxstack.h
 * @brief  Archivo de definición del TDA MaxStack
 */


#include <iostream>
#include <queue>
#include <cassert>
#include <ostream>

#ifndef _MAXSTACK_H_
#define _MAXSTACK_H_
using namespace std;


struct element{


    /**
     * @brief Inicializa el valor actual del objeto a través de un parametro int
     * @param i Parametro por el cual se inicializa el valor actual del objeto
     */
    element (int i);
    /**
     * @brief Valor actual del objeto
     */
    int value;

    /**
     * @brief Valor maximo del objeto
     */
    int maximum;
    /**
     * @brief Sobrecarga del operador << para mostrar por pantalla los valores del objeto de la estructura element
     * @param o Parametro al cual se le envía los datos para mostrar por pantalla
     * @param p Objeto de la estructura element
     * @return Devuelve la referencia del parametro al cual se le pasa los valores del objeto element
     */
    friend ostream& operator<<(ostream &o, const element &p);

};
class MaxStack{
    /**
 * @brief T.D.A MaxStack
 *
 * Implementación de una Pila (stack) a través del uso de una cola (queue) de la biblioteca STL y del uso de la estructura element.
 *
 * Se basa en el uso de una pila con un contenedor subyacente de cola formada por objetos de la estructura element
 * @author Florin Emanuel Todor
 * @author José Antonio Villarejo Caballero
 * @date Octubre 2022
*/


private:
    /**
     * @brief Cola formado por objetos de la estructura element
     */
    queue <element> cola;   //contenedor

    void ordenar(); //Se utiliza para ordenar los datos a través de un vector auxiliar, para que tenga la forma de una pila
    /**
     * @brief Sobrecarga del operador << para mostrar por pantalla los datos del contenedor del objeto
     * @param o Parametro al cual se le envía los datos del contenedor
     * @param p Objeto de la clase MaxStack
     * @return Referencia del parametro al cual se le envían los datos
     */
    friend ostream& operator<<(ostream &o , const MaxStack &p);


public:
    /**
     * @brief Constructor por defecto
     * @post Genera un objeto de la estructura element con valor actual y valor maximo inicializados a 0
     * @return Objeto de la estructura element
     *
     */
    MaxStack(); //Constructor
    /**
     * @brief Operador de tipo destructor
     * @return void
     *
     */
    ~MaxStack(); //Destructor
    /**
     * @brief Devuelve el elemento tope de la pila, que es el front de la cola
     * @return referencia al objeto element
     */
    element & top(); //Devuelve el elemento tope de la pila, que es el front de la cola

    /**
     * @brief Introduce un nuevo elemento en la pila (cola)
     * @param nuevoElemento
     */
    void push(element nuevoElemento);
    /**
     * @brief Saca el elemento tope de la pila, que es el elemento del front de la cola
     */
    void pop();//Sacar el elemento del tope de la pila, que es el front de la cola
    /**
     * @brief Devuelve el tamaño que tiene la cola
     * @return tamaño de la cola
     */
    unsigned long size(); //Devuelve el tamaño que tiene la cola
    /**
     * @brief Comprueba si la pila(cola) está vacia
     * @return true or false
     */
    bool empty();//Comprueba si la pila/cola está vacía
    /**
     * @brief Ordena la cola, con el uso de una cola auxiliar, para que tenga el orden interno de una Pila
     */

};

#endif // _MAXSTACK_H_