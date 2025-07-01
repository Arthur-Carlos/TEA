#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int auxiliar[200][20];
int valores[20][20];
int roupas[20];
int entrada, dinheiro, qtdRoupas;

int busca(int x, int y)
{
    if (x < 0)
    {
        return -1e6; // infinito negativo
    }
    if (y == qtdRoupas)
    {
        return dinheiro - x;
    }
    if (auxiliar[x][y] != -1)
    {
        return auxiliar[x][y];
    }
    int resposta = -1e6;
    for (int i = 0; i < roupas[y]; i++)
    {
        resposta = max(resposta, busca(x - valores[y][i], y + 1));
    }

    return auxiliar[x][y] = resposta;
}

int main()
{
    scanf("%d", &entrada);
    for (int i = 0; i < entrada; i++)
    {
        scanf("%d %d", &dinheiro, &qtdRoupas);

        for (int j = 0; j < qtdRoupas; j++)
        {
            scanf("%d", &roupas[j]);
            for (int k = 0; k < roupas[j]; k++)
            {
                scanf("%d", &valores[j][k]);
            }
        }

        memset(auxiliar, -1, sizeof(auxiliar));
        int resposta = busca(dinheiro, 0);

        if (resposta > 0)
        {
            printf("%d\n", resposta);
        }
        else
        {
            printf("no solution\n");
        }
    }
    return 0;
}