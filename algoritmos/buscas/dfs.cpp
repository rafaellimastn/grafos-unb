#include <bits/stdc++.h>

using namespace std;

const int N = 13;
vector<vector<int>> gs = {
    {},
    {2, 3},
    {1, 4, 5},
    {1, 6},
    {2},
    {2, 6, 8, 9},
    {3, 5, 7, 10},
    {6},
    {5, 11},
    {5, 10},
    {6, 9},
    {8, 12, 13},
    {11},
    {11}
};
vector<bool> vs (N+1);

void dfs (int u) {
    if(vs[u]) {
        return;
    }
    vs[u] = true;
    cout << u << " ";
    for (auto v : gs[u]) {
        dfs(v);
    }
}

int main() {
    dfs(1);
    cout << '\n';
}