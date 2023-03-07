/**
     * @brief Cuenta en el diccionario introducido por parámetro, las ocurrencias y la frecuencia relativa, de cada letra de un fichero de palabras introducido también por parámetro
     * @param diccionario (Fichero de palabras introducido como primer parámetro)
     * @param letras (Fichero de letras introducido como segundo parámetro)
     * @return Imprime por pantalla el número de ocurrencias y la frecuencia relativa, de cada letra del fichero de letras en el diccionario
     */

#include <iostream>
#include <fstream>
#include "dictionary.h"
#include "letters_set.h"

using namespace std;

int main(int argc, char *argv[]){

    if(argc!=3) {
        cout<<("Tienen que ser dos argumentos")<<endl;
        exit(1);
    }

    Dictionary diccionario;
    LettersSet letras;

    string ruta_diccionario = argv[1];

    ifstream archivo_diccionario;
    archivo_diccionario.open(ruta_diccionario);

    if(archivo_diccionario){
        archivo_diccionario >> diccionario;
    }

    string  ruta_letras = argv[2];

    ifstream  archivo_letras;
    archivo_letras.open(ruta_letras);

    if(archivo_letras) {
        archivo_letras >> letras;
    }

   map<char,LetterInfo>::iterator it=letras.begin();;

    cout<< "Letra\tFAbs.\tFrel." << endl;

    for( it = letras.begin(); it != letras.end(); it++){


        double total_ocurrencias = diccionario.getOccurrences(it->first);
        double total_letras = diccionario.getTotalLetters();
        double frecuencia_relativa = total_ocurrencias/total_letras;


        char letra_actual = toupper(it->first);

        cout << letra_actual << '\t' << total_ocurrencias << '\t' << frecuencia_relativa << endl;
    }

    return 0;
}