#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Curso {
    int prazo;
    int valor;
};

bool comparaPrazo(const Curso &a, const Curso &b) {
    return a.prazo < b.prazo;
}

int main() {
    int cursos, semanas;
    cin >> cursos >> semanas;

    vector<Curso> lista(cursos);
    for (int i = 0; i < cursos; ++i) {
        cin >> lista[i].prazo >> lista[i].valor;
    }

    sort(lista.begin(), lista.end(), comparaPrazo);
    vector<bool> semanaOcupada(semanas + 1, false); 

    int totalConhecimento = 0;

    for (const auto &curso : lista) {
        for (int semana = curso.prazo; semana >= 1; --semana) {
            if (!semanaOcupada[semana]) {
                semanaOcupada[semana] = true;
                totalConhecimento += curso.valor;
                break;
            }
        }
    }

    cout << totalConhecimento << "\n";
    return 0;
}