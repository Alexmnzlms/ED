/**
  * @file Diccionario.h
  * @brief Fichero cabecera del TDA Diccionario
  *
  */

#ifndef DICCIONARIO
#define DICCIONARIO

#include <string>
#include <iostream>
#include "Vector_Dinamico.h"
#include "Termino.h"
#include <sstream>

using namespace std;

/**
  *  @brief T.D.A. Diccionario
  *
  * Este módulo está dedicado a la especificación e implementación del TDA Diccionario.
  * Este TDA está formado conjunto de terminos.
  *
  * Vector_Dinamico<Termino> terminos
  *
  * Un ejemplo de su uso:
  * @include pruebadiccionario.cpp
  *
  * @author Sergio Campos
  * @author Alejandro Manzanares
  * @date Octubre 2018
  */

class Diccionario{
private:
/**
 * @page repConjunto Rep de los TDA Diccionario y Termino
 *
 * @section faConjunto Funcion de abstraccion del Diccionario y del Termino
 *
 * Un objeto valido @e rep del TDA Diccionario representa el vector
 *
 * terminos -> conjunto de terminos que pertenecen al diccionario
 *
 */
	Vector_Dinamico<Termino> terminos; /**< terminos */
public:
/**
  * @brief Constructor por defecto de la clase. Crea un diccionario vacio
  */
	Diccionario();
/**
  * @brief Constructor de la clase
  * @param ter Termino del Diccionario a construir
  * @return Crea el Diccionario
  * @pre ter debe contener un Termino
  */
	Diccionario(const Vector_Dinamico<Termino> & ter);
/**
  * @brief Constructor de copias de la clase
  * @param d Diccionario a ser copiado
  */ 
	Diccionario(const Diccionario & d);
/**
  * @brief Sobrecarga del operador =
  * @param d Diccionario a ser asignado
  * @return Devuelve una referncia al objeto this
  */
	Diccionario & operator=(const Diccionario& d);
/**
  * @brief Metodo para obtener el vector definiciones de un Termino
  * @param palabra Termino que se desea buscar
  * @return Devuelve el vector definiciones del Termino elegido
  */
	Vector_Dinamico<string> getDefiniciones(string palabra) const;
/**
  * @brief Metodo para obtener el vector de Terminos
  * @return Devuelve el vector de Terminos
  */	
	Vector_Dinamico<Termino> getTerminos() const;
/**
  * @brief Metodo para obtener el numero de Terminos
  * @return Devuelve el numero de Terminos
  */	
	int getNumTerminos() const;
/**
  * @brief Metodo para añadir un Termino al vector de Terminos
  * @paran t Termino a añadir
  * @return Añade al vector el Termino proporcionado
  */		
	void aniadirTermino(Termino t);
/**
  * @brief Metodo para eliminar un Termino del vector de Terminos
  * @paran palabra palabra del termino a eliminar
  * @return Elimina del vector el Termino cuya palabra coincida con la del parametro
  */	
	void eliminarTermino(string palabra);
/**
  * @brief Metodo para filtrar Terminos entre dos caracteres
  * @paran caracater_inicio caracter tope inicio
  * @paran caracater_fin caracter tope fin
  * @return Devuelve un subDiccionario que contiene los Terminos hubicados entre esos caracteres
  */	
	Diccionario filtradoIntervalo(const char caracter_inicio, const char caracter_fin);
/**
  * @brief Metodo para buscar Terminos que contengan una palabra
  * @paran clave palabra a buscar
  * @return Devuelve un subDiccionario que contiene los Terminos cuyas definiciones tengan esa palabra
  */	
	Diccionario buscarPorPalabraClave (string clave);
/**
  * @brief Metodo para obtener el numero de definiciones total
  * @return Devuelve el numero de definiciones total
  */
	double numeroDefiniciones();
/**
  * @brief Metodo para obtener el Termino que mas definiciones tiene
  * @return Devuelve el cuantas definiciones tiene
  */	
	double maximasDefPalabra();
/**
  * @brief Metodo para obtener el promedio de definiciones
  * @return Devuelve el promedio de definiciones por Termino
  */	
	double promedioDefPalabra();
/**
  * @brief Salida de un Diccionario a ostream
  * @param os stream de salia
  * @param dic Diccionario a escribir
  * @post Se obtiene en \a os la representacion del Diccionario
  */	
	friend ostream & operator<< (ostream & out, const Diccionario & dic); 
/**
  * @brief Entrada de un Diccionario desde istream
  * @param is stream de entrada
  * @param dic Diccionario que recibe el valor
  * @retval El Diccionario leido en dic
  * @pre La entrada tiene el formato string
  */	
	friend istream & operator>> (istream & in, Diccionario & dic); 
};

#endif
