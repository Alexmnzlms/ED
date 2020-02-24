/*****************************************************************************/
// Nombre: colaprioridad.h
// Autor: Alejandro Manzanares Lemus 
// Curso: 2º A GII
/*
    Implementacion del TDA cola con prioridad con templates
*/
/*****************************************************************************/

#ifndef COLAPRIORIDAD
#define COLAPRIORIDAD

template <class B, class P>
struct Pareja{
   P prioridad;
   B elemento;
};

template <class B, class P>
struct CeldaColaPri{
   Pareja<B,P> dato;
   CeldaColaPri<B,P>* sig;
};

template <class B, class P>
class ColaPri{
	private:
	CeldaColaPri<B,P>* primera;

	public:
	ColaPri<B,P> (void);
	ColaPri<B,P> (const ColaPri<B, P> & copia);
	~ColaPri<B,P> (void);
	ColaPri<B,P> & operator=(const ColaPri<B, P> & copia);
	bool vacia(void) const;
	B frente(void) const;
	P prioridad_frente(void) const;
	void poner(B num, P prio);
	void quitar(void);	
};

#include "colaprioridad.tpp"

#endif
