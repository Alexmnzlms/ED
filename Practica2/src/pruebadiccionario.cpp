#include "Diccionario.h"
#include "Termino.h"
#include "Vector_Dinamico.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char * argv[]){

  if (argc!=2){
      cout<<"Dime el nombre del fichero con el diccionario"<<endl;
      return 0;
    }

    ifstream f (argv[1]);
    if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
    }
    

    cout << "Comienza a leer" << endl;
    Diccionario mi_diccionario;
    f>>mi_diccionario;

    cout << "Numero de terminos: " << mi_diccionario.getNumTerminos() << endl; 

    mi_diccionario.eliminarTermino("spanish");

    cout << mi_diccionario.filtradoIntervalo('s','u');

    cout << mi_diccionario.buscarPorPalabraClave("for");

    cout << "Hay " << mi_diccionario.numeroDefiniciones() << " definiciones" << endl;

    cout << "El maximo numero de definiciones es " << mi_diccionario.maximasDefPalabra() << endl;

    cout << "El promedio de definiciones por palabra es " << mi_diccionario.promedioDefPalabra() << endl;
}
