#ifndef _NODO_HPP
#define _NODO_HPP

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Nodo{
    private:
        int id; 
        pair<double,double> posicion;

    public:

        Nodo(){this->id = 0; this->posicion.first = 0; this->posicion.second = 0;};
        Nodo(int id, int x, int y){ this->id = id; this->posicion.first = x; this->posicion.second = y; };
        double getX() const{ return posicion.first; };
        double getY() const { return posicion.second; };
        int getId() const { return id; };
        bool operator==(const Nodo &n1) const;
        bool operator!=(const Nodo &n1) const;
        Nodo& operator=(const Nodo &n1);
        double distancia(const Nodo &n1);
        
    friend ostream& operator<<(ostream& os, const Nodo& n);
    friend istream& operator>>(istream& is, Nodo& n);
};

#endif