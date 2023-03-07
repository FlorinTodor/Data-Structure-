/**
 * @brief Programa de prueba del template Bag
 * @param Parámetro1 char que indica si se va a crear una bolsa de enteros(I) o de string(C)
 * @param Parámetro2 Archivo con una lista de enteros o de char según corresponda
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "bag.h"
#include <vector>

using namespace std;

int main(int argc, char *argv[]){
   // Inicializamos el generador de números aleatorios
   srand(time(NULL));

   // Creamos una bolsa de caracteres si el primer argumento es una C
   if (argv[1][0] == 'C') {
     Bag <string> bag;

     // Metemos todos los argumentos en la bolsa
     for (int i = 2; i < argc; ++i) {
       bag.add(argv[i]);
     }

     // Los extraemos aleatoriamente y los imprimimos hasta que se nos quede la
     // bolsa vacía
     while(bag.size() > 0){
       cout << bag.get() << endl;
     }

     // Creamos una bolsa de enteros si el primer argumento es una I
   } else if (argv[1][0] == 'I') {
     Bag <int> bag;

     // Metemos todos los argumentos en la bolsa
     for (int i = 2; i < argc; ++i) {
       bag.add(atoi(argv[i]));
     }

     // Los extraemos aleatoriamente y los imprimimos hasta que se nos quede la
     // bolsa vacía
     while(bag.size() > 0){
       cout << bag.get() << endl;
     }
   }

   return 0;
}
