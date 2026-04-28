#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void trocar(int& a, int& b){
    int aux = a;
    a = b;
    b = aux;
}

void trocar(int *v, int p1, int p2){
    int temp = v[p1];
    v[p1] = v[p2];
    v[p2] = temp;
}

void max_heapify(vector<int>& v, int i, int limite){
    int e = 2*i+1; // salva as posições dos filhos
    int d = e + 1;
    int maior;

    if ((e < limite) && (v[e] > v[i])){ // usa limite para não haver acesso inválido
        maior = e;
    } else {
        maior = i;
    } if ((d < limite) && (v[d] > v[maior])){
        maior = d;
    }
    if (maior != i){
        trocar(v[i], v[maior]);
        max_heapify(v, maior, limite);
    }
}

void build_max_heap(vector<int>& v){
    const int n = v.size();
    for (int i = n/2; i >= 0; i--){
        max_heapify(v, i, n);
    }
}

void HeapSort(vector<int> &v){
    build_max_heap(v);
    for (int i = v.size()-1; i > 0; i--){
        trocar(v[0], v[i]);
        max_heapify(v, 0, i);
    }
}