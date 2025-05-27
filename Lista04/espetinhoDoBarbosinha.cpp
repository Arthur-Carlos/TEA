#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int tempoParaSegundos(int h, int m, int s)
{
    return h * 3600 + m * 60 + s;
}

int main()
{
    ios::sync_with_stdio(false);
    int entrada;
    int ent_hora, ent_minuto, ent_segundos;
    int sai_hora, sai_minuto, sai_segundos;
    cin >> entrada;

    vector<pair<int, int>> clientes;

    for (int i = 0; i < entrada; ++i)
    {
        scanf("%d:%d:%d", &ent_hora, &ent_minuto, &ent_segundos);
        scanf("%d:%d:%d", &sai_hora, &sai_minuto, &sai_segundos);

        int chegada = tempoParaSegundos(ent_hora, ent_minuto, ent_segundos);
        int saida = tempoParaSegundos(sai_hora, sai_minuto, sai_segundos);

        clientes.emplace_back(chegada, 1);
        clientes.emplace_back(saida, -1);
    }

    sort(clientes.begin(), clientes.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if (a.first == b.first) return a.second < b.second;
        return a.first < b.first; });

    int cadeiras = 0, max_cadeiras = 0;
    for (const auto &cliente : clientes)
    {
        cadeiras += cliente.second;
        max_cadeiras = max(max_cadeiras, cadeiras);
    }

    cout << max_cadeiras << endl;

    return 0;
}