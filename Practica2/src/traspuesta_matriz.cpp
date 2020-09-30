#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

//codigo para generar matrices con numeros aleatorios
void generaMatrices(int **matriz, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            matriz[i][j] = rand()%n;
    }
}

//codigo para mostrar las matrices
void mostrarMatrices(int **matriz, int orden)
{
    for (int i = 0; i < orden; i++)
    {
        for (int j = 0; j < orden; j++)
            cout << matriz[i][j] << "\t";
        cout << endl;
    }
}

//funcion auxiliar para cambiar el valor de dos enteros
void swap(int &a, int &b)
{
    int aux = a;
    a = b;
    b = aux;
}

//funcion para intercambiar dos submatrices dentro de una matriz
/*
*   @brief: Intercambias los elementos de una submatriz con los de otra subamtriz, para ello se hacen dos bucles iterando a la vez sobre las dos matrices
*/
void IntercambiarMatrices(int **matriz, int A_inicio_fila, int A_inicio_col, int A_fin_fila, int A_fin_col
                            , int B_inicio_fila, int B_inicio_col, int B_fin_fila, int B_fin_col)
{
    for (int it_fil1 = A_inicio_fila, it_fil2 = B_inicio_fila; it_fil1 <= A_fin_fila; it_fil1++, it_fil2++)
    {
        for (int it_col1 = A_inicio_col, it_col2 = B_inicio_col; it_col1 <= A_fin_col; it_col1++, it_col2++)
        {
            swap(matriz[it_fil1][it_col1] , matriz[it_fil2][it_col2]);
        }
    }
}

void Trasponer(int **matriz, int inicioI, int inicioJ,int finI, int finJ)
{
    if(finI > inicioI)
    { 

        int medioI = (finI+inicioI) / 2;
        int medioJ = (finJ+inicioJ) / 2;

        
        Trasponer(matriz, inicioI, inicioJ, medioI, medioJ);  // A
        
        Trasponer(matriz, medioI+1, medioJ+1, finI, finJ); // D


        
        Trasponer(matriz, medioI+1, inicioJ, finI, medioJ); // C
        
        Trasponer(matriz, inicioI, medioJ+1, medioI, finJ); // B
        
        IntercambiarMatrices(matriz,inicioI,medioJ+1,medioI,finJ,medioI+1,inicioJ,finI,medioJ);
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

    Trasponer(m,0,0,orden-1,orden-1);

    cout << endl;

    for (int i = 0; i < orden; i++)
        delete[] m[i];
    delete[] m;
}