#include <bits/stdc++.h>

using namespace std;

const int N = 10;
vector<vector<int>> gs = {
    {},
    {2, 3, 4, 5},
    {1, 6},
    {1, 6},
    {1, 8},
    {1, 7},
    {2, 3, 9},
    {5, 9},
    {4, 9},
    {6, 7, 8, 10},
    {9}
};

vector<int> cs (N+1);
const int NONE = 0, BLUE = 1, RED = 2;

bool bfs (int s) {
    queue<int> qs;
    qs.push(s);
    cs[s] = 1;

    while (!qs.empty()) {
        int u = qs.front(); qs.pop();

        for (auto v : gs[u]) {
            if (cs[v] == NONE) {
                cs[v] = 3 - cs[u];
                qs.push(v);
            } else if (cs[v] == cs[u]) {
                return false;
            }
        }
    }
    return true;
}
bool bipartite() {
    for (int u = 1; u <= N; u++) {
        if ( (cs[u] == NONE) &&  !bfs(u)) {
            return false;
        }
    }
    return true;
}

int main() {
    fill(cs.begin(), cs.end(), NONE);
    cout << (bipartite() ? "eh bipartido" : "nao eh bipartido") << '\n';
}