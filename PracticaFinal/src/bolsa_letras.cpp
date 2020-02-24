#include <chrono>
#include <random>
#include <algorithm>
#include "bolsa_letras.h"

int BolsaLetras::Tamanio(){
	return letras.size();
}
void BolsaLetras::Rellenar(ConjuntoLetras & cl){	
	int l;
	
	ConjuntoLetras::iterator c;
	for(c = cl.begin(); c!= cl.end(); ++c){
		for(l = 0; l < c->getApariciones(); l++){
			letras.push_back(c->getLetra());
		} 
	}
	unsigned semilla = chrono::system_clock::now().time_since_epoch().count();
	shuffle(letras.begin(), letras.end(), default_random_engine(semilla));
}
vector<char> BolsaLetras::Cogerletras(int n){
	vector<char> bolsa;
	BolsaLetras::iterator l = letras.begin();
	for(int i = 0; i < n; i++){
		bolsa.push_back(*l);
		letras.erase(l);
	}

	return bolsa;
}
BolsaLetras::iterator BolsaLetras::begin(){
	return letras.begin();
}

BolsaLetras::iterator BolsaLetras::end(){
	return letras.end();
}

BolsaLetras::const_iterator BolsaLetras::end() const{
	return letras.end();
}

BolsaLetras::const_iterator BolsaLetras::begin() const{
	return letras.begin();
}
istream & operator>> (istream & in, BolsaLetras & bletras){
	vector<char> v;
	for(int i = 0;i < bletras.Tamanio();i++){
		
	}

	return (in);
}
ostream & operator<< (ostream & out, BolsaLetras & bletras){
	BolsaLetras::iterator i;

	for(i = bletras.begin(); i != bletras.end(); ++i){
		out << *i << " ";
	}

	return(out);
}
