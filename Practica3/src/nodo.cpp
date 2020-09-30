#include "nodo.hpp"

ostream& operator<<(ostream& os, const Nodo& n) {
    os << n.id << " " << n.posicion.first << " " << n.posicion.second;
    return os;   
}


istream& operator>>(istream& is, Nodo& n) {
    is >> n.id;
    pair<double,double> aux;
    is >> aux.first;
    is >> aux.second; 
    n.posicion = aux;   
    return is;
}

bool Nodo::operator==(const Nodo &n) const{
    return this->getId() == n.getId() && this->getX() == n.getX() && this->getY() == n.getY();
}

bool Nodo::operator!=(const Nodo &n) const{
    return !((*this) == n);
}

double Nodo::distancia(const Nodo &n1){
    double x = n1.getX() - this->getX();
    double y = n1.getY() - this->getY();
    double dist = pow(x,2) + pow(y,2);
    dist = sqrt(dist);

    return dist;
}

Nodo& Nodo::operator=(const Nodo &n1) {
    if(n1 != (*this)) {
        this->id = n1.id; 
        this->posicion.first = n1.posicion.first;
        this->posicion.second = n1.posicion.second;
    }

    return *this;
}