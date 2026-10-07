#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<int>>& gs, int s, int e) {
    queue<int> q;
    
    vector<vector<int>> ds;
    q.push(s);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : gs[u]) {
            if(!vs[v]) {
                q.push(v);
                vs[v] = true;
            }
            if (v == e) {
                return ds[v];
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> gs(N + 1);

    vector<int> ds(N+1);
    for (int i = 1; i <= M; i++) {
        int v, u;
        cin >> v >> u;
        gs[v].push_back(u);
    }
    int S, T;
    cin >> S >> T;
    cout << bfs(gs, S, T) << '\n';
}