//
// Created by flo on 29/12/22.
//

#include <solver.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "letters_bag.h"
#include "letters_set.h"


using namespace  std;

int main(int argc, char *argv[]) {

    if (argc != 5) {
        cout << "Error debe de haber 4 argumentos los cuales son :" << endl;
        cout << "1. Ruta al archivo que contiene el diccionario" << endl;
        cout << "2. Ruta al archivo que contiene las Conjunto_de_Letras y su puntuación" << endl;
        cout << "3. Modo de juego (L = longitud, P = puntuación)" << endl;
        cout << "4. Ruta al archivo que contiene el diccionario" << endl;

        return -1;

    }

    ifstream f_diccionario(argv[1]);

    if (!f_diccionario) {
        cout << "No puedo abrir el fichero" << argv[1] << endl;
        return 0;
    }

    Dictionary diccionario;
    f_diccionario >> diccionario;


    LettersSet Conjunto_de_Letras;


    ifstream archivo_letras(argv[2]);


    if (archivo_letras) {
        archivo_letras >> Conjunto_de_Letras;
    }




    solver Solver(diccionario,Conjunto_de_Letras);


    vector<char> letras_disponibles; //vector formado por el subconjunto de letras disponbiles de un letter_set

    LettersBag Bolsa_de_Letras(Conjunto_de_Letras);


    ////////////////////////////////////////////77

///////////////////////////////////////////////////////77



    //utilizamos extracletters para almacenar las Conjunto_de_Letras disponibles, ya que saca Conjunto_de_Letras de forma aleatoria

    for (int i = 0; i < atoi(argv[4]); ++i) {
        letras_disponibles.push_back(Bolsa_de_Letras.extractLetter());
    }


    //prueba para comprobar las salidas dadas en el pdf de la práctica
/**
    letras_disponibles.push_back('d');
    letras_disponibles.push_back('s');
    letras_disponibles.push_back('n');
    letras_disponibles.push_back('t');
    letras_disponibles.push_back('d');
    letras_disponibles.push_back('a');
    letras_disponibles.push_back('i');
    letras_disponibles.push_back('e');
    letras_disponibles.push_back('n');
*/


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SALIDA PARA EL JUEZ

    cout << "LETRAS DISPONIBLES:" << endl;
    for (int i = 0; i < letras_disponibles.size(); ++i) {
        char letra = (letras_disponibles[i]);
        cout << letra << '\t';
    }
    cout << endl;
    cout << "SOLUCIONES:" << endl;

    pair<vector<string>, int> solucion;

    char *modo_juego = argv[3];
    bool modo = false;

    if (*modo_juego == 'L') { //jugar en longitud
        modo = false;

    }
    if (*modo_juego == 'P') { //jugar en puntuacion //Errores por el getscore de letterset, no sabemos como resolverlo. Por lo tanto no podemos continuar
        modo = true;
    }
    solucion = Solver.getSolutions(letras_disponibles, modo);

    for (int i = 0; i < solucion.first.size(); ++i) {
        string palabra = solucion.first[i];
        cout << palabra << endl;

    }
    cout<<"PUNTUACION:"<<endl;
    cout<<solucion.second<<endl;
    return 0;
}
