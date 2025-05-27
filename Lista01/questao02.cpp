#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minGondolas(vector<int> &peso, int x)
{
    sort(peso.begin(), peso.end());
    int i = 0;
    int j = peso.size() - 1;
    int gondolas = 0;

    while (i <= j)
    {
        if (peso[i] + peso[j] <= x)
        {
            i++;
        }
        j--;
        gondolas++;
    }
    return gondolas;
}

int main()
{
    ios::sync_with_stdio(false);
    int entrada, limite;
    cin >> entrada >> limite;
    vector<int> peso(entrada);
    for (int i = 0; i < entrada; ++i)
    {
        cin >> peso[i];
    }

    cout << minGondolas(peso, limite) << endl;
    return 0;
}
