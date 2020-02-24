#include "Termino.h"
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//Constructor por defecto
Termino :: Termino(){
   termino = pair<string,vector<string> >();
}
//Constructor con parametros
Termino :: Termino(string nombre, const vector<string> & defs){
   termino.first = nombre;
   termino.second = defs;
}
//Constructor de copia
Termino :: Termino(const Termino & copia){
   termino.first = copia.termino.first;
   termino.second = copia.termino.second;
}
//Sobrecarga del operador =
Termino & Termino :: operator= (const Termino & copia){
   termino.first = copia.termino.first;
   termino.second = copia.termino.second;
   return *this;
}
//Sobrecarga del operador ==
bool Termino :: operator==(const Termino & otro) const{
    return(!(termino.first.compare(otro.termino.first)));
}
//Sobrecarga del operador <
bool Termino :: operator<(const Termino & otro) const{
   return termino.first < otro.termino.first;
}
//Metodo para obtener un iterador al comienzo del vector
Termino::iterator Termino::begin(){
   Termino::iterator it;
   it = termino.second.begin();
   return it;
}
//Metodo para obtener un iterador al final del vector
Termino::iterator Termino::end(){
   Termino::iterator it;
   it = termino.second.end();
   return it;
}
//Metodo para obtener un iterador constante al comienzo del vector
Termino::const_iterator Termino::begin() const{
   Termino::const_iterator it;
   it = termino.second.begin();
   return it;
}
//Metodo para obtener un iterador constante al final del vector
Termino::const_iterator Termino::end() const{
   Termino::const_iterator it;
   it = termino.second.end();
   return it;
}
//Metodo para obtener la palabra
string Termino :: getPalabra() const{
   return termino.first;
}
//Metodo para obtener el vector definiciones
vector<string> Termino :: getDefiniciones() const{
   return termino.second;
}
//Metodo para obtener una definicion en concreto
string Termino :: getDefinicion(int indice) const{
    return termino.second[indice];
}
//Metodo para obtener el numero de definiciones
int Termino :: getNumeroDefiniciones() const{
   return termino.second.size();
}
//Metodo para cambiar la palabra
void Termino :: setPalabra(string palabra_nueva){
   termino.first = palabra_nueva;
}
//Metodo para añadir definiciones
void Termino :: aniadirDefinicion(string definicion){
   termino.second.push_back(definicion);
}
//Salida de un Termino a ostream
ostream& operator<< (ostream & os, const Termino & t){
   Termino::const_iterator it;
   for(it = t.begin(); it != t.end(); ++it){
      os << t.getPalabra() << "-->" << (*it) << endl;
   }
   return os;
}
//Entrada de un Termino desde istream
istream & operator>> (istream & in, Termino & term){
	string cad;
	string def = "";
   string palabra = "";
	getline(in, cad);
	istringstream iss;
	iss.str(cad);

	char c;
	c = iss.get();
	while(c != ';'){
		palabra += c;
		c = iss.get();
	}
   term.setPalabra(palabra);
	c = iss.get();
	while(!iss.eof()){
		def += c;
		c = iss.get();
	}

	term.aniadirDefinicion(def);
	return(in);
}
