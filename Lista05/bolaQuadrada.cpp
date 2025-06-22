#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> bola;

bool podeColocar(int linha, int coluna, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (bola[linha][i] == x)
            return false;
        if (bola[i][coluna] == x)
            return false;
    }
    return true;
}

bool resolver(int linha, int coluna)
{
    if (linha == n)
        return true;

    int proximaLinha = (coluna == n - 1) ? linha + 1 : linha;
    int proximaColuna = (coluna + 1) % n;

    if (bola[linha][coluna] != 0)
    {
        return resolver(proximaLinha, proximaColuna);
    }

    for (int x = 1; x <= n; x++)
    {
        if (podeColocar(linha, coluna, x))
        {
            bola[linha][coluna] = x;
            if (resolver(proximaLinha, proximaColuna))
                return true;
            bola[linha][coluna] = 0;
        }
    }
    return false;
}

int main()
{
    cin >> n;
    bola.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> bola[i][j];

    if (resolver(0, 0))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << bola[i][j];
                if (j < n - 1)
                    cout << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }

    return 0;
}
