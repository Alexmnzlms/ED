/**
  * @file pila_max_pila.h
  * @brief Fichero cabecera del TDA Pila_max
  *
*/
#ifndef PILA_MAX
#define PILA_MAX

#include <stack>
#include <deque>
#include "pareja.h"

using namespace std;

/**
  * @brief TDA Pila_max
  *
  * Este modulo esra dedicado a la especificacion e implemnetacion del TDA Pila con maximo.
  * Este TDA esta formado por una pila de un tipo concreto
  * 
  * stack<Pareja<T>> pila;
  *
  * Un ejemplo de su uso:
  * @include "pruebapila_max.cpp"
  * @author Sergio Campos Megias
  * @author Alejandro Manzanares Lemus
  * @date Noviembre 2018
*/

template <class T>
class Pila_max{

	private:
	  /**
 	* @page repConjunto Rep del TDA Pila con maximo
	 *
	 * @section faConjunto Funcion de abstraccion de la Pila con maximo
	 *
	 * Un objeto valido @e rep del TDA Pila con maximo representa una pila
	 *
	 * pila -> pila donde se insertan los datos
	 *
	 */
		stack<Pareja<T>> pila; /**pila*/
	
	public:
	/**
   * @brief Constructor por defecto de la clase. Crea una pila vacia
   */
      Pila_max<T>();
	/**
	* @brief Constructor de copias de la clase
	* @param c Pila a ser copiada
 	*/ 
		Pila_max<T>(const Pila_max<T> & c);
  /**
  * @brief Metodo para comprobar si la pila esta vacia
  * @return Devuelve true si la pil esta vacia y y false en caso contrario 
  */
		bool empty_max();
  /**
  * @brief Metodo para obtener el numero de elementos
  * @return Devuelve el numero de elementos
  */
		int size_max();

	/**
 	* @brief Metodo para eliminar una pareja
  	* @return Elimina de la pila el primer termino introducido
 	*/
		void pop_max();
  /**
  * @brief Metodo para añadir una pareja a la pila
  * @paran elemento T que se va a aniadir como pareja
  * @return Aniade una pareja a la pila
  */
		void push_max(T elemento);
	/**
	  * @brief Metodo que devuelve el elemento del frente
	  * @return Devuelve el elemento del frente
	  */
		T top_max();
	/**
 	* @brief Metodo que devuelve el maximo de la pila
  	* @return El valor maximo de la pila
 	*/
		T maximo_max();
};

#include "Pila_max.cpp"
#endif