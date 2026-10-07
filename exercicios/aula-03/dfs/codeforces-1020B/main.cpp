#include <bits/stdc++.h>

using namespace std;

void solve(vector<vector<int>>& gs, vector<bool>& bs, int a) {
    int c = gs[a][0];
    if (bs[c]){
        cout << c << " ";
        return;
    }
    bs[a] = true;
    solve(gs, bs, c);
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> gs(n+1);
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        gs[i].push_back(p);
    }
    
    for (int i = 1; i<=n; i++) {
        vector<bool> bs(n+1);
        solve(gs, bs, i);
    }
    cout << '\n';
}