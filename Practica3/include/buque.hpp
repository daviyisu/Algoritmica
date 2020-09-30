#ifndef _BUQUE_HPP
#define _BUQUE_HPP


#include <iostream>
#include <vector>
#include <list>
#include <utility>

using namespace std;

class Buque{
    private:
        double k;
        vector<pair<int,double>> pesos;
    public:
        Buque(double cant, vector<pair<int,double>> cargas);
        vector<pair<int,double>> maxContenedores();
        vector<pair<int,double>> maxToneladas();
                               
};
#endif