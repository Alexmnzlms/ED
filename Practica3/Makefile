SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -std=c++11
INCLUDES = $(INC)/Cola_max.h  $(INC)/Cola_max_pila.h $(INC)/Pila_max.h $(INC)/Cola_max_vd.h $(INC)/Vector_Dinamico.h $(INC)/pareja.h


all: $(BIN)/pruebacola_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebacola_max: $(SRC)/pruebacola_max.cpp $(INLCUDES)
	$(CXX) -o $@ $< $(CPPFLAGS)

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
