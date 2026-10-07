#include <bits/stdc++.h>

using namespace std;

const int N = 6;
vector<vector<int>> gs = {
    {},
    {2},
    {1, 3, 4, 6},
    {2},
    {2, 5, 6},
    {4},
    {2, 4}
};
bitset<N + 1> vs;

bool dfs(int u, int p = -1) {
    if (vs[u]) {
        return false;
    }
    vs[u] = true;
    for (auto v : gs[u]) {
        if (vs[v] && v != p) {
            return true;
        }
        if (dfs(v, u)) {
            return true;
        }
    }
    return false;
}

bool has_cycles() {
    vs.reset();
    for (int u = 1; u <= N; u++) {
        if ( !(vs[u]) && dfs(u) ) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << (has_cycles() ? "Tem ciclo" : "Nao tem ciclo") << '\n';
}