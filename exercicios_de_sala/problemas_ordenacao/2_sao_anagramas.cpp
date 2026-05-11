#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define DEBUG 1

// retorna true se s e t são anagramas. Caso contrário, retorna false.
// s e t são strings terminadas em 0.


/*
LÓGICA: strings são vetores númericos (ASCII);
1. Ordenar ambas as strings;
2. Comparar se as duas strings são iguais: for passando letra por letra e comparando-as.
*/


bool sao_anagramas(string& s, string& t){
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    // PODERIA SIMPLESMENTE SER return "s == t" no lugar do if -> comparador já retorna booleano

    if (size(s) != size(t)){
        return false;
    } 
    
    else{
        for (int i = 0; i < size(s); i++){
            if (s[i] != t[i]){
                return false;
            }
        }

        return true;
    }
    
}

int main(int argc, char** argv){

    string s1(argv[1]);
    string s2(argv[2]);

    #if DEBUG
    cout << sao_anagramas(s1, s2) << "\n";
    #endif
    
    return EXIT_SUCCESS;
}