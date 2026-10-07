#include <bits/stdc++.h>

using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

int solve(vector<int> &gs, vector<bool> &vs, vector<int> &sum, int a)
{
    if (sum[a] != -1)
    {
        return sum[a];
    }
    if (vs[a])
    {
        return 0;
    }

    vs[a] = true;
    int ans = 1 + solve(gs, vs, sum, gs[a]);
    vs[a] = false;
    return sum[a] = ans;
}

int found(vector<int> &sum, int n)
{
    int b = -1;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (sum[i] > b) {
            b = sum[i];
            idx = i;
        }
    }
    return idx;
}

int main() {
    fastio;

    int t;
    if (!(cin >> t))
        return 0;

    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> gs(n + 1);
        vector<bool> vs(n + 1);
        vector<int> sum(n + 1);

        for (int j = 1; j <= n; j++)
        {
            int u, v;
            cin >> u >> v;
            gs[u] = v;
        }

        fill(sum.begin(), sum.end(), -1);
        for (int j = 1; j <= n; j++)
        {
            if (sum[j] == -1) {
                solve(gs, vs, sum, j);
            }
        }
        cout << "Case " << i << ": " << found(sum, n) << '\n';
    }
}