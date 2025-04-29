#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void somaDeQuatro(vector<int> &arr, int X, int N)
{
    vector<vector<int>> vetor(N, vector<int>(2));

    for (int i = 0; i < N; i++)
    {
        vetor[i][0] = arr[i];
        vetor[i][1] = i + 1;
    }
    sort(vetor.begin(), vetor.end());
    for (int ptr1 = 0; ptr1 < N - 3; ptr1++)
    {
        for (int ptr2 = ptr1 + 1; ptr2 < N - 2; ptr2++)
        {
            int ptr3 = ptr2 + 1;
            int ptr4 = N - 1;
            while (ptr3 < ptr4)
            {
                int currentSum = vetor[ptr1][0] + vetor[ptr2][0] + vetor[ptr3][0] + vetor[ptr4][0];
                if (currentSum == X)
                {
                    cout << vetor[ptr1][1] << " " << vetor[ptr2][1] << " " << vetor[ptr3][1] << " " << vetor[ptr4][1] << "\n";
                    return;
                }
                else if (currentSum > X)
                {
                    ptr4--;
                }
                else if (currentSum < X)
                {
                    ptr3++;
                }
            }
        }
    }
    cout << "-1";
}

int main()
{
    ios::sync_with_stdio(false);
    int N, X;
    cin >> N >> X;
    vector<int> arr;
    arr.resize(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    somaDeQuatro(arr, X, N);
    return 0;
}
