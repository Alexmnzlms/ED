/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef _Diccionario_h_
#define _Diccionario_h_
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

/**
  * @brief Struct que permite la ordenacion de strings
  */
struct comparePalabra{
   bool operator() (const string& s1, const string& s2) const
  {return s1<s2;}
};

/**
  *  @brief T.D.A. Diccionario
  *
  * Este módulo está dedicado a la especificación e implementación del TDA Diccionario.
  * Este TDA está formado conjunto de strings.
  *
  * Funcion de Abstracción:
  * Diccionario = set<string,comparePalabra>
  *
  * Invariante de representación:
  * Todas las palabras del diccionario
  * deben estar ordenadas por orden alfabetico.
  * No pueden haber dos palabras repetidas.
  *
  * Un ejemplo de su uso:
  * @include testdiccionario.cpp
  *
  * @author Sergio Campos
  * @author Alejandro Manzanares
  * @date Enero 2019
  */


class Diccionario{
private:
/**
 * @page repConjunto Rep de los TDA Diccionario, Letra y BolsaLetras
 *
 * @page faConjunto Funcion de abstraccion del Diccionario, de Letra y de BolsaLetras
 *
 * Un objeto valido @e rep del TDA Diccionario representa el set:
 * datos -> conjunto de palabras que pertenecen al diccionario
 *
 */
		set<string,comparePalabra> datos; /**< datos */
	public:
/**
  *  @brief Iterador de la clase
  */
		typedef set<string,comparePalabra>::iterator iterator;
/**
  *  @brief Iterador constante de la clase
  */
		typedef set<string,comparePalabra>::const_iterator const_iterator;
/**
  * @brief Metodo para obtener un iterador al comienzo del set
  * @return Devuelve un iterador que apunta al comiezo del set
  */
		iterator begin();
/**
  * @brief Metodo para obtener un iterador al final del set
  * @return Devuelve un iterador que apunta al final del set
  */
		iterator end();
/**
  * @brief Metodo para obtener un iterador constante al comienzo del set
  * @return Devuelve un iterador constante que apunta al comiezo del set
  */
		const_iterator begin() const;
/**
  * @brief Metodo para obtener un iterador constante al final del set
  * @return Devuelve un iterador constante que apunta al final del set
  */
		const_iterator end() const;
/**
  * @brief Constructor por defecto de la clase. Crea un diccionario vacio
  */
		Diccionario();
/**
  * @brief Metodo para obtener el numero de palabras
  * @return Devuelve el numero de palabras
  */	
		int Tamanio() const;
/**
  * @brief Metodo para obtener un vector con todas las palabras de una determinada longitud
  * @param longitud int de las palabras que se desean buscar
  * @return Devuelve el vector con las palabras de la longitud elegida
  */
		vector<string> PalabrasLongitud(int longitud);
/**
  * @brief Metodo para comprobar si una palabra ya se encuentra en el set
  * @param palabra string que se desea buscar
  * @return Devuelve true si la palabra se encuentra en el set de datos y false si no es así
  */
		bool Esta(string palabra);
/**
  * @brief Metodo para añadir una palabra al set de palabras
  * @paran palabra string a añadir
  * @return Añade al set la palabra proporcionado
  */	
		void Insertar(string palabra);
/**
  * @brief Salida de un Diccionario a ostream
  * @param os stream de salia
  * @param dic Diccionario a escribir
  * @post Se obtiene en \a os la representacion del Diccionario
  */
		friend istream & operator >>(istream & is, Diccionario &D);
/**
  * @brief Entrada de un Diccionario desde istream
  * @param is stream de entrada
  * @param dic Diccionario que recibe el valor
  * @retval El Diccionario leido en dic
  * @pre La entrada tiene el formato string
  */	
		friend ostream & operator <<(ostream & os,const Diccionario &D);
};

#endif
		
