#include "buscas/algoritmos_busca.h"
#include "ordenacao/algoritmos_ordenacao.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    // Dados de exemplo so para a busca binária funcionar, pois a gente precisa de um vetor ordenado
    std::vector<int> dados = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int chave = 7;

    

    // Executa a busca sequencial
    // Esse auto substitui o "std::unique_ptr", ele ja pede pro compilador preencher esse tipo, sem eu precisar explicita-lo
    auto busca_sequencial = criar_busca_sequencial();
    std::cout << "Algoritmo: " << busca_sequencial->nome() << "\n";
    std::cout << "Chave buscada: " << chave << "\n";
    int indice_sequencial = busca_sequencial->buscar(dados, chave);
    std::cout << "Resultado: " << (indice_sequencial != -1 ? "encontrado no índice " + std::to_string(indice_sequencial) : "não encontrado") << "\n";

    // Executa a busca binária
    auto busca_binaria = criar_busca_binaria();
    std::cout << "Algoritmo: " << busca_binaria->nome() << "\n";
    std::cout << "Chave buscada: " << chave << "\n";
    int indice_binaria = busca_binaria->buscar(dados, chave);
    std::cout << "Resultado: " << (indice_binaria != -1 ? "encontrado no índice " + std::to_string(indice_binaria) : "não encontrado") << "\n";

    return 0;
}