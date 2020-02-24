#include <fstream>
#include <iostream>
#include "diccionario.h"
#include "letra.h"
#include <vector>
#include <utility>
#include <cctype>
#include <string>
#include <iomanip>

int calculofrerel(Letra l, Diccionario d){
  int apariciones = 0;
  Diccionario::const_iterator it;
  for(it = d.begin();it != d.end();it++){
    string::const_iterator i;
    string s = (*it);
		for(i = s.begin(); i != s.end();i++){
			if(l.getLetra() == toupper((*i))){
				apariciones++;
			}
		}
	}
	return apariciones;
} 

int main(int argc, char * argv[]){

  if (argc!=4){
    cout<<"Dime el nombre del fichero con el diccionario, el ficher con las letras y el fichero de salida"<<endl;
    return 0;
  }

  ifstream dic (argv[1]);
  if (!dic){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }

  ifstream let (argv[2]);
  if (!let){
    cout<<"No puedo abrir el fichero "<<argv[2]<<endl;
    return 0;
  }

  ofstream ext (argv[3]);
  if (!ext){
    cout<<"No puedo abrir el fichero "<<argv[3]<<endl;
    return 0;
  }

  Diccionario d;

  dic >> d;

  ConjuntoLetras l;

  ConjuntoLetras::const_iterator it;

  let >> l;

  int total_letras = 0;

  vector<pair<char,double>>   v; 

  for(it = l.begin(); it != l.end();it++){
	pair<char,double> p;
	p.first = ((*it).getLetra());
	p.second = calculofrerel(*it,d);
	total_letras += p.second;
	v.push_back(p);
  }

  ext << "#Letra   FAbs.    Frel." << endl;

  for(int k = 0; k < (int)v.size();k++){
	ext << v[k].first << setw (12) << v[k].second << setw (12) << v[k].second/total_letras*100 << endl;
  }
}

