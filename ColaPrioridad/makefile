#Autor: ALEJANDRO MANZANARES LEMUS
#Curso: 2º A GII

all: cabecera\
democolaprioridad\
clean

cabecera :
	@echo "\n"
	@echo "---------------------------------------------------------------------"
	@echo "		Implementación clase Cola con prioridad"
	@echo "		Autor: Alejandro Manzanares Lemus"
	@echo "		2º A GII"
	@echo "---------------------------------------------------------------------"
	@echo "\n"

democolaprioridad: ./democolaprioridad.o
	g++ -o democolaprioridad  ./democolaprioridad.o -std=c++11 -I.

democolaprioridad.o: ./democolaprioridad.cpp ./colaprioridad.h
	g++ -c -Wall -g -o democolaprioridad.o ./democolaprioridad.cpp -I. -std=c++11

ejecutar:
	./democolaprioridad

clean:
	@-rm ./*.o
	@echo "\n"
	@echo "Objetos eliminados"