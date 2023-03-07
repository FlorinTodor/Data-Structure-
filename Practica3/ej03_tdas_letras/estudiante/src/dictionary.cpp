/**
 * @brief TDA Dictionary
 * @details Almacena las palabras de un fichero de texto y permite iterar sobre ellas
 *
 */

#include "dictionary.h"

Dictionary::Dictionary() {
    words.clear();
}

Dictionary::Dictionary(const Dictionary &other) {
    Dictionary::const_iterator it = other.begin();

    for(it; it != other.words.end(); ++it){
        words.insert(*it);
    }
}

bool Dictionary::exists(const string &val) {
    if(!words.empty()){
        bool existe = false;
        if(words.count(val) == 1){
            existe = true;
        }
        return existe;
    }
    else return false;
}

bool Dictionary::insert(const string &val) {
    if(!this->exists(val)){
        words.insert(val);

        return true;
    }
    else return false;
}


bool Dictionary::erase(const string &val) {
    if(this->exists(val)){
        words.erase(val);
        return true;
    }
    else return false;
}

void Dictionary::clear() {
    words.clear();
}

bool Dictionary::empty() const {
    return words.empty();
}

unsigned int Dictionary::size() const {
    return words.size();
}

int Dictionary::getOccurrences(const char c) {  // CREO QUE BIEN, MIRA CAMBIOS
    set<string>::const_iterator it = words.begin();
    int ocurrencias=0;
    for(it; it != words.end(); ++it){
        for(int i=0; i < it->length(); i++){
            if(  it->operator[](i) == c){
                ocurrencias ++;
            }
        }
    }
    return ocurrencias;
}

int Dictionary::getTotalLetters() {  // BIEN, PERO MIRA CAMBIOS
    set<string>::const_iterator it = words.begin();
    int letras_totales=0;
    for(it; it != words.end(); ++it){
        letras_totales += it->length();
    }
    return letras_totales;
}

vector<string> Dictionary::wordsOfLength(int length) {  // LO VEO BIEN
    Dictionary::const_iterator it = words.begin();
    vector<string> palabras;
    string palabra_actual;
    for(it; it != words.end(); ++it){
        palabra_actual = *it;
        if(palabra_actual.length()==length){
            palabras.push_back(palabra_actual);
        }
    }
    return palabras;
}

istream & operator >> (istream &is, Dictionary & dic){ // MIRA EL CAMBIO
    string palabra;

    while(is){
        is >> palabra;
        dic.words.insert(palabra);
    }

    return is;
}