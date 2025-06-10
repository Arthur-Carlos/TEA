#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int especimes, qtdCamaras, total[10], contador = 1;
    while (cin >> qtdCamaras)
    {
        scanf("%d", &especimes);
        double soma = 0, imbalance = 0;
        for (int i = 0; i < especimes; i++)
        {
            scanf("%d", &total[i]);
            soma += total[i];
        }
        for (int j = especimes; j < 2 * qtdCamaras; j++)
        {
            total[j] = 0;
        }
        sort(total, total + 2 * qtdCamaras);

        soma = soma / qtdCamaras;
        printf("Set #%d\n", contador++);
        for (int i = 0; i < qtdCamaras; i++)
        {
            printf(" %d:", i);
            if (total[i])
            {
                printf(" %d ", total[i]);
            }
            if (total[2 * qtdCamaras - i - 1])
            {
                printf(" %d", total[2 * qtdCamaras - i - 1]);
            }
            printf("\n");
            imbalance += abs(soma - (total[i] + total[2 * qtdCamaras - i - 1]));
        }
        printf("IMBALANCE = %.5lf\n\n", imbalance);
    }
    return 0;
}