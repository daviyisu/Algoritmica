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
    salida << "COMMENT: Elaborado con técnica greedy "+modo+"\n";
    salida << "DIMENSION: " << lista.size() << "\n"; 
    salida << "EDGE_WEIGHT_TYPE: GEO\n";
    salida << "DISPLAY_DATA_TYPE: COORD_DISPLAY\n";
    salida << "NODE_COORD_SECTION\n";

    list<int>::const_iterator it = lista.cbegin();
    for (;it != lista.cend(); ++it)
    {
        salida << g[(*it)]<<"\n";   
    }
         
    salida.close();
};

int main(int argc, char** argv){
    if (argc != 3)
    {
        cout<<"Escriba el nombre del fichero a leer y la opción de mostrar lista\n";
        exit(-1);
    }

    string filename = argv[1];
    
    ifstream fichero;
    fichero.open(filename);

    Grafo n;
    fichero >> n;
    
    unsigned int opcion = stoi(argv[2]);
    list<int> l;

    if (opcion == 1)
    {
        n.cercania(l);
        mostrarLista(n, l, filename,"cercania");
    }
    else if (opcion == 2)
    {
        n.insercion(l);
        mostrarLista(n, l, filename,"insercion");
    }    
    else if (opcion == 3)
    {
        n.espiral(l);
        mostrarLista(n, l, filename,"espiral");
    }

    fichero.close();
     
    return(0);
}