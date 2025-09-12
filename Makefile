#Nome do compilador C++
CXX = g++

#Flags de compilação
CXXFLAGS = -std=c++17 -Wall -O2

#Nome do programa executável que será gerado
EXECUTABLE = programa_analise

#Lista de todos os arquivos fonte (.cpp)
SOURCES = main.cpp \
          buscas/busca_sequencial.cpp \
          buscas/busca_binaria.cpp \
          ordenacao/insertion_sort.cpp \
          ordenacao/merge_sort.cpp \
          analisador/analisador.cpp

#Gera a lista de arquivos objeto (.o) a partir da lista de fontes
OBJECTS = $(SOURCES:.cpp=.o)

#O all padrão (quando a gente digita "make" ele executa tudo)
all: $(EXECUTABLE)

#Serve para linkar os arquivos objeto e criar o executável final
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXECUTABLE) $(OBJECTS)

#Compilação de cada arquivo .cpp em um arquivo .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#clean serve para limpar os arquivos gerados, no caso os executaveis e os .o
clean:
	rm -f $(EXECUTABLE) $(OBJECTS)

.PHONY: all clean