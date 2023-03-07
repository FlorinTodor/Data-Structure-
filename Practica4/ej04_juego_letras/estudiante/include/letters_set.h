#ifndef __LETTER_SET_H__
#define __LETTER_SET_H__
#include <iostream>
#include <cstdlib>
#include <map>
using namespace  std;
/**
 * @brief TDA LetterInfo
 *
 * Contiene informaciÃ³n sobre un determinado carÃ¡cter del juego de las
 * letras. En concreto, almacena informaciÃ³n sobre el nÃºmero de repeticiones de
 * la letra en la partida y de la puntuaciÃ³n que otorga al utilizarse en una
 * palabra
 */
struct LetterInfo{
    int repetitions;
    int score;
};

/**
 * @brief TDA LettersSet
 *
 * Este TDA representa un conjunto de letras, con la informaciÃ³n necesaria para
 * jugar una partida al juego de las letras, es decir, el nÃºmero de repeticiones
 * que tenemos de la letra y la puntuaciÃ³n que dicha letra otorga cuando se
 * utiliza en una palabra
 */
class LettersSet {
private:
    std::map<char, LetterInfo> letters;

public:
    map<char, LetterInfo>::iterator begin();
    map<char, LetterInfo>::iterator end();

    map<char, LetterInfo>::const_iterator cbegin();
    map<char, LetterInfo>::const_iterator cend();

    map<char, LetterInfo>::iterator begin() const;
    map<char, LetterInfo>::iterator end() const ;

    map<char, LetterInfo>::const_iterator cbegin() const ;
    map<char, LetterInfo>::const_iterator cend() const ;

    /**
     * @brief map que alamacena una letra, su puntuación y sus repeticiones
     */


    /**
     * @brief Constructor por defecto. Crea un LettersSet vacío
     */
    LettersSet();

    /**
     * @brief Constructor de copia
     * @param other LettersSet a copiar
     */
    LettersSet(const LettersSet & other);

    /**
     * @brief Inserta un elemento en el LetterSet.
     * @param val Pareja de letra y LetterInfo asociada a insertar
     * @return booleano que marca si se ha podido insertar la letra en el LettersSet.
     * La letra sólo se inserta correctamente si no estaban aún incluida en la colección.
     */
    bool insert (const std::pair<char, LetterInfo> & val);

    /**
     * @brief Elimina un carácter del LettersSet.
     * @param key Carácter a eliminar.
     * @return booleano que indica si se ha podido eliminar correctamente la letra del LettersSet.
     */
    bool erase(const char & key);

    /**
     * @brief Limpia el contenido del LettersSet.
     * @post Elimina el contenido del LettersSet.
     */
    void clear();

    /**
     * @brief Consulta si el LettersSet está vacío.
     * @return true si el LettersSet está vacío, falso en caso contrario.
     */
    bool empty() const;

    /**
     * @brief Tamaño de LetterSet
     * @return Numero de elementos en el LettersSet
     */
    unsigned int size () const;

    /**
     * @brief Calcula la puntuación dada una palabra
     * @param word String con la palabra cuya puntuación queremos calcular
     * @return Puntuacion de la palabra, calculada como la suma de las puntuaciones de cada una de las palabras
     */
    int getScore(std::string word);

    /**
     * @brief Sobrecarga del operador de asignación
     * @param cl LettersSet a copiar
     * @return Referencia al objeto this para poder encadenar el operador
     */
    LettersSet & operator = (const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de consulta. Permite acceder a los elementos del map que hay en nuestra clase.
     * @param val Caracter a consultar
     * @return Estructura de tipo LetterInfo con la información del carácter consultando: Número de repeticiones y puntuación
     */
    LetterInfo & operator [] (const char & val);

    /**
     * @brief Sobrecarga del operador de salida
     * @param os Flujo de salida, donde escribir el LettersSet
     * @param cl LettersSet que se escribe
     */
    friend std::ostream & operator << (std::ostream& os, const LettersSet & cl);

    /**
     * @brief Sobrecarga del operador de entrada
     * @param is Flujo de entrada, del que leer el LettersSet
     * @param cl LettersSet en el que almacenar la información leída
     */
    friend std::istream & operator >> (std::istream& is, LettersSet & cl);

};

#endif