# Análise Empírica de Complexidade de Algoritmos

Este projeto foi desenvolvido para a disciplina de Estruturas de Dados Básicas II (IMD0039) da UFRN, sob orientação do Prof. João Guilherme.

## 📝 Descrição do Projeto

O objetivo deste trabalho é realizar uma análise empírica do tempo de execução de algoritmos de busca e ordenação. O programa implementado mede a performance de quatro algoritmos distintos para diferentes tamanhos de entrada (N), compara os resultados obtidos com as curvas de complexidade teóricas (Notação Big O) e gera um gráfico unificado para a visualização e análise dos dados.

## 🚀 Tecnologias Utilizadas

- **C++ (padrão C++17):** Para a implementação dos algoritmos e a medição de performance de alta precisão, utilizando a biblioteca `<chrono>`. O código foi estruturado de forma modular e orientada a objetos para facilitar a extensibilidade.
- **Python 3:** Para a análise e visualização dos dados.
  - **Pandas:** Para a manipulação dos dados exportados pelo programa em C++.
  - **Matplotlib:** Para a geração do gráfico comparativo final.
- **Make:** Para a automação do processo de compilação do projeto em C++.

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
