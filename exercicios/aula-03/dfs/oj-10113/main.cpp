#include <bits/stdc++.h>

using namespace std;
using ll = pair<long, long>;
struct Edge {
    string to;
    long long num, den;
};

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll dfs(unordered_map<string, vector<Edge>>& gs,
    unordered_map<string, bool>& ls,
    string& v, string& e,
    long long num = 1, long long den = 1) {
    ls[v] = true;
    if (v == e) {
        long long g = gcd(num, den);
        return {num / g, den / g};
    }

    for (auto nv : gs[v]) {
        if(!ls[nv.to]) {
            long long next_num = num * nv.num;
            long long next_den = den * nv.den;
            long long g = gcd(next_num, next_den);

            auto res = dfs(gs, ls, nv.to, e, next_num / g, next_den / g);

            if(res.first != -1) {
                return res;
            }
        }
    }
    return {-1, -1};
}

int main() {
    char op;
    unordered_map<string, bool> vs;
    unordered_map<string, vector<Edge>> gs;
    while(cin >> op && op != '.') {
        string a, b, eq;
        if (op == '!') {
            long long d, n;
            cin >> d >> a >> eq >> n >> b;
            long long g = gcd(d, n);
            d /= g;
            n /= g;
            gs[a].push_back({b, n, d});
            gs[b].push_back({a, d, n});
        } else if ( op == '?') {
            vs.clear();
            cin >> a >> eq >> b;
            ll v = dfs(gs, vs, a, b);
            if (v.first == -1) {
                cout << "? " << a << " = ? " << b << '\n';
            } else {
                gs[a].push_back({b, v.first, v.second});
                gs[b].push_back({a, v.second, v.first});
                cout << v.second << " " << a << " = " << v.first << " " << b << '\n';
            }
        }
    }
}