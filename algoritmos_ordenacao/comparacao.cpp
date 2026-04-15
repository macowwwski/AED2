#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

void trocar(int& a, int& b){
    int aux = a;
    a = b;
    b = aux;
}

void selection_sort(vector<int>& v){
    int n = v.size();
    for(int i = n-1; i > 0; i--){
        int maior = 0;
        for(int j = 1; j <= i; j++){
            if(v[j] > v[maior]){
                maior = j;
            }
        }
        trocar(v[i], v[maior]);
    }
}

std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    std::vector<int> v;
    v.reserve(n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

void merge(vector<int>& v, int p, int q, int r){
    //alocar E com n1 elementos (p..q)
    int n1 = q-p+1;
    vector<int> E;
    E.reserve(n1);
    
    //alocar D com n2 elementos (q+1..r)
    int n2 = r-q;
    vector<int> D;
    D.reserve(n2);

    //preencher E com V[p..q]
    for(int i = p; i <= q; i++)
        E.push_back(v[i]);
    
    //preencher D com v[q+1..r]
    for(int i = q+1; i <=r; i++)
        D.push_back(v[i]);
    
    int k = p, i = 0, j = 0;

    while( (i<n1) && (j<n2) ){
        if(E[i] < D[j]){
            v[k] = E[i];
            i++;
        }
        else{
            v[k] = D[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        v[k] = E[i];
        i++;
        k++;
    }
    while(j < n2){
        v[k] = D[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int>& V, int e, int d){
    if(e < d){
        int m = (e+d)/2;
        MergeSort(V, e, m);
        MergeSort(V, m+1, d);
        merge(V, e, m, d);
    }
}

void MergeSort(vector<int>& v){
    MergeSort(v, 0, v.size()-1);
}

int partition(vector<int>& v, int p, int r){
    int x = v[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(v[j] < x){
            i++;
            trocar(v[i], v[j]);
        }
    }
    return i+1;
}
void QuickSort(vector<int>& v, int e, int d){
    if(e<d){
        int q = partition(v, e, d);
        QuickSort(v, e, q-1);
        QuickSort(v, q+1, d);
    }
}
void QuickSort(vector<int>& v){
    QuickSort(v, 0, v.size()-1);
}

int main(int argc, char** argv){
    int n = atoi(argv[1]);
    string algoritmo(argv[2]);

    vector<int> v = gerar_vetor_aleatorio(n, 99, n * 100);

    if(algoritmo == "selection")
        selection_sort(v);
    if(algoritmo == "merge")
        MergeSort(v);
    if(algoritmo == "quick")
        QuickSort(v);
    
    return 0;
}


