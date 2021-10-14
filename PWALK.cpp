#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int N = 1100;
int n, q;
int c[N][N], d[N][N];
vector <ii> adj[N];

void dfs(int st, int u, int par) {
    // cout << st << " " << u << "\n";
    // if (d[st][u]) return;
    for (ii v: adj[u]) {
        int uv = v.second;
        if (v.first == par) continue;
        // cout << v.first << "\n";
        d[st][v.first] = d[st][u] + uv;
        dfs(st, v.first, u);
    }
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        c[u][v] = c[v][u] = w;
        adj[u].push_back(ii(v, w)); 
        adj[v].push_back(ii(u, w)); 
    }

    while (q--) {
        int s, t;
        scanf("%d%d", &s, &t);
        dfs(s, s, 0);
        printf("%d\n", d[s][t]);
    }
}