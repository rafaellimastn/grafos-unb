#include <bits/stdc++.h>

using namespace std;

int passos;

void dfs(int u, int c, vector<vector<int>>& gs, vector<int> cs) {
    if (cs[u] != c) {
        passos++;
        c = cs[u];
    }

    for (auto g : gs[u]) {
        dfs(g, c, gs, cs);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> gs(n + 1);

    for(int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        gs[p].push_back(i);
    }

    vector<int> cs(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> cs[i];
    }

    dfs(1, 0, gs, cs);
    cout << passos << '\n';
    return 0;
}