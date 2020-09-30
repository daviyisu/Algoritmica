#include "buque.hpp"
#include <vector>

Buque::Buque(double cant, vector<pair<int,double>> cargas)
{
    k = cant;
    pesos = cargas;
}

vector<pair<int,double>> Buque::maxContenedores()
{
    vector<pair<int,double>> result;
    vector<pair<int,double>> candidatos = pesos;
    
    double carga_actual = 0;
    vector<pair<int,double>>::iterator it_candidatos = candidatos.begin();

    while ( !candidatos.empty() )
    {
        vector<pair<int,double>>::iterator it = candidatos.begin();
        for (unsigned int i=0; i<candidatos.size() && it != candidatos.end(); ++i, ++it)
        {
            if ( (*it).second < (*it_candidatos).second)
                it_candidatos = it;   
        }

        if((carga_actual + (*it_candidatos).second) <= k){
            carga_actual += (*it_candidatos).second;
            result.push_back(*it_candidatos);
            candidatos.erase(it_candidatos);
            it_candidatos = candidatos.begin();
        } else
            candidatos.erase(it_candidatos);
    }
    
    return result;
    
};

void mostrarVector(vector<pair<int,double>> &v){
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i].first << "." << v[i].second << "  ";
    }
    
}

vector<pair<int,double>> Buque::maxToneladas(){
    vector<pair<int,double>> result;
    vector<pair<int,double>> candidatos(pesos.size());
    for (unsigned int i = 0; i < candidatos.size(); i++)
    {
        candidatos[i].first = pesos[i].first;
        candidatos[i].second = pesos[i].second;
    }
    cout << "Candidatos antes de while\n";
    mostrarVector(candidatos);

    
    double carga_actual = 0;
    double max = 0;
    int indice;
    int indice_max;
    vector<pair<int,double>>::iterator it_candidatos;
    vector<pair<int,double>>::const_iterator cit;
    while ( !candidatos.empty() )
    {
            
        for(cit = candidatos.cbegin(), indice=0; cit != candidatos.cend(); ++cit, ++indice)
        {
            if( (*cit).second > max ){
                max = (*cit).second;
                indice_max = indice;
            }
            
        }
        
        if( (carga_actual+max) <= k){
            carga_actual += max;
            it_candidatos = (candidatos.begin()+indice_max);
            result.push_back(candidatos[indice_max]);
            candidatos.erase(it_candidatos);
        } else
        {
            it_candidatos = (candidatos.begin()+indice_max);
            candidatos.erase(it_candidatos);
        }

        max=0;

        
    }
    //cout << "\nResult:\n";
    //mostrarVector(result);
    
    return result;
    
}