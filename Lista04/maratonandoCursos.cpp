#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool comparador(const pair<int, int>& a, const pair<int, int>& b) {
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second > b.second;
}

int main()
{
    ios::sync_with_stdio(false);
    int cursos, semanas, cargaHora, valor, soma = 0, contador;


    cin >> cursos >> semanas;

    vector<pair<int, int>> total;

    for (int i = 0; i < cursos; ++i)
    {
        cin >> cargaHora >> valor;
        total.emplace_back(cargaHora, valor);
    }

    sort(total.begin(), total.end(),comparador);

    for (const auto &cliente : total)
    {
        soma += cliente.first;
        contador = max(contador, soma);
    }
    
    return 0;
}