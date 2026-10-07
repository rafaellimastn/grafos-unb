#include <bits/stdc++.h>
using namespace std;
const int N = 9;


void dfs(vector<vector<int>>& gs, vector<int>& vs, int u) {
    cout << u << " ";
    vs[u] = true;
    for (auto v : gs[u]) {
        if(!vs[v]) {
            dfs(gs, vs, v);
        }
    }
}

int bfs(vector<vector<int>>& gs, vector<int>& vs, int start, int end) {
    if (start == end) {
        return 0;
    }

    queue<int> q;
    vector<int> dist(gs.size(), -1);

    q.push(start);
    dist[start] = 0;

    // vs[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // cout << u << " ";
        
        for (auto v : gs[u]) {
            if (dist[v] == -1) {
                dist[v] = 1 + dist[u];
                if (v == end) {
                    return dist[v];
                }
                q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    
    vector<vector<int>> gs = {
        {},
        {2, 3, 4, 5},
        {1, 3, 7},
        {1, 2, 4, 6, 8},
        {1, 3, 9},
        {1, 6, 9},
        {3, 5, 7, 8},
        {2, 6},
        {3, 6},
        {4, 5}
    }; 
    vector<int> vs (N+1);
    // dfs(gs, vs, 3);
    // fill(vs.begin(), vs.end(), false);
    // cout << '\n';
    // dfs(gs, vs, 8);
    // fill(vs.begin(), vs.end(), false);
    // cout << '\n';


    cout << bfs(gs, vs, 8, 9) << '\n';
    fill(vs.begin(), vs.end(), false);
    // cout << '\n';    
    // bfs(gs, vs, 8);
    // cout << '\n';



    
    
    return 0;
}