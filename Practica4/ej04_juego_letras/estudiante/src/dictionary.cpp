//
// Created by fluque1995 on 8/9/21.
//

#include <string>
#include <vector>
#include <utility>
#include <set>
#include "dictionary.h"
#include <cmath>

///////////////////////////////////////////////////////////////////////////////
//                             Private functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::node Dictionary::findLowerBoundChildNode(char character, Dictionary::node current) {
  node prev_child, curr_child = current.left_child();

  for (; !curr_child.is_null() && (*curr_child).character <= character; curr_child = curr_child.right_sibling()){
    prev_child = curr_child;
    if ((*curr_child).character == character) {
      return curr_child;
    }
  }
  if (!prev_child.is_null()) {
    return prev_child;
  }
  return current;
}

Dictionary::node Dictionary::insertCharacter(char character, Dictionary::node current) {
  node insertion_position = findLowerBoundChildNode(character, current);
  if (insertion_position == current){
    this->words.insert_left_child(current, char_info(character));
    return insertion_position.left_child();
  } else if ((*insertion_position).character != character){
    this->words.insert_right_sibling(insertion_position, char_info(character));
    return insertion_position.right_sibling();
  } else {
    return insertion_position;
  }
}

int Dictionary::getOccurrences(node curr_node, char c){
   int ocurrencia =0;
   if ( !curr_node.left_child().is_null()){
       ocurrencia += getOccurrences(curr_node.left_child(),c);

   }

   if( !curr_node.right_sibling().is_null()){
       ocurrencia += getOccurrences(curr_node.right_sibling(),c);
   }

   if ( c == curr_node.operator*().character){
       ocurrencia++;
   }
   return ocurrencia;
}

std::pair<int, int> Dictionary::getTotalUsages(node curr_node, char c){
    pair<int,int> pareja;
    pair<int,int> numero_izq;
    pair<int,int> numero_drch;
    pareja.first = 0  ; //Primer int es el número de usos
    pareja.second = 0 ;  //Primer int es el número de palabras que terminan por debajo del nodo actual

    if ( !curr_node.left_child().is_null()){
         numero_izq = getTotalUsages(curr_node.left_child(),c);
    }
    if ( !curr_node.right_sibling().is_null()){
         numero_drch = getTotalUsages(curr_node.right_sibling(),c);
    }

    pareja.first = numero_izq.first + numero_drch.first; // El número de usos es la sumatoria de los usos del hijo izquierda y del hermano derecha
    pareja.second = numero_izq.second + numero_drch.second; //El número de palabras que terminan por debajo del nodo actual es la sumatoria del hijo izquierda y del hermano de la derecha

    if ( curr_node.operator*().character == c){ //Si el caracter del nodo actual es igual al caracter que queremos saber el número de usos
        for(int i=0; i < numero_izq.second;++i){
            pareja.first++; //Aumentamos el numero de usos
        }
    }
    if ( curr_node.operator*().valid_word == true){ // Si en el nodo actual termina una palabra aumentamos el número de palabras
        if ( curr_node.operator*().character == c){ //Además de si en el nodo actual termina una palabra, si en ese nodo el caracter es igual al que buscamos para calcular su uso, también aumenta el número de usos
            pareja.first++;
        }
        pareja.second++;
    }

    return pareja;


}

///////////////////////////////////////////////////////////////////////////////
//                              Public functions                             //
///////////////////////////////////////////////////////////////////////////////

Dictionary::Dictionary() {
  this->words.set_root(char_info());
  this->total_words = 0;
}

Dictionary::Dictionary(const Dictionary &other) {
  this->words = other.words;
  this->total_words = other.total_words;
}

Dictionary::~Dictionary() {
  this->words.clear();
}

bool Dictionary::exists(const std::string & word) {
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current = this->findLowerBoundChildNode(word[i], current);
    if ((*current).character != word[i]) {
      return false;
    }
  }

  return (*current).valid_word;
}

bool Dictionary::insert(const std::string &word) {
  node current = this->words.get_root();
  for (int i = 0; i < word.size(); ++i){
    current = this->insertCharacter(word[i], current);
  }

  if (!(*current).valid_word) {
    (*current).valid_word = true;
    this->total_words++;
    return true;
  }

  return false;
}

bool Dictionary::erase(const std::string & val){
  node current = this->words.get_root();
  for (int i = 0; i < val.size(); ++i){
    current = this->findLowerBoundChildNode(val[i], current);
    if ((*current).character != val[i]) {
      return false;
    }
  }
  if ((*current).valid_word){
    (*current).valid_word = false;
    this->total_words--;
    return true;
  }
  return false;
}

Dictionary &Dictionary::operator=(const Dictionary &dic){
  if (this != &dic){
    this->words.clear();
    this->words = dic.words;
    this->total_words = dic.total_words;
  }
  return *this;
}

///////////////////////////////////////////////////////////////////////////////
//                               I/O overload                                //
///////////////////////////////////////////////////////////////////////////////

std::ostream& operator<<(std::ostream &os, const Dictionary &dict){
  for(Dictionary::iterator it = dict.begin();it != dict.end(); ++it){
    os <<*it << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream &is, Dictionary &dict){
  std::string curr_word;
  while (getline(is, curr_word)){
    dict.insert(curr_word);
  }
  return is;
}

///////////////////////////////////////////////////////////////////////////////
//                            Recursive counters                             //
///////////////////////////////////////////////////////////////////////////////

int Dictionary::getOccurrences(const char c){
    return getOccurrences(words.get_root(),c);

}

int Dictionary::getTotalUsages(const char c){
   return getTotalUsages(this->words.get_root(),c).first;

}

///////////////////////////////////////////////////////////////////////////////
//                                 Iterator                                  //
///////////////////////////////////////////////////////////////////////////////
Dictionary::iterator::iterator() {
    tree<char_info>::const_preorder_iterator it;
    iter = it;


}

Dictionary::iterator::iterator(tree<char_info>::const_preorder_iterator iter) {
    this->iter = iter;


}

std::string Dictionary::iterator::operator*() {
        return this->curr_word;

}

Dictionary::iterator &Dictionary::iterator::operator++() {

    do{

        int nivel_antiguo = iter.get_level(); //almacenamos el nivel antiguo
        iter.operator++(); //Aumentamos el iterador interno del arbol
        if(iter.get_level() - nivel_antiguo == 1) { //Si es mayor significa que hemos descendido
                curr_word.push_back(iter.operator*().character);
        }
        else if (iter.get_level() == nivel_antiguo){ //Nos encontramos en el mismo nive, por lo que se ha pasado al hermano
            curr_word.pop_back();
            curr_word.push_back(iter.operator*().character);
        }
        else{ //  nivel_antiguo > iter.get_level();

            int contador = 1; //Diferencia entre nivel_antiguo y el get_level del iterador, para saber cuanto ha ascendido
            contador = contador + (nivel_antiguo - iter.get_level());
            //Primero eliminamos todas las letras que vamos ascendiendo
            for(int i=0; i< contador; ++i){
                curr_word.pop_back();
            }

            //Segundo comprobamos si el iter.get_level() == 0, ya que nos encontraríamos en el mismo nivel pero en el hermano
            if ( iter.get_level() == 0){
                return *this;
            }

            //En el caso de que no, colocamos la letra del nodo actual

            curr_word.push_back(iter.operator*().character);
        }


    } while( iter.operator*().valid_word == false);
    return *this;
}




    bool Dictionary::iterator::operator==(const iterator &other) {
        return (this->iter == other.iter);}

    bool Dictionary::iterator::operator!=(const iterator &other) {
        return (this->iter != other.iter);}

    Dictionary::iterator Dictionary::begin() const {

     tree<char_info>::const_preorder_iterator it;
     it = words.get_root();
     Dictionary::iterator ite(it);
     ite.operator++();

     return ite;
}

    Dictionary::iterator Dictionary::end() const {
        return words.cend_preorder();
    }

///////////////////////////////////////////////////////////////////////////////
//                            Letters Iterator                               //
///////////////////////////////////////////////////////////////////////////////

/*
Dictionary::possible_words_iterator Dictionary::possible_words_begin(vector<char> available_characters) const {

}

Dictionary::possible_words_iterator Dictionary::possible_words_end() const {

}

Dictionary::possible_words_iterator::possible_words_iterator() {

}

Dictionary::possible_words_iterator::possible_words_iterator(node current_node, vector<char> available_letters){

}

Dictionary::possible_words_iterator::possible_words_iterator(const possible_words_iterator &other){

}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator=(const Dictionary::possible_words_iterator &other) {

}

bool Dictionary::possible_words_iterator::operator==(const Dictionary::possible_words_iterator &other) const {

}

bool Dictionary::possible_words_iterator::operator!=(const Dictionary::possible_words_iterator &other) const {

}

Dictionary::possible_words_iterator &Dictionary::possible_words_iterator::operator++() {

}

std::string Dictionary::possible_words_iterator::operator*() const {

}*/
