/**
* @brief Programa de prueba de LettersSet, calcula la puntuación de una palabra
* @param Parametro1 Archivo pasado como parámetro para crear un objeto LettersSet
* @param palabra Palabra a la que calcular su puntuación
* @return Imprime por pantalla la puntuación de la palabra dada por parámetro
*/

#include <iostream>
#include <fstream>
#include "letters_set.h"
using namespace  std;
int main(int argc, char *argv[]){

    if(argc!=3) {
        cout<<("Tienen que ser dos argumentos")<<endl;
        exit(1);
    }
    //1 argumento es la ruta de donde se encuentra el archivo sobre el conjunto de letras
    // 2 palabra que se va a calcular la puntuación

    string file;
    file = argv[1];
    ifstream archivo;
    LettersSet aux;
    string palabra= argv[2];

    archivo.open(file);

    if(archivo){
        archivo >>  aux;
    }
    else{
        cerr<< "El fichero no se ha abierto correctamente"<<endl;
        return -1;
    }

    archivo.close();

    cout<<aux.getScore(palabra)<<endl;
}
