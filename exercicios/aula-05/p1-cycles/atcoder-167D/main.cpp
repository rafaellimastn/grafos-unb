#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> path;
    vector<int> visited_step(n + 1, -1);

    int current = 1;
    while (visited_step[current] == -1) {
        visited_step[current] = path.size();
        path.push_back(current);
        current = a[current];
    }

    int cycle_start = visited_step[current];
    int path_len = path.size();
    int cycle_len = path_len - cycle_start;

    if (k < path_len) {
        cout << path[k] << "\n";
    } else {
        k -= cycle_start;
        k %= cycle_len;
        cout << path[cycle_start + k] << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}