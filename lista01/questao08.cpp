#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long Minimo(vector<int> &palitos)
{
    sort(palitos.begin(), palitos.end());
    int n = palitos.size();
    int median = palitos[n / 2];
    long long total = 0;
    for (int length : palitos)
    {
        total += abs(length - median);
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    int entrada;
    cin >> entrada;
    vector<int> palitos;
    palitos.resize(entrada);
    for (int i = 0; i < entrada; i++)
    {
        cin >> palitos[i];
    }
    cout << Minimo(palitos) << '\n';
    return 0;
}
