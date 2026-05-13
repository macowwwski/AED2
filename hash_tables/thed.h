#pragma once

#include <vector>
#include <utility>


using namespace std;

class TabHashEncadeamento {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEncadeamento(int tamanho){
        this->m = tamanho;
        this->n = 0;
        tabela = new vector<pair<int,int>>[this->m]; // alocando a tabela
        this->invalido = {-1, -1}; // para casos em que não se encontra o valor buscado
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEncadeamento(){
        delete[] tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor){
        auto& par = this->buscar(chave);

        if (par != this->invalido){
            // chave já está na tabela
            par.second = valor; // atualiza o valor (contador)
            return;
        }

        else {
            int h = this->hash(chave);
            this->tabela[h].push_back({chave, valor}); // na posição h, entra na lista e coloca o novo par na última posição (push_back)
            this->n++;
        }
    }
    
    //Remove o par com a chave da tabeka
    void remover(int chave);
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int>& buscar(int chave){
        int h = this->hash(chave); // descobre em qual lista (posição) a chave está

        for(auto& par : tabela[h]){ // h faz com que se pegue apenas uma linha
            if (par.first == chave){
                return par;
            }
        }
        // se não encontrar o valor, precisa avisar, mas como se trata de uma referência, não se pode retornar nullptr.
        return this->invalido;

    }
    
    //Imprime a tabela
    void imprimir();

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info();

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido;

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,int>> itens();

private:
    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    int limiar; 
    int redims; // número de redimensionamentos realizados

    std::vector<std::pair<int,int>> *tabela; // tabela -> vector dinâmico (ponteiro) para uma lista de vectors (posições) que armazenam pares de inteiros.
    int hash(int chave){ // função hash
        return chave % this->m;
    } 

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m); 
    
};