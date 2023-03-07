/**
 * @brief TDA LettersBag
 * @details Permite seleccionar las letras con las que se va a jugar la partida
 */

#include "letters_bag.h"
#include "letters_set.h"
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <assert.h>
using namespace  std;


LettersBag::LettersBag() {
    letters.clear();
}

LettersBag::LettersBag(const LettersSet & lettersSet) {
    //se debe de introducir cada letra como repeticiones tiene en su letterinfo


    map<char,LetterInfo>::const_iterator ite = lettersSet.begin();

    pair<char, LetterInfo> aux;

    for (ite; ite != lettersSet.end(); ++ite) {
        aux = *ite;
        for (int i = 0; i < aux.second.repeticiones; ++i) {

           letters.add(aux.first);
        }

    }

}

void LettersBag::insertLetter(const char &I) {
    letters.add(I);
}

char LettersBag::extractLetter() {
    return letters.get();
}

vector<char> LettersBag::extractLetters(int n) {

    vector<char>aux;
    aux.clear();
    for(int i=0; i< n; ++i){
        aux.push_back(letters.get());
    }

    return aux;
}

void LettersBag::clear() {
    letters.clear();
}

unsigned int LettersBag::size() {
    letters.size();
}

LettersBag & LettersBag::operator=(const LettersBag &other) {
    if(this != &other){
        letters.clear();
        letters  =  other.letters;
    }
    return *this;
}
