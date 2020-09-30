#include <iostream>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <vector>
#include <quicksort.hpp>

using namespace std;

//generador de ejemplos para el problema de eliminar elementos repetidos. Simplemente, para rellenar el vector de tama�o n genera n enteros aleatorios entre 0 y n-1

double uniforme() //Genera un numero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
  int t = rand();
  double f = ((double)RAND_MAX + 1.0);
  return (double)t / f;
}

void mostrarVector(int *T, int tamnyo){
  cout.flush();
  for (int l = 0; l < tamnyo; l++)
    cout << T[l] <<" ";
  cout<<"\n";
}

static int* fusion(int* T, int& tam_T,int tam_U, int tam_V, int* U, int* V)
{
  if (U[tam_U - 1] == V[0])
    tam_U--;
  
  tam_T = tam_U + tam_V;

  int *aux = new int[tam_T];

  for (int i = 0; i < tam_U; i++)
    aux[i] = U[i];
  
  for (int i = 0; i < tam_V; i++)
    aux[tam_U + i] = V[i];
  
  delete[] T;
  T = aux;

  return T;
}

int * eliminacion(int* T, int &tamanio)
{
  for (int i = 0; i < tamanio - 1; i++)
  {
    for (int j = i + 1; j < tamanio && T[j] == T[i]; j++)
    {
      for (int k = j; k < tamanio - 1; k++)
        T[k] = T[k + 1];
        
      j--;
      tamanio--;
    }
  }

  int *aux = new int[tamanio];
  for (int i = 0; i < tamanio; i++)
    aux[i] = T[i];
    
  delete [] T;
  T = 0;
  
  return aux;
}

const int UMBRAL = 3;

static int* eliminarDuplicados(int* T, int &tamanio)
{

  if (tamanio <= UMBRAL)
    T = eliminacion(T, tamanio);
  else
  {
    int tam_U = (tamanio) / 2;
    int *U = new int[tam_U];
    assert(U);
    for (int i = 0; i < tam_U; i++)
      U[i] = T[i];
    
    int tam_V = tamanio - tam_U;
    int *V = new int[tam_V];
    assert(V);

    for (int i = 0; i < tam_V; i++)
      V[i] = T[tam_U + i];

    U = eliminarDuplicados(U, tam_U);
    
    V = eliminarDuplicados(V, tam_V);
    
    T = fusion(T,tamanio, tam_U, tam_V, U, V); //fusion(int T[], int tam_U, int tam_V, int U[], int V[])
    
    delete[] U;
    delete[] V;
  }

  return T;
}

int main(int argc, char *argv[])
{
  struct timespec t_ini, t_fin;
  double tiempo;

  if (argc != 2)
  {
    cerr << "Formato " << argv[0] << " <num_elem>"<< "\n";
    return -1;
  }

  int n = atoi(argv[1]);
  int tam_original = n;

  int *T = new int[n];
  assert(T);

  srand(time(0));
  //para generar un vector que pueda tener elementos repetidos
  for (int j = 0; j < n; j++)
  {
    double u = uniforme();
    int k = (int)(n * u);
    T[j] = k;
  }

  quicksort(T, n);

  //Eliminar duplicados.
  clock_gettime(CLOCK_REALTIME, &t_ini);
  mostrarVector(T,n);
  T = eliminarDuplicados(T, n);
  mostrarVector(T,n);
  clock_gettime(CLOCK_REALTIME, &t_fin);
  tiempo = (double)(t_fin.tv_sec - t_ini.tv_sec) + (double)((t_fin.tv_nsec - t_ini.tv_nsec) / (1.e+9));

  cout << "\n" << tam_original << " " << tiempo << "\n";
}