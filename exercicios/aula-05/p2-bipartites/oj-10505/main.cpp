#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int NONE = 0, BLUE = 1, RED = 2;

ii bfs(vector<vector<int>>& gs, vector<int>& color, int s) {
    queue<int> qs;  
    bool bipartido = true;

    ii res = {0, 0};

    qs.push(s);
    color[s] = BLUE;
    res.first++;
    while (not qs.empty()) {

        auto v = qs.front(); qs.pop();

        for (auto u : gs[v]) {
            if (color[u] == NONE) {
                color[u] = 3 - color[v];
                if (color[u] == BLUE) {
                    res.first++;
                } else {
                    res.second++;
                }
                qs.push(u);
            } else if (color[u] == color[v]) {
                bipartido = false;
            }
        }
    }
    if (!bipartido) {
        return {0, 0};
    }
    return res;
}

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> gs(N+1);
    for (int i = 1; i <= N; i++) {
        int p;
        cin >> p;
        for (int j = 1; j <= p; j++) {
            int u;
            cin >> u;
            if (u <= N) {
                gs[i].push_back(u);
                gs[u].push_back(i);
            }
        }
    }

    vector<int> color (N+1);

    int maior = 0;
    for (int s = 1; s <= N; s++) {
        if (color[s] == NONE) {
            ii res = bfs(gs, color, s);
            maior += max(res.first, res.second);
        } 
    }
    cout << maior << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    cin >> M;
    while (M--) {
        solve();
    }
    return 0;
}