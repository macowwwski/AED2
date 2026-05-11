#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Gato{
public:
    Gato(string n, int i){ // declara a estrutura
        nome = n;
        idade = i;
    }

    bool operator==(const Gato& ld) const{ // sobreposição de operadores: define o que dois gatos precisam ter igual para serem iguais
        return (this->nome == ld.nome)
            && (this->idade == ld.idade);
    }

    string nome;
    int idade;
};

template <typename T>
int buscar(const vector<T>& v, T x){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == x){
            return i;
        }
    }
    return -1;
}

int main(){
    // vector<int> v = {3, 1, 6, 2, 4, 0};
    // int x = 9;
    // vector<float> v = {3.4, 1.2, 99.5, 1.3};
    // float x = 1.3;

    vector<Gato> v;
    v.push_back(Gato("Salem", 1));
    v.push_back(Gato("Tom", 3));
    v.push_back(Gato("Shitara", 8));
    v.push_back(Gato("Jerry", 6));

    Gato x = Gato("Shitara", 8);

    cout << buscar(v, x) << "\n";
}