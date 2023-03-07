/**
 * @file imageop.cpp
 * @brief Fichero con definiciones para el resto de métodos de la clase Image
 */

#include <iostream>
#include <cmath>
#include <image.h>

#include <cassert>

using namespace  std;

Image Image::Crop(int nrow, int ncol, int height, int width) const {
    //nrow ncol para saber de donde empezar a recortar
    Image subimagen(height,width);


    assert( height < get_rows() && width < get_cols() && height + nrow <= get_rows() && width + ncol  <= get_cols() &&
            height >0 && width >0 && ncol >=0 && nrow >=0);

    for (int i = nrow; i < height + nrow; i++) {
        for (int j = ncol; j < width + ncol; j++) {
            subimagen.set_pixel(i- nrow, j- ncol, get_pixel(i, j));
        }
    }
    return subimagen;
}



Image Image::Zoom2X() const {
    Image image_zoom;
    double media = 0;
    int a=0,k;
    image_zoom.Allocate(2 * this->get_rows() - 1, 2 * this->get_cols() - 1);

//Primero rellenamos los casos pares con los valores de la subimagen
    assert(image_zoom.get_rows() > 0 && image_zoom.get_cols() > 0);

    for (int i = 0; i <image_zoom.get_rows(); i=i+2) {
        k=0;
        for (int j = 0; j < image_zoom.get_cols(); j=j+2) {
            image_zoom.set_pixel(i, j, this->get_pixel(a, k));
            k++;
        }
        a++;
    }

    //Solo hay que tener en cuenta las posiciones impares, ya que en las posiciones pares se encuentra los datos originales de la subimagen
    //Duplicador de imagenes
//  Primero interpolación por columnas
    for (int i = 0; i < image_zoom.get_rows(); ++i) {
        for (int j = 0; j < image_zoom.get_cols(); ++j) {

            if ( j %2 != 0 ){ //QUe la columna sea impar
                media = (image_zoom.get_pixel(i,j-1)+ image_zoom.get_pixel(i,j+1)) / 2.00;
                image_zoom.set_pixel(i,j, lround(media));
            }
            if ( i%2 != 0 && i!= 0 && i != image_zoom.get_rows() -1){

                if ( j == 0 || j == image_zoom.get_cols()) {
                    media = ( image_zoom.get_pixel(i-1,j) + image_zoom.get_pixel(i+1,j)) / 2.00;
                    image_zoom.set_pixel(i,j, lround(media));
                }

            }

        }
    }
//Interpolación para las filas
    for (int i = 0; i < image_zoom.get_rows(); ++i) {
        for (int j = 0; j < image_zoom.get_cols(); ++j) {

            if( i % 2 == 0 && j % 2 != 0 ){ //Fila par y columnar impar
                media= (image_zoom.get_pixel(i,j-1) + image_zoom.get_pixel(i,j+1))/2.00;
                image_zoom.set_pixel(i,j, lround(media));
            }
            if( i %2 != 0 && j%2 != 0){ // Fila y columna impar
                media= (image_zoom.get_pixel(i-1,j-1) + image_zoom.get_pixel(i+1,j-1) + image_zoom.get_pixel(i-1,j+1) + image_zoom.get_pixel(i+1,j+1))/ 4.00;
                image_zoom.set_pixel(i,j, lround(media));
            }
            if ( i %2 !=0 && j %2 == 0){ // Fila impar y columna par
                media= (image_zoom.get_pixel(i-1,j)+ image_zoom.get_pixel(i+1,j)) / 2.00;
                image_zoom.set_pixel(i,j, lround(media));
            }


        }
    }
    return image_zoom;
}


double Image::Mean(int i, int j, int height, int width) const {
    double sumatorio=0, media=0;
    int contador=0;

    for(int k=i; k<height+i; ++k){
        for(int l=j; l<width+j; ++l){
            sumatorio+= get_pixel(k, l);
            contador++;
        }

    }
    media= (sumatorio/(contador));
    return media;
}

Image Image::Subsample(int factor) const{
    assert(this->get_rows() == this->get_cols()); //Para comprobar que es una matriz cuadrada
    assert(factor > 0 && this ->get_rows() % factor == 0); //Para comprobar que el factor es mayor que cero y que factor es múltiplo de la matriz, para poder
    //hacer una submatriz

    int icono_rows= this->get_rows()/factor;
    int icono_cols= this->get_cols()/factor;

    Image icono(icono_rows,icono_cols);


    for(int i=0; i<icono_rows; ++i){
        for(int j=0; j< icono_cols; ++j){
            icono.set_pixel(i, j, (byte)round(this->Mean(i*factor, j*factor, factor, factor)));
        }
    }




    return icono;
}


void Image::AdjustContrast (byte in1, byte in2, byte out1, byte out2){

    assert(0 <= in1 <= 255 && 0<= in2 <= 255 && 0 <= out1 <= 255 && 0<= out2 <= 255 && in2 > in1 && out2 > out1);

    double a,b,c,d,variable,valor;

    a = (double) in1;
    b= (double) in2;
    c = (double) out1;
    d = (double) out2;
    double cociente1 = c/a
    ,cociente2 = (d - c) / (b - a)
    ,cociente3= (255-d)/(255-b);

    for(int i=0; i < this->get_rows() * this->get_cols(); ++i){
        valor= (double) get_pixel(i);

        if ( valor >= 0 && valor < a){
            // maximo s1 - 0 / e1 - 0
            variable = cociente1 * valor;
            set_pixel(i,(byte) round(variable));


        }
        if ( valor >= a && valor <= b ){

            variable = out1 + (cociente2 * (valor - in1));
            set_pixel(i,(byte)round(variable));

        }
        if (valor > b && valor <= 255){

            variable = out2 + (cociente3 * ( valor - in2));
            set_pixel(i,(byte)round(variable));
        }


    }
}
/*
void Image::ShuffleRows() {
    const int p = 9973;
    Image temp(rows,cols);
    int newr;
    for (int r=0; r<rows; r++){
        newr = r*p % rows;
        for (int c=0; c<cols;c++)
            temp.set_pixel(r,c,get_pixel(newr,c));
    }
    Copy(temp);
} */
void Image::ShuffleRows() {
        const int p = 9973;
        byte **aux;
        aux= new byte [rows*cols];

        Image temp(rows,cols);

        int newr, c=0;
        for (int r=0; r<(rows * cols); ++r){
           newr = (r * p) % rows;
        }
        for( int i=0; i< (rows* cols); ++i){
            aux[i] = newr[i];
        }
        Copy(temp);
    }
