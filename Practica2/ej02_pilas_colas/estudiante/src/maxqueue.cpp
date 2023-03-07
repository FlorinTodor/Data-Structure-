/**
 * @file maxqueue.cpp
 * @brief  Archivo de implementación del TDA MaxQueue
 */

#include "maxqueue.h"

ostream &operator<<(ostream &o, const element &p){
    o <<  p.value << "," << p.maximum ;
    return o;
}

void MaxQueue::push(int i) {
    stack<element> aux;
    element nuevoElemento;
    nuevoElemento.value = i;
    nuevoElemento.maximum = i;

    while (!pila.empty()) {
        if (pila.top().maximum < nuevoElemento.maximum) {
            pila.top().maximum = nuevoElemento.maximum;
        } else {
            nuevoElemento.maximum = pila.top().maximum;
        }
        aux.push(pila.top());
        pila.pop();
    }
    pila.push(nuevoElemento);

    while (!aux.empty()) {
        pila.push(aux.top());
        aux.pop();
    }
}

element & MaxQueue::front() {
    return pila.top();
}

element & MaxQueue::back() {
    stack<element> aux;

    while (!pila.empty()){
        aux.push(pila.top());
        pila.pop();
    }
    element back = aux.top();

    while (!aux.empty()){
        pila.push(aux.top());
        aux.pop();
    }
    return back;
}

unsigned long MaxQueue::size() {
    return pila.size();
}

bool MaxQueue::empty() {
    return pila.empty();
}

void MaxQueue::pop(){
    pila.pop();
    MaxQueue aux;

    while(!pila.empty()){
        aux.push(pila.top().value);
        pila.pop();
    }
    pila = aux.pila;
}



MaxQueue::MaxQueue(){
}

MaxQueue::~MaxQueue() {
}