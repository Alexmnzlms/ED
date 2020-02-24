template <class T>
Cola_max<T>::Cola_max(){

}
template <class T>
Cola_max<T>::Cola_max(const Cola_max<T> & c){
   pila_inser = c.pila_inser;
	pila_consul = c.pila_consul;
}
template <class T>
bool Cola_max<T>::vacia(){
	mover_pila(pila_consul, pila_inser);
	return (pila_inser.empty_max());
}
template <class T>
int Cola_max<T>::num_elementos(){
	mover_pila(pila_consul, pila_inser);
	return pila_inser.size_max();
}
template <class T>
void Cola_max<T>::poner(T elemento){
	mover_pila(pila_consul, pila_inser);
	pila_inser.push_max(elemento);
}
template <class T>
void Cola_max<T>::quitar(){
	mover_pila(pila_inser, pila_consul);
	pila_consul.pop_max();
}
template <class T>
T Cola_max<T>::frente(){
	mover_pila(pila_inser, pila_consul);
	T t = pila_consul.top_max();
	return t;
}
template <class T>
T Cola_max<T>::maximo(){
	mover_pila(pila_inser, pila_consul);
	T m = pila_consul.maximo_max();
  	return m;
}
template <class T>
void Cola_max<T>::mover_pila(Pila_max<T> &llena, Pila_max<T> &vacia){
	int tamanio_llena = llena.size_max();
	for(int i = 0; i < tamanio_llena; i++){
		vacia.push_max(llena.top_max());
		llena.pop_max();
	}
}