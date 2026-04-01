#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// NESSA FUNÇÃO JÁ SE SABE PREVIAMENTE QUE HÁ SUBVESTORES ORDENADOS DENTRO DO VETOR INICIAL

void merge(vector<int> &v, int p, int q, int r){
    //alocar E com n1 elementos(p...q)
    int n1 = q-p+1;
    vector<int> E;
    E.reserve(n1);

    //alocar D com n2 elementos(q+1...r)
    int n2 = r-1;
    vector<int> D;
    D.reserve(n2);

    //preencher E com V[p...q]
    for (int i = p; i <= q; i++)
        E.push_back(v[i]);      // se tiver só uma linha no corpo do for, não precisa de chaves
    

    //preencher D com V[q+1...r]
    for (int i = q+1; i <= r; i++)
        D.push_back(v[i]); 
    

    int k = p, i = 0, j = 0;

    while( (i<n1) && (j<n2) ){
        if (E[i] < D[j]){
            v[k] = E[i];
            i++;
        }
        else {
            v[k] = D[j];
            j++;
        }

        k++;
    }


// Só um dos whiles vai rodar
    while (i < n1){     // D esgotou e E ainda não esgotou ao final do primeiro while, então cola E ao final de V
        v[k] =  E[i];
        i++;
        k++;
    }
    
    while (j < n2) {  // E esgotou e D ainda não esgotou, colar D
        v[k] = D[j];
        j++;
        k++;
    }
}