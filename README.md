# Algoritmos em Grafos - UnB

Repositório com os códigos, algoritmos e exercícios práticos da disciplina de Algoritmos em Grafos do curso da Universidade de Brasília (UnB).

## Estrutura do Repositório

### 📁 Algoritmos (`/algoritmos`)
Implementações em C++ dos principais algoritmos de travessia, propriedades estruturais e caminhos mínimos em grafos, organizados por categoria:

* **Buscas (`/algoritmos/buscas`):**
  * **Busca em Largura (BFS):** Exploração em nível em grafos (`bfs.cpp`).
  * **Busca em Profundidade (DFS):** Travessia e exploração profunda de vértices e arestas (`dfs.cpp`).
* **Propriedades (`/algoritmos/propriedades`):**
  * **Componentes Conectados:** Identificação de componentes conexos em grafos (`componentes-conectados.cpp`).
  * **Grafos Bipartidos:** Verificação de bipartição utilizando coloração de vértices (`bipartite.cpp`).
  * **Detecção de Ciclos:** Identificação da presença de ciclos no grafo (`cycles.cpp`).
* **Caminhos Mínimos (`/algoritmos/caminhos-minimos`):**
  * **Caminhos Mínimos com BFS:** Cálculo de distâncias mínimas em grafos não ponderados ou de peso constante (`caminhos-minimos.cpp`).
  * **BFS Binária (0-1 BFS):** Caminhos mínimos em grafos com arestas de peso 0 ou 1 (`bfs-binaria.cpp`).
  * **Dijkstra:** Caminhos mínimos de fonte única em grafos com pesos não negativos (`dijkstra.cpp`).
  * **Bellman-Ford:** Caminhos mínimos de fonte única com suporte a pesos negativos e detecção de ciclos negativos (`bellman-ford.cpp`).
  * **Floyd-Warshall:** Caminhos mínimos entre todos os pares de vértices (`floyd-warshall.cpp`).

### 📁 Exercícios (`/exercicios`)
Resolução de exercícios práticos e fixação de conteúdo divididos por aulas e listas de atividades:

* **Aulas (Aula 02 a 09):** Resolução de exercícios práticos abordando representação de grafos, busca, propriedades estruturais e caminhos mínimos (Bellman-Ford, Dijkstra e Floyd-Warshall).
* **Listas de Exercícios:** Listas aplicadas da disciplina para consolidação teórica e prática.

## Como compilar e executar

Para compilar e rodar qualquer um dos algoritmos em C++, navegue até a pasta correspondente pelo terminal e utilize o compilador `g++`:

Exemplo de compilação e execução:
```bash
g++ bfs.cpp -o main
./main