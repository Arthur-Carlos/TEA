#include <cstdio>
#include <string>
#include <bits/stdc++.h>

using namespace std;
string str;
int esq, dir;
int contador = 0;

void checaPalindromoGul(string str)
{
    dir = str.size() - 1;
    while (esq < dir)
    {
        if (str[esq] != str[dir])
        {
            contador++;
        }
        esq++;
        dir--;
    }
    cout << contador << endl;
}

int main()
{
    cin >> str;
    checaPalindromoGul(str);
    return 0;
}