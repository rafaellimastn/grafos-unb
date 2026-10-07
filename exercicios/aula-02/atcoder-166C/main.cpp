#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

int solve(vector<int> gs[], vector<int>& hs, int N) {
    int a = 0;
    for(int i = 1; i <= N; i++) {
        bool b = true;
        for (auto neighboors : gs[i]) {
            if (hs[i] <= hs[neighboors]) {
                b = false;
                break;
            }
        }
        if (b) {
            a++;
        }
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    
    vector<int> hs(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> hs[i];
    }
    
    vector<int> gs[N + 1];
    for (int i = 1; i <= M; i++) {
        int a, b;
        cin >> a >> b;
        gs[a].push_back(b);
        gs[b].push_back(a);
    }
    int res = solve(gs, hs, N);
    cout << res << '\n';
    return 0;
}