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
    Image image, image2;
    int nrow, ncol, height, width;

    // Comprobar validez de la llamada
    if (argc != 7) {
        cerr << "Error: Numero incorrecto de parametros.\n";
        cerr << "Uso: negativo <FichImagenOriginal> <FichImagenDestino>\n";
        exit(1);
    }

    // Obtener argumentos
    origen = argv[1];
    destino = argv[2];
    nrow = atoi(argv[3]);
    ncol = atoi(argv[4]);
    height = atoi(argv[5]);
    width = atoi(argv[6]);

    // Leer la imagen del fichero de entrada
    if (!image.Load(origen)) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;

    }

    // Calcular la subimagen
    image2 = image.Crop(nrow, ncol, height, width);

    // Guardar la imagen resultado en el fichero
    if (image2.Save(destino))
        cout << "La imagen se guardo en " << destino << endl;
    else {
        cerr << "Error: No pudo guardarse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        return 1;
    }

    return 0;
}