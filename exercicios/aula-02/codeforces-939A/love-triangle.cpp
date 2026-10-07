#include <bits/stdc++.h>

using namespace std;

bool solve(int n, const vector<int> &graph)
{
    for (int A = 1; A <= n; A++)
    {
        auto B = graph[A];
        auto C = graph[B];

        if (graph[C] == A)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    vector<int> graph(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> graph[i];
    auto ans = solve(N, graph);
    cout << (ans ? "YES" : "NO") << '\n';
}