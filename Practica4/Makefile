
SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/pruebadiccionario\
clean

# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/pruebadiccionario: $(OBJ)/pruebadiccionario.o $(OBJ)/termino.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/pruebadiccionario $(OBJ)/pruebadiccionario.o $(OBJ)/termino.o $(OBJ)/diccionario.o 
	
$(BIN)/prueba: $(OBJ)/prueba.o $(OBJ)/termino.o 
	$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o $(OBJ)/termino.o $

$(OBJ)/pruebadiccionario.o: $(SRC)/pruebadiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/pruebadiccionario.o $(SRC)/pruebadiccionario.cpp 

$(OBJ)/prueba.o: $(SRC)/prueba.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/prueba.o $(SRC)/prueba.cpp 

$(OBJ)/termino.o: $(SRC)/termino.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/termino.o $(SRC)/termino.cpp 

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp 

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
