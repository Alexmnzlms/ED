/**
  * @file bolsa_letras.h
  * @brief Fichero cabecera del TDA BolsaLetras
  *
  */

#ifndef _BolsaLetras_h_
#define _BolsaLetras_h_
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <random>
#include <algorithm>
#include "letra.h"

using namespace std;

/**
  *  @brief T.D.A. BolsaLetras
  *
  * Este módulo está dedicado a la especificación e implementación del TDA BolsaLetras.
  * Este TDA está formado por un conjunto de caracteres.
  *
  * Funcion de Abstracción:
  * BolsaLetras = vector<char>
  *
  * Invariante de representación:
  * Todas las letras del vector
  * estan ordenadas de forma aleatoria.
  *
  *
  * @author Sergio Campos
  * @author Alejandro Manzanares
  * @date Enero 2019
  */


class BolsaLetras{
/**
 * @page repConjunto Rep de los TDA Diccionario, Letra, ConjuntoLetras y BolsaLetras
 *
 * @page faConjunto Funcion de abstraccion del Diccionario, de Letra, del ConjuntoLetras y de BolsaLetras
 *
 * Un objeto valido @e rep del TDA BolsaLetras representa el vector:
 * letras -> conjunto de letras que pertenecen a la bolsa
 *
 */
	private:
		vector<char> letras; /**< letras */
	
	public:
/**
  *  @brief Iterador de la clase
  */
		typedef vector<char>::iterator iterator;
/**
  *  @brief Iterador constante de la clase
  */
		typedef vector<char>::const_iterator const_iterator;
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
  * @brief Metodo para obtener el numero de letras
  * @return Devuelve el numero de letras
  */
		int Tamanio();
/**
  * @brief Metodo para añadir un conjunto de letras al vector de letras
  * @paran cl ConjuntoLetras a añadir
  * @return Añade al vector las letras del conjunto que se le pasa como argumento
  */	
		void Rellenar(ConjuntoLetras & cl);
/**
  * @brief Metodo para extraer un determinado número de letras del vector y devolverlas
  * @paran n int número de letras a extraer
  * @return Un vector con las letras extraidas
  */
		vector<char> Cogerletras(int n);
/**
  * @brief Salida de una BolsaLetras a ostream
  * @param os stream de salia
  * @param bletras BolsaLetras a escribir
  * @post Se obtiene en \a os la representacion de la BolsaLetras
  */
		friend istream & operator>> (istream & in, BolsaLetras & bletras);
/**
  * @brief Entrada de una BolsaLetras desde istream
  * @param is stream de entrada
  * @param bletras BolsaLetras que recibe el valor
  * @retval La BolsaLetras leido en bletras
  * @pre La entrada tiene el formato char
  */	
		friend ostream & operator<< (ostream & out, BolsaLetras & bletras); 
};


#endif
