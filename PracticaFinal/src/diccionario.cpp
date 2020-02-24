#include <set>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <sstream>
#include "diccionario.h"

Diccionario::Diccionario(){
	
}

int Diccionario::Tamanio() const{
	return(datos.size());
}

bool Diccionario::Esta(string palabra){
	if(datos.find(palabra) == datos.end()){
		return false;
	}
	else{
		return true;
	}
}

vector<string> Diccionario::PalabrasLongitud(int longitud){
	vector<string> vec;
	set<string,comparePalabra>::iterator i;
	for(i = datos.begin();i != datos.end();i++){
		if((int)i->size() == longitud){
			vec.push_back((*i));
		}
	}

	return vec;
	
}
void Diccionario::Insertar(string palabra){
	datos.insert(palabra);
}

Diccionario::iterator Diccionario::begin(){
	return datos.begin();
}

Diccionario::iterator Diccionario::end(){
	return datos.end();
}

Diccionario::const_iterator Diccionario::end() const{
	return datos.end();
}

Diccionario::const_iterator Diccionario::begin() const{
	return datos.begin();
}

istream & operator>> (istream & in, Diccionario &d){
	string palabra;
	in >> palabra;
	
	while(!in.eof()){	
		d.Insertar(palabra);
		in >> palabra;
	}

	return(in);
}
ostream & operator<< (ostream & os, const Diccionario &d){
	
   set<string, comparePalabra>::iterator it;
   for(it = d.begin(); it != d.end(); ++it){
      os << (*it) << endl;
   }
	return os;
}

