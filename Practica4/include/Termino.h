/**
  * @file Termino.h
  * @brief Fichero cabecera del TDA Termino
  *
  */

#ifndef TERMINO
#define TERMINO

#include<iostream>
#include <vector>
#include <utility>
#include <string>
#include <sstream>

using namespace std;

/**
  *  @brief T.D.A. Termino
  *
  * Este módulo está dedicado a la especificación e implementación del TDA Termino.
  * Este TDA está formado por una palabra y un conjunto de definiciones asociadas a esa palabra.
  *
  * Funcion de Abstracción:
  * Termino = pair<string,vector<string>>
  * 
  * Invariante de representación:
  * Todas las posibles definiciones de un termino deben referenciar 
  * a diferentes definiciones de una misma palabra
  *
  * Un ejemplo de su uso:
  * @include pruebadiccionario.cpp
  *
  * @author Sergio Campos
  * @author Alejandro Manzanares
  * @date Diciembre 2018
  */

class Termino{
private:
/**
  * @page repConjunto Rep de los TDA Diccionario y Termino
  *
  * Un objeto valido @e rep del TDA Termino representa:
  * Una palabra y el conjunto de todas sus posibles definiciones
  *
  */
    pair<string,vector<string> > termino; /**< termino */

public:
/**
  *  @brief Iterador de la clase
  */
    typedef vector<string>::iterator iterator;
/**
  *  @brief Iterador constante de la clase
  * 
  */
    typedef vector<string>::const_iterator const_iterator;
/**
  * @brief Constructor por defecto de la clase. Crea un Termino vacio
  */
    Termino();
/**
  * @brief Constructor de la clase
  * @param nombre palabra del Termino a construir
  * @param defs vector de definiciones del Termino a construir
  * @return Crea el Termino
  * @pre defs debe contener una definicion
  */
    Termino(string nombre, const vector<string> & defs);
/**
  * @brief Constructor de copias de la clase
  * @param copia Termino a ser copiado
  */ 
    Termino(const Termino & copia);
/**
  * @brief Sobrecarga del operador =
  * @param copia Termino a ser asignado
  * @return Devuelve una referncia al objeto this
  */
    Termino & operator= (const Termino & copia);
/**
  * @brief Sobrecarga del operador ==
  * @param otro Termino con el que se compara
  * @return Devuelve true si las palabras son iguales
  * si no devuelve false
  */  
    bool operator==(const Termino & otro) const;
/**
  * @brief Sobrecarga del operador <
  * @param otro Termino con el que se compara
  * @return Devuelve true si el primer termino 
  * se ordena antes en orden alfabetico si no
  * devuelve false
  */
    bool operator<(const Termino & otro) const;
/**
  * @brief Metodo para obtener un iterador al comienzo del vector
  * @return Devuelve un iterador que apunta al comiezo del vector
  */
    iterator begin();
/**
  * @brief Metodo para obtener un iterador constante al comienzo del vector
  * @return Devuelve un iterador constante que apunta al comiezo del vector
  */
    const_iterator begin() const;
/**
  * @brief Metodo para obtener un iterador al final del vector
  * @return Devuelve un iterador que apunta al final del vector
  */
    iterator end();
/**
  * @brief Metodo para obtener un iterador constante al final del vector
  * @return Devuelve un iterador constante que apunta al final del vector
  */
    const_iterator end() const;
/**
  * @brief Metodo para obtener la palabra
  * @return Devuelve la palabra del Termino
  */
    string getPalabra() const;
/**
  * @brief Metodo para obtener el vector definiciones
  * @return Devuelve el vector definiciones del Termino
  */
    vector<string> getDefiniciones() const;
/**
  * @brief Metodo para obtener una definicion en concreto
  * @param indice posicion numero de la definicion
  * @return Devuelve la definicion que esta en la posicion indicada
  */
    string getDefinicion(int indice) const;
/** 
  * @brief Metodo para obtener el numero de definiciones
  * @return Devuelve el numero de definiciones
  */
    int getNumeroDefiniciones() const;
/**
  *  @brief Metodo para cambiar la palabra
  * @param palabra_nueva nueva palabra del Termino
  * @return Asigna la palabra_nueva comom palabra del Termino
  */
    void setPalabra(string palabra_nueva);
/** 
  * @brief Metodo para añadir definiciones
  * @param palabra_nueva nueva palabra del Termino
  * @return Asigna la palabra_nueva comom palabra del Termino
  */
    void aniadirDefinicion(string definicion);
/**
  * @brief Salida de un Termino a ostream
  * @param os stream de salia
  * @param term Termino a escribir
  * @post Se obtiene en \a os la representacion del Termino
  */
    friend ostream & operator<< (ostream & out, const Termino & term); 
/**
  * @brief Entrada de un Termino desde istream
  * @param is stream de entrada
  * @param term Termino que recibe el valor
  * @retval El Termino leido en term
  * @pre La entrada tiene el formato string
  */
    friend istream & operator>> (istream & in, Termino & term); 
};

#endif
