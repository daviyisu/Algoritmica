#include "grafo.hpp"

Grafo::iterator Grafo::begin(){
    Grafo::iterator i;
    i.it = nodos.begin();
    return i;
};
Grafo::iterator Grafo::end(){
    Grafo::iterator i;
    i.it = nodos.end();
    return i;
};
Grafo::const_iterator Grafo::cbegin() const{
    const_iterator i;
    i.it = nodos.cbegin();
    return i;
};
Grafo::const_iterator Grafo::cend() const{
    Grafo::const_iterator i;
    i.it = nodos.cend();
    return i;
};

Grafo& Grafo::operator+(const Nodo &n){
    Grafo::const_iterator it = this->cbegin();
    bool encontrado = false;
    while ( it != this->cend() && !encontrado){
        if (n == (*it))
            encontrado=true;
        else
            ++it;
    }

    if (!encontrado)
    {
        this->dimension++; 
        nodos.push_back(n);
    }     
    return *this;
};

const Nodo& Grafo::operator[](int id) const{
    Grafo::const_iterator cit = cbegin();
    int id_actual = -1;
    while( id != id_actual && cit != cend())
    {
        if ( id == (*cit).getId() )
            id_actual = id;
        else
            ++cit;
    }

    if (id_actual != -1)
        return (*cit);
    else
    {
        static Nodo n(-1,-1,-1);
        return n;
    }
};

Grafo& Grafo::operator=(const Grafo &g) {
    this->dimension = g.dimension;
    this->nodos = g.nodos;
    this->matrizAdyacencia = g.matrizAdyacencia;

    return *this;
};

void Grafo::rellenarMatriz() {
    for(int i=0; i<this->dimension; i++) {
        for(int j=i; j<this->dimension; j++) 
            this->matrizAdyacencia[i][j] = this->matrizAdyacencia[j][i] = this->nodos[i].distancia(this->nodos[j]);
    }
}


pair<double, list<int>> Grafo::distanciaConjunto(int indice, list<int> conjunto) {
    list<int> aux = conjunto;
    list<int> camino;
    
    pair<double, list<int>> min, min_aux;
    camino.push_back(indice);

    if (conjunto.size() == 0)
    {
        return make_pair(matrizAdyacencia[indice-1][0],camino);
    }
    else
    {
        //Asumimos que hace una copia por valor
        list<int> camino_siguiente = camino;
        int indice_siguiente = aux.front();
        aux.pop_front();
        pair<double, list<int>> resultadoHijo = distanciaConjunto(indice_siguiente,aux);
        camino_siguiente.splice(camino_siguiente.end(), resultadoHijo.second);
        min = make_pair(matrizAdyacencia[indice-1][indice_siguiente-1] + resultadoHijo.first, camino_siguiente);
        aux.push_front(indice_siguiente);

        list<int>::iterator it = aux.begin();
        ++it;

        for (; it != aux.end(); ++it)
        {
            indice_siguiente = (*it);
            it = aux.erase(it);

            //Asumimos que hace una copia por valor
            list<int> camino_aux = camino;

            pair<double, list<int>> resultadoHijo = distanciaConjunto(indice_siguiente,aux);
            camino_aux.splice(camino_aux.end(), resultadoHijo.second);
            min_aux = make_pair(matrizAdyacencia[indice-1][indice_siguiente-1] + resultadoHijo.first, camino_aux);
            aux.insert(it,indice_siguiente);
           
            if(min_aux.first < min.first) {
                min = min_aux;  
            }            
        }

        return min;
    }
}

ostream& operator<<(ostream& os, const Grafo& grafo) {
    for (Grafo::const_iterator cit = grafo.cbegin(); cit != grafo.cend(); ++cit)
        cout << *cit << "\n";

    cout << endl;
    /*
    for(int i=0; i<grafo.dimension;i++) {
        for(int j=0; j<grafo.dimension; j++) 
            cout << grafo.matrizAdyacencia[i][j] <<"\t";
        cout << endl;
    }*/    
    return os;
}


istream& operator>>(istream& is, Grafo& grafo) {
    string linea;
    getline(is, linea);
    getline(is, linea);
    getline(is, linea);
    getline(is, linea);

    string aux;
    
    size_t posDimension = linea.find(":");
    posDimension++;
    aux = linea.substr(posDimension);
    
    grafo.dimension = stoi(aux);

    grafo.nodos = vector<Nodo>(grafo.dimension);
    grafo.matrizAdyacencia = vector<vector<double>> (grafo.dimension, std::vector<double>(grafo.dimension));

    getline(is, linea);
    getline(is, linea);
    getline(is, linea);

    for(int i=0; i<grafo.dimension; i++) {
        Nodo nodoAux;
        is >> nodoAux;
        grafo.nodos[i] = nodoAux;
    }

    grafo.rellenarMatriz();
    
    return is;
}
