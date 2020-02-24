#include "Diccionario.h"
#include "Termino.h"
#include <fstream>
#include <iostream>

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
   
   Diccionario mi_diccionario;
   f >> mi_diccionario; //Cargamos en memoria el diccionario
   cout << "Diccionario Cargado" << endl;
   //Usamos un iterador para recorrer los terminos del diccionario e imprimirlos
   Diccionario::const_iterator it; 
   for(it = mi_diccionario.begin(); it != mi_diccionario.end(); ++it){
     cout << (*it) << endl;
   }
   
   cout << "----------------- Definiciones de afghan -----------------------" << endl;
   
   for( int i = 0; i < 5; i++){
   cout << mi_diccionario.getDefiniciones("afghan")[i] << endl;
	}

   cout << "<<<<<<<<<<<<<<<<<<<< Terminos comprendidos entre b y d >>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
   cout << mi_diccionario.filtradoIntervalo('b','d') << endl;

   cout << "=========================Definiciones que contienen el termino color=======================" << endl;
   cout << mi_diccionario.buscarPorPalabraClave("color")<< endl;

   cout << "++++++++++++++++++++++Numero total de definiciones, el maximo de definiciones " 
   << "asociadas a una palabra y el promedio de definiciones por palabra++++++++++++++++++++++++++++++++" << endl;

   cout << mi_diccionario.numeroDefiniciones() << ", " << mi_diccionario.maximasDefPalabra() 
   << ", " << mi_diccionario.promedioDefPalabra() << endl;
}
