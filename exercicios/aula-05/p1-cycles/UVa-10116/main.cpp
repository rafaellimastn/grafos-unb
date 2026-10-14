#include <bits/stdc++.h>

using namespace std;
using ii =  pair<int, int>;

void solve() {
    int n, m, s;
    cin >> n >> m >> s;

    vector<string> matriz (n+1);

    for (int i = 1; i <= n; i++) {
        cin >> matriz[i];
    }
    
    
    map<ii, bool> verified;
    int passos = 0;
    ii anterior = {-1, -1};
    ii cord = {1, s};
    while (!verified[cord] && cord != anterior) {
        verified[cord] = true;
        anterior = cord;
        switch (matriz[cord.first][cord.second]) {
        case 'N':
            cord.first++;
            break;
        
        case 'S':
            cord.first--;
            break;

        case 'E':
            cord.second++;
            break;

        case 'W':
            cord.second--;
            break;

        default:
            break;
        }
        passos++;
    }

    cout << passos << " step(s) to exit\n";
}

int main () {

    for (int i = 0; i < 3; i++)
        solve();

    return 0;
}