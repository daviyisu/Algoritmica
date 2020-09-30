SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -std=c++11 -g -Wall -I./include

all:$(BIN)/problema_grafo $(BIN)/problema_barco 


$(BIN)/problema_grafo: $(OBJ)/problema_grafo.o $(OBJ)/nodo.o $(OBJ)/grafo.o
	$(CXX) -o $(BIN)/problema_grafo $(OBJ)/problema_grafo.o $(OBJ)/nodo.o $(OBJ)/grafo.o 

$(BIN)/problema_barco: $(OBJ)/problema_barco.o $(OBJ)/buque.o
	$(CXX) -o $(BIN)/problema_barco $(OBJ)/problema_barco.o $(OBJ)/buque.o

$(OBJ)/problema_grafo.o: $(SRC)/problema_grafo.cpp $(INC)/grafo.hpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/problema_grafo.cpp -o $(OBJ)/problema_grafo.o

$(OBJ)/problema_barco.o: $(SRC)/problema_barco.cpp $(INC)/buque.hpp
	$(CXX) -c $(CPPFLAGS) $(SRC)/problema_barco.cpp -o $(OBJ)/problema_barco.o
	
$(OBJ)/buque.o: $(SRC)/buque.cpp $(INC)/buque.hpp
	$(CXX) -c $(CPPFLAGS) $(SRC)/buque.cpp -o $(OBJ)/buque.o

$(OBJ)/grafo.o: $(SRC)/grafo.cpp $(INC)/grafo.hpp $(INC)/arista.hpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/grafo.cpp -o $(OBJ)/grafo.o

$(OBJ)/nodo.o: $(SRC)/nodo.cpp $(INC)/nodo.hpp
	$(CXX) -c $(CPPFLAGS)  $(SRC)/nodo.cpp -o $(OBJ)/nodo.o
	
clean:
	rm bin/* obj/*
 
