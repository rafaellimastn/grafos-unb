#include <bits/stdc++.h>

using namespace std;
const int N = 10;
vector<vector<int>> gs = { {}, {2, 8}, {10}, {7}, {5, 9}, {4, 9}, {}, {3}, {1}, {4, 5}, {2} };
bitset<N> vs;

void dfs(int u) {
    if (vs[u]) {
        return;
    }
    vs[u] = true;
    cout << ' ' << u;
    for (auto v : gs[u]) {
        dfs(v);
    }
}

int components(vector<vector<int>>& gs) {
    vs.reset();
    int count = 0;
    for( int u = 1; u <= N; u++) {
        if (!vs[u]) {
            cout << "Component : " << ++count << ":";
            dfs(u);
            cout << '\n';
        }
    }
    return count;
}

int main() {
    int contador = components(gs);
    cout << "Componentes conectados = " << contador << '\n';
    
    return 0;
}