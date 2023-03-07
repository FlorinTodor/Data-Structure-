/**
     * @brief Busca en el diccionario introducido por parámetro, las palabras que sean de la longitud dada por otro parámetro
     * @param diccionario (Fichero de palabras introducido como primer parámetro)
     * @param longitud
         * @return Imprime por pantalla las palabras del diccionario  que sean de la longitud pedida
     */


using namespace std;
#include <iostream>
#include <fstream>
#include "dictionary.h"

int main(int argc, char *argv[]){
    Dictionary diccionario;

    if(argc!=3) {
        cout<<("Tienen que ser dos argumentos")<<endl;
        exit(1);
    }

    string ruta;
    ruta = argv[1];

    int longitud = atoi(argv[2]);

    ifstream archivo;
    archivo.open(ruta);

    if(archivo){
        archivo >> diccionario;
    }

    archivo.close();

    vector<string> palabras;

    palabras = diccionario.wordsOfLength(longitud);
    cout<<"Palabras de longitud "<<longitud<<endl;
    for(int i=0; i < palabras.size(); i++){

        cout << palabras[i] << endl;
    }
}
