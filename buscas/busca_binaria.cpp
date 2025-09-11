#include "algoritmos_busca.h"
#include <string>
#include <vector>


// criamos a classe concreta que implementa a busca binária, puxamos a interface AlgoritmoBusca e tornamos ela publica para que os métodos possam ser acessados
class BuscaBinaria : public AlgoritmoBusca {
public:
    std::string nome() const override {
        return "Busca Binária";
    }

    int buscar(const std::vector<int>& dados, int chave) const override {
        int esquerda = 0;
        int direita = static_cast<int>(dados.size()) - 1;

        while (esquerda <= direita) {
            int meio = esquerda + (direita - esquerda) / 2;

            if (dados[meio] == chave) {
                return meio; // Retorna o índice se encontrou
            }
            else if (dados[meio] < chave) {
                esquerda = meio + 1; // Busca na metade para a direita
            }
            else {
                direita = meio - 1; // Busca na metade para a esquerda
            }
        }
        return -1; // Retorna -1 se não encontrou
    }

};

// Fábrica para criar instâncias da BuscaBinaria, retornando um ponteiro para a interface
std::unique_ptr<AlgoritmoBusca> criar_busca_binaria() {
    return std::make_unique<BuscaBinaria>();
}

