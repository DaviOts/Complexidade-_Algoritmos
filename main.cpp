#include "algoritmos_busca.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    // Dados de exemplo so para a busca binária funcionar, pois a gente precisa de um vetor ordenado
    std::vector<int> dados = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int chave = 7;

    // Criamos as instâncias dos algoritmos de busca usando as fábricas
    std::unique_ptr<AlgoritmoBusca> busca_sequencial = criar_busca_sequencial();
    std::unique_ptr<AlgoritmoBusca> busca_binaria = criar_busca_binaria();

    // Executa a busca sequencial
    int indice_sequencial = busca_sequencial->buscar(dados, chave);
    if (indice_sequencial != -1) {
        std::cout << busca_sequencial->nome() << ": Chave " << chave << " foi encontrada no índice: " << indice_sequencial << std::endl;
    } else {
        std::cout << busca_sequencial->nome() << ": Chave " << chave << " Não foi encontrada" << std::endl;
    }

    // Executa a busca binária
    int indice_binaria = busca_binaria->buscar(dados, chave);
    if (indice_binaria != -1) {
        std::cout << busca_binaria->nome() << ": Chave " << chave << " Foi encontrada no índice: " << indice_binaria << std::endl;
    } else {
        std::cout << busca_binaria->nome() << ": Chave " << chave << " Não foi encontrada" << std::endl;
    }

    return 0;
}