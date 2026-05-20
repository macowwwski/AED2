#pragma once

#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class TabHashEndAberto {
public:
    //Construtor: inicializa uma nova tabela com tamanho m
    TabHashEndAberto(int tamanho){
        this->m = tamanho;
        this->n = 0;
        this-> invalido;
        this->tabela = new Elemento[this->m];
        for (int i = 0; i < this->m; i++){
            this->tabela[i].estado = Estado::LIVRE;
        }
    }

    //Destrutor: libera todos os recursos alocados para a tabela
    ~TabHashEndAberto(){
        delete[] this->tabela;
    }
    
    //Insere um novo par (chave, valor) na tabela
    void inserir(int chave, int valor){
        int pos = buscar_pos(chave);

        if(pos >= 0){   // Chave já está na tabela
            this->tabela[pos].valor = valor;    // Atualiza valor
            return;
        }
        // chave ainda não está na tabela
        int k = 0;
        int h = hash(chave, k);
        while(this->tabela[h].estado == Estado::OCUPADO){
            k++;
            if (k == this->m){
                return;
            }
            h = hash(chave, k);
        }
        this->tabela[h].estado = Estado::OCUPADO;
        this->tabela[h].chave = chave;
        this->tabela[h].valor = valor;
        this->n++;
    }
    
    //Remove o par com a chave da tabela
    void remover(int chave){
        int pos = buscar_pos(chave);
        if(pos >= 0){
            this->tabela[pos].estado = Estado::APAGADO;
            this->n--;
        }
    }
    
    //Busca o valor associado a chave na tabela
    std::pair<int,int> buscar(int chave){
        int pos = buscar_pos(chave);
        if(pos >= 0){
            return {this->tabela[pos].chave,
                this->tabela[pos].valor};
        } else{
            return invalido;
        }
    }
    
    //Imprime a tabela
    void imprimir(){
        for (int i = 0; i < this->m; i++) {
            std::cout << i << ": ";
            const auto& el = this->tabela[i];
            std::cout << "(" << el.chave << "," << el.valor << ") ";
            char estado = el.estado == Estado::APAGADO ? 'A' :
                        (el.estado == Estado::LIVRE ? 'L' : 'O');
            std::cout << "[" << estado << "]";
            std::cout << std::endl;
        }    
    }

    //Imprime informações sobre a tabela (m, n e fator de carga)
    void imprimir_info()
    {
        std::cout << "m: " << this->m << std::endl;
        std::cout << "n: " << this->n << std::endl;
        std::cout << "fator de carga: " << (float)this->n/this->m << std::endl;
        std::cout << "redimensionamentos: " << this->redims << std::endl;
    }

    //par chave-valor inválido para indicar que a chave não foi encontrada
    std::pair<int,int> invalido;

    // retorna as chaves da tabela
    std::vector<int> chaves();

    // retorna todos os pares (chave, valor) da tabela
    std::vector<std::pair<int,int>> itens();

private:

    enum class Estado {
        LIVRE,
        OCUPADO,
        APAGADO
    };

    struct Elemento {
    public:
        int chave;
        int valor;
        Estado estado;
    };

    int m; // tamanho da tabela
    int n; // número de elementos na tabela
    // limiar para redimensionamento. quando n/m > limiar, redimensionar
    float limiar; 
    int redims; // número de redimensionamentos realizados

    Elemento *tabela; // tabela hash

    int hash(int chave, int k){ //função hash
        return ((chave % this->m) + k) % this->m;
    }

    // redimensiona a tabela para o novo tamanho (novo_m)
    void redimensionar(int novo_m); 

    //retorna a posição que a chave ocupa na tabela. 
    //(ou -1 se a chave não estiver na tabela)
    int buscar_pos(int chave){
        int k = 0;
        int h = hash(chave, k);

        while (this->tabela[h].estado != Estado::LIVRE){ // A busca continua enquanto o estado não é livre
            if ((this->tabela[h].estado == Estado::OCUPADO)
            && (this->tabela[h].chave == chave)){       // Se estiver ocupado e tiver a mesma chave buscada, então encontrou
                return h;
            }

            k++;    // Próxima tentativa
            if (k == this->m){  // Percorreu todas as posições da tabela
                break;
            }

            h = hash(chave, k);
        }
        return -1;  // Não encontrou
    }
    
};