#include "letters_set.h"
#include <map>
#include "istream"

using namespace std;

map<char, LetterInfo>::iterator LettersSet::begin() {
    return letters.begin();
}

map<char, LetterInfo>::iterator LettersSet::end() {
    return letters.end();
}
map<char, LetterInfo>::const_iterator LettersSet::cbegin() {
    return letters.cbegin();
}

map<char, LetterInfo>::const_iterator LettersSet::cend() {
    return letters.cend();
}

/////////////////////////////////////////////////////////////////////////////////


map<char, LetterInfo>::const_iterator LettersSet::cbegin() const {
    return letters.cbegin();
}

map<char, LetterInfo>::const_iterator LettersSet::cend() const  {
    return letters.cend();
}

LettersSet::LettersSet() {
    letters.clear();
}

LettersSet::LettersSet(const LettersSet &other) {
    if(!empty())
        this->clear();
    for(std::map<char,LetterInfo>::const_iterator it= other.letters.begin(); it !=other.letters.end(); next(it)){
        insert(make_pair(it->first,it->second));
    }
}

bool LettersSet::insert(const std::pair<char, LetterInfo> &val) {
    int contador=letters.size();
    letters.insert(val);
    if(letters.size()==contador+1){
        return true;
    }
    return false;
}

bool LettersSet::erase(const char &key) {
    return letters.erase(key);
}

void LettersSet::clear() {
    letters.clear();
}

bool LettersSet::empty() const {
    return letters.empty();
}

unsigned int LettersSet::size() const {
    return letters.size();
}

int LettersSet::getScore(string word) {
    int suma=0;
    for (int i=0; i<word.size(); i++) {
        suma += letters[word[i]].score;
    }
    return suma;
}

LettersSet & LettersSet::operator=(const LettersSet & cl){
    if(this!=&cl) {
        letters.clear();
        this->letters = cl.letters;
    }
    return *this;
}

LetterInfo & LettersSet::operator [] (const char & val) {
    return letters[val];
}

istream & operator >> (istream & is, LettersSet & cl) {

    char letra;
    int n1 , n2;
    string cadena;

    getline(is,cadena);

    while(is){
        is >> letra >> n1 >> n2;
        letra = tolower(letra);
        pair<char, LetterInfo> aux;
        aux.first = letra;
        aux.second.repetitions = n1;
        aux.second.score = n2;

        cl.insert(aux);
    }

    return is;
}

std::ostream & operator << (std::ostream &os, const LettersSet &cl){
    for(std::map<char,LetterInfo>::const_iterator it= cl.letters.begin(); it !=cl.letters.end(); next(it)){
        os << it->first << "/t" << it->second.repetitions << "/t" << it->second.score << endl;
    }

    return os;
}