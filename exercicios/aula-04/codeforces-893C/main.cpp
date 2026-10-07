#include <bits/stdc++.h>

using namespace std;
bitset<100005> verifed;

long long bfs(vector<vector<long long>>& gs, vector<long long>& price, long long s) {
    queue<long long> qs;
    long long smallest = price[s];
    qs.push(s);
    verifed[s] = true;

    while (!qs.empty()) {
        long long u = qs.front(); qs.pop();
        for (auto v : gs[u]) {
            if (!verifed[v]) {
                if (price[v] < smallest) {
                    smallest = price[v];
                }
                qs.push(v);
                verifed[v] = true;
            }
        }
    }
    return smallest;
}

void solve(vector<vector<long long>>& gs, vector<long long>& price, long long N) {
    verifed.reset();

    long long total = 0 ;
    for (long long u = 1; u <= N; u++) {
        if (!verifed[u]) {
            total += bfs(gs, price, u);
        }
    }
    cout << total << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    cin >> N >> M;

    vector<long long> price (N+1);
    for (long long i = 1; i <= N; i++) {
        cin >> price[i];
    }

    vector<vector<long long>> gs (N+1);
    for (long long i =1; i <= M; i++) {
        long long x, y;
        cin >> x >> y;
        gs[x].push_back(y);
        gs[y].push_back(x);
    }

    solve(gs, price, N);
    return 0;
}