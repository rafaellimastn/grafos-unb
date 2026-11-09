#include <bits/stdc++.h>

using namespace std;

const int oo = 1e9;
int N;
vector<vector<int>>gs (N+1);

vector<int> min_dist(int s, int w = 1) {
    vector<int> dist (N+1, oo);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        for (auto v : gs[u]) {
            if (dist[v] == oo) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    // declaracao do grafo gs
    N = 7;
    gs = {
        {},          // 0 (não usado, 1-indexed)
        {2, 3},      // 1
        {1, 4},      // 2 (origem da busca)
        {1, 4, 5},   // 3
        {2, 3, 5},   // 4
        {3, 4, 6},   // 5
        {5},         // 6
        {}           // 7 (isolado)
    };

    vector<int> dists = min_dist(2); // grafo das distancias dos vertices comecando a busca em 2
    for (int i = 1; i <= N; i++) {
        if (dists[i] == oo) {
            cout << "Vertice " << i << ": " << "oo" << '\n';
            continue;
        }
        cout << "Vertice " << i << ": " << dists[i] << '\n';
    }
    return 0;
}