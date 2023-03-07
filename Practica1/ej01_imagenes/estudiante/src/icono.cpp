//
// Created by flo on 4/10/22.
//
#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]) {
    char *origen,*destino;
    int factor;
    Image image, image2;

    if (argc != 4) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
        exit(1);
    }
    origen = argv[1];
    destino = argv[2];
    factor = atoi(argv[3]);

    if (!image.Load(origen)) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;

    }

    image2= image.Subsample(factor);

    if (image2.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }



}