//
// Created by flo on 4/10/22.
//
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <ctime>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]) {
    char *origen,*destino;
    clock_t ini;
    clock_t fin;
    Image image;
    ofstream archivo("fichero1.dat");
    ofstream archivo_media("fichero_media.dat");
    double media=0;



    if (argc != 3) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
        exit(1);
    }
    origen = argv[1];
    destino = argv[2];



    if (!image.Load(origen)) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;

    }

    for(int i=0; i< 50; ++i){
        ini=clock();
        image.ShuffleRows();
        fin=clock();
        media+=(fin-ini)/(double)CLOCKS_PER_SEC;
        archivo << media<<endl;
    }


    media=media/50;
    archivo_media << media;



    if (image.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }






}