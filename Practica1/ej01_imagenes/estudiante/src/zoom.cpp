//
// Created by flo on 28/09/22.
//

#include <iostream>
#include <cstring>
#include <cstdlib>

#include <image.h>

using namespace std;

int main(int argc, char *argv[]) {

    char *origen, *destino; // nombres de los ficheros
    Image image, image2, image3;
    int nrow, ncol, lado;

    // Comprobar validez de la llamada
    if (argc != 6) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
        exit(1);
    }

    // Obtener argumentos
    origen = argv[1];
    destino = argv[2];
    nrow = atoi(argv[3]);
    ncol = atoi(argv[4]);
    lado = atoi(argv[5]);


    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;

    }

    // Calcular la subimagen
    image2 = image.Crop(nrow, ncol, lado, lado);

    //Hacer el zoom en la subimagen

    image3 = image2.Zoom2X();


    // Guardar la imagen resultado en el fichero
    if (image3.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}