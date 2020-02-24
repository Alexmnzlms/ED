#include <set>
#include <vector>
#include <utility>
#include <string>
#include <iostream>
#include <sstream>
#include "letra.h"

void Letra::setLetra(char l){
   letra = l;
}
void Letra::setApariciones(int ap){
   apariciones = ap;
}
void Letra::setPuntuacion(int p){
   puntuacion = p;
}

char Letra::getLetra() const{
   return(letra);
}
int Letra::getApariciones() const{
   return(apariciones);
}
int Letra::getPuntuacion() const{
   return(puntuacion);
}

istream & operator>> (istream & in, Letra & letra){
   char l;
   in >> l;
   int ap;
   in >> ap;
   int p;
   in >> p;
   letra.setLetra(l);
   letra.setApariciones(ap);
   letra.setPuntuacion(p);

   return(in);

}
ostream & operator<< (ostream & out, const Letra & letra){
   out << letra.getLetra() << 
   "\t" << letra.getApariciones() << 
   "\t" << letra.getPuntuacion() << endl;
   return(out);
}

void ConjuntoLetras::insertar(Letra l){
   letras.insert(l);
}

int ConjuntoLetras::Tamanio(){
   return letras.size();
}

ConjuntoLetras::iterator ConjuntoLetras::begin(){
	return letras.begin();
}

ConjuntoLetras::iterator ConjuntoLetras::end(){
	return letras.end();
}

ConjuntoLetras::const_iterator ConjuntoLetras::end() const{
	return letras.end();
}

ConjuntoLetras::const_iterator ConjuntoLetras::begin() const{
	return letras.begin();
}

istream & operator>> (istream & in, ConjuntoLetras & cletra){
   string clave;
   in >> clave;
   if(clave == "#Letra" && !in.eof()){
      in >> clave;
      in >> clave;
      Letra l;
      in >> l;
      while(!in.eof()){
         cletra.insertar(l);
         in >> l;
      }
      cletra.insertar(l);
      in >> l;
   }
   return(in);
}

ostream & operator<< (ostream & out, ConjuntoLetras & cletra){
   ConjuntoLetras::const_iterator i;
   out << "#Letra	Cantidad	Puntos" << endl;
   for(i = cletra.begin(); i != cletra.end(); ++i){
      out << *i << endl;
   }

   return(out);
}



