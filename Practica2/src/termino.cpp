#include "Termino.h"
#include "Vector_Dinamico.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//Constructor por defecto
Termino :: Termino(){
   palabra = "";
   definiciones = Vector_Dinamico<string>(0);
}
//Constructor con parametros
Termino :: Termino(string nombre, const Vector_Dinamico<string> & defs){
   palabra = nombre;
   definiciones = defs;
}
//Constructor de copia
Termino :: Termino(const Termino & copia){
   palabra = copia.palabra;
   definiciones = copia.definiciones;
}
//Sobrecarga del operador =
Termino & Termino :: operator= (const Termino & copia){
   palabra = copia.palabra;
   definiciones = copia.definiciones;
   return *this;
}
//Sobrecarga del operador ==
bool Termino :: operator==(const Termino & otro) const{
    return(!(palabra.compare(otro.palabra)));
}
//Metodo para obtener la palabra
string Termino :: getPalabra() const{
   return palabra;
}
//Metodo para obtener el vector definiciones
Vector_Dinamico<string> Termino :: getDefiniciones() const{
   return definiciones;
}
//Metodo para obtener una definicion en concreto
string Termino :: getDefinicion(int indice) const{
    return definiciones[indice];
}
//Metodo para obtener el numero de definiciones
int Termino :: getNumeroDefiniciones() const{
   return definiciones.size();
}
//Metodo para cambiar la palabra
void Termino :: setPalabra(string palabra_nueva){
   palabra = palabra_nueva;
}
//Metodo para añadir definiciones
void Termino :: aniadirDefinicion(string definicion){
   definiciones.resize(definiciones.size() + 1);
   definiciones[definiciones.size() - 1] = definicion;
}
//Salida de un Termino a ostream
ostream & operator<< (ostream & out, Termino & term){
	out << "Palabra del termino: " << term.getPalabra() << endl;
	for(int i = 0; i < term.getNumeroDefiniciones(); i++){
		out << "Definicion numero " << i+1 << " : " << term.getDefinicion(i) << endl;
	}

	return out;
}
//Entrada de un Termino desde istream
istream & operator>> (istream & in, Termino & term){
	string cad;
	string def = "";
	getline(in, cad);
	istringstream iss;
	iss.str(cad);

	char c;
	c = iss.get();
	while(c != ';'){
		term.palabra += c;
		c = iss.get();
	}
	c = iss.get();
	while(!iss.eof()){
		def += c;
		c = iss.get();
	}

	term.aniadirDefinicion(def);

	return(in);
}
