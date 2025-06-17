#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Info
{
    int saldo;
    int minPrefixo;
};

Info calculaInfo(const string &s)
{
    int saldo = 0, minSaldo = 0;
    for (char c : s)
    {
        if (c == '(')
            saldo++;
        else
            saldo--;
        minSaldo = min(minSaldo, saldo);
    }
    return {saldo, minSaldo};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int entrada;
    cin >> entrada;

    vector<pair<Info, string>> positivos, negativos;

    for (int i = 0; i < entrada; ++i)
    {
        string s;
        cin >> s;
        Info info = calculaInfo(s);

        if (info.saldo >= 0)
        {
            positivos.emplace_back(info, s);
        }
        else
        {
            negativos.emplace_back(info, s);
        }
    }

    sort(positivos.begin(), positivos.end(), [](const auto &a, const auto &b)
         { return a.first.minPrefixo > b.first.minPrefixo; });

    sort(negativos.begin(), negativos.end(), [](const auto &a, const auto &b)
         { return (b.first.minPrefixo - b.first.saldo) < (a.first.minPrefixo - a.first.saldo); });

    int saldoTotal = 0;

    for (auto &p : positivos)
    {
        if (saldoTotal + p.first.minPrefixo < 0)
        {
            cout << "No\n";
            return 0;
        }
        saldoTotal += p.first.saldo;
    }

    for (auto &p : negativos)
    {
        if (saldoTotal + p.first.minPrefixo < 0)
        {
            cout << "No\n";
            return 0;
        }
        saldoTotal += p.first.saldo;
    }

    if (saldoTotal == 0)
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }

    return 0;
}
