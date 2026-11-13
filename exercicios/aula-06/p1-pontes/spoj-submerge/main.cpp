#include <bits/stdc++.h>

using namespace std;

int N, M;
int timer_dfs;
vector<vector<int>> gs;
vector<int> tin, low;
vector<bool> is_articulation;

void dfs(int u, int p) {
    tin[u] = low[u] = ++timer_dfs;
    int filhos = 0;

    for (int v : gs[u]) {
        if (v == p) continue; // ignora a aresta de onde viemos (pai direto)

        if (tin[v] != 0) {
            // v ja foi visitado -> aresta de retorno (back-edge)
            low[u] = min(low[u], tin[v]);
        } else {
            // v nao foi visitado -> aresta de arvore (tree-edge)
            filhos++;
            dfs(v, u);
            low[u] = min(low[u], low[v]);

            // Regra 1: u nao e raiz e o filho v nao alcanca nenhum ancestral de u
            if (p != 0 && low[v] >= tin[u]) {
                is_articulation[u] = true;
            }
        }
    }

    // Regra 2: u e a raiz da DFS e possui mais de 1 filho na arvore de DFS
    if (p == 0 && filhos > 1) {
        is_articulation[u] = true;
    }
}

void solve() {
    gs.assign(N + 1, vector<int>());
    tin.assign(N + 1, 0);
    low.assign(N + 1, 0);
    is_articulation.assign(N + 1, false);
    timer_dfs = 0;

    for (int i = 1; i <= M; i++) { // construcao do grafo
        int a, b;
        cin >> a >> b;
        gs[a].push_back(b);
        gs[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        if (tin[i] == 0) {
            dfs(i, 0);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (is_articulation[i]) {
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N >> M && (N != 0 || M != 0)) {
        solve();
    }
    return 0;
}