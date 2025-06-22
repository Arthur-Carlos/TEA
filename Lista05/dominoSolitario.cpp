#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Peca
{
    int a, b;
    bool usada = false;
};

int melhorTamanho = 0;
vector<Peca> melhorSequencia;

void backtrack(vector<Peca> &pecas, vector<Peca> &sequenciaAtual, int ultimoValor)
{
    if (sequenciaAtual.size() > melhorTamanho)
    {
        melhorTamanho = sequenciaAtual.size();
        melhorSequencia = sequenciaAtual;
    }

    for (int i = 0; i < pecas.size(); i++)
    {
        if (!pecas[i].usada)
        {
            if (pecas[i].a == ultimoValor)
            {
                pecas[i].usada = true;
                sequenciaAtual.push_back(pecas[i]);
                backtrack(pecas, sequenciaAtual, pecas[i].b);
                sequenciaAtual.pop_back();
                pecas[i].usada = false;
            }
            else if (pecas[i].b == ultimoValor)
            {
                pecas[i].usada = true;
                swap(pecas[i].a, pecas[i].b);
                sequenciaAtual.push_back(pecas[i]);
                backtrack(pecas, sequenciaAtual, pecas[i].b);
                sequenciaAtual.pop_back();
                swap(pecas[i].a, pecas[i].b);
                pecas[i].usada = false;
            }
        }
    }
}

int main()
{
    int entrada;
    cin >> entrada;
    vector<Peca> pecas(entrada);

    for (int i = 0; i < entrada; i++)
    {
        char barra;
        cin >> pecas[i].a >> barra >> pecas[i].b;
    }

    for (int i = 0; i < entrada; i++)
    {
        for (int inverso = 0; inverso < 2; inverso++)
        {
            vector<Peca> sequenciaAtual;
            pecas[i].usada = true;
            sequenciaAtual.push_back(pecas[i]);
            backtrack(pecas, sequenciaAtual, pecas[i].b);
            sequenciaAtual.pop_back();
            pecas[i].usada = false;
            swap(pecas[i].a, pecas[i].b);
        }
    }

    cout << melhorTamanho << endl;
    for (int i = 0; i < melhorSequencia.size(); i++)
    {
        cout << melhorSequencia[i].a << "|" << melhorSequencia[i].b;
        if (i != melhorSequencia.size() - 1)
            cout << " ";
    }
    cout << endl;

    return 0;
}
