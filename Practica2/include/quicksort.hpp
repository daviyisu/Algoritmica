#ifndef _QUICKSORT_HPP
#define _QUICKSORT_HPP
#include <iostream>
#include <vector>

using namespace std;

const int UMBRAL_QS = 50;

static void dividir_qs(int * T, int inicial, int final, int &pp);

static void insercion_lims(int * T, int inicial, int final);
inline static void insercion(int * T, int num_elem);

static void quicksort_lims(int * T, int inicial, int final);
void quicksort(int* T, int num_elem);
#endif