#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int entrada;
    cin >> entrada;
    vector<int> palito(entrada);
    for (int i = 0; i < entrada; ++i)
    {
        cin >> palito[i];
    }
    sort(palito.begin(), palito.end());
    int median = palito[entrada / 2];
    float cost = 0;
    for (int i = 0; i < entrada; ++i)
    {
        cost += abs(palito[i] - median);
    }
    cout << cost << "\n";
    return 0;
}
