#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__
#include <map>
#include <string>
#include <iostream>
using  namespace  std;

/**
 * @brief TDA LetterInfo
 *
 * Contiene información sobre un determinado carácter del juego de las
 * letras. En concreto, almacena información sobre el número de repeticiones de
 * la letra en la partida y de la puntuación que otorga al utilizarse en una
 * palabra
 */

struct LetterInfo{
    /**
     * @brief número de veces que se repite una letra
     */
    int repeticiones;
    /**
     * @brief Puntuación que tiene dicha letra
     */
    int score;

    /**
     * @brief Constructor por defecto
     */
    LetterInfo();

    /**
     * @brief Constructor con parámetros
     * @param a Parámetro para asociar el valor a repeticiones
     * @param b Parámetro para asociar el valor a score
     */
    LetterInfo(int a, int b);

    void insert_valores(int a, int b);

};


/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la información necesaria para
 * jugar una partida al juego de las letras, es decir, el número de repeticiones
 * que tenemos de la letra y la puntuación que dicha letra otorga cuando se
 * utiliza en una palabra
 */
 class LettersSet {
 private:
     map<char, LetterInfo> letters;

 public:
     /**
      * @brief Constructor por defecto
      */
     LettersSet();

     /**
      * @brief Constructor de copia
      * @param other es el objeto de clase LettersSet a copiar
      */
     LettersSet(const LettersSet &other);

     /**
      * @brief Inserta un elemento en el LettersSet
      * @param val Pareja de la letra y el LetterInfo asociada a insertar
      * @return Devuelve un bool que marca si se ha insertado de forma correcta en el LettersSet. La letra se podrá incluir si no estaba aún incluida en la colección.
      */
     bool insert(const pair<char, LetterInfo> &val);

     /**
      * @brief Elimina un carácter del LettersSet
      * @param key Carácter a eliminar
      * @return Devuelve un bool que indica si se ha podido eliminar de forma correcta la letra del LettersSet
      */
     bool erase(const char &key);

     /**
      *@brief Elimina el contenido del LettersSet
      */
     void clear();

     /**
      * @brief Consulta si el LettersSet está vacio
      * @return Devuelve true en el caso de que esté vacío, false en caso contrario
      */
     bool empty() const;

     /**
      * @brief Tamaño del LettersSet
      * @return Devuelve el número de elementos en el LettersSet
      */
     unsigned int size() const;

     /**
      * @brief Calcula la puntuación de cada palabra
      * @param word Es el string con la palabra cuya puntuación queremos calcular
      * @return Puntuación de la palabra, calculada con la suma de las puntuaciones de cada una de sus letras
      */
     int getScore(string word);

     /**
      * @brief Sobrecarga del operador de asignación
      * @param other es el objeto de la clase LettersSet que queremos copiar
      * @return Devuelve la referencia al objeto this para poder encadenar el operador
      */
     LettersSet &operator=(const LettersSet &other);

     /**
      * @brief Sobrecarga del operador de consulta, []. Permite acceder a los elementos del map que hay en nuestra clase
      * @param val Es el carácter a consultar
      * @return Devuelve la estructura de tipo LetterInfo con la información del carácter consultado: Número de repeticiones y puntuación
      */
     LetterInfo &operator[](const char &val);

     /**
      * @brief Sobrecarga del operador de salida
      * @param os Flujo de salida, donde se va a escribir el LettersSet
      * @param other Es el LettersSet que se va a escribir en el flujo de salida
      * @return Referencia hacia el flujo de salida
      */
     friend ostream &operator<<(ostream &os, const LettersSet &other);

     /**
      * @brief Sobrecarga del operador de entrada
      * @param is Flujo de entrada, donde se va a leer el LettersSet
      * @param other Es el LettersSet en el que se va a almacenar la información leída
      * @return Devuelve una referencia hacia el flujo de entrada
      */
     friend istream &operator>>(istream &is, LettersSet &other);

    /**
     * @brief Creación del iterator begin
     * @return iterator = letters.begin();
     */
    map<char,LetterInfo>::iterator begin(){
        map<char,LetterInfo>::iterator it;
        it=letters.begin();
        return it;
    }
     /**
      * @brief Creación del iterator end
      * @return iterator = letters.end();
      */
     map<char,LetterInfo>::iterator end(){
         map<char,LetterInfo>::iterator it;
         it=letters.end();
         return it;
     }
     /**
      * @brief Creación del const_iterator begin
      * @return const_iterator = letters.begin();
      */
     map<char,LetterInfo>::const_iterator begin() const{
         map<char,LetterInfo>::const_iterator it;
         it=letters.begin();
         return it;
     }
     /**
       * @brief Creación del const_iterator end
       * @return const_iterator = letters.end();
       */
     map<char,LetterInfo>::const_iterator end() const{
         map<char,LetterInfo>::const_iterator it;
         it=letters.end();
         return it;
     }

 };
#endif
