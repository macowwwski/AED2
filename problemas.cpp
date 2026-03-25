// ENUNCIADO ESTÁ NO CADERNO. PROBLEMA 1.

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

// --------------- AUXILIARES ---------------

std::vector<int> gerar_vetor_aleatorio(int n, int seed, int max){
    std::vector<int> v;
    v.reserve(n);
    srand(seed);
    for(int i = 0; i < n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

void imprimir_vetor(vector<int>& v){
    for (int x : v){
        cout << x << ", ";
    }
    cout << "\n";
}


// --------------- PRINCIPAL ---------------

vector <int> remover_duplicatas(vector<int>& v){
    vector<int> S;  // novo vetor para a saída

    if (v.size() == 0){
        return S;   // se a lista estiver vazia, já retorna
    }

    else {
        sort(v.begin(), v.end());   // ordenação

        S.push_back(v[0]);      // insere o primeiro elemento de v no final de S
        int ultimoS = v[0];     // guarda esse mesmo valor como sendo o último de S

        for (int i = 1; i < v.size(); i++){     // começa no v[1] porque o v[0] já foi colocado em S[0]
            if (v[i] != ultimoS){               // se o valor da posição atual (x) de v é diferente ao último valor em S:
                S.push_back(v[i]);      // coloca o x na lista de saída  
                ultimoS = v[i];         // seta o x como último 
            }
        }
        return S;
    }
}

int main(int argc, char** argv){
    int n = std::atoi(argv[1]);
    std::vector<int> v = gerar_vetor_aleatorio(n, 99, n * 10);
    std::vector<int> s = remover_duplicatas(v);
    imprimir_vetor(v);
    imprimir_vetor(s);
    std::cout << v.size() << " " << s.size() << "\n";
    
    // std::vector<int> v = {5, 2, 1, 2, 4, 5, 0, 1};
    // std::vector<int> s = remover_duplicatas(v);
    // imprimir_vetor(v);
    // imprimir_vetor(s);
}
