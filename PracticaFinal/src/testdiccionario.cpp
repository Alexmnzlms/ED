#include <fstream>
#include <iostream>
#include <set>
#include <vector>
#include "diccionario.h"

using namespace std;

int main(int argc, char *argv[]){

  if (argc!=2){
      cout << "Dime el nombre del fichero con el diccionario" << endl;
      return 0;
   }

   ifstream f (argv[1]);
   if (!f){
    cout<<"No puedo abrir el fichero "<< argv[1] <<endl;
    return 0;
   }
   
   Diccionario D;
   f >> D; //Cargamos en memoria el diccionario
   cout << "Diccionario Cargado" << endl;
   cout << D << endl;
   
   int longitud;

   cout << "Dime la longitud de las palabras que quieres ver" << endl;

   cin >> longitud;

   vector<string> v;

   v = D.PalabrasLongitud(longitud);

   cout<<"Palabras de longitud "<<longitud<<endl;

   for (unsigned int i=0;i<v.size();i++){
      cout<<v[i]<<endl;
   }

   string p;

   cout << "Dime una palabra" << endl;

   cin >> p;

   if(D.Esta(p)) 
	   cout<<"Esa palabra existe" << endl;
   else
      cout<<"Esa palabra no existe" << endl;
}
















