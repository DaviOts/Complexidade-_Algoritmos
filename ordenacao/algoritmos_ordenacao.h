#pragma once //substitui o #ifndef/#define/#endif 

#include <vector>
#include <iostream>
#include <memory>


//interface para ordenação
class AlgoritmosOrdenacao {
public:
    //destrutor virtual
    virtual ~AlgoritmosOrdenacao() = default;
    
    //método para retornar o nome
    virtual std::string nome() const = 0;

    //ordenação do vetor
    virtual void ordenar(std::vector<int>& arr) = 0;

};


//puxamos as fábricas novamente, para ficar mais fácil a organização e adição de novos algoritmos 
std::unique_ptr<AlgoritmosOrdenacao> criar_insertion_sort();
std::unique_ptr<AlgoritmosOrdenacao> criar_merge_sort();

