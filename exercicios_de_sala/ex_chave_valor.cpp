#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

// 1. Primeiro não repetido
int primeiro_nao_repetido(const vector <int>& v){
    unordered_map<int, int> cont;

    for(int x : v){
        if(cont.find(x) == cont.end()){     // a chave x não está na estrutura se retorna end - IF ELSE OPCIONAL
            cont.insert({x, 1});            // insere chave com valor 1 na estrutura
        }
        else{
            cont[x]++;                      // retorna uma referência do valor da chave x e permite que o valor já seja incrementado - PODERIA SER A ÚNICA LINHA DO FOR
        }                                   // sobrecarga de operador sobre o [] 
    }

    for (int i = 0; i < v.size(); i++){
        if(cont[v[i]] == 1){                // cont[v[i]] acessa o dict usando o valor de um determinado índice de v como sendo a chave
            return i;
        }
    }
    return -1;
}


int main(){
    vector<int> v = {1,2,3,2,1,3};
    int res = primeiro_nao_repetido(v);

    if(res != -1){
        cout << "O primeiro elemento que aparece só uma vez é " << v[res] << "\n";
    }
    else {
        cout << "Não há elemento que aparece uma única vez.\n";
    }
}