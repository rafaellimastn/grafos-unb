#include <bits/stdc++.h>

using namespace std;

int solve(vector<vector<int>>& es) {
    
    map<int, int> ms;
    set<int> ss;
    for(auto e : es) {
        ss.insert(e[0]);
        ss.insert(e[1]);
        ms[e[0]]++;
        ms[e[1]]++;
    }
    int m = 0;
    
    for(auto s : ss) {
        if(ms[s] > m) {
            m = s;
        }
    }
    return m;
}

int main() {
    vector<vector<int>> edges = {{1,2},{5,1},{1,3},{1,4}};
    
    cout << solve(edges) << '\n';
}