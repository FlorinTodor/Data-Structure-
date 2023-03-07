/**
 * @brief Programa de prueba del TDA LettersBag
 * @details crea un objeto del TDA LettersBag a partir de un objeto del TDA LettersSet
 * @param Parametro1 Archivo con información para rellenar un objeto del TDA LettersSet
 * @return Imprime por pantalla de forma aleatoria todas las letras del objeto LettersBag creado
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "letters_bag.h"
#include "letters_set.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[]){
    srand(time(NULL));
   LettersSet conjunto_letras;
    char c;

   ifstream archivo_letras;

   archivo_letras.open(argv[1]);

   if(archivo_letras){
    archivo_letras >> conjunto_letras;
   } else{
       cerr<< " EL fichero no se ha abierto de forma correcta"<<endl;
        return -1;
   }
   archivo_letras.close();

   LettersBag bolsa_letras(conjunto_letras);

   while(bolsa_letras.size()> 0){
       c= toupper(bolsa_letras.extractLetter());

       cout << c<< endl;
   }






return 0;



}