#include <bits/stdc++.h>

using namespace std;
// using ii = pair<int, int>;
int solve(int N, vector<vector<int>>& gs) {
    bool bs = true;
    int res = 0;
    while (bs) {
        vector<int> marcados;
        for (int i = 1; i <= N; i++) {
            if (gs[i].size() == 1) {
                // remove a aresta
                marcados.push_back(i);
            }
        }

        if (marcados.empty()) { // verifica se marcados esta vazio, se estiver retorna 0
            return res;
        } 
        res++;
        
        // se nao incrementa res e itera parra remover os alunos
        for (auto u : marcados) {
            if(gs[u].empty()) continue;

            int v = gs[u][0];

            auto it = find(gs[v].begin(), gs[v].end(), u);
            if (it != gs[v].end()) {
                gs[v].erase(it);
            }
            
            gs[u].clear();
        }

    }
    return res;
}

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<vector<int>> gs (N + 1);
    
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        gs[a].push_back(b);
        gs[b].push_back(a);
    }

    int res = solve(N, gs);
    cout << res << '\n';
    return 0;
}