#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Dado um vetor de inteiros não-negativos v, retorne um par de inteiros 
//cuja diferença é a menor possível dentre todas as diferenças possíveis
//entre dois elementos do vetor.
//Exemplo: v = {10, 14, 4, 7}
//menor_diferenca(v) = {4, 7}
//O vetor de entrada não deve ser modificado.


pair<int,int> menor_diferenca_minha_versao(vector<int> &v){  //pair é uma classe que guarda 2 valores - tupla de 2 valores 
    
    vector<int> v2(v); // cópia de vetores de jeito fácil

    sort(v2.begin(), v2.end());

    pair<int,int> par_menor_dif = {v2[0], v2[1]}; // inicializa o par menor partindo dos dois primeiros elementos
    int valor_menor_dif = v2[1] - v2[0];    // inicializa a menor diferença partindo dos dois primeiros elementos

    if (size(v2) < 2 ){
        return {0, 0};
    } 
    
    else {
        for (int i = 1; i < size(v2)-1; i++){   // i inicia em 1 para testar a partir do segundo par
            int valor_dif = v2[i+1] - v2[i];
            if (valor_dif < valor_menor_dif){
                valor_menor_dif = valor_dif;
                par_menor_dif = {v2[i], v2[i+1]};
            }
        }
        return par_menor_dif;
    }
}

pair<int,int> menor_diferenca(vector<int> &v){   
    
    vector<int> v2(v); 

    sort(v2.begin(), v2.end());

    pair<int,int> p = {v2[0], v2[1]}; 
    int dif = v2[1] - v2[0];

    for (int i = 1; i < v2.size()-1; i++){
        int dif_atual = v2[i+1] - v2[i];
        if (dif_atual < dif){
            p = {v2[i], v2[i+1]};
            dif = dif_atual;
        }
    }

    return p;

}


int main(){
    vector<int> v = {9, 14, 4, 7, 32, 43, 98, 47, 1, 2};

    pair<int,int> res = menor_diferenca_minha_versao(v);

    cout << res.first << " " << res.second << "\n";

    return EXIT_SUCCESS;
}