#include <bits/stdc++.h>

using namespace std;

int solve(map<int, vector<int>> &ms, int k, int v)
{
    if (ms.count(v) == 0 || ms[v].size() < k)
    {
        return 0;
    }

    return ms[v][k - 1];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    while (cin >> N >> M)
    {
        map<int, vector<int>> ms;
        for (int i = 1; i <= N; i++)
        {
            int v;
            cin >> v;
            ms[v].push_back(i);
        }

        for (int i = 0; i < M; i++)
        {
            int k, v;
            cin >> k >> v;
            cout << solve(ms, k, v) << '\n';
        }
    }

    return 0;
}