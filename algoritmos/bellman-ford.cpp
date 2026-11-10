#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u;
    int v;
    int w;
};

const int oo = 1e9;
int N;
vector<edge>edges (N+1);

vector<int> bellman_ford(int s) {
    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    for (int i = 1; i <= N; i++) { // itera por todos os elementos do grafo
        for (auto [u, v, w] : edges) { // itera por cada aresta
            if (dist[u] < oo and dist[v] > dist[u] + w) { // verifica se u ja foi alcançado e se a distancia de u + o peso de u -> w eh menor que a atual distancia pra v
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

int main() {
    N = 6;
    edges = {
        {1, 2, 9}, {1, 3, 7}, {1, 4, 4},
        {1, 5, 2}, {2, 3, 1}, {2, 6, 3},
        {3, 4, 2}, {4, 5, 1}, {5, 6, 11}
    };

    // Adiciona as arestas no sentido inverso (v -> u)
    int M = edges.size();
    for (int i = 0; i < M; i++) {
        auto [u, v, w] = edges[i];
        edges.push_back({v, u, w});
    }

    auto dist = bellman_ford(1);

    for (int u = 1; u <= N; ++u) {
        cout << "Distancia minima de 1 a " << u << ": " << dist[u] << '\n';
    }

    return 0;
}