/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funzione per moltiplicare due matrici
vector<vector<int>> prodottoMatrici(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    // Inizializzare la matrice prodotto con zeri
    vector<vector<int>> prodotto(rowsA, vector<int>(colsB, 0));

    // Calcolare il prodotto delle due matrici
    for (int i = 0; i < rowsA; ++i)
    {
        for (int j = 0; j < colsB; ++j)
        {
            for (int k = 0; k < colsA; ++k)
            {
                prodotto[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return prodotto;
}

// Funzione per generare numeri casuali e aggiungerli alla matrice
void aggiungiNumeriCasuali(vector<vector<int>> &matrice, unsigned int seed)
{
    int rows = matrice.size();
    int cols = matrice[0].size();

    // Inizializzare il generatore di numeri casuali con un seme fisso
    srand(seed);

    // Generare e aggiungere numeri casuali alla matrice
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            int numeroCasuale = rand() % 11; // Numeri casuali tra 0 e 10
            matrice[i][j] += numeroCasuale;
        }
    }
}

int main()
{
    // Esempio di matrici
    vector<vector<int>> A = {
        {1, 2},
        {3, 4}};

    vector<vector<int>> B = {
        {5, 6},
        {7, 8}};

    // Calcolare il prodotto delle matrici
    vector<vector<int>> risultato = prodottoMatrici(A, B);

    // Aggiungere numeri casuali alla matrice risultante usando un seme fisso
    unsigned int seed = 42; // Usa un seme fisso per generare sempre la stessa sequenza di numeri casuali
    aggiungiNumeriCasuali(risultato, seed);

    // Stampare il risultato
    cout << "Risultato finale:" << endl;
    for (const auto &row : risultato)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

/*In our case (just the first entries of the "ADD Matrix" ) :
- if even :
{ 4, 7, 8, 6, 4, 6, 7, 3, 10, 2, 3, 8, 1, 10, 4, 7, 1, 7, 3, 7 },
{ 2, 9, 8, 10, 3, 1, 3, 4, 8, 6, 10, 3, 3, 9, 10, 8, 4, 7, 2, 3 }
{ 10, 4, 2, 10, 5, 8, 9, 5, 6, 1, 4, 7, 2, 1, 7, 4, 3, 1, 7, 2 },
{ 6, 6, 5, 8, 7, 6, 7, 10, 4, 8, 5, 6, 3, 6, 5, 8, 5, 5, 4, 1 }}
- if odd : */