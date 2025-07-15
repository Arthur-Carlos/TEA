#include <iostream>
#include <string>
#include <cmath>

#define MAX 1001
using namespace std;

int matriz[MAX][MAX];
string str, copia;
int esq, dir; //reutilizei os nomes da versao que nao funcionou

void checaPalindromoDinamico(string str)
{
    copia = string(str.rbegin(), str.rend()); // copia recebe o reverso
    esq = str.size(), dir = copia.size();
    // fazendo as matrizes
    for (int i = 0; i <= esq; i++)
    {
        matriz[i][0] = i;
    }
    for (int i = 0; i <= dir; i++)
    {
        matriz[0][i] = i;
    }
    // percorre a matriz
    for (int i = 1; i <= esq; i++)
    {
        for (int j = 1; j <= dir; j++)
        {
            if (str[i - 1] == copia[j - 1])
            {
                matriz[i][j] = matriz[i - 1][j - 1];
            }
            else
            {
                // matriz vai receber o menor entre as matrizes +1 do custo da operacao
                matriz[i][j] = min(min(matriz[i - 1][j], matriz[i][j - 1]), matriz[i - 1][j - 1]) + 1; // formula do bagulho
            }
        }
    }

    cout << matriz[esq][dir] / 2 << endl; // esqueci o porque disso, mas o professor explicou que e o correto.
}

int main()
{
    cin >> str;
    checaPalindromoDinamico(str);
    return 0;
}