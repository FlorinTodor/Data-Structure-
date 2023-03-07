
#ifndef __DICTIONARY_H__
#define __DICTIONARY_H__

/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace  std;



class Dictionary {
private:
    set <string> words;

public:
    /**
     * @brief Constructor por defecto
     */
    Dictionary();

    /**
     * @brief Constructor de copia
     * @param other, objeto de la clase Dictionary que queremos copiar
     */
    Dictionary(const Dictionary &other);

    /**
     * @brief Indica si una palabra está en el diccionario o no
     * @param val, es la palabra que se quiere buscar
     * @return Devuelve true si la palabra existe en el diccionario o false en caso contrario
     */
    bool exists(const string &val);

    /**
     * @brief Inserta una palabra en el diccionario
     * @param val, Es la palabra que se quiere introducir en el diccionario
     * @return Devuelve true si se ha introducido con éxito , true en caso contrario. Se realiza una introducción exitosa si no existe ya en el diccionario
     */
    bool insert(const string &val);

    /**
     * @brief Elimina una palabra del diccionario
     * @param val Es la palabra que se quiere eliminar
     * @return Devuelve un bool que indica si se ha eliminado del diccionario
     **/
    bool erase(const string &val);

    /**
     * @brief Elimina todas las palabras contenidas en el contenido
     */
    void clear();

    /**
     * @brief Comprueba si el diccionario está vacío.
     * @returnDevuelve true en el caso de que esté vacío y false en caso contrario
     */
    bool empty() const;

    /**
     * @brief Tamaño del diccionario
     * @return Devuelve el número de palabras guardadas en el diccionario
     */
    unsigned int size() const;

    /**
     * @brief Indica el número de apariciones de una letra
     * @param c letra a buscar
     * @return Devuelve un entero indicando el número de apariciones
     */
    int getOccurrences(const char c);

    /**
     * @brief Cuenta el total de las letras de un diccionario
     * @return Entero con el total de letras.
     */
    int getTotalLetters();

    /**
     * @brief Devuelve las palabras del diccionario con una longitud dada
     * @param length Longitud de las palabras buscada
     * @return Vector de palabras con la longitud deseada
     */
    vector <string> wordsOfLength(int length);

    friend istream & operator >> (istream & is, Dictionary & dic);

    /**
     * @brief Class iterator de la Class Dictionary
     */
    class iterator {
    private:
        set<string>::iterator it;
    public:
        /**
         * @brief constructor por defecto
         */
        iterator() {};
        /**
         * @brief Constructor de copia de un iterador de set
         * @param other iterator de set
         */
        iterator(const set<string>::iterator &other) : it(other) {
        };
        /**
         * @brief Constructor de copia de un iterador constante
         * @param other iterador constante
         */
        iterator(const iterator &other) : it(other.it) {
        };
        /**
         * @brief Destructor
         */
        ~iterator() {};
        /**
         * @brief Sobrecarga del operador de asignación
         * @param other iterador constante del cual se obtiene su información
         * @return iterador con información de other
         */
        iterator &operator=(const iterator &other) {
            it = other.it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador de asignación
         * @param other iterador de set del cual se obtiene su información
         * @return iterador con información de other
         */
        iterator &operator=(const set<string>::iterator &other) {
            it = other;
            return *this;
        }

        /**
         * @brief Sobrecarga del operador de *
         * @return Devuelve *it
         */
        const string operator*() const {
            return *it;
        }
        /**
         * @brief Sobrecarga del operador unario de ++
         * @return Devuelve ++it
         */
        iterator &operator++() {
            ++it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador unario de --
         * @return Devuelve --it
         */
        iterator &operator--() {
            --it;
            return *this;
        }
        /**
        * @brief Sobrecarga del operador unario de ++
        * @return Devuelve ++it
        */
        iterator &operator++(int) {
            ++it;
            return *this;
        }
        /**
        * @brief Sobrecarga del operador unario de --
        * @return Devuelve --it
        */
        iterator &operator--(int) {
            --it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador lógico de !=
         * @param other iterador constante con el cual se realiza la comparación lógica
         * @return true si son distintos o false en caso contrario
         */
        bool operator!=(const iterator &other) {
            return it != other.it;
        }
        /**
         * @brief Sobrecarga del operador lógico de ==
         * @param other iterador constante con el cual se realiza la comparación lógica
         * @return true si son iguales y false en caso contrario
         */
        bool operator==(const iterator &other) {
            return it == other.it;
        }

    };

    /**
     * @brief Class const_iterator de la Class Dictionary
     */
    class const_iterator {
    private:
        set<string>::const_iterator const_it;
    public:
        /**
        * @brief constructor por defecto
        */
        const_iterator() {}
        /**
        * @brief Constructor de copia de un const_iterador de set
        * @param other iterator de set
        */
        const_iterator(const set<string>::const_iterator &other)  {
            const_it = other;
        }
        /**
       * @brief Constructor de copia de un const_iterador
       * @param other iterador constante
       */
        const_iterator(const const_iterator &other) {
            const_it = other.const_it;
        };
        /**
         * @brief Destructor
         */
        ~const_iterator() {}

        /**
         * @brief Sobrecarga del operador de asignación
         * @param other const_iterador de set del cual se obtiene su información
         * @return const_iterador con información de other
         */
        const_iterator &operator=(const set<string>::const_iterator &other) {
            const_it = other;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador de asignación
         * @param other const_iterator del cual se obtiene su información
         * @return const_iterator con información de other
         */
        const_iterator &operator = (const const_iterator &other) {
            const_it = other.const_it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador de *
         * @return Devuelve *it
         */
        const string operator*() const {
            return *const_it;
        }
        /**
         * @brief Sobrecarga del operador unario de ++
         * @return Devuelve ++const_int;
         */
        const_iterator &operator++() {
            ++const_it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador unario de --
         * @return Devuelve --const_int;
         */
        const_iterator &operator--() {
            --const_it;
            return *this;
        }
        /**
        * @brief Sobrecarga del operador unario de ++
        * @return Devuelve ++const_int;
        */
        const_iterator &operator++(int) {
            ++const_it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador unario de --
         * @return Devuelve --const_int;
         */
        const_iterator &operator--(int) {
            --const_it;
            return *this;
        }
        /**
         * @brief Sobrecarga del operador lógico de !=
         * @param other const_iterator  con el cual se realiza la comparación lógica
         * @return true si son distintos o false en caso contrario
         */
        bool operator!=(const const_iterator &other) {
            return const_it != other.const_it;
        }
        /**
         * @brief Sobrecarga del operador lógico de ==
         * @param other const_iterator  con el cual se realiza la comparación lógica
         * @return true si son iguales y false en caso contrario
         */
        bool operator==(const const_iterator &other) {
            return const_it == other.const_it;
        }
    };

    //Begin and end use

    /**
     * @brief Devuelve un iterator apuntando a word.begin();
     * @return iterator = word.begin()
     */
    iterator begin() {
        iterator i;
        i = words.begin();
        return i;
    }
    /**
     * @brief Devuelve un iterator apuntando a word.end();
     * @return iterator = word.end();
     */
    iterator end() {
        iterator i;
        i = words.end();
        return i;
    }
    /**
    * @brief Devuelve un const_iterator apuntando a word.begin();
    * @return const_iterator = word.begin()
    */
    const_iterator begin() const {
        const_iterator const_i;
        const_i = words.begin();
        return const_i;
    }

    /**
    * @brief Devuelve un const_iterator apuntando a word.end();
    * @return const_iterator = word.end()
    */
    const_iterator end() const {
        const_iterator const_i;
        const_i = words.end();
        return const_i;
    }

};

#endif
