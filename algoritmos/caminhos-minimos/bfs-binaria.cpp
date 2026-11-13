#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int oo {10000010};
vector<vector<ii>> gs;

vector<int> bfs_binaria(int s, int N) {
    vector<int> dist (N + 1, oo);
    dist[s] = 0;

    deque<int> q;
    q.emplace_back(s);

    while (not q.empty()) {
        auto u = q.front(); q.pop_front();

        for (auto [v, w] : gs[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                w == 0 ? q.emplace_front(v) : q.emplace_back(v);
            }
        }
    }
    return dist;
}

pair<vector<int>, vector<int>> bfs_binaria_caminho(int s, int N) {
    vector<int> dist(N + 1, oo), pred(N + 1, oo);
    dist[s] = 0;
    pred[s] = s;

    deque<int> q;
    q.emplace_back(s);

    while (not q.empty()) {
        auto u = q.front(); q.pop_front();

        for (auto [v, w] : gs[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pred[v] = u;
                w == 0 ? q.emplace_front(v) : q.emplace_back(v);
            }
        }
    }
    return {dist, pred};
}

vector<ii> path(int s, int u, const vector<int>& pred) {
    vector<ii> p;
    int v = u;

    do {
        p.emplace_back(pred[v], v);
        v = pred[v];
    } while (v != s);

    reverse(p.begin(), p.end());

    return p;
}

int main() {
    int N = 6;
    gs.resize(N + 1);

    vector<tuple<int, int, int>> edges = {
        {1, 2, 0}, {1, 3, 1}, {2, 3, 0},
        {2, 4, 1}, {3, 5, 1}, {4, 5, 0},
        {4, 6, 1}, {5, 6, 0}
    };

    for (auto [u, v, w] : edges) {
        gs[u].emplace_back(v, w);
        gs[v].emplace_back(u, w);
    }

    auto [dist, pred] = bfs_binaria_caminho(1, N);

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