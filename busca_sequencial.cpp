#include "algoritmos_busca.h"
#include <string>
#include <vector>

//criamos a classe concreta que implementa a busca sequencial, puxamos a interface AlgoritmoBusca e tornamos ela publica para que os métodos possam ser acessados
class BuscaSequencial : public AlgoritmoBusca {
public:
    // Implementamos o metodo nome, que retorna o nome do algoritmo, e esse override pra garantir que estamos sobrescrevendo algo da classe base
    std::string nome() const override {
        return "Busca Sequencial";
    }
    
    // Aqui é a implementação da busca sequencial
    //esse const override nos garente que o objeto não vai ser modificado, e também sobrescreve o método da classe base      
    int buscar(const std::vector<int>& dados, int chave) const override {
        for (size_t i = 0; i < dados.size(); ++i)
        {
            if (dados[i] == chave) {
                return static_cast<int>(i); // Retorna o índice se encontrou
            }
        }
        return -1; // Retorna -1 se não encontrou
    }

}; 

// Fábrica para criar instâncias da BuscaSequencial, retornando um ponteiro para a interface
std::unique_ptr<AlgoritmoBusca> criar_busca_sequencial() {
    return std::make_unique<BuscaSequencial>();
}