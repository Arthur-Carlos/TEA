#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool compara(const pair<double, double> &v1, const pair<double, double> &v2)
{
    return v1.first < v2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    int entrada, comprimento, largura;
    while (cin >> entrada >> comprimento >> largura)
    {
        bool impossible = false;
        vector<pair<double, double>> aspersor;

        for (int i = 0; i < entrada; i++)
        {
            int posicao, alcance;
            cin >> posicao >> alcance;

            if (alcance * 2 <= largura)
                continue;

            double pythagoras = sqrt(alcance * alcance - (largura / 2.0) * (largura / 2.0));
            aspersor.push_back({posicao - pythagoras, posicao + pythagoras});
        }

        sort(aspersor.begin(), aspersor.end(), compara);

        int contador = 0;
        double atual = 0;
        int j = 0;
        int n = aspersor.size();

        while (atual < comprimento)
        {
            double max_reach = atual;
            while (j < n && aspersor[j].first <= atual)
            {
                max_reach = max(max_reach, aspersor[j].second);
                j++;
            }

            if (max_reach == atual)
            {
                impossible = true;
                break;
            }

            contador++;
            atual = max_reach;
        }
        if (impossible)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << contador << "\n";
        }
    }
    return 0;
}

