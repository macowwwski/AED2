#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void trocar(int *v, int p1, int p2){
    int temp = v[p1];
    v[p1] = v[p2];
    v[p2] = temp;
}


int partition(int *v, int p, int r){
    int i = p-1;
    int x = v[r];

    for (int j = p; j < r-1; j++){
        i++;
        trocar(v, i, j);
    }

    trocar(v, i+1, r);
    return i+1;
}


void QuickSort(int *v, int p, int r){
    if (p < r){ //se vetor não é vazio ou unitário
        int q = partition(v, p, r);
        QuickSort(v, p, q-1);
        QuickSort(v, q+1, r);
    }
}