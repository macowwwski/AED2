#include <iostream>
#include <vector> // é o template para a estrutura de lista

using namespace std;

vector <int> coletor_pares (const vector<int> &v){
    /* A função deve percorrer uma lista, verificar quais números são pares
    e criar uma nova lista com eles, que deverá ser retornada. */

    vector <int> P; // nova lista
    
    for (int x : v){ // para cada elemento na lista v (sem se importar com índice):
        if (x % 2 == 0){
        P.push_back(x); // adiciona o elemento na lista P
        }
    }
    return P;

}

int main(){
    vector <int> v = {1,2,0,7,9,4,6,5};
    vector <int> z = coletor_pares(v);
    for(int x : z){
        cout << x << ", ";
    }
    cout << "\n";
}