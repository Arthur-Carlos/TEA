#include <iostream>
#include <vector>

using namespace std;

bool backtrack(int idx, int soma, const vector<int> &angulo, int entrada)
{
    if (idx == entrada)
    {

        return (soma % 360 + 360) % 360 == 0;
    }

    return backtrack(idx + 1, soma + angulo[idx], angulo, entrada) ||
           backtrack(idx + 1, soma - angulo[idx], angulo, entrada);
}

int main()
{
    int entrada;
    cin >> entrada;

    vector<int> angulo(entrada);
    for (int i = 0; i < entrada; ++i)
    {
        cin >> angulo[i];
    }

    if (backtrack(0, 0, angulo, entrada))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
