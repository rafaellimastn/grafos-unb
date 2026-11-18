#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> gs;

// dfs aplicada em arvores (nao necessita do vetor de verificados)
void dfs(int u, int p) {
    for (auto v : gs[u]) {
        if (v != p) {
            dfs(v, u);
        }
    }
}

// conta quantos nós existe para uma arvore, cuja a raiz é o nó u
void dfs_nodes(int u, int p, vector<int>& ns) {
    for (auto v : gs[u]) { // itera pelos nós filhos de u (v)
        if (v == p) {
            continue;
        }

        dfs_nodes(v, u, ns); // calcula quanto nos existe na sub-arvore cuja a raiz é o nó v (filho atual que está sendo processado)
        ns[u] += ns[v]; // soma a qtd de nós da sub-arvore do nó filho (v) a qtd de nós da arvóre do nó pai (u)
    }
}

vector<int> nodes(int u, int N) {
    vector<int> ns (N+1, 1);

    dfs_nodes(u, 0, ns);

    return ns;
}

void dfs_toLeads(int u, int p, vector<int>& tl) {
    for (auto v : gs[u]) {
        if (v == p) {
            continue;
        }

        dfs_toLeads(v, u, tl);
        tl[u] = max(tl[u], 1 + tl[v]);
    }
}

vector<int> toLeads(int u, int N) {
    vector<int> tl(N+1, 0);

    dfs_toLeads(u, 0, tl);

    return tl;
}