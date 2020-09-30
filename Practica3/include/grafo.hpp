#ifndef _GRAFO_HPP
#define _GRAFO_HPP


#include <iostream>
#include <vector>
#include <list>
#include "nodo.hpp"
#include "arista.hpp"

using namespace std;

class Grafo{
    private:
        int dimension;
        vector<Nodo> nodos;
        vector<vector<double>> matrizAdyacencia;
        
    public:
        int getId(){ return dimension; };

        class iterator
        {
            private: 
                vector<Nodo>::iterator it;
            public:
                iterator() {};
                bool operator==(const iterator &i) const{
                    return i.it == it;
                }
                bool operator!=(const iterator &i) const{
                    return i.it != it;
                }
                Nodo& operator*() {
                    return *it;
                }
                iterator& operator++() {
                    ++it;
                    return *this;
                }
                iterator& operator--() {
                    --it;
                    return *this;
                }
                friend class Grafo;
        };

        class const_iterator
        {
            private: 
                vector<Nodo>::const_iterator it;
            public:
                const_iterator() {};
                bool operator==(const const_iterator &i) const{
                    return i.it == it;
                }
                bool operator!=(const const_iterator &i) const{
                    return i.it != it;
                }
                const Nodo& operator*() const{
                    return *it;
                }
                const_iterator& operator++() {
                    ++it;
                    return *this;
                }
                const_iterator& operator--() {
                    --it;
                    return *this;
                }
                friend class Grafo;
        };

        iterator begin();
        iterator end();
        const_iterator cbegin() const;
        const_iterator cend() const;

        Grafo& operator+(const Nodo &n);
        Grafo& operator=(const Grafo &g);
        const Nodo& operator[](int id) const;

        void rellenarMatriz();
        
        void cercania(list<int>& result);
        void insercion(list<int>& result);
        void espiral(list<int>& result);

        friend ostream& operator<<(ostream& os, const Grafo& grafo);
        friend istream& operator>>(istream& is, Grafo& grafo);
};

#endif