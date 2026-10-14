#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long K;
    cin >> K;
    if (K % 2 == 0 || K % 5 == 0) {
        cout << "-1\n";
        return;
    }

    long long current = 7 % K;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}