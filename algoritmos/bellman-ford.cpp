#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
struct edge {
    int u;
    int v;
    int w;
};

const int oo = 1e9;
int N = 6;
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

pair<vector<int>, vector<int>> bellman_ford_caminho(int s) {
    vector<int> dist(N+1, oo), pred(N+1, oo);

    dist[s] = 0;
    pred[s] = s;

    for(int i = 1; i <= N; i++) {
        for (auto[u, v, w] : edges) {
            if (dist[u] < oo and dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }
    return {dist, pred};
}

vector<ii> path(int s, int u, const vector<int>& pred) {
    vector<ii> p;
    int v = u;

    do {
        p.push_back( ii(pred[v], v));
        v = pred[v];
    } while (v != s);

    reverse(p.begin(), p.end());

    return p;
}

bool has_negative_cycle(int s) {
    vector<int> dist(N + 1, oo);
    dist[s] = 0;

    // Algoritmo de Bellman-Ford
    for (int i = 1; i <= N; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] < oo and dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Verifica mais uma vez, se houver relaxamento, existe um ciclo negativo
    for (auto[u, v, w] : edges) {
        if (dist[u] < oo and dist[v] > dist[u] + w) {
            return false;
        }
    }

    return true;
}

int main() {
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

    auto [dist, pred] = bellman_ford_caminho(1);

    for (int u = 1; u <= N; ++u) {
        cout << "Custo minimo de 1 a " << u << " = " << dist[u] << ". Caminho: ";
        auto p = path(1, u, pred);
        cout << 1;
        for (auto [de, para] : p) {
            if (de != para) {
                cout << " -> " << para;
            }
        }
        cout << '\n';
    }

    return 0;
}