#include "analisador.h"
#include "../buscas/algoritmos_busca.h"
#include "../ordenacao/algoritmos_ordenacao.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <numeric>


//construtor
Analisador::Analisador(const std::vector<int>& tamanhos, int repeticoes, const std::string& arquivo_saida) : tamanhos_n(tamanhos), num_repeticoes(repeticoes), nome_arquivo_saida(arquivo_saida) {}

//método principal para a execução
void Analisador::executar(){
    std::ofstream arquivo(nome_arquivo_saida);
    arquivo << "algoritmo,tamanho_n,tempo_medio_ms\n"; //infos para o CSV


    auto insertion_sort = criar_insertion_sort();
    auto merge_sort = criar_merge_sort();
    auto busca_sequencial = criar_busca_sequencial();
    auto busca_binaria = criar_busca_binaria();

    //loop principal para cada tamanho de entrada "n"
    for(int n : tamanhos_n) {
        std::cout << "Analisando para n = " << n << "...\n";


        auto dados_originais = gerar_dados(n);
        int chave_busca = dados_originais.back(); //vai buscar o ultimo elemento para garantir que ele existe

                //analise dos algoritmos de ORDENAÇÃO

        auto dados_para_ordenar =  dados_originais;

        //insertion
        double tempo_insertion = medir_tempo_ordenacao(insertion_sort.get(), dados_para_ordenar, num_repeticoes);
        arquivo << insertion_sort->nome() << "," << n << "," << tempo_insertion << "\n";

        //merge
        double tempo_merge = medir_tempo_ordenacao(merge_sort.get(), dados_para_ordenar, num_repeticoes);
        arquivo << merge_sort->nome() << "," << n << "," << tempo_merge << "\n";



                //analise dos algoritmos de BUSCA

        auto dados_ordenados = dados_originais;
        std::sort(dados_ordenados.begin(), dados_ordenados.end()); //ordena os dados para a binaria
        
        //sequencial
        double tempo_seq = medir_tempo_busca(busca_sequencial.get(), dados_originais, chave_busca, num_repeticoes);
        arquivo << busca_sequencial->nome() << "," << n << "," << tempo_seq << "\n";

        //binaria
        double tempo_bin = medir_tempo_busca(busca_binaria.get(), dados_ordenados, chave_busca, num_repeticoes);
        arquivo << busca_binaria->nome() << "," << n << "," << tempo_bin << "\n";

    }

    arquivo.close();
    std::cout << "\nAnalise concluida! Os resultados foram salvos em '" << nome_arquivo_saida << "'\n";
}

//implementação das funções auxiliares

std::vector<int> Analisador::gerar_dados(int tamanho) {
    std::vector<int> dados(tamanho);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, tamanho * 10);
    for (int i = 0; i < tamanho; ++i) {
        dados[i] = distrib(gen);
    }
    return dados;
}

double Analisador::medir_tempo_ordenacao(AlgoritmosOrdenacao* algoritmo, const std::vector<int>& dados, int repeticoes) {
    std::vector<double> tempos;
    for (int i = 0; i < repeticoes; ++i) {
        auto dados_copia = dados; // Sempre usa uma cópia desordenada
        auto inicio = std::chrono::high_resolution_clock::now();
        algoritmo->ordenar(dados_copia);
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempo = fim - inicio;
        tempos.push_back(tempo.count());
    }
    double soma = std::accumulate(tempos.begin(), tempos.end(), 0.0);
    return soma / repeticoes;
}

double Analisador::medir_tempo_busca(AlgoritmoBusca* algoritmo, const std::vector<int>& dados, int chave, int repeticoes) {
    std::vector<double> tempos;
    for (int i = 0; i < repeticoes; ++i) {
        auto inicio = std::chrono::high_resolution_clock::now();
        algoritmo->buscar(dados, chave);
        auto fim = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> tempo = fim - inicio;
        tempos.push_back(tempo.count());
    }
    double soma = std::accumulate(tempos.begin(), tempos.end(), 0.0);
    return soma / repeticoes;
}

