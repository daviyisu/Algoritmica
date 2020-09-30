#include<iostream>
#include"buque.hpp"
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

void mostrarVector(vector<pair<int,double>> v){
    for (size_t i=0; i<v.size(); ++i)
        cout << v[i].first << "." << v[i].second <<" ";
    cout<<endl;
}                                                                                                                                                                                                                                                                                                                                                     

int main(int argc, char** argv)
{
    if (argc < 4)
    {
        cout<<"Error al pasar parametros, el orden es: ./bin/ejecutable\tValor_de_k\tValor_de_N\tEjercicio_a_probar"<<endl;
        exit(-1);
    }

    srand(time(NULL));

    double toneladas = stoi(argv[1]);
    double n = stoi(argv[2]);
    double opcion = stoi(argv[3]);

    vector<pair<int,double>> cargas;
    pair<int,double> aux;

    for( int i=0; i<n; ++i){
        aux.first = i+1;
        double f = rand() % ((int)toneladas/4);
        aux.second =  1 + f;
        cargas.push_back(aux);
    }

    Buque b(toneladas,cargas);

    if (opcion == 1){
        vector<pair<int,double>> resultado = b.maxContenedores();
        mostrarVector(resultado);
    }
    else if (opcion == 2){
        vector<pair<int,double>> resultado = b.maxToneladas();
        mostrarVector(resultado);
    }
    else
        cout<<"La opción debe ser 1 o 2"<<endl;   
}