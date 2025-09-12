#include "algoritmos_ordenacao.h"
#include <vector>
#include <iostream>
#include <memory>

//classe concreta que implementa o MergeSort
class MergeSort : public AlgoritmosOrdenacao {
public:
    std::string nome() const override {
        return "Merge Sort";
    }

    void ordenar(std::vector<int>& arr) override {
        merge_sort(arr, 0, static_cast<int>(arr.size()) - 1);
    }

private:
    //função auxiliar para mesclar duas metades do vetor
    void merge(std::vector<int>& arr, int esquerda, int meio, int direita) {
        int n1 = meio - esquerda + 1;
        int n2 = direita - meio;

        //aqui a gente cria dois vetores temporários para armazenar as metades, no caso L e R
        std::vector<int> L(n1), R(n2);
        for (int i = 0; i < n1; ++i) L[i] = arr[esquerda + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[meio + 1 + j];

        int i = 0, j = 0, k = esquerda;

        //mescla os vetores temporários de volta ao vetor original
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }

        //copia os elementos restantes de L, caso haja
        while (i < n1) arr[k++] = L[i++];
        //copia os elementos restantes de R, caso haja
        while (j < n2) arr[k++] = R[j++];
    }

    //função recursiva que implementa o MergeSort
    void merge_sort(std::vector<int>& arr, int esquerda, int direita) {
        if (esquerda < direita) {
            int meio = esquerda + (direita - esquerda) / 2;
            merge_sort(arr, esquerda, meio);
            merge_sort(arr, meio + 1, direita);
            merge(arr, esquerda, meio, direita);
        }
    }
};

//Fábrica
std::unique_ptr<AlgoritmosOrdenacao> criar_merge_sort() {
    return std::make_unique<MergeSort>();
}