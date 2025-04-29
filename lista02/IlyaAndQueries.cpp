#include <iostream>
#include <vector>

using namespace std;

//usei uma árvore que eu achei na net
class FenwickTree
{
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size)
    {
        n = size;
        tree.assign(n + 1, 0);
    }

    void update(int index, int valor)
    {
        while (index <= n)
        {
            tree[index] += valor;
            index += index & -index;
        }
    }

    int query(int index)
    {
        int res = 0;
        while (index > 0)
        {
            res += tree[index];
            index -= index & -index;
        }
        return res;
    }

    int range_query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    string entrada;
    int qtdConsultas, consultas1, consultas2;
    cin >> entrada;
    cin >> qtdConsultas;
    for (int i = 0; i < qtdConsultas; i++)
    {
        cin >> consultas1 >> consultas2;
    }
    cout << consultas1 << consultas2;

    return 0;
}