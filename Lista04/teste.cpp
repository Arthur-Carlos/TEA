#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comparador(const pair<int, int> &a, const pair<int, int> &b)
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    int cursos, semanas, cargaHora, valor, soma = 0, contador = 0;

    cin >> cursos >> semanas;

    vector<pair<int, int>> total;

    for (int i = 0; i < cursos; ++i)
    {
        cin >> cargaHora >> valor;
        total.emplace_back(cargaHora, valor);
    }

    sort(total.begin(), total.end(), comparador);
    for (const auto &cliente : total)
    {
        if (cliente.first > contador)
        {
            soma += cliente.second;
            contador++;
        }
    }
    cout << soma << endl;
    return 0;
}