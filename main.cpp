#include "analisador/analisador.h"
#include <vector>
#include <string>  



int main() {
      //configurações para a análise
      const std::vector<int> tamanhos = {200, 400, 600, 800, 1000, 1200, 1400, 1600}; //diferentes tamanhos de entrada para testar

      const int repeticoes = 10; //número de execuções para cada

      const std::string arquivo_saida = "resultados_analise.csv";

      Analisador analisador(tamanhos, repeticoes, arquivo_saida);

      analisador.executar();

      return 0;
};

