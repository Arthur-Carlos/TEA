#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Tupla
{
    int quebra;
    int totalContador;
};

int main()
{
    int entrada;
    cin >> entrada;
    vector<Tupla> positivo, negativo;
    string s;

    for (int i = 0; i < entrada; i++)
    {
        cin >> s;
        int contador = 0, x = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                contador++;
            }
            else
            {
                contador--;
            }
            x = min(x, contador);
        }
        Tupla tupla = {-x, contador};
        if (contador >= 0)
        {
            positivo.push_back(tupla);
        }

        else
        {
            negativo.push_back(tupla);
        }
    }

    sort(positivo.begin(), positivo.end(), [](const Tupla &a, const Tupla &b)
         { return a.quebra < b.quebra; });

    sort(negativo.begin(), negativo.end(), [](const Tupla &a, const Tupla &b)
         { return a.quebra > b.quebra; });

    int total = 0;
    bool ok = true;

    for (auto tupla : positivo)
    {
        if (total < tupla.quebra)
        {
            ok = false;
            break;
        }
        total += tupla.totalContador;
    }

    if (ok)
    {
        for (auto tupla : negativo)
        {
            if (total < tupla.quebra)
            {
                ok = false;
                break;
            }
            total += tupla.totalContador;
        }
    }

    if (ok && total == 0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
