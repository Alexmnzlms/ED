#ifndef VectorDinamico_h
#define VectorDinamico_h

#include <string>

template <class T>
class Vector_Dinamico{
private:

  T * datos;
  int nelementos;

public:

  Vector_Dinamico<T>(int n=0);
  Vector_Dinamico<T>(const Vector_Dinamico & original);
  ~Vector_Dinamico<T>();
  int size() const;
  void resize( int n);
  T & operator[](const int i);
  const T & operator[](const int i) const;
  Vector_Dinamico <T>& operator=(const Vector_Dinamico<T> & original);
};

#include "Vector_Dinamico.cpp"

#endif// VectorDinamico_h
