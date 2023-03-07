//
// Created by flo on 2/01/23.
//

#ifndef P04_JUEGO_LETRAS_SOLVER_H
#define P04_JUEGO_LETRAS_SOLVER_H
#include "dictionary.h"
#include "letters_set.h"
using namespace  std;

class solver{
private:
    Dictionary dict;
    LettersSet letters_set;


    /**
     * @brief Comprueba si una palabra se puede formar con las letras disponibles
     * @param avaliable_letters
     * @param palabra
     * @return true si se puede formar y false en caso contrario
     */
    bool comprobacion(const string palabra,const vector<char> & avaliable_letters);



public:
    /**
     * @brief Constructor por parámetros, crea un solver que tiene asociado un Dictionary y un LettersSet
     * @param dict
     * @param letters_set
     */
    solver(const Dictionary & dict, const LettersSet & letters_set);




    /**
     * @brief Obtiene las mejores soluciones dado el vector de letras disponibles y el tipo de partida que se juega
     * @param avaliable_letters vector de letras disponibles para la partida
     * @param score_game True indica que la partida se juega a puntuación, y false que se juega a longitud
     * @return Devuelve un vector con las mejores soluciones y sus puntuaciones
     */
    pair<vector<string>, int> getSolutions(const vector<char> & avaliable_letters, bool score_game);

};


#endif //P04_JUEGO_LETRAS_SOLVER_H
