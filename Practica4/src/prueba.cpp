#include <iostream>
#include <vector>
#include <string>
#include "nodo.hpp"
#include "grafo.hpp"


using namespace std;

int main(int argc, char** argv) {

    Grafo g;
    Nodo n(1,1,1);
    g+n;
    cout << g;
    Nodo l(2,2,2);
    g+l;
    cout <<"\n" <<g;

    return(0);
}