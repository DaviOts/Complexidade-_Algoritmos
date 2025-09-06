#pragma once // uma forma mais moderna do ifndef/define/endif e evita erros definição múltipla

#include <vector>
#include <string>
#include <memory>

// Interface base para algoritmos de busca
class AlgoritmoBusca {
public:
    virtual ~AlgoritmoBusca() = default; // destrutor virtual padrão, ele é chamado quando um objeto é destruído
    virtual std::string nome() const = 0; // retorna o nome do algoritmo de busca
    virtual int buscar(const std::vector<int>& dados, int chave) const = 0; // executa a busca e retorna o índice ou -1 se não for encontrado
};

// Fábricas para criar instâncias concretas de algoritmos
std::unique_ptr<AlgoritmoBusca> criar_busca_sequencial();
std::unique_ptr<AlgoritmoBusca> criar_busca_binaria();

// Com essas fábricas, fica mais fácil adicionar novos algoritmos no futuro sem modificar o código existente. Pois o main, por exemplo, só interage com a interface AlgoritmoBusca, não com as implementações concretas.
