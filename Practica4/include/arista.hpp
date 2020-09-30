#include <nodo.hpp>
#include <iostream>

using namespace std;

class Arista{
    private:
        Nodo p1, p2;
        double distancia;
    public:
        Arista(Nodo p1, Nodo p2) {this->p1 = p1; this->p2 = p2; distancia = p1.distancia(p2); };
        Nodo getP1() const { return p1; };
        Nodo getP2() const { return p2; };
        double getDistancia() const { return distancia; };
};