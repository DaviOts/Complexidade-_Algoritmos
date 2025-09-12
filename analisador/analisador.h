#pragma once

#include <vector>
#include <string>

class AlgoritmosOrdenacao;
class AlgoritmoBusca;

//classe para encapsular toda a lógica de análise
class Analisador{
public:

    //construtor para receber os parâmetros de análise
    Analisador(const std::vector<int>& tamanhos, int repeticoes, const std::string& arquivo_saida);

    //metodo para executar análise
    void executar();

private:
    
    //funções auxiliares main
    std::vector<int> gerar_dados(int tamanho);
    double medir_tempo_ordenacao(AlgoritmosOrdenacao* algoritmo, const std::vector<int>& dados, int repeticoes);
    double medir_tempo_busca(AlgoritmoBusca* algoritmo, const std::vector<int>& dados, int chave, int repeticoes);

    //configurações da análise
    std::vector<int> tamanhos_n;
    int num_repeticoes;
    std::string nome_arquivo_saida;

};

