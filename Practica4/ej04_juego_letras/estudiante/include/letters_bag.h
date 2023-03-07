#ifndef __LETTERS_BAG_H__
#define __LETTERS_BAG_H__
#include "letters_set.h"
#include "bag.h"

/**
 * @brief TDA LettersBag
 *
 * Este TDA almacena un conjunto de chars utilizado en el juego de letras.
 * La estructura de datos subyacente es una lista de chars.
 */

class LettersBag {
private:
    Bag<char> letters;
public:
    /**
     * @brief Constructor por defecto
     */
    LettersBag();

    /**
     * @brief Constructor dado un LettersSet. Este constructor debe de rellenar la letterBag con las letras que contiene el LettersSet, introduciendo cada letra el número de veces indicado por el campo de repeticiones.
     * @param lettersSet TDA LettersSet a pasarse
     */
    LettersBag(const LettersSet &lettersSet);

    /**
     * @brief Introduce una letra en la bolsa
     * @param I es la letra a añadir a la letterBag
     */
    void insertLetter(const char &I);

    /**
     * @brief Extrae de manera aleatoria una letra de la bolsa y posteriormente la elimina del conjunto
     * @return Devuelve un char con la letra extraida
     */
    char extractLetter();

    /**
     * @brief Extrae un conjunto de letras de la LettersBag y posteriormente las elimina del conjunto
     * @param n Es el número de letras que se van a extraer de forma aleatoria
     * @return Devuelve una lista de letras extraídas de manera aleatoria.
     */
    vector<char> extractLetters(int n);

    /**
     * @brief Vacía la LettersBag
     */
    void clear();

    /**
     * @brief Tamaño de la bolsa
     * @return Devuelve un entero con el tamaño de la bolsa
     */
    unsigned int size();

    /**
     * @brief Sobrecarga del operador de asignación
     * @param other, es el objeto LettersBag a copiar
     * @return Devuelve la referencia a this de esta forma el operador puede ser encadenadoz
     */
    LettersBag &operator=(const LettersBag &other);

};

#endif
