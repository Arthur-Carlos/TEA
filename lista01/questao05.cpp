#include <iostream>
#include <vector>
using namespace std;

void imparParSort(vector<int> &a)
{
    int n = a.size();
    if (n <= 1)
        return;

    vector<int> impar, par;
    for (int i = 0; i < n; ++i)
    {
        if ((i + 1) % 2 == 1)
        {
            impar.push_back(a[i]);
        }
        else
        {
            par.push_back(a[i]);
        }
    }

    imparParSort(impar);
    imparParSort(par);

    for (int i = 0; i < n / 2; ++i)
    {
        a[i] = impar[i];
        a[i + n / 2] = par[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int entrada;
    cin >> entrada;
    vector<int> a(entrada);

    for (int i = 0; i < entrada; ++i)
    {
        cin >> a[i];
    }

    imparParSort(a);

    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}