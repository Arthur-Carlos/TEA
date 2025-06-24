#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Curso
{
    int prazo;
    int valor;
};

bool comparaPrazo(const Curso &a, const Curso &b)
{

    return a.valor > b.valor;
}

vector<int> aux;

int find(int x)
{
    if (aux[x] != x)
    {
        aux[x] = find(aux[x]);
    }
    return aux[x];
}

void Union(int x, int y)
{
    aux[x] = y;
}

int main()
{
    int cursos, semanas;
    cin >> cursos >> semanas;

    vector<Curso> lista(cursos);
    for (int i = 0; i < cursos; ++i)
    {
        cin >> lista[i].prazo >> lista[i].valor;
    }

    sort(lista.begin(), lista.end(), comparaPrazo);

    aux.resize(semanas + 2);
    for (int i = 0; i <= semanas + 1; ++i)
    {
        aux[i] = i;
    }

    int totalConhecimento = 0;

    for (const auto &curso : lista)
    {
        int semanaOcupada = find(min(curso.prazo, semanas));
        if (semanaOcupada > 0)
        {
            totalConhecimento += curso.valor;
            Union(semanaOcupada, semanaOcupada - 1);
        }
    }

    cout << totalConhecimento << "\n";
    return 0;
}