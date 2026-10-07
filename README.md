# Algoritmos em Grafos - UnB

Repositório com os códigos, algoritmos e exercícios práticos da disciplina de Algoritmos em Grafos do curso da Universidade de Brasília (UnB).

## Estrutura do Repositório

### 📁 Códigos (`/codigos`)
Implementações em C++ dos principais algoritmos de representação, travessia e análise de propriedades em grafos:

* **Busca em Largura (BFS):** Algoritmo para exploração em nível e cálculo de distâncias em grafos não ponderados (`bfs.cpp`).
* **Busca em Profundidade (DFS):** Algoritmo de travessia e exploração profunda de vértices e arestas (`dfs.cpp`).
* **Componentes Conectados:** Algoritmo para identificação de componentes conexos em grafos (`componentes-conectados.cpp`).
* **Grafos Bipartidos:** Verificação de bipartição em grafos utilizando coloração de vértices (`bipartite.cpp`).
* **Detecção de Ciclos:** Algoritmo para identificação da presença de ciclos no grafo (`cycles.cpp`).

### 📁 Exercícios (`/exercicios`)
Resolução de exercícios práticos e fixação de conteúdo divididos por aulas e listas de atividades:

* **Aulas (Aula 02 a 05):** Resolução de exercícios práticos abordando conceitos de representação (matriz e lista de adjacência), busca e propriedades estruturais dos grafos.
* **Listas de Exercícios:** Listas aplicadas da disciplina para consolidação teórica e prática.

## Como compilar e executar

Para compilar e rodar qualquer um dos algoritmos em C++, navegue até a pasta correspondente pelo terminal e utilize o compilador `g++`:

Exemplo de compilação e execução:
```bash
g++ bfs.cpp -o main
./main