#include "buscas/algoritmos_busca.h"
#include "ordenacao/algoritmos_ordenacao.h"
#include "analisador/analisador.h"
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>
#include <fstream>
#include <random>
#include <algorithm>
#include <numeric>

    // função auxiliar para gerar dados aleatórios   






int main() {
      //configurações para a análise
      const std::vector<int> tamanhos = {100, 500, 1000, 5000, 10000, 50000, 100000}; //diferentes tamanhos de entrada para testar
      const int repeticoes = 10; //número de execuções para cada

    // Executa a busca sequencial
    // Esse auto substitui o "std::unique_ptr", ele ja pede pro compilador preencher esse tipo, sem eu precisar explicita-lo
    auto busca_sequencial = criar_busca_sequencial();

    // Marcamos o tempo antes da busca sequencial
    auto inicio_sequencial = std::chrono::high_resolution_clock::now();
    int indice_sequencial_timed = busca_sequencial->buscar(dados, chave);
    auto fim_sequencial = std::chrono::high_resolution_clock::now();
    // Calculamos a diferença de tempo
    std::chrono::duration<double, std::milli> tempo_seq = fim_sequencial - inicio_sequencial;

    // Exibindo os resultados da busca sequencial
    std::cout << "Algoritmo: " << busca_sequencial->nome() << "\n";
    std::cout << "Chave buscada: " << chave << "\n";
    int indice_sequencial = busca_sequencial->buscar(dados, chave);
    std::cout << "Resultado: " << (indice_sequencial != -1 ? "encontrado no índice " + std::to_string(indice_sequencial) : "não encontrado") 
              << " | Tempo: " << tempo_seq.count() << " ms\n\n";


    // ORDENAÇÃO + BUSCA BINÁRIA

    // Cópia dos dados para o InsertionSort
    auto dados_insertion = dados;
    auto insertion = criar_insertion_sort();

    // Marcamos o tempo antes da ordenação por InsertionSort
    auto inicio_insertion = std::chrono::high_resolution_clock::now();
    insertion->ordenar(dados_insertion);
    auto fim_insertion = std::chrono::high_resolution_clock::now();
    // Calculamos o tempo de execução do InsertionSort
    std::chrono::duration<double, std::milli> tempo_insertion = fim_insertion - inicio_insertion;


    // Cópia dos dados para o MergeSort
    auto dados_merge = dados;
    auto merge = criar_merge_sort();

    // Marcamos o tempo antes da ordenação por MergeSort
    auto inicio_merge = std::chrono::high_resolution_clock::now();
    merge->ordenar(dados_merge);
    auto fim_merge = std::chrono::high_resolution_clock::now();
    // Calculamos o tempo de execução do MergeSort
    std::chrono::duration<double, std::milli> tempo_merge = fim_merge - inicio_merge;


    // Busca Binária (rodando em cima do vetor ordenado pelo MergeSort)
    auto busca_binaria = criar_busca_binaria();

    // Marcamos o tempo antes da busca binária
    auto inicio_binaria = std::chrono::high_resolution_clock::now();
    int indice_binaria_timed = busca_binaria->buscar(dados_merge, chave);
    auto fim_binaria = std::chrono::high_resolution_clock::now();
    // Calculamos o tempo de execução da busca binária
    std::chrono::duration<double, std::milli> tempo_bin = fim_binaria - inicio_binaria;

    // Exibindo os resultados da busca binária
    std::cout << "Algoritmo: " << busca_binaria->nome() << " (dados ordenados com MergeSort)\n";
    std::cout << "Chave buscada: " << chave << "\n";
    int indice_binaria = busca_binaria->buscar(dados_merge, chave);
    std::cout << "Resultado: " 
              << (indice_binaria != -1 ? "encontrado no índice " + std::to_string(indice_binaria) : "não encontrado") 
              << " | Tempo de ordenação (InsertionSort): " << tempo_insertion.count() << " ms"
              << " | Tempo de ordenação (MergeSort): " << tempo_merge.count() << " ms"
              << " | Tempo de busca: " << tempo_bin.count() << " ms\n\n";


    // Salvando os tempos em um arquivo CSV para depois plotar no python
    std::ofstream arquivo("tempos.csv");
    arquivo << "algoritmo,tempo(ms)\n";
    arquivo << "Busca Sequencial," << tempo_seq.count() << "\n";
    arquivo << "InsertionSort," << tempo_insertion.count() << "\n";
    arquivo << "MergeSort," << tempo_merge.count() << "\n";
    arquivo << "Busca Binária," << tempo_bin.count() << "\n";
    arquivo.close();


    return 0;
}
