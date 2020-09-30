SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -g -I./include

all: $(BIN)/genera_duplicados $(BIN)/trasponer_matriz $(OBJ)/genera_duplicados.o $(OBJ)/quicksort.o

$(BIN)/trasponer_matriz: $(SRC)/traspuesta_matriz.cpp
	$(CXX) $(CPPFLAGS) $(SRC)/traspuesta_matriz.cpp -o $(BIN)/trasponer_matriz

$(BIN)/genera_duplicados: $(OBJ)/genera_duplicados.o $(OBJ)/quicksort.o
	$(CXX) -o $(BIN)/genera_duplicados $(OBJ)/genera_duplicados.o $(OBJ)/quicksort.o

$(OBJ)/genera_duplicados.o: $(SRC)/genera-duplicados_DyV.cpp $(INC)/quicksort.hpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/genera-duplicados_DyV.cpp -o $(OBJ)/genera_duplicados.o

$(OBJ)/quicksort.o: $(INC)/quicksort.hpp $(SRC)/quicksort.cpp
	$(CXX) $(CPPFLAGS) -c $(SRC)/quicksort.cpp -o $(OBJ)/quicksort.o

clean:
	rm bin/* obj/*