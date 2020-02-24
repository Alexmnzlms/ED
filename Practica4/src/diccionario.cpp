#include "Diccionario.h"
#include "Termino.h"
#include <string>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <utility>

using namespace std;

//Constructor por defecto
Diccionario :: Diccionario(){
	terminos = set<Termino,compareTermino>();
}
//Constructor de la clase
Diccionario :: Diccionario(const set<Termino,compareTermino> & ter){
	terminos = ter;
}
//Constructor de copias de la clase
Diccionario :: Diccionario(const Diccionario & d){
	terminos = d.terminos;
}
//Sobrecarga del operador =
Diccionario & Diccionario :: operator=(const Diccionario& d){
	terminos = d.terminos;
	return *this;
}
//Metodo para obtener el vector definiciones de un Termino
vector<string> Diccionario :: getDefiniciones(string palabra) const{
	vector <string> devolver;
	bool encontrado = false;
	Termino correcto;
	set<Termino>::iterator i;	
	for(i = terminos.begin(); i != terminos.end() && !encontrado; i++){
		if (i->getPalabra() == palabra){
			devolver = i->getDefiniciones();
			encontrado = true;
			}
		}
	return devolver;
}

//Metodo para obtener el vector de Terminos
set<Termino,compareTermino> Diccionario :: getTerminos() const{
	return terminos;
}
//Metodo para obtener el numero de Terminos
int Diccionario :: getNumTerminos() const{
	return terminos.size();
}
//Metodo para añadir un Termino al vector de Terminos
void Diccionario :: aniadirTermino(Termino t){
	terminos.insert(t);
}
//Metodo para eliminar un Termino del vector de Terminos
void Diccionario :: eliminarTermino(string palabra){
	bool encontrado = false;
	Termino t;
	set<Termino>::iterator i;
	for(i = terminos.begin(); i != terminos.end() && !encontrado; i++){
		if (i->getPalabra() == palabra){
			t = (*i);
			encontrado = true;
		}
	}

	terminos.erase(t);
	
}
//Metodo para filtrar Terminos entre dos caracteres
Diccionario Diccionario :: filtradoIntervalo(const char caracter_inicio, const char caracter_fin){
	Diccionario intervalo = Diccionario();
	bool continuar = true;
	bool fin = false;
	set<Termino>::iterator i;
	set<Termino>::iterator j;
	for(i = terminos.begin(); i != terminos.end() && continuar; i++){
		if(i->getPalabra()[0] == caracter_inicio){
			continuar = false;
		}
	}

	for(j = i; j != terminos.end() && !fin ;j++){
 		if(j->getPalabra()[0] == caracter_fin+1){
			fin = true;
		}
		else{
			intervalo.aniadirTermino(*j);
		}
	}

	return intervalo;
		
}
//Metodo para buscar Terminos que contengan una palabra
Diccionario Diccionario :: buscarPorPalabraClave (string clave){
	Diccionario nuevo_dic;
	clave += " ";
	Diccionario::iterator it;
	Termino::const_iterator i;
	
	for(it = begin(); it != end(); ++it){
		
		for(i = (*it).begin(); i != (*it).end();++i){
				if(i->find(clave) != std::string::npos){
					Termino termino;
					termino.setPalabra(it->getPalabra());
				
					termino.aniadirDefinicion(*i);
					nuevo_dic.aniadirTermino(termino);
			}
		}
	}

	return nuevo_dic;
		
}
//Metodo para obtener el numero de definiciones total
double Diccionario :: numeroDefiniciones(){

	double total_definiciones = 0;
	Diccionario::iterator i;
	for(i = begin(); i != end(); i++){
		total_definiciones = total_definiciones + i->getNumeroDefiniciones();
	}
	return total_definiciones;
}
//Metodo para obtener el Termino que mas definiciones tiene
double Diccionario :: maximasDefPalabra(){
	double max_n_def = -1;
	Diccionario::iterator i;
	for(i = begin(); i != end(); i++){
		if(i->getNumeroDefiniciones() >= max_n_def){
			max_n_def = i->getNumeroDefiniciones();
		}
	}

	return max_n_def;
}
//Metodo para obtener el promedio de definiciones		
double Diccionario :: promedioDefPalabra(){
	return(numeroDefiniciones()/getNumTerminos());
}
//Salida de un Diccionario a ostream
ostream& operator<< (ostream & os, const Diccionario & d){
	Diccionario::const_iterator it;
	for(it = d.begin(); it != d.end(); ++it){
		os << *it;
	}
	return os;
}

//Entrada de un Diccionario desde istream
istream & operator>> (istream & in, Diccionario & dic){
	Termino term, term2;
	in >> term;
	cout << term << endl;
	
	while(!in.eof()){	
		in >> term2;
		if(term == term2){
			term.aniadirDefinicion(term2.getDefinicion(0));
		}
		else{
			dic.aniadirTermino(term);
			term = term2;
		}
		term2 = Termino();
	}
	
	dic.aniadirTermino(term);

	return(in);
}
//Metodo para obtener un iterador al comienzo del set
Diccionario::iterator Diccionario::begin(){
	return terminos.begin();
}
//Metodo para obtener un iterador al final del set
Diccionario::iterator Diccionario::end(){
	return terminos.end();
}
//Metodo para obtener un iterador constante al final del set
Diccionario::const_iterator Diccionario::end() const{
	return terminos.end();
}
//Metodo para obtener un iterador constante al comienzo del set
Diccionario::const_iterator Diccionario::begin() const{
	return terminos.begin();
}

