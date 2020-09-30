#include <iostream>
#include <fstream>
#include <list>
#include "grafo.hpp"

using namespace std;

void mostrarLista(const Grafo& g,const list<int> &lista, string ficheroEntrada, string modo){
    
    size_t principio_frase = ficheroEntrada.find_last_of("/");
    size_t final_frase = ficheroEntrada.find_last_of(".");
    size_t tam_frase = final_frase - principio_frase;

    string ficheroSalida = ficheroEntrada.substr(principio_frase+1, tam_frase-1);
    ficheroSalida += "-with-" + modo + ".tsp";

    ofstream salida("./data/" + ficheroSalida);

    salida << "NAME: " + ficheroSalida << "\n";
    salida << "TYPE: TSP\n";
    salida << "COMMENT: Elaborado con técnica "+modo+"\n";
    salida << "DIMENSION: " << lista.size() << "\n"; 
    salida << "EDGE_WEIGHT_TYPE: GEO\n";
    salida << "DISPLAY_DATA_TYPE: COORD_DISPLAY\n";
    salida << "NODE_COORD_SECTION\n";

    list<int>::const_iterator it = lista.cbegin();
    for (;it != lista.cend(); ++it)
    {
        salida << g[(*it)]<<"\n";   
    }

    salida << g[(*lista.cbegin())]<<"\n";
         
    salida.close();
};

int main(int argc, char** argv){
    if (argc != 2)
    {
        cout<<"Escriba el nombre del fichero a leer \n";
        exit(-1);
    }

    string filename = argv[1];
    string modo = "Dinamico";
    
    ifstream fichero;
    fichero.open(filename);

    Grafo g;
    fichero >> g;
    

    list<int> resultado;
    list<int> conjunto;

    for (int i = 1; i < g.getDimension(); i++)
        conjunto.push_back(i+1);
    

    pair<double, list<int>> result = g.distanciaConjunto(1,conjunto);
    cout << "Distancia total: "<<result.first<<endl;
    
    mostrarLista(g, result.second, filename, modo);

    fichero.close();
     
    return(0);
}