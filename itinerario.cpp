#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<pair<string,string>>
reconstruir_itinerario(const vector<pair<string,string>>& passagens){
    unordered_map<string,string> d_passagens;
    unordered_set<string> origens;
    unordered_set<string> destinos;

    //Construir o dicionário de passagens,
    //e os conjuntos de origem e destino
    //for(const pair<string,string>& passagem : passagens)
    for(const auto& passagem : passagens){
        origens.insert(passagem.first);
        destinos.insert(passagem.second);
        d_passagens.insert({passagem.first, passagem.second});
    }

    string partida;
    //Encontrar o ponto de partida.
    //O ponto de partida é uma origem que não é destino.
    for(const string& origem : origens){
        if(destinos.find(origem) == destinos.end()){
            partida = origem;
            break;
        }
    }

    //Percorrer o dicionário a partir do ponto de partida
    vector<pair<string,string>> itinerario;
    while(d_passagens.find(partida) != d_passagens.end()){
        string destino_atual = d_passagens[partida];
        itinerario.push_back({partida, destino_atual});
        partida = destino_atual;
    }
    return itinerario;
}

int main(){
    vector<pair<string,string>> passagens = {
        {"X","Z"},
        {"K","X"},
        {"Z","Y"},
        {"W","K"},
        {"Y","M"}
    };

    auto itinerario = reconstruir_itinerario(passagens);

    for(auto& trecho : itinerario){
        cout << trecho.first << " -> " << trecho.second << endl;
    }
    
    return 0;
}