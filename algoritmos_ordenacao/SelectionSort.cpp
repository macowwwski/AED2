#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
------------------ AUXILIARES ------------------
*/

int maior_pos(const vector <int> &v, int ini, int fim){
    int maior = ini;
    for (int i = ini+1; i <= fim; i++){
        if (v[i] > v[maior]){
            maior = i;
        }
    }
    return maior;
}