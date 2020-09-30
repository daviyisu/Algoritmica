SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -g -Wall -I./include

all:$(BIN)/problema_grafo $(BIN)/prueba 


$(BIN)/problema_grafo: $(OBJ)/problema_grafo.o $(OBJ)/nodo.o $(OBJ)/grafo.o
	$(CXX) -o $(BIN)/problema_grafo $(OBJ)/problema_grafo.o $(OBJ)/nodo.o $(OBJ)/grafo.o 


$(BIN)/prueba: $(OBJ)/prueba.o $(OBJ)/nodo.o $(OBJ)/grafo.o
	$(CXX) -o $(BIN)/prueba $(OBJ)/prueba.o $(OBJ)/nodo.o $(OBJ)/grafo.o 


$(OBJ)/problema_grafo.o: $(SRC)/problema_grafo.cpp $(INC)/grafo.hpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/problema_grafo.cpp -o $(OBJ)/problema_grafo.o
	
$(OBJ)/prueba.o: $(SRC)/prueba.cpp $(INC)/grafo.hpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/prueba.cpp -o $(OBJ)/prueba.o


$(OBJ)/grafo.o: $(SRC)/grafo.cpp $(INC)/grafo.hpp $(INC)/arista.hpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/grafo.cpp -o $(OBJ)/grafo.o

$(OBJ)/nodo.o: $(SRC)/nodo.cpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/nodo.cpp -o $(OBJ)/nodo.o
	
clean:
	rm bin/* obj/*
 
