#include <bits/stdc++.h>

using namespace std;
bitset<2* 1000005> vs;

void dfs(vector<vector<int>>& gs, int u, int id, vector<int>& comp) {
    if (vs[u]) {
        return;
    }
    vs[u] = true;
    
    comp[u] = id;
    for (auto v : gs[u]) {
        dfs(gs, v, id, comp);
    }
}

void solve(int N, vector<vector<int>>& gs, vector<int>& comp) {
    vs.reset();

    int count = 0;
    for (int u = 1; u <= N; u++) {
        if (!vs[u]) {
            count++;
            dfs(gs, u, count, comp);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;
    cin >> N >>  K >> L;

    vector<vector<int>> gs1(N + 1);
    for (int i = 1; i <= K; i++) { // roads
        int p, k;
        cin >> p >> k;

        gs1[p].push_back(k);
        gs1[k].push_back(p);
    }

    vector<vector<int>> gs2(N + 1);
    for (int i = 1; i <= L; i++) { // railways
        int r, s;
        cin >> r >> s;

        gs2[r].push_back(s);
        gs2[s].push_back(r);
    }
    vector<int> comp1(N+1);
    vector<int> comp2(N+1);

    solve(N, gs1, comp1);
    solve(N, gs2, comp2);

    cout << "comp1: ";
    for (int i = 1; i <= N; i++) {
        cout << comp1[i] << ' ';
    }
    cout << '\n';

    cout << "comp2: ";
    for (int i = 1; i <= N; i++) {
        cout << comp2[i] << ' ';
    }
    cout << '\n';

    map<pair<int, int>, int> freq;
    for (int i = 1; i <= N; i++) {
        freq[{comp1[i], comp2[i]}]++;
    }
    cout << '\n';

    return 0;
}