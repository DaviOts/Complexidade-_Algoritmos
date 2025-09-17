import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

#nessa parte vamos carregar e preparar os dados
try:
    df = pd.read_csv('resultados_analise.csv', skipinitialspace=True)
    df.columns = df.columns.str.strip()
except FileNotFoundError:
    print("Erro: O arquivo 'resultados_analise.csv' não foi encontrado.")
    exit()

#criei uma nova coluna para guardar os tempos normalizados de cada algoritmo, indo de 0-1
df['tempo_normalizado'] = 0.0

#esse for passa por cada algoritmo, ou seja, insertion, merge e etc
for algoritmo in df['algoritmo'].unique():
    #pega o maior tempo que esse algoritmo específico levou
    max_tempo = df.loc[df['algoritmo'] == algoritmo, 'tempo_medio_ms'].max()
    
    #aqui faço a normalização: divido cada tempo pelo tempo máximo
    #isso garante pra gente que o maior tempo de cada um vire 1 e os outros fiquem proporcionais
    if max_tempo > 0:
        df.loc[df['algoritmo'] == algoritmo, 'tempo_normalizado'] = df.loc[df['algoritmo'] == algoritmo, 'tempo_medio_ms'] / max_tempo

#definir as Funções de Complexidade teorica
#usei np.log2 pois a base 2 acaba sendo comum
def f_n_squared(n): return n**2
def f_n_log_n(n): return n * np.log2(n)
def f_n(n): return n
def f_log_n(n): 
    #tive que colocar um pequeno ajuste para evitar log de 0 ou 1, que podem dar problema
    return np.log2(n + 1)

#aqui prepara as curvas teóricas, também normalizadas
n_values = np.sort(df['tamanho_n'].unique())

#calcular os valores brutos das curvas
y_n2 = f_n_squared(n_values)
y_nlogn = f_n_log_n(n_values)
y_n = f_n(n_values)
y_logn = f_log_n(n_values)

#depois normalizo cada uma delas para aquela escala 0-1
y_n2_norm = y_n2 / y_n2.max()
y_nlogn_norm = y_nlogn / y_nlogn.max()
y_n_norm = y_n / y_n.max()
y_logn_norm = y_logn / y_logn.max()

#parte de configuração visual, como vai ficar interface grafica
plt.style.use('seaborn-v0_8-whitegrid')
font_config = {'family': 'sans-serif', 'weight': 'bold', 'size': 12}
title_config = {'family': 'sans-serif', 'weight': 'bold', 'size': 16}

#cria o grafico final junto
print("Gerando gráfico final...")
plt.figure(figsize=(12, 8))

# Adicionado: Plotando primeiro as curvas teóricas, tracejadas
plt.plot(n_values, y_n2_norm, linestyle='--', color='red', label=r'$O(n^2)$ teórico')
plt.plot(n_values, y_nlogn_norm, linestyle='--', color='blue', label=r'$O(n \log n)$ teórico')
plt.plot(n_values, y_n_norm, linestyle='--', color='green', label=r'$O(n)$ teórico')
plt.plot(n_values, y_logn_norm, linestyle='--', color='purple', label=r'$O(\log n)$ teórico')

#plotando os dados empíricos
#so colocando as cores para cada algoritmo, para bater com sua curva teorica
cores = {
    'Insertion Sort': 'red',
    'Merge Sort': 'blue',
    'Busca Sequencial': 'green',
    'Busca Binária': 'purple'
}

for algoritmo, cor in cores.items():
    subset = df[df['algoritmo'] == algoritmo]
    #agora ploto o tempo_normalizado, e não mais o tempo_medio_ms
    plt.plot(subset['tamanho_n'], subset['tempo_normalizado'], marker='o', linestyle='-', color=cor, label=f'{algoritmo} (empírico)')

#configuração do gráfico em geral, como vai ser exibido
plt.title('Comparação entre análise teórica e empírica', fontdict=title_config, pad=20)
plt.xlabel('Tamanho da entrada (n)', fontdict=font_config)
plt.ylabel('Tempo normalizado', fontdict=font_config)
plt.legend(fontsize=10)
plt.grid(True, which="both", ls="--")
plt.tight_layout()
plt.savefig('grafico_complexidade.png', dpi=300)
print("'grafico_complexidade.png' salvo com sucesso!")

