#include "algoritmos_ordenacao.h"
#include <vector>
#include <iostream>
#include <memory>

//classe concreta para a implementação do InsertionSort
class InsertionSort : public AlgoritmosOrdenacao {
public:
    std::string nome() const override {
        return "Insertion Sort";
    }

    //método que implementa a ordenação por inserção
    void ordenar(std::vector<int>& arr) override {
        int n = static_cast<int>(arr.size()); // tamanho do vetor
        //esse for percorre o vetor a partir do segundo elemento
        for (int i = 1; i < n; ++i) {  
            int chave = arr[i];
            int j = i - 1;
            //move os elementos do vetor que são maiores que a chave
            //uma posição à frente da sua posição atual(direita)
            while (j >= 0 && arr[j] > chave) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = chave; //insere a chave na posição correta
        }
    }
};

//Fábrica
std::unique_ptr<AlgoritmosOrdenacao> criar_insertion_sort() {
    return std::make_unique<InsertionSort>();
}
    