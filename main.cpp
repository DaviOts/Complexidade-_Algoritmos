#include "analisador/analisador.h"
#include <vector>
#include <string>  



int main() {
      //configurações para a análise
      const std::vector<int> tamanhos = {100, 500, 1000, 2500, 5000, 10000, 20000}; //diferentes tamanhos de entrada para testar

      const int repeticoes = 10; //número de execuções para cada

      const std::string arquivo_saida = "resultados_analise.csv";

      Analisador analisador(tamanhos_n, repeticoes, arquivo_saida);

      analisador.executar();

      return 0;
}
