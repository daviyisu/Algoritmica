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

Grafo& Grafo::operator=(const Grafo &g){
    this->dimension = g.dimension;
    this->nodos = g.nodos;
    this->matrizAdyacencia = g.matrizAdyacencia;

    return *this;
};

void Grafo::rellenarMatriz(){
    for(int i=0; i<this->dimension; i++) {
        for(int j=i; j<this->dimension; j++) 
            this->matrizAdyacencia[i][j] = this->matrizAdyacencia[j][i] = this->nodos[i].distancia(this->nodos[j]);
    }
}

void Grafo::cercania(list<int>& result) {
    list<int> candidatos;

    for(int i=0; i<dimension; i++)
        candidatos.push_back(i+1);

    result.push_back(candidatos.front());
    candidatos.pop_front();

    list<int>::iterator it_candidatos;
    list<int>::iterator it_resultado = result.begin();
    double dist_min;
    list<int>::iterator menor_candidato;

    while ( !candidatos.empty() )
    {
        it_candidatos = candidatos.begin();
        dist_min = matrizAdyacencia[(*it_resultado)-1][(*it_candidatos)-1];
        menor_candidato = it_candidatos;

        for(; it_candidatos != candidatos.end(); ++it_candidatos){
            if(dist_min > matrizAdyacencia[(*it_resultado)-1][(*it_candidatos)-1])
            {
                dist_min = matrizAdyacencia[(*it_resultado)-1][(*it_candidatos)-1];
                menor_candidato = it_candidatos;
            }
        }

        result.push_back( (*menor_candidato) );
        candidatos.erase( menor_candidato ); 
       
       ++it_resultado;
    }
};

void Grafo::insercion(list<int>& result){

    list<int> candidatos;

    for(int i=0; i<dimension; i++)
        candidatos.push_back(i+1);

    list<int>::iterator it_candidatos = candidatos.begin();
    list<int>::iterator punto_cardinal = it_candidatos; 
    
    // El vértice más al norte
    for(;it_candidatos != candidatos.end();++it_candidatos)
    {
        if(nodos[(*punto_cardinal)-1].getY() < nodos[(*it_candidatos)-1].getY())
            punto_cardinal = it_candidatos;
    }

    Nodo norte = nodos[(*punto_cardinal)-1];
    candidatos.erase(punto_cardinal);
    punto_cardinal = it_candidatos = candidatos.begin();

    // El vértice más al oeste
    for(;it_candidatos != candidatos.end();++it_candidatos)
    {
        if(nodos[(*punto_cardinal)-1].getX() > nodos[(*it_candidatos)-1].getX())
            punto_cardinal = it_candidatos;
    }
    
    Nodo oeste = nodos[(*punto_cardinal)-1];
    candidatos.erase(punto_cardinal);
    punto_cardinal = it_candidatos = candidatos.begin();

    //El candidato más al este
    for(;it_candidatos != candidatos.end();++it_candidatos)
    {
        if(nodos[(*punto_cardinal)-1].getX() < nodos[(*it_candidatos)-1].getX())
            punto_cardinal = it_candidatos;
    }

    Nodo este = nodos[(*punto_cardinal)-1];
    candidatos.erase(punto_cardinal);
    vector<Arista> lados;

    lados.push_back(Arista(norte, este));
    lados.push_back(Arista(este,oeste));
    lados.push_back(Arista(oeste,norte));

    while (!candidatos.empty())
    {
        int posicion_arista = 0;

        list<int>::const_iterator nodo_anadir = candidatos.cbegin();
        double mejor_distancia = matrizAdyacencia[lados[0].getP1().getId()-1][(*nodo_anadir)-1] 
                                 + matrizAdyacencia[(*nodo_anadir)-1][lados[0].getP2().getId()-1]
                                 - lados[0].getDistancia(); 

        for (list<int>::const_iterator cit = candidatos.cbegin(); cit != candidatos.cend(); ++cit)
        {
            Nodo opcion = nodos[(*cit)-1];

            for(size_t i=0; i<lados.size(); ++i)
            {
                double incremento = matrizAdyacencia[lados[i].getP1().getId()-1][opcion.getId()-1] 
                                    + matrizAdyacencia[lados[i].getP2().getId()-1][opcion.getId()-1]
                                    - lados[i].getDistancia();
                
                if (incremento < mejor_distancia)
                {
                    mejor_distancia = incremento;
                    nodo_anadir = cit;
                    posicion_arista = i;
                }                
            }
        }
    
        Arista x(lados[posicion_arista].getP1(),nodos[(*nodo_anadir)-1]);
        Arista y(nodos[(*nodo_anadir)-1],lados[posicion_arista].getP2());
        
        cout << x.getP1() << "\t" << x.getP2() << endl;
        cout << y.getP1() << "\t" << y.getP2() << endl;
        cout << endl;

        //lados[posicion_arista] = x;
        vector<Arista>::const_iterator it = lados.begin() + posicion_arista +1;
        lados[posicion_arista] = x;
        lados.insert(it, y);

        candidatos.erase(nodo_anadir);
        
        for(size_t i=0; i<lados.size(); i++){
            cout << lados[i].getP1()<<"\n";
            cout << lados[i].getP2()<<"\n";
        }
        cout<<endl<<endl;
    }

    for (size_t i=0; i<lados.size(); ++i)
    {
        result.push_back(lados[i].getP1().getId());
    }
};
void Grafo::espiral(list<int>& result)
{
    list<int> izquierda;
    list<int> derecha;

    for(int i=0; i<dimension; i++)
    {
        izquierda.push_back(i+1);
    }
        
    result.push_back(izquierda.front());

    list<int>::iterator it_izq = izquierda.begin();
    
    int elementoY = izquierda.front();

    it_izq = izquierda.begin();
    izquierda.erase(it_izq);
    it_izq = izquierda.begin();
    list<int>::iterator it_elemY;

    int elemento_izquierda;
    int elemento_derecha;

    while (!izquierda.empty() || !derecha.empty())
    {

        while ( !izquierda.empty())
        {
            elemento_izquierda = elementoY;

            for(;it_izq != izquierda.end();)
            {
                if(nodos[elemento_izquierda-1].getX() < nodos[(*it_izq)-1].getX())
                {
                    derecha.push_back((*it_izq));
                    it_izq = izquierda.erase(it_izq);
                }
                else
                    ++it_izq; 
            }

            it_elemY = izquierda.begin();
            elementoY = izquierda.front();

            for( it_izq = izquierda.begin(); it_izq != izquierda.end();++it_izq){
                if(nodos[elementoY-1].getY() < nodos[(*it_izq)-1].getY())
                {
                    elementoY = (*it_izq);
                    it_elemY = it_izq;
                }
            }
            if(izquierda.size() != 0) {
                result.push_back((*it_elemY));
                izquierda.erase(it_elemY);
            }
            
            it_izq = izquierda.begin();
        }
        
        list<int>::iterator it_derecha = derecha.begin();

        while ( !derecha.empty())
        {
            elemento_derecha = elementoY;

            for(;it_derecha != derecha.end();)
            {
                if(nodos[elemento_derecha-1].getX() >= nodos[(*it_derecha)-1].getX())
                {
                    izquierda.push_back((*it_derecha));
                    it_derecha = derecha.erase(it_derecha);
                } 
                else
                    ++it_derecha; 
            }

            it_elemY = derecha.begin();
            elementoY = derecha.front();

            for( it_derecha = derecha.begin(); it_derecha != derecha.end();++it_derecha){
                if(nodos[elementoY-1].getY() > nodos[(*it_derecha)-1].getY())
                {
                    elementoY = (*it_derecha);
                    it_elemY = it_derecha;
                }
            }
            if (derecha.size() != 0) {
                result.push_back((*it_elemY));
                derecha.erase(it_elemY);
            }
            it_derecha = derecha.begin();
        }
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
