#include <iostream>
#include <vector>
using namespace std;

int entrada;
vector<vector<int>> bola;

bool podeColocar(int linha, int coluna, int x)
{
    for (int i = 0; i < entrada; i++)
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
    if (linha == entrada)
        return true;

    int proximaLinha = (coluna == entrada - 1) ? linha + 1 : linha;
    int proximaColuna = (coluna + 1) % entrada;

    if (bola[linha][coluna] != 0)
    {
        return resolver(proximaLinha, proximaColuna);
    }

    for (int x = 1; x <= entrada; x++)
    {
        if (podeColocar(linha, coluna, x))
        {
            bola[linha][coluna] = x;
            if (resolver(proximaLinha, proximaColuna))
            {
                return true;
            }
            bola[linha][coluna] = 0;
        }
    }
    return false;
}

int main()
{
    cin >> entrada;
    bola.resize(entrada, vector<int>(entrada));

    for (int i = 0; i < entrada; i++)
        for (int j = 0; j < entrada; j++)
            cin >> bola[i][j];

    if (resolver(0, 0))
    {
        for (int i = 0; i < entrada; i++)
        {
            for (int j = 0; j < entrada; j++)
            {
                cout << bola[i][j];
                if (j < entrada - 1)
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
