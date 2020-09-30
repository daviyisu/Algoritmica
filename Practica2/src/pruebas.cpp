#include <iostream>

using namespace std;

void swapMatrices(int **matriz, int i, int j, int k, int l){
    int **matriz_aux = new int* [l-k / 2];
    for (int it_1 = 0, it_2 = i; it_2 < j; it_1++){
        matriz_aux[it_1] = new int [i + j / 2];
    }

    for( int it_1 = 0, it_2 = i+j/2; it_2 < j; ++it_1, ++it_2){
        for ( int it_3 = 0, it_4 = k; it_4 < (k+l)/2; ++it_3, ++it_4)
            matriz_aux[it_1][it_3] = matriz[it_2][it_4];
    }

    for( int it_1 = (i+j)/2,it_2 = i; it_1 < j; ++it_1, ++it_2){
        for ( int it_3 = k, it_4 = (k+l)/2; it_4 < l; ++it_3, ++it_4)
            matriz[it_1][it_3] = matriz[it_2][it_4];
    }

    for( int it_1 = 0, it_2 = i; it_2 < (i+j)/2; ++it_1, ++it_2){
        for ( int it_3 = 0, it_4 = (k+l)/2; it_4 < l; ++it_3, ++it_4)
            matriz[it_2][it_4] = matriz_aux[it_1][it_3];
    }   
}

void generaMatrices(int **matriz, int n)
{
    int a = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz[i][j] = a++;
           
        }
    }
}

void mostrarMatrices(int **matriz, int orden)
{
    for (int i = 0; i < orden; i++)
    {
        for (int j = 0; j < orden; j++)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }
}

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        cerr << "Faltan argumentos\n";
        exit(-1);
    }

    unsigned int orden = atoi(argv[1]);

    int **m = new int *[orden];
    for (int i = 0; i < orden; i++)
        m[i] = new int[orden];

    generaMatrices(m, orden);

    mostrarMatrices(m, orden);

    swapMatrices(m, orden/2, orden-1, orden/2, orden-1);

    cout << endl;

    mostrarMatrices(m, orden);

    for (int i = 0; i < orden; i++)
        delete[] m[i];
    delete[] m;
}
