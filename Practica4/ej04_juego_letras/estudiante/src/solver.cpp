//
// Created by flo on 2/01/23.
//
#include <solver.h>
#include <vector>
#include <string>
#include <dictionary.h>
#include <letters_set.h>

using namespace  std;

solver::solver(const Dictionary &dicct, const LettersSet & lettersset) {
    this->dict = dicct;
    this->letters_set = lettersset;
}





bool solver::comprobacion(const string palabra , const vector<char> & avaliable_letters){
    vector<char> letras_disponibles = avaliable_letters; //Hacemos una copia de la variable avaliable_letters para poder ir quitando las plabras inecesarias
    bool puede = false; //Creamos una variable bool para indicar si la palabra está formada con las letras dispinibles
    int num_letras = 0; //COntador para el número de letras de la palabra que coincide con las palabras disponibles

    for (int i = 0; i < palabra.size(); i++) {
        for(vector<char>::iterator it = letras_disponibles.begin(); it != letras_disponibles.end(); it++){ //creamos un iterador para movernos por el vector<char>
            if(it.operator*() == palabra[i]) {
                num_letras++;
                letras_disponibles.erase(it);
                break; //Para
            }

        }

    }

    if (num_letras == palabra.size()){ // las letras de la palabra se encuentra en las letras disponibles
        puede = true;
    }

    return puede;
}

pair<vector<string>, int> solver::getSolutions(const vector<char> & avaliable_letters, bool score_game){
    string current_word;
    int score_max = 0, current_score;
    vector<string> palabras_score_max;
    pair<vector<string>, int> result;
    Dictionary::iterator p = dict.begin();

    for(p; p != dict.end(); ++p){
        current_word = *p;
        if(score_game) {
            current_score = letters_set.getScore(current_word);
        }
        else current_score = current_word.length();

        //Siempre que comprobacion == true (se puede formar la palabra), si la puntuacion de la palabra actual es mayor:
        if (score_max < current_score && comprobacion(current_word, avaliable_letters)) {
            score_max = current_score;

            //Limpiamos el vector con las soluciones si no esta vacio e introducimos la nueva palabra
            palabras_score_max.clear();

            palabras_score_max.push_back(current_word);

        } else if (score_max == current_score && comprobacion(current_word, avaliable_letters)) {
            palabras_score_max.push_back(current_word);
        }
    }

    result.first = palabras_score_max;
    result.second = score_max;
    return result;
}