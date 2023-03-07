/**
 * @brief TDA LettersSet
 * @details crea un objeto compuesto por un conjunto de letras que serán usadas en el juego en base a un contenedor subyacente map.
 * @details cada letra es un pair de primera componente char y de segunda componente un TDA LetterInfo
 * @details el TDA LetterInfo se compone de dos campos repeticiones y score
 */


#include "letters_set.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace  std;

LetterInfo::LetterInfo() {
    this->repeticiones=0;
    this->score=0;
}

LetterInfo::LetterInfo(int a, int b){
    this->repeticiones= a;
    this->score= b;
};

LettersSet::LettersSet() {clear();};

LettersSet::LettersSet(const LettersSet &other) {
    letters = other.letters;
}


bool LettersSet::insert(const pair<char, LetterInfo> &val){

    if(letters.count(val.first) ==  0) {
        letters.insert(val);

        return true;
    }
    else return false;
}


bool LettersSet::erase(const char & key) {
    if( letters.count(key) > 0)
    {
        letters.erase(key);
        return true;
    }
    else
        return false;
}

void LettersSet::clear(){
    letters.clear();
}

bool LettersSet::empty() const {
    return letters.empty();
}

unsigned int LettersSet::size() const {
    return letters.size();
}

int LettersSet::getScore(string word){
    int puntuacion = 0;

    for(int i=0; i<word.size(); ++i){
        puntuacion += letters[word[i]].score;
    }
    return puntuacion;
}

LettersSet & LettersSet::operator=(const LettersSet &other) {

    if(this != &other){
        if(!this->empty()){
            letters.clear();
            this->letters = other.letters;
        }
        return *this;
    }
}

LetterInfo & LettersSet::operator[](const char &val) {

    if(!empty()){
        return letters[val];
    }

}


ostream & operator<<(ostream & os, const LettersSet & other){
map<char,LetterInfo>::const_iterator it;
it = other.letters.begin();


    while(it != other.letters.end()){
        os<< it->first<<'/t'<<it->second.repeticiones<<'/t'<<it->second.score;
        it++;
    }

    return os;

}

istream  & operator >> (istream & is ,  LettersSet & other){
    char caracter;

    int repe,puntua;
    pair<char,LetterInfo> p;
    string palabra;

    getline(is,palabra);

    while (is){

        is >> caracter;
        caracter = tolower(caracter);
        is >> repe;
        is >> puntua;

        p.first= caracter;
        p.second.repeticiones= repe;
        p.second.score = puntua;
        other.insert(p);

    }
    return is;

}

