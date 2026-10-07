#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<string> mapa;
vector<vector<int>> id_componente;
vector<int> tamanho_componente;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dentro_do_mapa(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

int dfs(int x, int y, int id) {
    id_componente[x][y] = id;
    int tamanho = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (dentro_do_mapa(nx, ny) && mapa[nx][ny] == '.' && id_componente[nx][ny] == -1) {
            tamanho += dfs(nx, ny, id);
        }
    }
    return tamanho;
}

void solve() {
    id_componente.assign(N, vector<int> (M, -1));
    int id_atual = 0;

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (mapa[i][j] == '.' && id_componente[i][j] == -1) {
                int tamanho = dfs(i, j, id_atual);
                tamanho_componente.push_back(tamanho);
                id_atual++;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (mapa[i][j] == '*') {
                set<int> grupos_vizinhos_unicos;
                
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    
                    if (dentro_do_mapa(ni, nj) && mapa[ni][nj] == '.') {
                        grupos_vizinhos_unicos.insert(id_componente[ni][nj]);
                    }
                }
                
                int tamanho_total = 1;
                
                for (int id : grupos_vizinhos_unicos) {
                    tamanho_total += tamanho_componente[id];
                }
                
                cout << (tamanho_total % 10);
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    
    mapa.resize(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> mapa[i];
    }

    solve();
}