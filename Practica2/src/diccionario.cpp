#include "Diccionario.h"
#include "Termino.h"
#include "Vector_Dinamico.h"
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

//Constructor por defecto
Diccionario :: Diccionario(){
	terminos = Vector_Dinamico<Termino>();
}
//Constructor de la clase
Diccionario :: Diccionario(const Vector_Dinamico<Termino> & ter){
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
Vector_Dinamico<string> Diccionario :: getDefiniciones(string palabra) const{
	bool encontrado = false;
	Termino correcto;	
	for(int i = 0; i < terminos.size() && !encontrado; i++){
		if (!(terminos[i].getPalabra().compare(palabra))){
			correcto = terminos[i];
			encontrado = true;
		}
	}
	return correcto.getDefiniciones();
}
//Metodo para obtener el vector de Terminos
Vector_Dinamico<Termino> Diccionario :: getTerminos() const{
	return terminos;
}
//Metodo para obtener el numero de Terminos
int Diccionario :: getNumTerminos() const{
	return terminos.size();
}
//Metodo para añadir un Termino al vector de Terminos
void Diccionario :: aniadirTermino(Termino t){
	terminos.resize(terminos.size()+1);
	terminos[terminos.size()-1] = t;
}
//Metodo para eliminar un Termino del vector de Terminos
void Diccionario :: eliminarTermino(string palabra){
	bool encontrado = false;
	for(int i = 0; i < terminos.size() && !encontrado; i++){
		if (!(terminos[i].getPalabra().compare(palabra))){
			for(int j = i; j < terminos.size() -1; j++){
				terminos[j] = terminos[j+1];
			}
		}
	}

	terminos.resize(terminos.size()-1);
	
}
//Metodo para filtrar Terminos entre dos caracteres
Diccionario Diccionario :: filtradoIntervalo(const char caracter_inicio, const char caracter_fin){
	Diccionario intervalo = Diccionario(0);
	bool continuar = true;
	bool fin = false;
	int i;
	for(i = 0; i < terminos.size() && continuar; i++){
		if(terminos[i].getPalabra()[0] == caracter_inicio){
			continuar = false;
		}
	}

	for(int j = i; j < terminos.size() && !fin ;j++){
 		if(terminos[j].getPalabra()[0] == caracter_fin+1){
			fin = true;
		}
		else{
			intervalo.aniadirTermino(terminos[j]);
		}
	}

	return intervalo;
		
}
//Metodo para buscar Terminos que contengan una palabra
Diccionario Diccionario :: buscarPorPalabraClave (string clave){
	string cad;
	bool sigue,aniadir_termino;
	Diccionario subconjunto = Diccionario();
	for(int i = 0; i < terminos.size();i++){
		aniadir_termino=false;
		Vector_Dinamico<string> las_definiciones;
		for(int j = 0; j < terminos[i].getNumeroDefiniciones(); j++){
			istringstream iss;
			iss.str(terminos[i].getDefiniciones()[j]);
			sigue = true;
			iss >> cad;
			while(!iss.eof() && sigue){			
				if(!(clave.compare(cad))){
					sigue=false;
					aniadir_termino=true;
					las_definiciones.resize(las_definiciones.size()+1);
					las_definiciones[las_definiciones.size()-1]=terminos[i].getDefiniciones()[j];
				}
				iss >> cad;
			}	
		}
		if(aniadir_termino){
			Termino t(terminos[i].getPalabra(),las_definiciones);
			subconjunto.aniadirTermino(t);
		}
	}
	return subconjunto;
}
//Metodo para obtener el numero de definiciones total
double Diccionario :: numeroDefiniciones(){

	double total_definiciones = 0;
	for(int i = 0; i < terminos.size(); i++){
		total_definiciones = total_definiciones + terminos[i].getNumeroDefiniciones();
	}
	return total_definiciones;
}
//Metodo para obtener el Termino que mas definiciones tiene
double Diccionario :: maximasDefPalabra(){
	double max_n_def = -1;
	for(int i = 0; i < terminos.size(); i++){
		if(terminos[i].getNumeroDefiniciones() >= max_n_def){
			max_n_def = terminos[i].getNumeroDefiniciones();
		}
	}

	return max_n_def;
}
//Metodo para obtener el promedio de definiciones		
double Diccionario :: promedioDefPalabra(){
	return(numeroDefiniciones()/getNumTerminos());
}
//Salida de un Diccionario a ostream
ostream & operator<< (ostream & out, const Diccionario & dic){
	for(int i = 0; i < dic.getNumTerminos(); i++){
		out << "Termino " << i+1 << " : " << dic.getTerminos()[i] << endl;
	}

	return out;
}
//Entrada de un Diccionario desde istream
istream & operator>> (istream & in, Diccionario & dic){
	Termino term, term2;
	in >> term;
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

















	
