/*****************************************************************************/
// Nombre: colaprioridad.tpp
// Autor: Alejandro Manzanares Lemus 
// Curso: 2º A GII
/*
    Implementacion del TDA cola con prioridad con templates
*/
/*****************************************************************************/

#include <cassert>

template <class B, class P>
ColaPri<B, P> :: ColaPri(void){
   primera = 0;
}

template <class B, class P>
ColaPri<B, P> :: ColaPri(const ColaPri<B, P> & copia){
	if(copia.primera == 0){
		primera = 0;
	}
	else{
		primera = new CeldaColaPri<B,P>;	
		primera->dato = copia.primera->dato;
		CeldaColaPri<B,P>* src = copia.primera;
		CeldaColaPri<B,P>* dest = primera;
		while(src->sig != 0){
			dest->sig = new CeldaColaPri<B,P>;
			src = src->sig;
			dest = dest->sig;
			dest->dato = src->dato;
		}
		dest->sig = 0;
	}
}

template <class B, class P>
ColaPri<B, P> :: ~ColaPri(void){
	CeldaColaPri<B,P>* aux;
	while(primera != 0){
		aux = primera;
		primera = primera->sig;
		delete aux;
	}
}

template <class B, class P>
ColaPri<B, P> & ColaPri<B, P> :: operator= (const ColaPri<B, P> & copia) {
	ColaPri colatemp(copia);
	CeldaColaPri<B,P>* aux;
	aux = primera;
	primera = colatemp.primera;
	colatemp.primera = aux;
	return *this;
}

template <class B, class P>
bool ColaPri<B, P> :: vacia(void) const {
	return (primera == 0);
}

template <class B, class P>
B ColaPri<B, P> :: frente(void) const {
	assert(primera != 0);
	return (primera->dato.elemento);
}

template <class B, class P>
P ColaPri<B, P> :: prioridad_frente(void) const {
	assert(primera != 0);
	return (primera->dato.prioridad);
}

template <class B, class P>
void ColaPri<B, P> :: poner (B num, P prio) {
	CeldaColaPri<B,P>* aux = new CeldaColaPri<B,P>; 
	aux->dato.elemento = num;
	aux->dato.prioridad = prio;
	aux->sig = 0;
	if (primera==0)
		primera = aux;

	else if(primera->dato.prioridad < prio){ 
		aux->sig = primera;
		primera = aux;
	}

	else{
		CeldaColaPri<B,P>* p = primera;
		while(p->sig!=0){
			if(p->sig->dato.prioridad < prio){
				aux->sig = p->sig;
				p->sig = aux;
				return;
			}
			else p = p->sig;
		}
		p->sig = aux;
	}
}

template <class B, class P>
void ColaPri<B, P> :: quitar (void){
	assert(primera!=0);
	CeldaColaPri<B,P>* aux = primera;
	primera = primera->sig;
	delete aux;
}