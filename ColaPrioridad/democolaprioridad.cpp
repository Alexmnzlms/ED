/*****************************************************************************/
// Nombre: democolaprioridad.cpp
// Autor: Alejandro Manzanares Lemus 
// Curso: 2º A GII
/*
    Demostracion del TDA cola con prioridad con templates
*/
/*****************************************************************************/

#include <iostream>
#include "colaprioridad.h"

using namespace std;

template<class B, class P>
void ImprimirCola(const ColaPri<B,P>& colapri){
    int cont = 0;
    ColaPri<B,P> colaux(colapri);
    while(!colaux.vacia()){
        cout << "Elmento numero: " << cont + 1 << endl;
        cout << "Valor: " << colaux.frente() << endl;
        cout << "Prioridad: " << colaux.prioridad_frente() << endl;
        colaux.quitar();
        cont++;
    }
    cout << "Numero de elementos: " << cont << endl;
}

int main(void){
    ColaPri<int, int> cola;
    for(int i = 0; i < 10; i++){
        cola.poner(i,i);
    }
    cout << "Imprimiendo cola" << endl;
    ImprimirCola(cola);

    ColaPri<int, int> cola2;
    cola2 = cola;
    cout << endl;
    cout << "---------------------------" << endl;
    cout << "Imprimiendo cola2" << endl;
    ImprimirCola(cola2);

    return 0;
}