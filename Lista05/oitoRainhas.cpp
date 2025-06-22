#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 8;

vector<int> tabuleiro(N, -1);

bool podeColocar(int linha, int coluna)
{
    for (int i = 0; i < linha; i++)
    {
        if (tabuleiro[i] == coluna ||
            abs(tabuleiro[i] - coluna) == abs(i - linha))
        {
            return false;
        }
    }
    return true;
}

bool resolver(int linha)
{
    if (linha == N)
    {
        return true;
    }

    for (int coluna = 0; coluna < N; coluna++)
    {
        if (podeColocar(linha, coluna))
        {
            tabuleiro[linha] = coluna;
            if (resolver(linha + 1))
            {
                return true;
            }
            tabuleiro[linha] = -1;
        }
    }
    return false;
}

void imprimirTabuleiro()
{
    for (int i = 0; i < N; i++)
    {
        cout << i << " ";
        for (int j = 0; j < N; j++)
        {
            if (tabuleiro[i] == j)
            {
                cout << j;
            }
        }
        cout << endl;
    }
}

int main()
{
    if (resolver(0))
    {
        imprimirTabuleiro();
    }
    return 0;
}
