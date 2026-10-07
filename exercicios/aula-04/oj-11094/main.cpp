#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<string> mapa;
char terra;
char agua;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dfs(int x, int y) {
    mapa[x][y] = '.';

    int count = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = (y + dy[i] + N) % N;
        
        if (nx >= 0 && nx < M && mapa[nx][ny] == terra) {
            count += dfs(nx, ny);
        }
    }

    return count;
}

void solve() {
    while (cin >> M >> N) {
        mapa.assign(M, "");

        for (int i = 0; i < M; i++) {
            cin >> mapa[i];
        }
    
        int X, Y;
        cin >> X >> Y;
        terra = mapa[X][Y];
        dfs(X, Y);
    
        int maior = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mapa[i][j] == terra) {
                    int atual = dfs(i, j);
                    if (atual > maior) {
                        maior = atual;
                    }
                }
            }
        }
        cout << maior << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();

    return 0;
}