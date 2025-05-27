#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Autor
{
    string nome;
    int indiceH;
};

int calcularIndiceH(vector<int> &citacoes)
{
    sort(citacoes.rbegin(), citacoes.rend());
    int h = 0, n = citacoes.size();
    for (int i = 0; i < n; ++i)
    {
        if (citacoes[i] >= i + 1)
        {
            h = i + 1;
        }
        else
        {
            break;
        }
    }
    return h;
}

bool compara(const Autor &a, const Autor &b)
{
    if (a.indiceH != b.indiceH)
        return a.indiceH > b.indiceH;
    return a.nome < b.nome;
}

int main()
{
    ios::sync_with_stdio(false);
    int entrada;
    cin >> entrada;
    vector<Autor> autores;

    for (int i = 0; i < entrada; ++i)
    {
        string nome;
        int publicacoes;
        cin >> nome >> publicacoes;
        vector<int> citacoes(publicacoes);
        for (int j = 0; j < publicacoes; ++j)
        {
            cin >> citacoes[j];
        }

        int h = calcularIndiceH(citacoes);
        autores.push_back({nome, h});
    }

    sort(autores.begin(), autores.end(), compara);

    for (const auto &autor : autores)
    {
        cout << autor.nome << " " << autor.indiceH << endl;
    }

    return 0;
}
