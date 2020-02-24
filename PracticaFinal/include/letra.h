/**
  * @file letra.h
  * @brief Fichero cabecera del TDA Letra y ConjuntoLetras
  *
  */


#ifndef _Letra_h_
#define _Letra_h_
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Letra
  *
  * Este módulo está dedicado a la especificación e implementación del TDA Letra
  * Este TDA está formado por una terna de un caracter y dos enteros.
  *
  * Funcion de Abstracción:
  * Letra = char letra; int apariciones; int puntuacion
  *
  * Invariante de representación:
  * La letra debe de ser un elemento del alfabeto
  * La puntuación y las apariciones deben de ser iguales o mayores de 0.
  *
  *
  * @author Sergio Campos
  * @author Alejandro Manzanares
  * @date Enero 2019
  */

class Letra{
/**
 * @page repConjunto Rep de los TDA Diccionario, Letra, ConjuntoLetra y BolsaLetras
 *
 * @page faConjunto Funcion de abstraccion del Diccionario, de Letra, del ConjuntoLetra y de BolsaLetras
 *
 * Un objeto valido @e rep del TDA Letra representa el char:
 * letra -> valor alfabetico de la letra
 * Y los int:
 * apariciones -> veces que aparece esta letra
 * puntuaciones -> puntos que vale esta letra
 *
 */
	private:
		char letra; /**< letra */
		int apariciones; /**< apariciones */
		int puntuacion; /**< puntuacion */

	public:
/**
  * @brief Metodo para cambiar el valor de la variable letra
  * @paran l char nuevo valor de letra
  * @return Cambia el valor de letra
  */
		void setLetra(char l);
/**
  * @brief Metodo para cambiar el valor de la variable apariciones
  * @paran ap int nuevo valor de apariciones
  * @return Cambia el valor de apariciones
  */
		void setApariciones(int ap);
/**
  * @brief Metodo para cambiar el valor de la variable puntuacion
  * @paran p int nuevo valor de puntuacion
  * @return Cambia el valor de puntuacion
  */
		void setPuntuacion(int p);
/**
  * @brief Metodo para obtener el valor char de la Letra
  * @return Devuelve el valor char de la Letra
  */	
		char getLetra() const;
/**
  * @brief Metodo para obtener el número de apariciones de la letra
  * @return Devuelve el número de apariciones de la letra
  */	
		int getApariciones() const;
/**
  * @brief Metodo para obtener la puntuación que vale la letra
  * @return Devuelve la puntuación que vale la letra
  */	
		int getPuntuacion() const;
/**
  * @brief Salida de una Letra a ostream
  * @param os stream de salia
  * @param letra Letra a escribir
  * @post Se obtiene en \a os la representacion de la Letra
  */
		friend istream & operator>> (istream & in, Letra & letra);
/**
  * @brief Entrada de una Letra desde istream
  * @param is stream de entrada
  * @param letra Letra que recibe el valor
  * @retval La Letra leido en bletras
  * @pre La entrada tiene el formato char e int
  */
		friend ostream & operator<< (ostream & out, const Letra & letra);
};
/**
  * @brief Struct que permite la ordenacion de Letras
  */
struct compareLetra{
   bool operator() (const Letra& a, const Letra& b) const
  {return a.getLetra()<b.getLetra();}
};

/**
  *  @brief T.D.A. ConjuntoLetras
  *
  * Este módulo está dedicado a la especificación e implementación del TDA ConjuntoLetras.
  * Este TDA está formado por un conjunto de Letras.
  *
  * Funcion de Abstracción:
  * ConjuntoLetras = set<Letra, compareLetra>
  *
  * Invariante de representación:
  * Todas las Letras del diccionario
  * deben estar ordenadas por orden alfabetico.
  * No pueden haber dos Letras repetidas.
  *
  *
  * @author Sergio Campos
  * @author Alejandro Manzanares
  * @date Enero 2019
  */

class ConjuntoLetras{
/**
 * @page repConjunto Rep de los TDA Diccionario, Letra, ConjutoLetras y BolsaLetras
 *
 * @page faConjunto Funcion de abstraccion del Diccionario, de Letra, del ConjuntoLetras y de BolsaLetras
 *
 * Un objeto valido @e rep del TDA ConjuntoLetras representa el set:
 * letras -> conjunto de Letras que pertenecen al conjunto
 *
 */
	private:
		set<Letra, compareLetra> letras; /**< letras */

	public:
/**
  *  @brief Iterador de la clase
  */
		typedef set<Letra>::iterator iterator;
/**
  *  @brief Iterador constante de la clase
  */
		typedef set<Letra>::const_iterator const_iterator;
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
  * @brief Metodo para añadir una Letra al set de Letras
  * @paran l Letra a añadir
  * @return Añade al set la Letra proporcionado
  */	
		void insertar(Letra l);
/**
  * @brief Metodo para obtener el numero de Letras
  * @return Devuelve el numero de Letras
  */
		int Tamanio();
/**
  * @brief Salida de un ConjutoLetras a ostream
  * @param os stream de salia
  * @param cletra ConjuntoLetras a escribir
  * @post Se obtiene en \a os la representacion del ConjuntoLetras
  */
		friend istream & operator>> (istream & in, ConjuntoLetras & cletra);

};

#endif
