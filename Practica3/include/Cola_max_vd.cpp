
//Constructor por defecto

template <class T>
Cola_max<T>::Cola_max(){
	cola_m=Vector_Dinamico<Pareja<T>>(1);
	nelem = 0;
	anterior = 0;
	posterior = 0;
}

//Constructor de copia

template <class T>
Cola_max<T>::Cola_max(const Cola_max<T> & c){
	cola_m = c;
	
}

//Comprueba si la cola esta vacia

template <class T>
bool Cola_max<T>::vacia(){
	return (nelem == 0);
}

//Devuelve el numero de elementos de la cola

template <class T>
int Cola_max<T>::num_elementos(){
		return (nelem);
}

//Coloca un elemento al final de la cola

template <class T>
void Cola_max<T>::poner(T elemento){
	bool seguir = true;
	if (nelem == cola_m.size()){
		resize_circular(2*cola_m.size());
	}
	Pareja<T> par;
	par.first = elemento;
	par.second = elemento;
	cola_m[posterior] = par;
	nelem++;
	for (int i = posterior; i != anterior && seguir; i = (i-1)%cola_m.size()){
		if(cola_m[i].second > cola_m[(i-1)%cola_m.size()].second){
			cola_m[(i-1)%cola_m.size()].second = cola_m[i].second;
		}
		else{
			seguir = false;
		}
	}
	posterior=(posterior+1)%cola_m.size();
}

//Elimina el primer elemento de la cola

template <class T>
void Cola_max<T>::quitar(){
	anterior = (anterior+1)%cola_m.size();
	nelem--;
	if (nelem < cola_m.size()/4){
		resize_circular(cola_m.size()/2);
	}

}

//Devuelve el primer elemento de la cola

template <class T>
T Cola_max<T>::frente(){
	return cola_m[anterior].first;
}

//Devuelve el valor maximo de la cola

template <class T>
T Cola_max<T>::maximo(){
	return cola_m[anterior].second;
}

template <class T>
void Cola_max<T>::resize_circular(const int n){

	Vector_Dinamico<Pareja<T>> aux;
	aux = Vector_Dinamico<Pareja<T>>(n);
	for(int i = 0; i<nelem; i++){
		aux[i] = cola_m[(anterior+i)%cola_m.size()];
	}
	anterior = 0;
	posterior = nelem;
	cola_m = aux;
}









