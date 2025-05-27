#include <iostream>
#include <vector>
#include <string>

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, x, y, valor, contador = 1;
    vector<int> ohms;
    string entrada;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        ohms.resize(N);
        FenwickTree ft(N);

        for (int i = 1; i <= N; ++i)
        {
            cin >> ohms[i];
            ft.update(i, ohms[i]);
        }

        if (contador > 1)
        {
            cout << '\n';
        }
        cout << "Case " << contador << ":\n";

        while (cin >> entrada)
        {
            if (entrada == "END")
            {
                break;
            }

            cin >> x >> y;

            if (entrada == "S")
            {
                valor = y - ohms[x];
                ohms[x] = y;
                ft.update(x, valor);
            }
            else if (entrada == "M")
            {
                int res = ft.range_query(x, y);
                cout << res << '\n';
            }
        }

        ++contador;
    }

    return 0;
}