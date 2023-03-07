//
// Created by flo on 2/01/23.
//

#ifndef P04_JUEGO_LETRAS_BAG_H
#define P04_JUEGO_LETRAS_BAG_H
/**
 *  \brief TDA abstracto Bolsa
 *
 *  Este TDA abstracto nos permite trabajar con una colección de elementos que
 *  permite la extracción de elementos de forma aleatoria sin reemplazamiento
 */

#ifndef BAG_H
#define BAG_H
#include <vector>

using namespace std;

template <class T>

class Bag{
private:

    vector <T> v;

public:

    /**
     * @brief Constructor por defecto
     */
    Bag(){
        v.empty();
    }

    /**
     * @brief Constructor de copia
     * @param other Objeto de tipo Bag <T> del que se va a realizar la copia
     */
    Bag(const Bag <T> & other){
        typename  vector<T>::iterator it;
        it=other.v.begin();

        if(!empty()){
            v.clear();
        }
        for(it; it != other.v.end(); ++it){
            v.add(it);
        }

    }

    /**
     * @brief Método para añadir un elemento en la bolsa
     * @param element elemento de tipo T que se va a añadir en la bolsa
     */
    void add(const T & element){
        v.push_back(element);
    }

    /**
     * @brief Método para devolver un elemento aleatorio de la bolsa
     * @pre  Bolsa > 0
     * @post El elemento que se devuelve se debe de eliminar de la bolsa
     * @return Elemento de tipo T extraído de la bolsa
     */
    T get(){
        if(!v.empty()){
            //Generar numero aleatorio
            int num = rand()%v.size();
            Bag<T> aux; //Bag auxiliar para guardar los que no se sacan
            T elemento_vector = v[num]; //Guardar el elemento T del vector, el cual se retorna
            bool repeticion = false;
            for(int i=0; i < v.size(); ++i){
                //Comprueba que el elemento no sea el buscado o que la repetición sea true
                if(v[i] !=  elemento_vector or  repeticion){
                    aux.add(v[i]);
                }
                    //Para cuando las letras sean repetidas
                else{
                    repeticion = true;
                }

            }

            v.clear(); //Limpiar el vector v
            v = aux.v; //Copiar del vector aux al vector v
            //Devolver el elemento aleatorio
            return elemento_vector;

        }

    }

    /**
     * @brief Elimina todos los elementos de la bolsa
     */
    void clear(){
        v.clear();
    }

    /**
     * @brief Tamaño de la bolsa
     * @return Devuelve el número de elementos que hay en la bolsa
     */
    unsigned int size() const{
        return  v.size();
    }

    /**
     * @brief Comprueba que la bolsa está vacía
     * @return true si la bolsa está vacía, false en caso contrario
     */
    bool empty(){
        return  v.empty();
    }

    /**
     * @brief Sobrecarga del operador de asignación
     * @param other Bag<T> a copiar
     * @return Referencia a this para poder encadenar el operador
     */
    const Bag <T> &  operator =  ( const Bag <T> & other){
        if(this != &other){
            if(!v.empty()){
                v.clear();
                v=other.v;
            }
            return *this;

        }


    }
};

#endif


#endif //P04_JUEGO_LETRAS_BAG_H
