/**
 * @file maxstack.cpp
 * @brief  Archivo de implementación del TDA MaxStack
 */
#include "maxstack.h"
#include <iostream>

using namespace std;

element &MaxStack::top() {
    return cola.front();
}

void MaxStack::push(element nuevoElemento) {
//Tendria que comprobar que no está vacio, meter el elemento y
    if (cola.empty() == true) { //Si la cola está vacia se inicializa con el nuevoElemento
        cola.push(nuevoElemento);
        top().maximum = nuevoElemento.value;
    } else { // Si no está vacia hay que dividir la situación en dos

        if (nuevoElemento.value > cola.front().maximum) { //Si el valor del nuevoElemento es mayor que el maximo del numero anterior de la cola, se cambia el maximo
            nuevoElemento.maximum = nuevoElemento.value; //Cambiamos el valor del maximo
            cola.push(nuevoElemento); //Insertamos el nuevo elemento a la cola
        }

        if (nuevoElemento.value < cola.front().maximum || nuevoElemento.value ==cola.front().maximum) {
            //En el caso en el que el valor del nuevo elemento es igual o inferior al maximo, para cambiar el max
            nuevoElemento.maximum = top().maximum;
            cola.push(nuevoElemento);
        }

    }

    ordenar();
}

void MaxStack::pop() {
    //Hay que sacar el ultimo elemento introducido en la cola
    //NO hace falta ordenarlo si lo voy a ordenar en el momento de introducir los datos
    assert(!cola.empty());
    cola.pop();
}


void MaxStack::ordenar() {
    int contador = 0;
    assert(!cola.empty()); //COmprobamos que la cola  no esté vacia
    queue<element> vec_aux; //Vector auxiliar para realizar el cambio
    vec_aux = cola; //El vector_aux copia los datos que se encuentran en la cola

    while (&cola.front() !=
           &cola.back()) { //Mientras que la posición de la cola no sea la ultima, quitamos los datos de la cola para quedarnos con el último dato
        cola.pop();
        ++contador;
    }

    for (int i = 0; i < contador; ++i) { //Tras tener el último dato de la cola, introducimos de nuevo los datos que habíamos quitado, por ello lo del contador
        //Para saber  cuantos tenemos que introducir.
        cola.push(vec_aux.front());
        vec_aux.pop();
    }
}

unsigned long MaxStack::size() {
    return cola.size();
}

bool MaxStack::empty() {
    if (cola.empty()) {
        return true;
    } else {
        return false;
    }
}

ostream &operator<<(ostream &o, const element &p) {
    o << p.value << "," << p.maximum;
    return o;
}

element::element(int i) {
    this->value = i;
}

MaxStack::~MaxStack() {};

MaxStack::MaxStack() {
}



