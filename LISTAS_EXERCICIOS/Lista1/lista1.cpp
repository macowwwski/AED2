#include <vector>
#include <iostream>

using namespace std;

// 1) Implemente a função max usada no algoritmo de ordenação por seleção
int max (const vector<int>& v, int pos_ini, int pos_final){
    int pos_maior = pos_ini; 
                     
    for (int i = pos_ini + 1; i <= pos_final; i++){
        if (v[i] > v[pos_maior]){                                                   
            pos_maior = i;
        }
    }

    return pos_maior;
}


// 2) Implemente a função troca usada nos algoritmos de ordenação por seleção e bolha 
void trocar (vector<int>& v, int pos1, int pos2){
    int aux; 
    aux = v[pos1];
    v[pos1] = v[pos2];
    v[pos2] = aux;
}


/* 3) Reescreva o algoritmo de ordenação por seleção apresentado no Vídeo 1 de tal forma que ordene 
o vetor escolhendo os menores elementos ao invés dos maiores. */
int min (const vector<int>& v, int pos_inicial, int pos_final){
    int pos_menor = pos_inicial; 
                     
    for (int i = pos_inicial + 1; i <= pos_final; i++){
        if (v[i] < v[pos_menor]){                                                   
            pos_menor = i;
        }
    }

    return pos_menor;
}


void Selection_Sort_Menores(vector<int>& v){
    int n = v.size();

    for (int i = 0; i < n - 1; i++){        // busca o menor entre i e n-1 porque o último valor já estará certo
        int menor = min(v, i, n-1);     // troca o menor encontrado com i
        trocar(v, menor, i);
    }
}

// 5) Altere o algoritmo de ordenação por seleção de forma que os vetores resultantes estejam ordenados em ordem decrescente. 
void Selection_Sort_Decrescente(vector<int>& v, int n){

    for (int i = 0; i < n-1; i++){
        int maior_pos = max(v, i, n-1);
        trocar(v, maior_pos, i);
    }
}

void Selection_Sort(vector<int>& v, int n){

    for (int i = n-1; i > 0; i--){  //posição final do vetor, vai decrescendo
        int maior_pos = max(v, 0, i);
        trocar(v, maior_pos, i);
    }
}
/*
    v = {3, 9, 0, 2}
    n = 4

    0 < 4 
    maior_pos = max(0, 3) = 1  (valor 9)
    trocar(1, 0) -> {9, 3, 0, 2}

    1 < 4
    maior_pos = max(1, 3) = 1  (valor 3)
    trocar(1, 1) -> {9, 3, 0, 2}

    2 < 4
    maior_pos = max(2, 3) = 3  (valor 2)
    trocar(3, 2) -> {9, 3, 2, 0}

    3 < 4 (INÚTIL, trocar para n-1 no laço)
    maior_pos = max(3, 3) = 1  (valor 3)
    trocar(1, 1) -> {9, 3, 0, 2}
*/



int main(){
    vector<int> vec = {10, 8, 3, 6, 0, 11};
    Selection_Sort(vec, 6);

    for (int i = 0; i < vec.size(); i++){
        cout << vec[i] << " "; 
    }
}