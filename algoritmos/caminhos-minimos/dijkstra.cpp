#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int oo {10000010};
vector<vector<ii>>gs; // vetor de adjacencias (vertice, distancia)

vector<int> dijkstra(int s, int N) {
    vector<int> dist (N+1, oo);
    dist[s] = 0;

    set<ii> U;
    U.emplace(0, s);

    while(not U.empty()) {
        auto [d, u] = *U.begin(); // extrai o primeiro vértice(u) e a sua distancia(d) do conjunto U
        U.erase(U.begin());

        for (auto [v, w] : gs[u]) { // itera pelos vértices vizinhos(v) do vértice u
            if (dist[v] > d + w) {
                U.erase(ii(dist[v], v)); // verifica se o dist[v] e v já esão contidos no conjunto U, se tiver é preciso remove-lo p/ atualizar o valor.

                dist[v] = d + w;
                U.emplace(dist[v], v);
            }
        }
    }
    return dist;
}

pair<vector<int>, vector<int>> dijkstra_caminho(int s, int N) {
    vector<int> dist (N+1, oo), pred(N+1, oo);
    dist[s] = 0;
    pred[s] = s;

    set<ii> U;
    U.emplace(0, s);

    while(not U.empty()) {
        auto [d, u] = *U.begin(); // extrai o primeiro vértice(u) e a sua distancia(d) do conjunto U
        U.erase(U.begin());

        for (auto [v, w] : gs[u]) { // itera pelos vértices vizinhos(v) do vértice u
            if (dist[v] > d + w) {
                U.erase(ii(dist[v], v)); // verifica se o dist[v] e v já esão contidos no conjunto U, se tiver é preciso remove-lo p/ atualizar o valor.

                dist[v] = d + w;
                pred[v] = u;
                U.emplace(dist[v], v);
            }
        }
    }

    return {dist, pred};
}

vector<ii> path(int s, int u, const vector<int>& pred) {
    vector<ii> path;
    int v = u;

    do {
        path.emplace_back(pred[v], v);
        v = pred[v];
    } while(v != s);

    reverse(path.begin(), path.end());

    return path;
}

int main() {
    int N = 6;
    gs.resize(N + 1);

    // Grafo do Slide 19 (A=1, B=2, C=3, D=4, E=5, F=6)
    vector<tuple<int, int, int>> edges = {
        {1, 2, 9}, {1, 3, 7}, {1, 4, 4},
        {1, 5, 2}, {2, 3, 1}, {2, 6, 3},
        {3, 4, 2}, {4, 5, 1}, {5, 6, 11}
    };

    for (auto [u, v, w] : edges) {
        gs[u].emplace_back(v, w);
        gs[v].emplace_back(u, w); // grafo não-direcionado
    }

    auto [dist, pred] = dijkstra_caminho(1, N);


    for (int u = 1; u <= N; ++u) {
        cout << "Distancia minima de 1 a " << u << " = " << dist[u] << ". Caminho: ";
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