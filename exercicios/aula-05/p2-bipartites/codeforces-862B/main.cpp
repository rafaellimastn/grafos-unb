#include <bits/stdc++.h>

using namespace std;

using ll = pair<long long, long long>;

ll bfs(vector<vector<long long>>& gs, long long N) {
    long long NONE = 0, BLUE = 1, RED = 2;
    vector<long long> colors (N+1);
    queue<long long> qs;
    ll res;
    
    res.first = 1;
    qs.push(1);
    colors[1] = BLUE;
    long long i = 0;
    while (not qs.empty()) {

        auto u = qs.front(); qs.pop();

        for (auto v : gs[u]) {
            if (colors[v] == NONE) {
                colors[v] = 3 - colors[u];
                if (colors[v] == BLUE) {
                    res.first++;
                } else if (colors[v] == RED) {
                    res.second++;
                }
                qs.push(v);
            }
        }
    }
    return res;
}

void solve() {
    long long N;
    cin >> N;
    vector<vector<long long>> gs (N + 1);
    for (long long i = 1; i <= N-1; i++) {
        long long u, v;
        cin >> u >> v;
        gs[u].push_back(v);
        gs[v].push_back(u);
    }

    ll br = bfs(gs, N);

    long long res = (br.first * br.second) - (N-1);
    cout << res << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}