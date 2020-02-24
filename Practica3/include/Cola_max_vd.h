/**
  * @file Cola_max_vd.h
  * @brief 	Fichero cabecera del TDA Cola_max en su implementacion con un vector dinamico
  *
*/


#ifndef COLA_MAX_VD
#define COLA_MAX_VD

#include <iostream>
#include <cassert>
#include "Vector_Dinamico.h"
#include "pareja.h"

using namespace std;

/**
  * @brief TDA Cola_max(vectores)
  *
  * Este modulo esra dedicado a la especificacion e implemnetacion del TDA Cola con maximo.
  * Este TDA esta formado por un vector de parejas de un tipo concreto
  * 
	* cola_m;
	*
	*
	* nelem;
	*
	*
	* anterior;
	*
	*
	* posterior;
	*
	*
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
 	* @page repConjunto Rep del TDA Cola con maximo con la implementacion de vectores
	 *
	 * @section faConjunto Funcion de abstraccion de la Cola con maximo (vectores)
	 *
	 * Un objeto valido @e rep del TDA Cola con maximo representa el vector
	 *
	 * cola_m -> cola de parejas
	 * 
	 * nelem -> numero de elementos de la cola
	 * 
	 * anterior -> posicion del primer elemento
	 * 
	 * posterior -> posicion del ultimo elemento
	 *
	 */
		Vector_Dinamico<Pareja<T>> cola_m; /**< cola_m */
		int nelem; /**< nelem */
		int anterior; /**< anterior */
		int posterior; /**< posterior */
	
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
		void resize_circular(const int n);
		
};

#include "Cola_max_vd.cpp"
	
#endif
	
