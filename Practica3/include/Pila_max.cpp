template <class T>
Pila_max<T>::Pila_max(){

}
template <class T>
Pila_max<T>::Pila_max(const Pila_max<T> & c){
   pila = c.pila;
}
template <class T>
bool Pila_max<T>::empty_max(){
   return pila.empty();
}
template <class T>
int Pila_max<T>::size_max(){
   return pila.size();
}
template <class T>
void Pila_max<T>::pop_max(){
   pila.pop();
}
template <class T>
void Pila_max<T>::push_max(T elemento){
   Pareja<T> pareja;
   pareja.first = elemento;
   pareja.second = elemento;
   if(!pila.empty()){
      T max = maximo_max();
      if(pareja.second < max){
         pareja.second = max;
      }
   }
   pila.push(pareja);
}
template <class T>
T Pila_max<T>::top_max(){
   return pila.top().first;
}
template <class T>
T Pila_max<T>::maximo_max(){
   return pila.top().second;
}