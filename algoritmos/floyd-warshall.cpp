#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int oo {10000010};
vector<vector<ii>>gs;

vector<vector<int>> floyd_warshall(int N) {
    vector<vector<int>> dist (N+1, vector<int>(N+1, oo)); // preenche todas as distancias com oo(infinito)

    for (int u = 1; u <= N; u++) { // distancia de u -> u = 0
        dist[u][u] = 0;
    }

    for (int u = 1; u <= N; u++) {
        for (auto[v, w] : gs[u]) { // itera por todas as arestas e preenche a distancia de u -> v = w
            dist[u][v] = w;
        }
    }

    for (int k = 1; k <= N; k++) { // itera pelos vertices intermediarios
        for (int u = 1; u <= N; u++) { // itera pelos vertices de saida
            for (int v = 1; v <= N; v++){ // itera pelos vertices de chegada
                if (dist[u][k] < oo and dist[k][v] < oo) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]); // compara e atribui qual a menor distancia: a distancia do vertice de saida para o vertice de chegada (u -> v) ou a distancia do vertice de saida para o vertice intermediario + vertice de chegada ( (u -> k) + (k -> v) )
                }
            }
        }
    }

    return dist;
}

pair<vector<vector<int>>, vector<vector<int>>> floyd_warshall_caminho(int N) {
    vector<vector<int>> dist (N+1, vector<int>(N+1, oo));
    vector<vector<int>> pred (N+1, vector<int>(N+1, oo));

    for (int u = 1; u <= N; u++) { // distancia de u -> u = 0
        dist[u][u] = 0;
        pred[u][u] = u;
    }

    for (int u = 1; u <= N; u++) {
        for (auto[v, w] : gs[u]) { // itera por todas as arestas e preenche a distancia de u -> v = w
            dist[u][v] = w;
            pred[u][v] = u;
        }
    }

    for (int k = 1; k <= N; k++) { // itera pelos vertices intermediarios
        for (int u = 1; u <= N; u++) { // itera pelos vertices de saida
            for (int v = 1; v <= N; v++){ // itera pelos vertices de chegada
                if (dist[u][k] < oo and dist[k][v] < oo and dist[u][v] > dist[u][k] + dist[k][v]) { // verifica se realmente houve mudança no valor da distancia de u -> v
                    dist[u][v] = dist[u][k] + dist[k][v];
                    pred[u][v] = pred[k][v];
                }
            }
        }
    }

    return {dist, pred};
}

vector<ii> path(int u, int  v, const vector<vector<int>>& pred) {
    vector<ii> p;

    do {
        p.emplace_back(pred[u][v], v);
        v = pred[u][v];
    } while(v != u);

    reverse(p.begin(), p.end());

    return p;
}

bool has_negative_cycle(int N) {
    vector<vector<int>> dist (N+1, vector<int>(N+1, oo));

    for (int u = 1; u <= N; u++) {
        dist[u][u] = 0;
    }

    for (int u = 1; u <= N; u++) {
        for (auto[v, w] : gs[u]) {
            dist[u][v] = w;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++){
                if (dist[u][k] < oo and dist[k][v] < oo) {
                    dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                }
            }
        }
    }

    for (int u = 1; u <= N; u++) {
        if (dist[u][u] < 0) return true; // verifica se na matriz de distancias finais existe algum elemento na diagonal menor que 0 (indicando que existe um ciclo negativo de u -> u)
    }

    return false;
}

int main() {
    int N = 6;
    gs.resize(N + 1);

    // Grafo do Slide 19 com o vértice 6 isolado (inalcançável por 1..5)
    vector<tuple<int, int, int>> edges = {
        {1, 2, 9}, {1, 3, 7}, {1, 4, 4},
        {1, 5, 2}, {2, 3, 1},
        {3, 4, 2}, {4, 5, 1}
    };

    for (auto [u, v, w] : edges) {
        gs[u].emplace_back(v, w);
        gs[v].emplace_back(u, w);
    }

    auto [dist, pred] = floyd_warshall_caminho(N);

    for (int u = 1; u <= N; ++u) {
        for (int v = 1; v <= N; ++v) {
            if (dist[u][v] == oo) {
                cout << "Distancia minima de " << u << " a " << v << " = oo.\n";
                continue; 
            }
            cout << "Distancia minima de " << u << " a " << v << " = " << dist[u][v] << ". ";
            cout << "Caminho: " << u;
            auto p = path(u, v, pred);
            for (auto [de, para] : p) {
                if (de != para) {
                    cout << " -> " << para;
                }
            }
            cout << '\n';
        }
        cout << '\n';
    }

    return 0;
}