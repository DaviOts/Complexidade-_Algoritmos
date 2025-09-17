# Análise Empírica de Complexidade de Algoritmos

Este projeto foi desenvolvido para a disciplina de Estruturas de Dados Básicas II (IMD0039) da UFRN, sob orientação do Prof. João Guilherme.

---

### 📋 Sumário
- [📝 Descrição do Projeto](#-descrição-do-projeto)
- [🚀 Tecnologias Utilizadas](#-tecnologias-utilizadas)
- [🏛️ Arquitetura Modular e Extensibilidade](#️-arquitetura-modular-e-extensibilidade)
- [🛠️ Como Compilar e Executar](#️-como-compilar-e-executar)
- [👨‍💻 Autor](https://github.com/DaviOts/Complexidade-_Algoritmos/edit/main/README.md#%E2%80%8D-autor)

---

## 📝 Descrição do Projeto

O objetivo deste trabalho é realizar uma análise empírica do tempo de execução de algoritmos de busca e ordenação. O programa implementado mede a performance de quatro algoritmos distintos para diferentes tamanhos de entrada (N), compara os resultados obtidos com as curvas de complexidade teóricas (Notação Big O) e gera um gráfico unificado para a visualização e análise dos dados.

## 🚀 Tecnologias Utilizadas

- **C++ (padrão C++17):** Para a implementação dos algoritmos e a medição de performance de alta precisão, utilizando a biblioteca `<chrono>`. O código foi estruturado de forma modular e orientada a objetos para facilitar a extensibilidade.
- **Python 3:** Para a análise e visualização dos dados.
  - **Pandas:** Para a manipulação dos dados exportados pelo programa em C++.
  - **Matplotlib:** Para a geração do gráfico comparativo final.
- **Make:** Para a automação do processo de compilação do projeto em C++.

## 🏛️ Arquitetura Modular e Extensibilidade

Um dos requisitos centrais do projeto foi a criação de um código modular que permitisse a fácil inclusão de novos algoritmos. A arquitetura foi desenhada utilizando o padrão de projeto **Interface** e **Fábrica (Factory)**.

Para adicionar um novo algoritmo, não é necessário alterar a lógica principal do `Analisador`. Basta seguir os passos abaixo, usando como exemplo a adição de um novo algoritmo de busca chamado `Busca de salto(JumpSearch)`:

### Passo 1: Implementar o Novo Algoritmo

Crie um novo arquivo, por exemplo, `buscas/busca_salto.cpp`. Nele, implemente a classe do algoritmo, garantindo que ela herde da interface `AlgoritmoBusca` e implemente os métodos virtuais `nome()` e `buscar()`.

```cpp
// Em buscas/busca_salto.cpp
#include "algoritmos_busca.h"
// ... outros includes

class BuscaSalto : public AlgoritmoBusca {
public:
    std::string nome() const override {
        return "Busca Salto";
    }
    int buscar(const std::vector<int>& dados, int chave) const override {
        // ... Lógica do jumpsearch(busca de salto) aqui ...
    }
};
```

### Passo 2: Criar a Fábrica (Factory)

Para que o sistema "conheça" o novo algoritmo, declare e implemente uma função de fábrica para ele.

1.  **Declare a fábrica** no arquivo de cabeçalho `buscas/algoritmos_busca.h`:

    ```cpp
    // Em buscas/algoritmos_busca.h
    std::unique_ptr<AlgoritmoBusca> criar_busca_salto();
    ```

2.  **Implemente a fábrica** no final do arquivo `buscas/busca_salto.cpp`:
    ```cpp
    // Em buscas/busca_salto.cpp
    std::unique_ptr<AlgoritmoBusca> criar_busca_salto() {
        return std::make_unique<BuscaSalto>();
    }
    ```

### Passo 3: Adicionar o Algoritmo à Análise

No arquivo `analisador/analisador.cpp`, adicione o algoritmo ao processo de medição dentro do método `executar()`:

```cpp
// Em analisador/analisador.cpp
// ...
auto busca_salto = criar_busca_salto(); // <-- Adiciona a criação
// ...
// ... Medir os outros algoritmos ...
double tempo_salto = medir_tempo_busca(busca_salto.get(), dados_ordenados, chave_busca, num_repeticoes);
arquivo << busca_salto->nome() << "," << n << "," << tempo_salto << "\n"; // <-- Adiciona a medição
```

### Passo 4: Atualizar a Compilação

Finalmente, adicione o novo arquivo `.cpp` à lista de fontes no `Makefile`:

```makefile
# No Makefile
SOURCES = main.cpp \
          buscas/busca_sequencial.cpp \
          buscas/busca_binaria.cpp \
          buscas/busca_salto.cpp \ # <-- Adiciona o novo arquivo
          ...
```

## 🛠️ Como Compilar e Executar

Certifique-se de ter o compilador `g++` e o `make` instalados no seu sistema.

### Passo 1: Compilar o Projeto em C++

Navegue até a pasta raiz do projeto e execute o comando `make`. Isso irá compilar todos os arquivos-fonte e gerar o executável `programa_analise`.

```bash
make
```

### Passo 2: Executar a Análise e Gerar os Dados

Execute o programa gerado no passo anterior. Ele irá rodar os testes de performance e criar um arquivo `resultados_analise.csv` com os dados de tempo.

```bash
./programa_analise
```

### Passo 3: Preparar o Ambiente Python e Gerar o Gráfico

É recomendado o uso de um ambiente virtual para instalar as dependências.

```bash
# Criar e ativar o ambiente virtual (apenas na primeira vez)
python3 -m venv .venv
source .venv/bin/activate

# Instalar as bibliotecas necessárias
pip install pandas matplotlib numpy
```

Com o ambiente ativo, execute o script Python para gerar o gráfico final a partir dos dados do CSV.

```bash
python plotagem.py
```

Isso irá gerar a imagem `grafico_complexidade.png`.

### Limpando o Projeto

Para remover todos os arquivos gerados (executável, arquivos objeto, CSV e imagem), utilize o comando:

```bash
make clean
```

## 👨‍💻 Autor

- **[Davi Otaviano Bezerra Pontes]**
