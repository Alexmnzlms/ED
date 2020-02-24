/**
  * @file Cola_max_pila.h
  * @brief Fichero cabecera del TDA Cola_max en su implementacion con dos pilas
  *
*/

#ifndef COLA_MAX_VD
#define COLA_MAX_VD

#include <stack>
#include <deque>
#include "Pila_max.h"
#include "pareja.h"

using namespace std;

/**
  * @brief TDA Cola_max(pilas)
  *
  * Este modulo esra dedicado a la especificacion e implemnetacion del TDA Cola con maximo.
  * Este TDA esta formado por dos pilas de parejas de un tipo concreto
  * 
  * Pila_max<T> pila_inser;
  * 
  *
  * Pila_max<T> pila_consul;
  *
  * Un ejemplo de su uso:
  * @include "pruebacola_max.cpp"
  * @author Sergio Campos Megias
  * @author Alejandro Manzanares Lemus
  * @date Noviembre 2018
*/

template <class T>
class Cola_max{

	private:
  /**
 	* @page repConjunto Rep del TDA Cola con maximo implementacion con pilas
	 *
	 * @section faConjunto Funcion de abstraccion de la Cola con maximo (pilas)
	 *
	 * Un objeto valido @e rep del TDA Cola con maximo representa dos pilas
	 *
	 * pila_inser -> pila donde se insertan los datos
   * 
	 * pila_consul -> pila donde se consultan los datos
	 *
	 */
		Pila_max<T> pila_inser; /** pila inser*/
		Pila_max<T> pila_consul; /** pila_consul*/
	
	public:
  /**
   * @brief Constructor por defecto de la clase. Crea una cola vacia
   */
    Cola_max<T>();

	/**
	* @brief Constructor de copias de la clase
	* @param c Cola a ser copiada
 	*/ 
		Cola_max<T>(const Cola_max<T> & c);

  /**
  * @brief Metodo para comprobar si la cola esta vacia
  * @return Devuelve true si la cola esta vacia y y false en caso contrario 
  */
		bool vacia();

  /**
  * @brief Metodo para obtener el numero de elementos
  * @return Devuelve el numero de elementos
  */
		int num_elementos();

	/**
 	* @brief Metodo para eliminar una pareja
  	* @return Elimina de la cola el primer termino introducido
 	*/
		void quitar();

  /**
  * @brief Metodo para añadir una pareja a la cola
  * @paran elemento T que se va a aniadir como pareja
  * @return Aniade una pareja a la cola
  */
		void poner(T elemento);

	/**
	  * @brief Metodo que devuelve el elemento del frente
	  * @return Devuelve el elemento del frente
	  */
		T frente();

	/**
 	* @brief Metodo que devuelve el maximo de la cola
  	* @return El valor maximo de la cola
 	*/
		T maximo();

  private:
    void mover_pila(Pila_max<T> &llena, Pila_max<T> &vacia);
};

#include "Cola_max_pila.cpp"
#endif