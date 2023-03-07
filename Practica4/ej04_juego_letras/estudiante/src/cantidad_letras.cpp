
#include <iostream>
#include <dictionary.h>
#include <letters_set.h>
#include <fstream>

using namespace  std;
int main(int argc, const char * argv[]){

    if ( argc != 3){
        cout<<"Errorr, debe de pasarse 2 parámetros, el primero sería un fichero diccionario y el segundo un fichero de letras "<<endl;
        return -1;
    }

    ifstream f_diccionario(argv[1]);

    if(!f_diccionario){
        cout << "No puedo abrir el fichero" << argv[1] << endl;
        return -1;
    }

    Dictionary diccionario;
    f_diccionario >> diccionario;

    LettersSet letras;
    ifstream archivo_letras;
    archivo_letras.open(argv[2]);

    if( archivo_letras ){
        archivo_letras >> letras;
    }




    cout<< "Letra\tUsos\tOcurrencias"<<endl;
    Dictionary::iterator ite = diccionario.begin();
    map<char,LetterInfo>::iterator  it = letras.begin();
    for( it; it != letras.end(); ++it){
        char letra_actual = toupper(it->first);

        int total_ocurrencias = diccionario.getOccurrences(it->first);
        int usos = diccionario.getTotalUsages(it->first);
        cout << letra_actual << '\t' << usos << '\t' << total_ocurrencias <<endl;

    }
    return 0;


}

