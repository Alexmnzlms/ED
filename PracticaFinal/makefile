SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++ -std=c++11
CPPFLAGS = -Wall -g  -I$(INC) -c


all: $(BIN)/cantidad_letras\
$(BIN)/letras\
$(BIN)/testdiccionario\
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/cantidad_letras: $(OBJ)/cantidad_letras.o $(OBJ)/letra.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/cantidad_letras $(OBJ)/cantidad_letras.o $(OBJ)/letra.o $(OBJ)/diccionario.o

$(OBJ)/cantidad_letras.o: $(SRC)/cantidad_letras.cpp 
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/cantidad_letras.o $(SRC)/cantidad_letras.cpp

$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/letra.o $(OBJ)/diccionario.o $(OBJ)/bolsa_letras.o
	$(CXX) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/letra.o $(OBJ)/diccionario.o $(OBJ)/bolsa_letras.o

$(OBJ)/letras.o: $(SRC)/letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letras.o $(SRC)/letras.cpp

$(BIN)/testdiccionario: $(OBJ)/testdiccionario.o $(OBJ)/letra.o $(OBJ)/diccionario.o
	$(CXX) -o $(BIN)/testdiccionario $(OBJ)/testdiccionario.o $(OBJ)/letra.o $(OBJ)/diccionario.o

$(OBJ)/testdiccionario.o: $(SRC)/testdiccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/testdiccionario.o $(SRC)/testdiccionario.cpp

$(OBJ)/letra.o: $(SRC)/letra.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/letra.o $(SRC)/letra.cpp

$(OBJ)/bolsa_letras.o: $(SRC)/bolsa_letras.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp

$(OBJ)/diccionario.o: $(SRC)/diccionario.cpp
	$(CXX) $(CPPFLAGS)  -o $(OBJ)/diccionario.o $(SRC)/diccionario.cpp

# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
